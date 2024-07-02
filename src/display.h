#ifndef DISPLAY_H
#define DISPLAY_H

#include "main.h"
#include <SDL2/SDL.h>

void OSX_DrawGrid();
void OSX_DrawPixel(int x, int y, u32 Color);
void OSX_DrawLine(int x0, int y0, int x1, int y1, u32 Color);
void OSX_DrawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, u32 Color);
void OSX_DrawRectangle(int x, int y, int Width, int Height, u32 Color);
void OSX_RenderColorBuffer(SDL_Renderer *Renderer);
void OSX_ClearColorBuffer(u32 Color);

#endif
