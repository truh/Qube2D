# Qube2D - 2D Game Engine

## Instructions - Linux

### Dependencies

| Dependency | NixOs Package    |
| ---------- | ---------------- |
| gcc        | gcc              |
| qmake      | qt5.full         |
| FreeType2  | freetype         |
| GL         | mesa             |
| GLFW       | glfw             |
| glm        | glm              |
| X11        | xorg.libX11      |
| Xi         | xorg.libXi       |
| Xrandr     | xorg.libXrandr   |
| Xxf86vm    | xorg.libXxf86vm  |
| Xinerama   | xorg.libXinerama |
| Xcursor    | xorg.libXcursor  |

#### Ubuntu



#### NixOS

    nix-shell --pure -p gcc qt5.full mesa glfw xorg.libX11 xorg.libXi xorg.libXrandr xorg.libXxf86vm xorg.libXinerama xorg.libXcursor

### Build Instructions

    git clone https://github.com/glClear/Qube2D.git
    cd Qube2D/
    qmake Qube2D.pro
    make

### Building and testing examples

   cd examples/03_ScrollingBackground/
   gcc -std=c++11 main.cpp -I../../include/ -lQube2D -L../../release/linux/
   LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../../release/linux/ ./a.out

### Install into folder

    mkdir -p Qube2D-out/lib
    cp Qube2D/release/linux/* Qube2D-out/lib/
    cp -R Qube2D/include/ Qube2D-out/
