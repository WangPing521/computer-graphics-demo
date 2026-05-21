#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>

class Window {
public:
    Window(int width, int height, const std::string& title);
    ~Window();

    bool init();
    void cleanup();
    bool shouldClose() const;
    void swapBuffers();
    void processInput();
    void setTitle(const std::string& title);

    glm::vec2 getMouseDelta() const { return mouseDelta; }
    bool isKeyPressed(int key) const;
    int getWidth() const { return width; }
    int getHeight() const { return height; }

private:
    static void mouseCallback(GLFWwindow* window, double xpos, double ypos);
    static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);

    GLFWwindow* glfwWindow;
    int width, height;
    std::string title;
    glm::vec2 lastMousePos;
    glm::vec2 mouseDelta;
    static Window* instance;
};

#endif // WINDOW_H
