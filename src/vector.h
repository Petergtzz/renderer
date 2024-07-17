#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    float x, y;
} vec2_t;

typedef struct {
    float x, y, z;
} vec3_t;

float Vec2Length(vec2_t v);
vec2_t Vec2Add(vec2_t a, vec2_t b);
vec2_t Vec2Sub(vec2_t a, vec2_t b);
vec2_t Vec2Mul(vec2_t v, float factor);
vec2_t Vec2Div(vec2_t v, float factor);

float Vec3Length(vec3_t v);
vec3_t Vec3Add(vec3_t a, vec3_t b);
vec3_t Vec3Sub(vec3_t a, vec3_t b);
vec3_t Vec3Mul(vec3_t v, float factor);
vec3_t Vec3Div(vec3_t v, float factor);
vec3_t Vec3Cross(vec3_t a, vec3_t b);

vec3_t Vec3RotateX(vec3_t v, float angle);
vec3_t Vec3RotateY(vec3_t v, float angle);
vec3_t Vec3RotateZ(vec3_t v, float angle);

#endif
