#include <stdio.h>
#include <string.h>
#include "mesh.h"
#include "triangle.h"
#include "vector.h"
#include "array.h"

#define FILE_BUFFER 100

mesh_t Mesh = {
    .Vertices = NULL,
    .Faces = NULL,
    .Rotation = {0, 0, 0}
};

vec3_t CubeMeshVertices[N_CUBE_MESHVERTICES] = {
    { .x = -1, .y = -1, .z = -1 },
    { .x = -1, .y =  1, .z = -1 },
    { .x =  1, .y =  1, .z = -1 },
    { .x =  1, .y = -1, .z = -1 },
    { .x =  1, .y =  1, .z =  1 },
    { .x =  1, .y = -1, .z =  1 },
    { .x = -1, .y =  1, .z =  1 },
    { .x = -1, .y = -1, .z =  1 }
};

face_t CubeMeshFaces[N_CUBE_MESHFACES] = {
    // front
    { .a = 1, .b = 2, .c = 3 },
    { .a = 1, .b = 3, .c = 4 },
    // top
    { .a = 2, .b = 7, .c = 5 },
    { .a = 2, .b = 5, .c = 3 },
    // right
    { .a = 4, .b = 3, .c = 5 },
    { .a = 4, .b = 5, .c = 6 },
    // left
    { .a = 8, .b = 7, .c = 2 },
    { .a = 8, .b = 2, .c = 1 },
    // bottom
    { .a = 6, .b = 8, .c = 1 },
    { .a = 6, .b = 1, .c = 4 },
    // back
    { .a = 6, .b = 5, .c = 7 },
    { .a = 6, .b = 7, .c = 8 }
};

void LoadCubeData()
{
    for(int i = 0; i < N_CUBE_MESHVERTICES; i++)
    {
        vec3_t CubeVertex = CubeMeshVertices[i];
        array_push(Mesh.Vertices, CubeVertex);
    }

    for(int i = 0; i < N_CUBE_MESHFACES; i++)
    {
        face_t CubeFace = CubeMeshFaces[i];
        array_push(Mesh.Faces, CubeFace);
    }
}

void LoadObjFile(char *FileName)
{
    FILE *File = fopen(FileName, "r");

    if(File)
    {
        char FileBuffer[FILE_BUFFER];

        while(fgets(FileBuffer, FILE_BUFFER, File))
        {
            // Vertex information
            if(strncmp(FileBuffer, "v ", 2) == 0)
            {
                vec3_t Vertex;
                sscanf(FileBuffer, "v %f %f %f", &Vertex.x, &Vertex.y, &Vertex.z);
                array_push(Mesh.Vertices, Vertex);
            }

            // Face information
            if(strncmp(FileBuffer, "f ", 2) == 0)
            {
                int VertexIndices[3];
                int TextureIndices[3];
                int NormalIndices[3];
                sscanf(FileBuffer,
                    "f %d/%d/%d %d/%d/%d %d/%d/%d",
                    &VertexIndices[0], &TextureIndices[0], &NormalIndices[0],
                    &VertexIndices[1], &TextureIndices[1], &NormalIndices[1],
                    &VertexIndices[2], &TextureIndices[2], &NormalIndices[2]);
                face_t Faces = {
                    .a = VertexIndices[0],
                    .b = VertexIndices[1],
                    .c = VertexIndices[2],
                };
                array_push(Mesh.Faces, Faces);
            }
        }
        fclose(File);
    }
    else
    {
        fprintf(stderr, "Error: Unable to open file\n");
    }
}
