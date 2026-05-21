#ifndef CUBE_H
#define CUBE_H

#include <GL/glew.h>
#include <vector>

class Cube {
public:
    Cube();
    ~Cube();
    void draw();

private:
    GLuint VAO, VBO, EBO;
    GLuint indexCount;
    void setupMesh();
};

#endif // CUBE_H
