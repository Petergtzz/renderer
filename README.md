## 3D Software Renderer

This software renderer is written from scratch in C11 with SDL2 as the only dependency. All illustrations are my own. 

## Journey

### Allocating color buffer

![Memory drawio](https://github.com/Petergtzz/renderer/assets/100330366/77319174-5ba0-4eb2-b638-f588696af303)

Rendering an object to a sceen requires individual pixels to light up. So, by allocating space in memory for a color buffer we can color individual pixels. It is important to mention that the color buffer array is not a matrix of n x m, instead, is a contiguous array in memory. 

### Perspective projection

Perspective projection is similar to how humans perceive the real world. In this type of projection, vertices that are close to us appear bigger and things that are far away appear smaller.

<img width="1280" alt="Screenshot 2024-07-03 at 1 02 32 p m" src="https://github.com/Petergtzz/renderer/assets/100330366/02de5923-02e3-4ab6-809c-5f004f9e0d4e">

![Side drawio](https://github.com/Petergtzz/renderer/assets/100330366/5f2ffc65-5f0a-4155-a9b5-0e866af0b2f0)

* Because we are working in a 2D plane (the screen), we must apply a transformation to each individual pixel; each with their corresponding [x, y, z] values. This transformation comes by applying a property, i.e triangles that have the same shape, but one is a scaled version of the other, share a side ratio.

$\frac{BC}{DE} = \frac{AB}{AD}$

$\frac{y'}{y} = \frac{1}{z}$

$y' = \frac{y}{z}$

## Screenshots and videos

Static 9*9*9 cube made of individual pixels

<img width="2560" alt="Screenshot 2024-06-19 at 1 54 12 p m" src="https://github.com/Petergtzz/renderer/assets/100330366/6cea3484-2850-46e8-9113-f6596571e8d5">

Same, but rotating cube

![Screen Recording 2024-06-23 at 12 46 15 p m](https://github.com/Petergtzz/renderer/assets/100330366/c6b1ed88-2057-4f77-8ec7-bbf8eb049388)

Cube made of vertices and triangular faces

![Screen Recording 2024-07-02 at 11 16 02 a m](https://github.com/Petergtzz/renderer/assets/100330366/c8b1869d-ec57-4f50-a40f-e9277a98c745)

F22 raptor loaded as OBJ file

![Screen Recording 2024-07-03 at 12 24 04 p m](https://github.com/Petergtzz/renderer/assets/100330366/fa2ed3c4-6457-4e63-8dd1-777fa427bd3a)
