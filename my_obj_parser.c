#include "my_obj_parser.h"
#include "lists/ListOfVertices.h"
#include "lists/ListOfTextures.h"
#include "ObjParametersTuple.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/gl.h>

void draw_3d_scene_from_file(char* filename) {
    if (!file_is_present(filename) || !file_is_obj(filename)) {
        return;
    }

    FILE* file = fopen(filename, "r");

    handle_file(file);

    fclose(file);
}

bool file_is_present(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror(filename);
        return false;
    }
    fclose(file);
    return true;
}

bool file_is_obj(char* filename) {
    int size = strlen(filename);
    char* ptr = &(filename[size - 4]);
    return ptr[0] == '.' && ptr[1] == 'o' && ptr[2] == 'b' && ptr[3] == 'j';
}

void handle_file(FILE* file) {
    ObjParametersTuple tuple = create_obj_parameters_tuple();

    read_file(file, &tuple);

    draw_model(&tuple);

    free_obj_parameters_tuple(&tuple);
}

void read_file(FILE* file, ObjParametersTuple* tuple) {
    char string[256];
    memset(string, 0, sizeof(string));

    while (!(feof(file))) {
        fgets(string, 255, file);
        parse_string(string, tuple);
    }
}

void draw_model(ObjParametersTuple* tuple) {
    for (int i = 0; i < tuple->list_of_faces->size; ++i) {
        int type = define_face_connection_type(tuple->list_of_faces->faces[i].number_of_vertices);

        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        
        glBegin(type);

        draw_vertices_of_face(&(tuple->list_of_faces->faces[i]));

        glEnd();
    }
}

void draw_vertices_of_face(const Face* face) {
    for (int j = 0; j < face->number_of_vertices; ++j) {
        Vertex vertex = face->vertices[j];
        glVertex3f(vertex.x, vertex.y, vertex.z);
    }
}

int define_face_connection_type(int number_of_vertices_in_face) {
    switch (number_of_vertices_in_face) {
        case 3:
            return GL_TRIANGLES;
        case 4:
            return GL_QUADS;
        default:
            return -1;
    }
}

enum InputStringType define_string_type(char* string) {
    if (string[0] == 'v' && string[1] == ' ') {
        return VERTEX;
    }

    if (string[0] == 'v' && string[1] == 't') {
        return TEXTURE;
    }

    if (string[0] == 'f' && string[1] == ' ') {
        return FACE;
    }

    if (string[0] == 'v' && string[1] == 'n') {
        return NORMAL;
    }
}

void parse_string(char* string, ObjParametersTuple* tuple) {
    switch (define_string_type(string)) {
        case VERTEX:
            return parse_vertex_string(string, tuple);
        case TEXTURE:
            return parse_texture_string(string, tuple);
        case FACE:
            return parse_face_string(string, tuple);
        case NORMAL:
            return parse_normal_string(string, tuple);
        default:
            return;
    }
}

void parse_vertex_string(char* string, ObjParametersTuple* tuple) {
    ++string;

    GLfloat values[3];
    for (int i = 0; i < 3; ++i) {
        values[i] = 0.0f;
    }

    for (int j = 0; *string != '\n' && j < 3; ++j) {
        ++string;
        values[j] = parse_float_number(&string);
    }

    Vertex vertex = create_vertex_with_coordinates(values);
    add_in_list_of_vertices(tuple->list_of_vertices, &vertex);
}

void parse_texture_string(char* string, ObjParametersTuple* tuple) {
    ++string;

    GLfloat values[2];
    for (int i = 0; i < 2; ++i) {
        values[i] = 0.0f;
    }

    for (int j = 0; *string != '\n' && j < 2; ++j) {
        ++string;
        values[j] = parse_float_number(&string);
    }

    Texture texture = create_texture_with_parameters(values);
    add_in_list_of_textures(tuple->list_of_textures, &texture); 
}

void parse_face_string(char* string, ObjParametersTuple* tuple) {
    ++string;

    int number_of_vertices_to_connect = number_of_slashes(string) / 2;
    int* indexes = (int*)malloc(number_of_vertices_to_connect * sizeof(int));

    for (int j = 0; *string != '\n' && j < number_of_vertices_to_connect; ++j) {
        ++string;

        indexes[j] = parse_int_number(&string) - 1;
        
        while (*string != ' ' && *string != '\n') {
            ++string;
        }
    }

    Face face;
    face.number_of_vertices = number_of_vertices_to_connect;
    face.vertices = (Vertex*)malloc(face.number_of_vertices * sizeof(Vertex));

    for (int i = 0; i < face.number_of_vertices; ++i) {
        face.vertices[i] = tuple->list_of_vertices->vertices[indexes[i]];
    }
    
    add_in_list_of_faces(tuple->list_of_faces, &face);

    free(indexes);
}

void parse_normal_string(char* string, ObjParametersTuple* tuple) {
    ++string;

    GLfloat values[3];
    for (int i = 0; i < 3; ++i) {
        values[i] = 0.0f;
    }

    for (int j = 0; *string != '\n' && j < 3; ++j) {
        ++string;
        values[j] = parse_float_number(&string);
    }

    Normal normal = create_normal_with_coordinates(values);
    add_in_list_of_normals(tuple->list_of_normals, &normal);
}

float parse_float_number(char** string) {
    char buffer[256];
    memset(buffer, 0, sizeof(buffer));

    read_number_from_string(string, buffer);

    return atof(buffer);
}

int parse_int_number(char** string) {
    char buffer[256];
    memset(buffer, 0, sizeof(buffer));

    read_number_from_string(string, buffer);

    return atoi(buffer);
}

int number_of_slashes(char* string) {
    int number_of_slashes = 0;

    while (*string != '\n') {
        if (*string == '/') {
            ++number_of_slashes;
        }
        ++string;
    }

    return number_of_slashes;
}

void read_number_from_string(char** string_to_read, char* buffer_to_write) {    
    for (int i = 0; !isNumberFinished(*string_to_read); ++i) {
        buffer_to_write[i] = **string_to_read;
        ++(*string_to_read);
    }
}

bool isNumberFinished(const char* string_to_read) {
    return *string_to_read == ' ' || *string_to_read == '\n' || *string_to_read == '/';
}

Vertex create_vertex_with_coordinates(GLfloat* coordinates) {
    Vertex vertex;
    vertex.x = coordinates[0];
    vertex.y = coordinates[1];
    vertex.z = coordinates[2];
    return vertex;
}

Texture create_texture_with_parameters(GLfloat* parameters) {
    Texture texture;
    texture.u = parameters[0];
    texture.v = parameters[1];
    return texture;
}

Normal create_normal_with_coordinates(GLfloat* coordinates) {
    Normal normal;
    normal.x = coordinates[0];
    normal.y = coordinates[1];
    normal.z = coordinates[2];
    return normal;
}