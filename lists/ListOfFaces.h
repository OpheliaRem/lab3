#ifndef LISTOFFACES
#define LISTOFFACES

#include "ListOfVertices.h"

typedef struct {
    Vertex* vertices;
    int number_of_vertices;
} Face;

typedef struct {
    Face* faces;
    int capacity;
    int size;
} ListOfFaces;

Face* make_copy_of_faces(ListOfFaces* list);

ListOfFaces create_list_of_faces(const int capacity);

void add_in_list_of_faces(ListOfFaces* list, const Face* face);

void free_list_of_faces(ListOfFaces* list);

#endif