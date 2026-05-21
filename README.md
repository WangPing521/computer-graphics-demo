# Computer Graphics Demo

A C++ + OpenGL project demonstrating 3D graphics with rotating cube and Earth visualization.

## Features

- **Rotating Cube**: A 3D cube rotating around multiple axes
- **Rotating Earth**: A sphere representing Earth with realistic rotation
- **Mouse Camera Control**: Orbit around objects with mouse movement
- **Lighting & Shading**: Phong lighting model with ambient, diffuse, and specular components
- **Scene Switching**: Press 1 for Cube, 2 for Earth
- **Anti-aliasing**: 4x MSAA enabled by default

## Requirements

- C++17 compatible compiler
- CMake 3.10 or higher
- OpenGL 3.3+
- GLFW3
- GLEW
- GLM

## Installation (Linux/Mac)

### Ubuntu/Debian
```bash
sudo apt-get install libglfw3-dev libglew-dev libglm-dev
```

### macOS (with Homebrew)
```bash
brew install glfw glew glm
```

### Fedora/RHEL
```bash
sudo dnf install glfw-devel glew-devel glm-devel
```

## Building

```bash
mkdir build
cd build
cmake ..
make
```

## Running

```bash
./ComputerGraphicsDemo
```

## Controls

- **Mouse**: Move to rotate camera around the object
- **1**: Switch to rotating cube
- **2**: Switch to rotating Earth (sphere)
- **ESC**: Exit application

## Project Structure

```
computer-graphics-demo/
├── src/
│   ├── main.cpp          # Main application entry point
│   ├── window.h/cpp      # GLFW window management
│   ├── shader.h/cpp      # Shader program compilation and management
│   ├── cube.h/cpp        # Cube geometry and rendering
│   ├── sphere.h/cpp      # Sphere geometry and rendering
│   └── camera.h/cpp      # Camera control and view matrix
├── shaders/
│   ├── vertex.glsl       # Vertex shader
│   └── fragment.glsl     # Fragment shader
├── CMakeLists.txt        # CMake configuration
└── README.md             # This file
```

## Graphics Pipeline

1. **Vertex Processing**: Vertices are transformed by model, view, and projection matrices
2. **Fragment Processing**: Phong lighting is calculated per fragment
3. **Output**: Final color combines ambient, diffuse, and specular components

## Lighting Model

The project uses Phong lighting with:
- **Ambient**: Constant environmental lighting
- **Diffuse**: Surface brightness based on normal and light direction
- **Specular**: Shiny highlights based on viewing angle

## Future Enhancements

- [ ] Texture mapping
- [ ] Normal mapping
- [ ] Shadow mapping
- [ ] Multiple objects in scene
- [ ] Animation playback
- [ ] Model loading (OBJ/GLTF)

## License

MIT License

## Author

WangPing521
