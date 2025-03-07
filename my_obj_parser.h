#ifndef MYOBJPARSER
#define MYOBJPARSER

#include <stdbool.h>
#include <stdio.h>
#include <GL/gl.h>
#include "ObjParametersTuple.h"

enum InputStringType {
    VERTEX,
    TEXTURE,
    FACE,
    NORMAL
};

enum InputStringType define_string_type(char* string);

bool file_is_present(const char* filename);
bool file_is_obj(char* filename);

void handle_file(FILE* file);

void read_file(FILE* file, ObjParametersTuple* set_of_obj_elements);

int define_face_connection_type(int number_of_vertices_in_face);

void draw_model(ObjParametersTuple* set_of_obj_elements);

void draw_vertices_of_face(const Face* face);

void parse_string(char* string, ObjParametersTuple* set_of_obj_elements);

void parse_vertex_string(char* string, ObjParametersTuple* set_of_obj_elements);
void parse_texture_string(char* string, ObjParametersTuple* set_of_obj_elements);
void parse_face_string(char* string, ObjParametersTuple* set_of_obj_elements);
void parse_normal_string(char* string, ObjParametersTuple* set_of_obj_elements);

void define_face_parameters(char** string, Face* face);

bool string_has_textures(char* string);
bool string_has_normals(char* string);

int number_of_slashes(char* string);

float parse_float_number(char** string);
int parse_int_number(char** string);

void read_number_from_string(char** string_to_read, char* buffer_to_write);

bool isNumberFinished(const char* string_to_read);

Vertex create_vertex_with_coordinates(GLfloat* coordinates);
Texture create_texture_with_parameters(GLfloat* parameters);
Normal create_normal_with_coordinates(GLfloat* coordinates);

void draw_3d_scene_from_file(char* filename);

#endif