#pragma once
#include "../wolf/wolf.h"
#include "../samplefw/Sample.h"
#include <vector>
#include <stdlib.h>
#include <ctime>

class Building
{
    public:
    void createBuilding(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength, GLfloat heightLength);
    void initialize();
    void update(float dt);
    void render(int width, int height, glm::mat4 view, glm::vec3 lightDir);
    void setScale(int sX, int sY, int sZ);

    Building(GLfloat x, GLfloat y, GLfloat z);
    ~Building();

    int arrayIndex;
    const GLfloat buildingTypeHeights[6];
    const GLfloat buildingTypeWidths[6];
    const std::string buildingTextures[6];

    struct Vertex
    {
        GLfloat x, y, z; //Position
        GLfloat u, v; //Texture Coords
        GLfloat nX, nY, nZ; //Normal
    };
    

    private:
    wolf::Program* shaderProgram;
    wolf::VertexBuffer* bVBO;
    wolf::VertexDeclaration* bVAO;
    wolf::Texture* textureStuff; 
    float m_time;
    std::vector <Vertex> vertices;

    //Building Details
    GLfloat centerX, centerY, centerZ;
    GLfloat buildingHeight, buildingWidth; 
    

};