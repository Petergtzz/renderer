## 3D Software Renderer

This software renderer is written from scratch in C11 with SDL2 as the only dependency. All illustrations are my own. 

## Journey

### Allocating color buffer

![Memory drawio](https://github.com/Petergtzz/renderer/assets/100330366/77319174-5ba0-4eb2-b638-f588696af303)

* To color individual pixels in the color buffer, we must have two nested loops; one going vertically (height) and one going horizontally (width). e.g. to create a white dotted grid, color each pixel by indexing color_buffer[(Width * y) + x]; x colors pixels horizontally and to skip an entire row, we multiply by the width and y to go down vertically. 

### Perspective projection

Perspective projection is similar to how humans perceive the real world. In this type of projection, vertices that are close to us appear bigger and things that are far away appear smaller.

<img width="1280" alt="Screenshot 2024-07-03 at 1 02 32 p m" src="https://github.com/Petergtzz/renderer/assets/100330366/02de5923-02e3-4ab6-809c-5f004f9e0d4e">

* Because we are working in a 2D plane (the screen), we must apply a transformation to each individual pixel; all of them have their corresponding [x, y, z] values. This transformation comes by applying a property, i.e triangles that have the same shape, but one is a scaled version of the other, share a side ratio.

$BC/DE = AB/AD$  
