#include "main.h"

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "array.h"
#include "display.h"
#include "triangle.h"
#include "vector.h"
#include "mesh.h"

#include "array.c"
#include "display.c"
#include "vector.c"
#include "mesh.c"

// Field of view
#define FOV 1024

// #define NPOINTS (9*9*9)

bool Running = false;

vec3_t CameraPosition = {.x = 0, .y = 0, .z = 5};
//vec3_t Cube3D[NPOINTS];
//vec2_t Cube2D[NPOINTS];
//vec3_t CubeRotation = {.x = 0, .y = 0, .z = 0};

triangle_t *TrianglesToRender = NULL;

static void OSX_ProcessInput(SDL_Window *Window)
{
    SDL_Event Event;
    SDL_PollEvent(&Event);

    switch (Event.type)
    {
        case SDL_QUIT:
        {
            Running = false;
        } break;

        case SDL_WINDOWEVENT:
        {
            switch (Event.window.event)
            {
                case SDL_WINDOWEVENT_SIZE_CHANGED:
                {
                    // TODO(pedro)
                    //SDL_GetWindowSize(Window, &Width, &Height);
                } break;
            }
        } break;

        default:
        {
            // TODO(pedro)
        }
    }
}

static void OSX_Setup(SDL_Renderer *Renderer)
{
    // Allocate memory for each 4 byte pixel; spanning the whole display area
    u32 PixelSize = 4;
    ColorBuffer = (u32*) malloc(PixelSize * WindowWidth * WindowHeight);

    ColorTexture = SDL_CreateTexture(
        Renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        WindowWidth,
        WindowHeight);

    //LoadCubeData();
    LoadObjFile("assets/cube.obj");

    /*
        Fill the x, y, and z coordinates for each pixel in the Cube array.

        Each side has a size of 2, i.e ranging from -1 to 1 and by using a step of 0.25, we create a 9 * 9 * 9 cube.
    */

    /*
    int PointCounter = 0;

    for (float x = -1; x <= 1; x+=.25)
    {
        for (float y = -1; y <= 1; y+=.25)
        {
            for (float z = -1; z <= 1; z+=.25)
            {
                vec3_t NewPoint = {.x = x, .y = y, .z = z};
                Cube3D[PointCounter++] = NewPoint;
            }
        }
    }
    */
}

vec2_t OSX_OrthographicProjection(vec3_t Point)
{
    /*
        Orthogrpahic projection is a 2D perspective of the object. To display the object, the z value is discarded as there is no depth in a 2D plane.

        To give the illusion that depth exists, we must divide x and y by z. This division moves x and y by some offset and gives a depth illusion.

        Multiplying by a field of view scales each pixel, i.e the points closer to the eye seem bigger than those farthest.
    */
    vec2_t ProjectedPoint = {
        .x = (FOV * Point.x) / Point.z,
        .y = (FOV * Point.y) / Point.z
    };

    return ProjectedPoint;
}

