#include "ListOfNormals.h"
#include <stdlib.h>

Normal* make_copy_of_normals(ListOfNormals* list) {
    Normal* normals = (Normal*)malloc(list->capacity * sizeof(Normal));
    for (int i = 0; i < list->size; ++i) {
        normals[i] = list->normals[i];
    }
    return normals;
}

ListOfNormals create_list_of_normals(const int capacity) {
    ListOfNormals list;
    list.size = 0;
    list.capacity = capacity;
    list.normals = (Normal*)malloc(list.capacity * sizeof(Normal));
    return list;
}

void add_in_list_of_normals(ListOfNormals* list, const Normal* normal) {
    list->normals[list->size++] = *normal;

    if (list->size == list->capacity) {
        list->capacity *= 2;

        Normal* normals = make_copy_of_normals(list);
        free(list->normals);
        list->normals = normals;
    }
}

void free_list_of_normals(ListOfNormals* list) {
    free(list->normals);
}