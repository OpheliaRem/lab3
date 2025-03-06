#ifndef LISTOFTEXTURES
#define LISTOFTEXTURES

#include <GL/gl.h>

typedef struct {
    GLfloat u;
    GLfloat v;
} Texture;

typedef struct {
    Texture* textures;
    int capacity;
    int size;
} ListOfTextures;

Texture* make_copy_of_textures(ListOfTextures* list);

ListOfTextures create_list_of_textures(const int capacity);

void add_in_list_of_textures(ListOfTextures* list, const Texture* texture);

void free_list_of_textures(ListOfTextures* list);

#endif