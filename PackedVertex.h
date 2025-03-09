#ifndef PACKED_VERTEX
#define PACKED_VERTEX

#include "lists/ListOfFaces.h"

typedef struct {
    float x, y, z;
    float u, v;
    float nx, ny, nz;
} PackedVertex;

PackedVertex* unpack_data(ListOfFaces* list);

#endif