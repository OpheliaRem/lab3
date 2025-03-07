#include "ListOfFaces.h"
#include <stdlib.h>

Face* make_copy_of_faces(ListOfFaces* list) {
    Face* faces = (Face*)malloc(list->capacity * sizeof(Face));
    for (int i = 0; i < list->size; ++i) {
        faces[i] = list->faces[i];
    }
    return faces;
}

ListOfFaces create_list_of_faces(const int capacity) {
    ListOfFaces list;
    list.capacity = capacity;
    list.size = 0;
    list.faces = (Face*)malloc(list.capacity * sizeof(Face));
    return list;
}

void add_in_list_of_faces(ListOfFaces* list, const Face* face) {
    list->faces[list->size++] = *face;

    if (list->size == list->capacity) {
        list->capacity *= 2;

        Face* faces = make_copy_of_faces(list);

        free(list->faces);
        list->faces = faces;
    }
}

void free_list_of_faces(ListOfFaces* list) {
    if (list->faces == NULL) {
        return;
    }

    if (list->faces->tuple_of_face_indexes != NULL) {

        if (list->faces->tuple_of_face_indexes->normals_indexes != NULL) {
            free(list->faces->tuple_of_face_indexes->normals_indexes);
            list->faces->tuple_of_face_indexes->normals_indexes = NULL;
        }

        if (list->faces->tuple_of_face_indexes->textures_indexes != NULL) {
            free(list->faces->tuple_of_face_indexes->textures_indexes);
            list->faces->tuple_of_face_indexes->textures_indexes = NULL;
        }

        if (list->faces->tuple_of_face_indexes->vertices_indexes != NULL) {
            free(list->faces->tuple_of_face_indexes->vertices_indexes);
            list->faces->tuple_of_face_indexes->vertices_indexes = NULL;
        }

        free(list->faces->tuple_of_face_indexes);
        list->faces->tuple_of_face_indexes = NULL;
    }

    for (int i = 0; i < list->size; ++i) {
        if (list->faces[i].vertices != NULL) {
            free(list->faces[i].vertices);
            list->faces[i].vertices = NULL;
        }

        if (list->faces[i].textures != NULL) {
            free(list->faces[i].textures);
            list->faces[i].textures = NULL;
        }

        if (list->faces[i].normals != NULL) {
            free(list->faces[i].normals);
            list->faces[i].normals = NULL;
        }
    }
    
    free(list->faces);
    list->faces = NULL;
}