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
    for (int i = 0; i < list->size; ++i) {
        free(list->faces[i].vertices);
    }
    free(list->faces);
}