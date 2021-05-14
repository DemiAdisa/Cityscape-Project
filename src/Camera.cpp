#include "Camera.h"

Camera::Camera() : 
    viewDirection(0.0f, 0.0f, -1.0f), 
    UP(0.0f, 1.0f, 0.0f),
    PAN_SPEED{0.05f}, 
    MOVE_SPEED{100.0f}

{
    //Default Camera Starting Position
    cameraPosition = glm::vec3(500.0f,100.0f,1000.0f);

}

void Camera::mouseUpdate(glm::vec2 newMousePosition)
{
     glm::vec2 mouseDelta = newMousePosition - oldMousePosition;

    //Rotate Camera Left or Right
    viewDirection = glm::mat3(glm::rotate((-mouseDelta.x * PAN_SPEED), UP)) * viewDirection;

    //Rotate Camera Up or Down
    glm::vec3 toRotateAround = glm::cross(viewDirection, UP);
    viewDirection = glm::mat3(glm::rotate((-mouseDelta.y * PAN_SPEED), toRotateAround)) * viewDirection;


    oldMousePosition = newMousePosition;
}

void Camera::moveForward()
{
    cameraPosition += MOVE_SPEED * viewDirection;

}

void Camera::moveBackward()
{
    cameraPosition += -(MOVE_SPEED * viewDirection);
}

void Camera::strafeLeft()
{
    glm::vec3 strafeDirection = glm::cross(viewDirection, UP);
    cameraPosition += -(MOVE_SPEED * strafeDirection);

}

void Camera::strafeRight()
{
    glm::vec3 strafeDirection = glm::cross(viewDirection, UP);
    cameraPosition += MOVE_SPEED * strafeDirection;

}

void Camera::moveUp()
{
    cameraPosition += MOVE_SPEED * UP;
}


void Camera::moveDown()
{
    cameraPosition += -(MOVE_SPEED * UP);
}


glm::mat4 Camera::generateViewMatrix()
{
    return glm::lookAt(cameraPosition, (cameraPosition + viewDirection), UP);
}

glm::vec3 Camera::returnCameraLocation()
{
    return cameraPosition;
}

