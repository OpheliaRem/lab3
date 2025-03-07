#ifndef LISTOFFACES
#define LISTOFFACES

#include "ListOfVertices.h"
#include "ListOfTextures.h"
#include "ListOfNormals.h"

typedef struct {
    int* vertices_indexes;
    int* textures_indexes;
    int* normals_indexes;
} TupleOfFaceIndexes;

typedef struct {
    TupleOfFaceIndexes* tuple_of_face_indexes;

    Vertex* vertices;
    int number_of_vertices;

    Texture* textures;
    int number_of_textures;
    
    Normal* normals;
    int number_of_normals;
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