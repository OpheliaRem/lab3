#ifndef LISTOFVERTICES
#define LISTOFVERTICES

#include <stdbool.h>
#include <stdio.h>
#include <GL/gl.h>

typedef struct {
    GLfloat x;
    GLfloat y;
    GLfloat z;
} Vertex;

typedef struct {
    Vertex* vertices;
    int capacity;
    int size;
} ListOfVertices;

Vertex* make_copy_of_vertices(ListOfVertices* list);

ListOfVertices create_list_of_vertices(const int capacity);

void add_in_list_of_vertices(ListOfVertices* list, const Vertex* vertex);

void free_list_of_vertices(ListOfVertices* list);

#endif