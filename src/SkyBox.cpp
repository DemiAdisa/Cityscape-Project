#include "SkyBox.h" 

void SkyBox::setScale(GLfloat x, GLfloat y, GLfloat z)
{
    

}

void SkyBox::createSky()
{
    //Front Face
    vertices.push_back({-100, 100, 100}); //Top Left
    vertices.push_back({100, 100, 100}); //Top Right
    vertices.push_back({-100, -100, 100}); //Bottom Left
    vertices.push_back({-100, -100, 100}); //Bottom Left
    vertices.push_back({100, -100, 100}); //Bottom Right
    vertices.push_back({100, 100, 100}); //Top Right
    

    
}

/*
    Constructor takes in x, y, z values to scale 
    and an integer called Face which will determine what
    skybox texture to use
*/
SkyBox::SkyBox(GLfloat x, GLfloat y, GLfloat z):
    skyBoxTextures{
        "data/skybox/top.png", "data/skybox/bottom.png",
        "data/skybox/left.png", "data/skybox/right.png",
        "data/skybox/front.png", "data/skybox/back.png"
    }
{

    createSky();
    initialize();
    setScale(x, y, z);
    
    
}

SkyBox::~SkyBox()
{
    wolf::ProgramManager::DestroyProgram(m_shaderProgram);
	wolf::BufferManager::DestroyBuffer(m_bVBO);
    delete m_bVAO;
    wolf::TextureManager::DestroyTexture(m_textureObj);
}

void SkyBox::initialize()
{
    
    //m_textureObj = wolf::TextureManager::CreateTexture("data/TextureFiles/Sky Paint1.png");
    //m_textureObj = wolf::TextureManager::CreateTexture(skyBoxTextures[faceNumber]);
    m_shaderProgram = wolf::ProgramManager::CreateProgram("data/Sky.vsh", "data/SkyPixel.fsh");
    
    m_bVBO = wolf::BufferManager::CreateVertexBuffer(vertices.data(), sizeof(Vertex) * vertices.size());    

    m_bVAO = new wolf::VertexDeclaration();
    m_bVAO->Begin();
    m_bVAO->AppendAttribute(wolf::AT_Position, 3, wolf::CT_Float);
    //m_bVAO->AppendAttribute(wolf::AT_TexCoord1, 2, wolf::CT_Float);
    m_bVAO->SetVertexBuffer(m_bVBO);
    m_bVAO->End();

}

void SkyBox::update(float dt)
{

}

void SkyBox::render(int width, int height, glm::mat4 view)
{

    //Depth Test
    glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
    glDisable(GL_CULL_FACE);

    glm::mat4 mProj = glm::perspective(glm::radians(60.0f), (float)width / (float)height, 0.1f, 500000000.0f);
    glm::mat4 mView = view;
    glm::mat4 mWorld = glm::mat4(1.0f);
    mWorld = glm::scale(mWorld, scaleVector);

    //Use Shader Program and Texture
    m_shaderProgram->Bind();
    m_textureObj->Bind(1);

    // Bind Uniforms
    m_shaderProgram->SetUniform("projection", mProj);
    m_shaderProgram->SetUniform("view", mView);
    m_shaderProgram->SetUniform("world", mWorld);

    //Set Up Source Data
    m_bVAO->Bind();
    m_bVBO->Bind();

    glDrawArrays(GL_TRIANGLES, 0, vertices.size());

}