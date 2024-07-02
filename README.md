## 3D Software Renderer

This software renderer is written from scratch in C11 with SDL2 as the only dependency

## Journey

### Static 3D image of a cube

<img width="2560" alt="Screenshot 2024-06-19 at 1 54 12 p m" src="https://github.com/Petergtzz/renderer/assets/100330366/401767c5-0181-4a16-b004-0c42924e0b39">

Steps:
1. Setup SDL window, renderer, and texture.
2. Implement logic to render something each frame. i.e setup, and loop; process input, update, and render until quit key is pressed. 
-  Allocate a color buffer to store each pixel (4 bytes) across the corresponding display area (2260 * 1440).
-  Color buffer is a contiguous array in memory, so to display a grid one must loop over the width and height dimensions of the display and color each individual element in the color buffer array given a step.


3D rotating cube

![Screen Recording 2024-07-02 at 11 16 02 a m](https://github.com/Petergtzz/renderer/assets/100330366/a4d97ccd-e57d-4cdc-886b-c7afaf8d1994)


