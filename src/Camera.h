#pragma once
#include "../wolf/wolf.h"
#include "../samplefw/Sample.h"

class Camera{
    
    private:
    //Default Camera Starting Position
    glm::vec3 cameraPosition;

    glm::vec3 viewDirection; //Default Axis we are looking at
    const glm::vec3 UP;// = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec2 oldMousePosition;
    const GLfloat PAN_SPEED; //Determines how fast the camera rotates
    const GLfloat MOVE_SPEED = 15.0f; //Determines how fast camera moves


    public:
    Camera();
    ~Camera();

    void mouseUpdate(glm::vec2 newMousePosition);
    void moveForward();
    void moveBackward();
    void strafeLeft();
    void strafeRight();
    void moveUp();
    void moveDown();
    glm::vec3 returnCameraLocation();

    glm::mat4 generateViewMatrix();
};