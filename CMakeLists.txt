cmake_minimum_required(VERSION 3.10)
project(ComputerGraphicsDemo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)

# Add source files
set(SOURCES
    src/main.cpp
    src/window.cpp
    src/shader.cpp
    src/cube.cpp
    src/sphere.cpp
    src/camera.cpp
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME}
    OpenGL::OpenGL
    glfw
    GLEW::GLEW
    glm::glm
)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
