## 3D Software Renderer

This software renderer is written from scratch in C11 with SDL2 as the only dependency. All illustrations are my own. 

## Journey

### Allocating color buffer

![Memory drawio](https://github.com/Petergtzz/renderer/assets/100330366/77319174-5ba0-4eb2-b638-f588696af303)

* To color individual pixels in the color buffer, we must have two neseted loops; one going vertically (height) and horizontally (width). 

### 3D rotating cube

![Screen Recording 2024-06-23 at 12 46 15 p m](https://github.com/Petergtzz/renderer/assets/100330366/fa8b5db3-cc75-426b-ba56-4346a62ab6cd)

### 3D rotating cube with vertices, edges, and faces

![Screen Recording 2024-07-02 at 11 16 02 a m](https://github.com/Petergtzz/renderer/assets/100330366/a4d97ccd-e57d-4cdc-886b-c7afaf8d1994)




Steps:
1. Setup SDL window, renderer, and texture.
2. Implement logic to render something each frame. i.e setup, and loop; process input, update, and render until quit key is pressed. 
