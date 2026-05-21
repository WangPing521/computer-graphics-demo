#include "window.h"
#include <GL/glew.h>
#include <iostream>

Window* Window::instance = nullptr;

Window::Window(int width, int height, const std::string& title)
    : glfwWindow(nullptr), width(width), height(height), title(title),
      lastMousePos(0.0f), mouseDelta(0.0f) {
    instance = this;
}

Window::~Window() {
    cleanup();
}

bool Window::init() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return false;
    }

    // Set window hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 4); // MSAA 4x

    // Create window
    glfwWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!glfwWindow) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(glfwWindow);
    glfwSwapInterval(1); // Enable vsync

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return false;
    }

    // Set viewport
    glViewport(0, 0, width, height);

    // Set callbacks
    glfwSetCursorPosCallback(glfwWindow, mouseCallback);
    glfwSetScrollCallback(glfwWindow, scrollCallback);

    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
    return true;
}

void Window::cleanup() {
    if (glfwWindow) {
        glfwDestroyWindow(glfwWindow);
        glfwTerminate();
    }
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(glfwWindow);
}

void Window::swapBuffers() {
    glfwSwapBuffers(glfwWindow);
}

void Window::processInput() {
    if (glfwGetKey(glfwWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(glfwWindow, true);
    }
    mouseDelta = glm::vec2(0.0f);
}

void Window::setTitle(const std::string& newTitle) {
    if (glfwWindow) {
        glfwSetWindowTitle(glfwWindow, newTitle.c_str());
    }
}

bool Window::isKeyPressed(int key) const {
    return glfwGetKey(glfwWindow, key) == GLFW_PRESS;
}

void Window::mouseCallback(GLFWwindow* window, double xpos, double ypos) {
    if (instance) {
        instance->mouseDelta = glm::vec2(xpos - instance->lastMousePos.x,
                                        instance->lastMousePos.y - ypos);
        instance->lastMousePos = glm::vec2(xpos, ypos);
    }
}

void Window::scrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
    // Can be used for zoom functionality
}
