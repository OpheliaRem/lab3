#include "ListOfTextures.h"
#include <stdlib.h>

Texture* make_copy_of_textures(ListOfTextures* list) {
    Texture* textures = (Texture*)malloc(list->capacity * sizeof(Texture));
    for (int i = 0; i < list->size; ++i) {
        textures[i] = list->textures[i];
    }
    return textures;
}

ListOfTextures create_list_of_textures(const int capacity)
{
    ListOfTextures list;
    list.size = 0;
    list.capacity = capacity;
    list.textures = (Texture*)malloc(list.capacity * sizeof(Texture));
    return list;
}

void add_in_list_of_textures(ListOfTextures* list, const Texture* texture) {
    list->textures[list->size++] = *texture;

    if (list->size == list->capacity) {
        list->capacity *= 2;

        Texture* textures = make_copy_of_textures(list);

        free(list->textures);
        list->textures = textures;
    }
}

void free_list_of_textures(ListOfTextures* list) {
    free(list->textures);
}