static void OSX_Update()
{
    // Initialize the array of triangles to render each frame
    TrianglesToRender = NULL;

    Mesh.Rotation.x += 0.003;
    //Mesh.Rotation.y += 0.003;
    //Mesh.Rotation.z += 0.003;

    int NumFaces = array_length(Mesh.Faces);
    for (int i = 0; i < NumFaces; i++)
    {
        face_t MeshFace = Mesh.Faces[i];

        vec3_t FaceVertex[3];
        FaceVertex[0] = Mesh.Vertices[MeshFace.a - 1];
        FaceVertex[1] = Mesh.Vertices[MeshFace.b - 1];
        FaceVertex[2] = Mesh.Vertices[MeshFace.c - 1];

        triangle_t ProjectedTriangle;

        for (int j = 0; j < 3; j++)
        {
            vec3_t TransformedVertex = FaceVertex[j];

            TransformedVertex = Vec3RotateX(TransformedVertex, Mesh.Rotation.x);
            TransformedVertex = Vec3RotateY(TransformedVertex, Mesh.Rotation.y);
            TransformedVertex = Vec3RotateZ(TransformedVertex, Mesh.Rotation.z);

            // Translate vertex away from camera
            TransformedVertex.z -= CameraPosition.z;

            // Project the current vertex
            vec2_t ProjectedVertex = OSX_OrthographicProjection(TransformedVertex);

            // Scale and project points to middle of the screen
            ProjectedVertex.x += (WindowWidth / 2.0);
            ProjectedVertex.y += (WindowHeight / 2.0);

            ProjectedTriangle.Points[j] = ProjectedVertex;
        }
        // Save the projected triangle in the array of triangles to render
        array_push(TrianglesToRender, ProjectedTriangle);
    }
    /*
    for (int i = 0; i < NPOINTS; i++)
    {
        vec3_t Point = Cube3D[i];

        vec3_t TransformedPoint = Vec3RotateX(Point, CubeRotation.x);
        TransformedPoint = Vec3RotateY(TransformedPoint, CubeRotation.y);
        TransformedPoint = Vec3RotateZ(TransformedPoint, CubeRotation.x);

        // Move points away from camera
        TransformedPoint.z -= CameraPosition.z;

        // Project the current point
        vec2_t ProjectedPoint = OSX_OrthographicProjection(TransformedPoint);

        // Store projected points in an array
        Cube2D[i] = ProjectedPoint;
    }
    */
}

static void OSX_Render(SDL_Renderer *Renderer)
{
    OSX_DrawGrid();

    int NumTriangles = array_length(TrianglesToRender);
    for (int i = 0; i < NumTriangles; i++)
    {
        triangle_t Triangle = TrianglesToRender[i];

        // Draw vertices
        OSX_DrawRectangle(
            Triangle.Points[0].x, Triangle.Points[0].y, 5, 5, 0xFFFFFF00);
        OSX_DrawRectangle(
            Triangle.Points[1].x, Triangle.Points[1].y, 5, 5, 0xFFFFFF00);
        OSX_DrawRectangle(
            Triangle.Points[2].x, Triangle.Points[2].y, 5, 5, 0xFFFFFF00);

        // Draw triangle
        OSX_DrawTriangle(
            Triangle.Points[0].x,
            Triangle.Points[0].y,
            Triangle.Points[1].x,
            Triangle.Points[1].y,
            Triangle.Points[2].x,
            Triangle.Points[2].y,
            0xFFFFFF00);
    }

        /* Mapping x and y on the screen start from the upper left corner (0, 0), so  to visualize each pixel we must position them in the middle of the screen by adding a certain amount.

        OSX_DrawRectangle(
            ProjectedPoint.x + WindowWidth / 2.0,
            ProjectedPoint.y + WindowHeight / 2.0,
            5,
            5,
            0xFFFFFF00);
        */

    array_free(TrianglesToRender);

    OSX_RenderColorBuffer(Renderer);
    OSX_ClearColorBuffer(0x00000000);
    SDL_RenderPresent(Renderer);
}

int main(int ArgCount, char **Args)
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "Error initializing SDL.\n");
    }

    SDL_DisplayMode DisplayArea;
    SDL_GetCurrentDisplayMode(0, &DisplayArea);

    WindowWidth = DisplayArea.w;
    WindowHeight = DisplayArea.h;

    SDL_Window *Window = SDL_CreateWindow(
        "3D Renderer",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WindowWidth,
        WindowHeight,
        SDL_WINDOW_BORDERLESS);

    if(Window)
    {
        SDL_Renderer *Renderer = SDL_CreateRenderer(Window, -1, 0);

        if(Renderer)
        {
            OSX_Setup(Renderer);

            Running = true;
            while(Running)
            {
                OSX_ProcessInput(Window);
                OSX_Update();
                OSX_Render(Renderer);
            }

            free(ColorBuffer);

        }
        else
        {
            fprintf(stderr, "Error creating SDL renderer.\n");
        }
    }
    else
    {
        fprintf(stderr, "Error creating SDL window.\n");
    }

    return 0;
}
