#ifndef FACE_H
#define FACE_H

#include "vector.h"

typedef struct {
    int a, b, c;
} face_t;

typedef struct {
    vec2_t Points[3];
} triangle_t;

#endif
