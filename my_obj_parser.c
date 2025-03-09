#include <GL/gl.h>
#include "my_obj_parser.h"
#include "lists/ListOfVertices.h"
#include "lists/ListOfTextures.h"
#include "ObjParametersTuple.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stb_image.h"
#include <stddef.h>

GLuint texture_id;

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

    DrawingParameters parameters;
    parameters.color_r = 0.0;
    parameters.color_g = 0.0;
    parameters.color_b = 0.0;
    parameters.face_mode = GL_FRONT_AND_BACK;
    parameters.connection_mode = GL_FILL;
    draw_model(&tuple, &parameters);
    parameters.color_g = 1.0;
    parameters.connection_mode = GL_LINE;
    draw_model(&tuple, &parameters);

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

void draw_model(ObjParametersTuple* tuple, DrawingParameters* parameters) {
    for (int i = 0; i < tuple->list_of_faces->size; ++i) {
        int type = define_face_connection_type(tuple->list_of_faces->faces[i].number_of_vertices);

        glColor3f(parameters->color_r, parameters->color_g, parameters->color_b);
        glPolygonMode(parameters->face_mode, parameters->connection_mode);
        
        glBindTexture(GL_TEXTURE_2D, texture_id);
        
        glBegin(type);

        draw_vertices_of_face(&(tuple->list_of_faces->faces[i]));

        glEnd();
    }
}

void draw_vertices_of_face(const Face* face) {
    for (int j = 0; j < face->number_of_vertices; ++j) {
        Texture texture;
        if (face->number_of_textures != 0) {
            texture = face->textures[j];
            glTexCoord2f(texture.u, texture.v);
        }
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
    string += 2;

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

    Face face;

    define_face_parameters(&string, &face);

    int* vertices_indexes = face.tuple_of_face_indexes->vertices_indexes;
    int* textures_indexes = face.tuple_of_face_indexes->textures_indexes;
    int* normals_indexes = face.tuple_of_face_indexes->normals_indexes;

    for (int i = 0; i < face.number_of_vertices; ++i) {
        face.vertices[i] = tuple->list_of_vertices->vertices[vertices_indexes[i]];
    }

    for (int i = 0; i < face.number_of_textures; ++i) {
        face.textures[i] = tuple->list_of_textures->textures[textures_indexes[i]];
    }

    for (int i = 0; i < face.number_of_normals; ++i) {
        face.normals[i] = tuple->list_of_normals->normals[normals_indexes[i]];
    }
    
    add_in_list_of_faces(tuple->list_of_faces, &face);
}

void define_face_parameters(char** string, Face* face) {

    bool has_textures = string_has_textures(*string);
    bool has_normals = string_has_normals(*string);

    face->number_of_vertices = number_of_slashes(*string) / 2;
    face->number_of_textures = has_textures ? face->number_of_vertices : 0;
    face->number_of_normals = has_normals ? face->number_of_vertices : 0;

    face->vertices = (Vertex*)malloc(face->number_of_vertices * sizeof(Vertex));
    face->textures = (Texture*)malloc(face->number_of_textures * sizeof(Texture));
    face->normals = (Normal*)malloc(face->number_of_normals * sizeof(Normal));

    face->tuple_of_face_indexes = (TupleOfFaceIndexes*)malloc(sizeof(TupleOfFaceIndexes));
    
    face->tuple_of_face_indexes->vertices_indexes = 
        (int*)malloc(face->number_of_vertices * sizeof(int));

    if (has_textures) {
        face->tuple_of_face_indexes->textures_indexes = 
            (int*)malloc(face->number_of_textures * sizeof(int));
    }

    if (has_normals) {
        face->tuple_of_face_indexes->normals_indexes = 
            (int*)malloc(face->number_of_normals * sizeof(int));
    }

    for (int i = 0; i < face->number_of_vertices; ++i) {
        ++(*string);

        face->tuple_of_face_indexes->vertices_indexes[i] = parse_int_number(string) - 1;

        if (!has_textures && !has_normals) {
            while (**string != ' ' && **string != '\n') {
                ++(*string);
            }
            continue;
        }

        ++(*string);
        if (has_textures) {
            face->tuple_of_face_indexes->textures_indexes[i] = parse_int_number(string) - 1;
        }

        ++(*string);
        if (has_normals) {
            face->tuple_of_face_indexes->normals_indexes[i] = parse_int_number(string) - 1;
        }
    }
}

bool string_has_textures(char* string) {
    while (*(string++) != '/');
    return *string != '/';
}

bool string_has_normals(char* string) {
    for (int i = 0; i < 2; ++i) {
        while (*(string++) != '/');
    }
    return *string != ' ';
}

void parse_normal_string(char* string, ObjParametersTuple* tuple) {
    string += 2;

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

void load_texture() {
    int height, width, channels;
    unsigned char* image = stbi_load(
        "/home/artem/programming/c/lab3/resources/cottage_textures/cottage_diffuse.png",
        &width,
        &height,
        &channels,
        0
    );

    if (!image) {
        printf("Failed to load the texture\n");
        return;
    }

    glGenTextures(1, &texture_id);
    //glBindTexture(GL_TEXTURE_2D, textureID);

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Upload the image data to the texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    //glGenerateMipmap(GL_TEXTURE_2D);

    // Free the image data
    stbi_image_free(image);
}