#ifndef LISTOFNORMALS
#define LISTOFNORMALS

#include <GL/gl.h>

typedef struct {
    GLfloat x;
    GLfloat y;
    GLfloat z;
} Normal;

typedef struct {
    Normal* normals;
    int capacity;
    int size;
} ListOfNormals;

Normal* make_copy_of_normals(ListOfNormals* list);

ListOfNormals create_list_of_normals(const int capacity);

void add_in_list_of_normals(ListOfNormals* list, const Normal* normal);

void free_list_of_normals(ListOfNormals* list);

#endif