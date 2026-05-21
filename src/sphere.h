#ifndef SPHERE_H
#define SPHERE_H

#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>

class Sphere {
public:
    Sphere(float radius, int sectors, int stacks);
    ~Sphere();
    void draw();

private:
    GLuint VAO, VBO, EBO;
    GLuint indexCount;
    void setupMesh(float radius, int sectors, int stacks);
};

#endif // SPHERE_H
