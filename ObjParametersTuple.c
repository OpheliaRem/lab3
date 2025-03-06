#include "ObjParametersTuple.h"
#include <stdlib.h>

ObjParametersTuple create_obj_parameters_tuple() {
    ObjParametersTuple tuple;

    tuple.list_of_vertices = (ListOfVertices*)malloc(sizeof(ListOfVertices));
    tuple.list_of_textures = (ListOfTextures*)malloc(sizeof(ListOfTextures));
    tuple.list_of_faces = (ListOfFaces*)malloc(sizeof(ListOfFaces));
    tuple.list_of_normals = (ListOfNormals*)malloc(sizeof(ListOfNormals));

    *(tuple.list_of_vertices) = create_list_of_vertices(100);
    *(tuple.list_of_textures) = create_list_of_textures(100);
    *(tuple.list_of_faces) = create_list_of_faces(100);
    *(tuple.list_of_normals) = create_list_of_normals(100);

    return tuple;
}

void free_obj_parameters_tuple(ObjParametersTuple* tuple) {
    free(tuple->list_of_vertices->vertices);
    free(tuple->list_of_textures->textures);
    free(tuple->list_of_faces->faces);
    free(tuple->list_of_normals->normals);

    free(tuple->list_of_vertices);
    free(tuple->list_of_textures);
    free(tuple->list_of_faces);
    free(tuple->list_of_normals);
}