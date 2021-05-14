#pragma once
#include "../wolf/wolf.h"
#include "../samplefw/Sample.h"

class SkyBox{
    public:

    struct Vertex {
        GLfloat x, y, z;
    };

    void initialize();
    void update(float dt);
    void render(int width, int height, glm::mat4 view);
    void createSky();
    void setScale(GLfloat x, GLfloat y, GLfloat z);


    SkyBox(GLfloat x, GLfloat y, GLfloat z);
    ~SkyBox();

    private:
    wolf::Program* m_shaderProgram;
    wolf::VertexBuffer* m_bVBO;
    wolf::VertexDeclaration* m_bVAO;
    wolf::Texture* m_textureObj;

    const std::string skyBoxTextures[6];

    std::vector <Vertex> vertices;

    glm::vec3 scaleVector;   
    
};