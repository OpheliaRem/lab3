#include "PackedVertex.h"
#include <stdlib.h>

PackedVertex* unpack_data(ListOfFaces* list) {

    int number_of_vertices = 0;

    for (int i = 0; i < list->size; ++i) {
        number_of_vertices += list->faces[i].number_of_vertices;
    }

    PackedVertex* packed_vertices = 
        (PackedVertex*)malloc(number_of_vertices * sizeof(PackedVertex));

    for (int i = 0; i < list->size; ++i) {

        for (int j = 0; j < list->faces[i].number_of_vertices; ++j) {
            int n = list->faces[i].number_of_vertices;

            packed_vertices[i * n + j].x = list->faces[i].vertices[j].x;
            packed_vertices[i * n + j].y = list->faces[i].vertices[j].y;
            packed_vertices[i * n + j].z = list->faces[i].vertices[j].z;
        }

        for (int j = 0; j < list->faces[i].number_of_textures; ++j) {
            int n = list->faces[i].number_of_textures;

            packed_vertices[i * n + j].u = list->faces[i].textures[j].u;
            packed_vertices[i * n + j].v = list->faces[i].textures[j].v;
        }

        for (int j = 0; j < list->faces[i].number_of_normals; ++j) {
            int n = list->faces[i].number_of_normals;

            packed_vertices[i * n + j].nx = list->faces[i].normals[j].x;
            packed_vertices[i * n + j].ny = list->faces[i].normals[j].y;
            packed_vertices[i * n + j].nz = list->faces[i].normals[j].z;
        }
    }

    return packed_vertices;
}