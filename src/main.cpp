#include "window.h"
#include "shader.h"
#include "cube.h"
#include "sphere.h"
#include "camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

int main() {
    // Initialize window
    Window window(1280, 720, "Computer Graphics Demo - Rotating Cube & Earth");
    if (!window.init()) {
        std::cerr << "Failed to initialize window" << std::endl;
        return -1;
    }

    // Initialize camera
    Camera camera(glm::vec3(0.0f, 2.0f, 5.0f));

    // Create shader program
    Shader shader("shaders/vertex.glsl", "shaders/fragment.glsl");

    // Create objects
    Cube cube;
    Sphere sphere(1.0f, 50, 50); // radius, sectors, stacks

    // Scene state
    int currentScene = 0; // 0 = Cube, 1 = Sphere
    float rotationSpeed = 50.0f; // degrees per second
    float cubeRotation = 0.0f;
    float sphereRotation = 0.0f;

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);

    // Main loop
    double lastTime = glfwGetTime();
    while (!window.shouldClose()) {
        double currentTime = glfwGetTime();
        float deltaTime = static_cast<float>(currentTime - lastTime);
        lastTime = currentTime;

        // Update rotation
        cubeRotation += rotationSpeed * deltaTime;
        sphereRotation += rotationSpeed * deltaTime * 0.5f; // Slower rotation for sphere

        // Wrap rotation
        if (cubeRotation > 360.0f) cubeRotation -= 360.0f;
        if (sphereRotation > 360.0f) sphereRotation -= 360.0f;

        // Handle input
        window.processInput();
        camera.processMouseInput(window.getMouseDelta());

        // Scene switching with number keys
        if (window.isKeyPressed(GLFW_KEY_1)) currentScene = 0;
        if (window.isKeyPressed(GLFW_KEY_2)) currentScene = 1;

        // Clear screen
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Use shader
        shader.use();

        // Set up matrices
        glm::mat4 projection = glm::perspective(glm::radians(45.0f),
                                               1280.0f / 720.0f, 0.1f, 100.0f);
        glm::mat4 view = camera.getViewMatrix();
        glm::mat4 model = glm::mat4(1.0f);

        // Set uniforms
        shader.setMat4("projection", projection);
        shader.setMat4("view", view);

        // Set lighting
        shader.setVec3("lightPos", glm::vec3(5.0f, 5.0f, 5.0f));
        shader.setVec3("viewPos", camera.getPosition());
        shader.setVec3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f));

        if (currentScene == 0) {
            // Draw rotating cube
            model = glm::rotate(glm::mat4(1.0f), glm::radians(cubeRotation),
                               glm::vec3(1.0f, 1.0f, 1.0f));
            shader.setMat4("model", model);
            shader.setVec3("objectColor", glm::vec3(0.2f, 0.7f, 1.0f));
            cube.draw();

            // Display info
            window.setTitle("Computer Graphics Demo - Rotating Cube (Press 2 for Earth)");
        } else {
            // Draw rotating sphere (Earth)
            model = glm::rotate(glm::mat4(1.0f), glm::radians(sphereRotation),
                               glm::vec3(0.0f, 1.0f, 0.0f));
            shader.setMat4("model", model);
            shader.setVec3("objectColor", glm::vec3(0.2f, 0.5f, 1.0f));
            sphere.draw();

            // Display info
            window.setTitle("Computer Graphics Demo - Rotating Earth (Press 1 for Cube)");
        }

        // Swap buffers and poll events
        window.swapBuffers();
        glfwPollEvents();
    }

    window.cleanup();
    return 0;
}
