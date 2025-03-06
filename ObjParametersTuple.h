#ifndef OBJPARAMETERSTUPLE
#define OBJPARAMETERSTUPLE

#include "lists/ListOfVertices.h"
#include "lists/ListOfTextures.h"
#include "lists/ListOfFaces.h"
#include "lists/ListOfNormals.h"

typedef struct {
    ListOfVertices* list_of_vertices;
    ListOfTextures* list_of_textures;
    ListOfFaces* list_of_faces;
    ListOfNormals* list_of_normals;
} ObjParametersTuple;

ObjParametersTuple create_obj_parameters_tuple();

void free_obj_parameters_tuple(ObjParametersTuple* tuple);

#endif