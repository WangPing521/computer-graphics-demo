#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
    Camera(const glm::vec3& position);
    
    glm::mat4 getViewMatrix() const;
    glm::vec3 getPosition() const { return position; }
    void processMouseInput(const glm::vec2& mouseDelta);
    void setPosition(const glm::vec3& newPos) { position = newPos; }

private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    
    float yaw;
    float pitch;
    float sensitivity;
    
    void updateCameraVectors();
};

#endif // CAMERA_H
