#include <math.h>
#include "vector.h"
////////////////////////////////////////////////////////////////////////////////
// 2D functions
////////////////////////////////////////////////////////////////////////////////
float Vec2Length(vec2_t v)
{
    return sqrt(v.x * v.x + v.y * v.y);
}

vec2_t Vec2Add(vec2_t a, vec2_t b)
{
    vec2_t Result = {
        .x = a.x + b.x,
        .y = a.y + b.y
    };
    return Result;
}

vec2_t Vec2Sub(vec2_t a, vec2_t b)
{
    {
        vec2_t Result = {
            .x = a.x - b.x,
            .y = a.y - b.y
        };
        return Result;
    }
}

vec2_t Vec2Mul(vec2_t a, float factor)
{
    vec2_t Result = {
        .x = a.x * factor,
        .y = a.y * factor
    };
    return Result;
}
vec2_t Vec2Div(vec2_t a, float factor)
{
    vec2_t Result = {
        .x = a.x / factor,
        .y = a.y / factor
    };
    return Result;
}
////////////////////////////////////////////////////////////////////////////////
// 3D functions
////////////////////////////////////////////////////////////////////////////////
float Vec3Length(vec3_t v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

vec3_t Vec3Add(vec3_t a, vec3_t b)
{
    vec3_t Result = {
        .x = a.x + b.x,
        .y = a.y + b.y,
        .z = a.z + b.z
    };
    return Result;
}

vec3_t Vec3Sub(vec3_t a, vec3_t b)
{
    {
        vec3_t Result = {
            .x = a.x - b.x,
            .y = a.y - b.y,
            .z = a.z - b.z
        };
        return Result;
    }
}

vec3_t Vec3Mul(vec3_t a, float factor)
{
    {
        vec3_t Result = {
            .x = a.x * factor,
            .y = a.y * factor,
            .z = a.z * factor
        };
        return Result;
    }
}

vec3_t Vec3Div(vec3_t a, float factor)
{
    {
        vec3_t Result = {
            .x = a.x / factor,
            .y = a.y / factor,
            .z = a.z / factor
        };
        return Result;
    }
}

////////////////////////////////////////////////////////////////////////////////
// Rotation functions
////////////////////////////////////////////////////////////////////////////////
vec3_t Vec3RotateX(vec3_t v, float angle)
{
    vec3_t RotatedVector = {
        .x = v.x,
        .y = v.y * cos(angle) - v.z * sin(angle),
        .z = v.y * sin(angle) + v.z * cos(angle)
    };
    return RotatedVector;
}

vec3_t Vec3RotateY(vec3_t v, float angle)
{
    vec3_t RotatedVector = {
        .x = v.x * cos(angle) - v.z * sin(angle),
        .y = v.y,
        .z = v.x * sin(angle) + v.z * cos(angle)
    };
    return RotatedVector;
}

vec3_t Vec3RotateZ(vec3_t v, float angle)
{
    vec3_t RotatedVector = {
        .x = v.x * cos(angle) - v.y * sin(angle),
        .y = v.x * sin(angle) + v.y * cos(angle),
        .z = v.z
    };
    return RotatedVector;
}
