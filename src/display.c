#include "display.h"
#include <stdint.h>
#include <stdlib.h>

int WindowWidth, WindowHeight;

u32 *ColorBuffer;
SDL_Texture *ColorTexture;

void OSX_DrawGrid()
{
    /*
        Color buffer is a contigous block of memory, each block corresponds to a 4 byte pixel (ARGB; one byte each). We need to fill each block with a specified color in each step for the entire length of the window width an height.

        Example:
        [WHITE] [] [] [] [] [] [] [] [] [] [WHITE] [] [] [] [] [] [] [] [] [] [WHITE] [] [] [] [] [] [] [] [] [] [WHITE] [] []...

    */
    for (int y = 0; y < WindowHeight; y+=10)
    {
        for (int x = 0; x < WindowWidth; x+=10)
        {
            ColorBuffer[(WindowWidth * y) + x] = 0xFFFFFFFF;
        }
    }
}

void OSX_DrawPixel(int x, int y, u32 Color)
{
    if (x >= 0 && x < WindowWidth && y >= 0 && y < WindowHeight)
    {
        ColorBuffer[(WindowWidth * y) + x] = Color;
    }
}

void OSX_DrawLine(int x0, int y0, int x1, int y1, u32 Color)
{
    int Delta_x = (x1 - x0);
    int Delta_y = (y1 - y0);

    int SideLength = (abs(Delta_x) >= abs(Delta_y)) ? abs(Delta_x) : abs(Delta_y);

    // Find how much to increment in both x and y for each step
    float Inc_x = Delta_x / (float)SideLength;
    float Inc_y = Delta_y / (float)SideLength;

    float Current_x = x0;
    float Current_y = y0;

    for(int i = 0; i <= SideLength; i++)
    {
        OSX_DrawPixel(round(Current_x), round(Current_y), Color);
        Current_x += Inc_x;
        Current_y += Inc_y;
    }
}

void OSX_DrawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, u32 Color)
{
    OSX_DrawLine(x0, y0, x1, y1, Color);
    OSX_DrawLine(x1, y1, x2, y2, Color);
    OSX_DrawLine(x2, y2, x0, y0, Color);
}

void OSX_DrawRectangle(int x, int y, int Width, int Height, u32 Color)
{
    for (int i = 0; i < Width; i++)
    {
        for (int j = 0; j < Height; j++)
        {
            int Current_x = x + i;
            int Current_y = y + j;
            OSX_DrawPixel(Current_x, Current_y, Color);
        }
    }
}

void OSX_RenderColorBuffer(SDL_Renderer *Renderer)
{
    SDL_UpdateTexture(
        ColorTexture,
        NULL,
        ColorBuffer,
        (int)(sizeof(u32) * WindowWidth));
    SDL_RenderCopy(
        Renderer,
        ColorTexture,
        NULL,
        NULL);
}

void OSX_ClearColorBuffer(u32 Color)
{
    for (int y = 0; y < WindowHeight; y++)
    {
        for (int x = 0; x < WindowWidth; x++)
        {
            ColorBuffer[(WindowWidth * y) + x] = Color;
        }
    }
}
