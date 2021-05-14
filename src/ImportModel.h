#pragma once
#include "../wolf/wolf.h"
#include "../samplefw/Sample.h"
#include <vector>
#include <stdlib.h>
#include <ctime>

class Spaceship
{
    public:
    void createSpaceship(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ);
    void initialize();
    void update(float dt);
    void render(int width, int height, glm::mat4 view);
    Spaceship(GLfloat x, GLfloat y, GLfloat z);
    ~Spaceship();

    struct Vertex
    {
        GLfloat x, y, z; //Position
        //GLfloat u, v; //Texture Coords
    };
    

    private:
    wolf::Program* shaderProgram;
    wolf::VertexBuffer* bVBO;
    wolf::VertexDeclaration* bVAO;
    wolf::Texture* textureStuff; 
    float m_time;
    std::vector <Vertex> shipVertices;
 
    

};