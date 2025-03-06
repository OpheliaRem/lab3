#include <stdlib.h>
#include "ListOfVertices.h"

Vertex* make_copy_of_vertices(ListOfVertices* list) {
    Vertex* vertices = (Vertex*)malloc(list->capacity * sizeof(Vertex));
    for (int i = 0; i < list->size; ++i) {
        vertices[i] = list->vertices[i];
    }
    return vertices;
}


ListOfVertices create_list_of_vertices(const int capacity) {
    ListOfVertices list;
    list.size = 0;
    list.capacity = capacity;
    list.vertices = (Vertex*)malloc(list.capacity * sizeof(Vertex));
    return list;
}

void add_in_list_of_vertices(ListOfVertices *list, const Vertex *vertex)
{
    list->vertices[list->size++] = *vertex;

    if (list->size == list->capacity) {
        list->capacity *= 2;

        Vertex* vertices = make_copy_of_vertices(list);

        free(list->vertices);
        list->vertices = vertices;
    }
}

void free_list_of_vertices(ListOfVertices* list) {
    free(list->vertices);
}
