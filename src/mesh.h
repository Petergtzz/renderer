#ifndef MESH_H
#define MESH_H

#include "triangle.h"
#include "vector.h"

#define N_CUBE_MESHVERTICES 8
#define N_CUBE_MESHFACES 12

extern vec3_t CubeMeshVertices[N_CUBE_MESHVERTICES];
extern face_t CubeMeshFaces[N_CUBE_MESHFACES];

typedef struct
{
    vec3_t *Vertices;
    face_t *Faces;
    vec3_t Rotation;
} mesh_t;

extern void LoadCubeData();

extern void LoadObjFile(char *FileName);

#endif
