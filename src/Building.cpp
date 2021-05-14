#include "Building.h"

/*
Creates a Building simulation using Cuboids
Cuboids Origin is the Center of its Base/Bottom
*/
void Building::createBuilding(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength, GLfloat heightLength)
{

    buildingWidth = edgeLength;

    /*Since we are starting from the center, the Length should be halfed
    The edgeLength is the lenth of an edge/side in the cube
    */
    GLfloat halfEdgeLength = (GLfloat) (edgeLength * 0.5);

    //Building Specifications (Vertices)
    //Front Face
    vertices.push_back({centerPosX - halfEdgeLength, centerPosY + heightLength, centerPosZ + halfEdgeLength, 1, 0, 0, 0, 1}); //Top Left
    vertices.push_back({centerPosX + halfEdgeLength, centerPosY + heightLength, centerPosZ + halfEdgeLength, 0, 0, 0, 0, 1}); //Top Right
    vertices.push_back({centerPosX - halfEdgeLength, centerPosY, centerPosZ + halfEdgeLength, 1, 1, 0, 0, 1}); //Bottom Left
    vertices.push_back({centerPosX - halfEdgeLength, centerPosY, centerPosZ + halfEdgeLength, 1, 1, 0, 0, 1}); //Bottom Left
    vertices.push_back({centerPosX + halfEdgeLength, centerPosY, centerPosZ + halfEdgeLength, 0, 1, 0, 0, 1}); //Bottom Right
    vertices.push_back({centerPosX + halfEdgeLength, centerPosY + heightLength, centerPosZ + halfEdgeLength, 0, 0, 0, 0, 1}); //Top Right


    //Back Face
    vertices.push_back({centerPosX - halfEdgeLength, centerPosY + heightLength, centerPosZ - halfEdgeLength, 1, 0, 0, 0, -1}); //Top Left
    vertices.push_back({centerPosX + halfEdgeLength, centerPosY + heightLength, centerPosZ - halfEdgeLength, 0, 0, 0, 0, -1}); //Top Right
    vertices.push_back({centerPosX - halfEdgeLength, centerPosY, centerPosZ - halfEdgeLength, 1, 1, 0, 0, -1}); //Bottom Left
    vertices.push_back({centerPosX - halfEdgeLength, centerPosY, centerPosZ - halfEdgeLength, 1, 1, 0, 0, -1}); //Bottom Left
    vertices.push_back({centerPosX + halfEdgeLength, centerPosY, centerPosZ - halfEdgeLength, 0, 1, 0, 0, -1}); //Bottom Right
    vertices.push_back({centerPosX + halfEdgeLength, centerPosY + heightLength, centerPosZ - halfEdgeLength, 0, 0, 0, 0, -1}); //Top Right

    
    //Left Face
    vertices.push_back({centerPosX - halfEdgeLength, centerPosY + heightLength, centerPosZ - halfEdgeLength, 1, 0, -1, 0, 0}); //Top Left
    vertices.push_back({centerPosX - halfEdgeLength, centerPosY + heightLength, centerPosZ + halfEdgeLength, 0, 0, -1, 0, 0}); //Top Right
    vertices.push_back({centerPosX - halfEdgeLength, centerPosY, centerPosZ - halfEdgeLength, 1, 1, -1, 0, 0}); //Bottom Left
    vertices.push_back({centerPosX - halfEdgeLength, centerPosY, centerPosZ - halfEdgeLength, 1, 1, -1, 0, 0}); //Bottom Left
    vertices.push_back({centerPosX - halfEdgeLength, centerPosY, centerPosZ + halfEdgeLength, 0, 1, -1, 0, 0}); //Bottom Right
    vertices.push_back({centerPosX - halfEdgeLength, centerPosY + heightLength, centerPosZ + halfEdgeLength, 0, 0, -1, 0, 0}); //Top Right

    
    //Right Face
    vertices.push_back({centerPosX + halfEdgeLength, centerPosY + heightLength, centerPosZ + halfEdgeLength, 1, 0, 1, 0, 0}); //Top Left
    vertices.push_back({centerPosX + halfEdgeLength, centerPosY + heightLength, centerPosZ - halfEdgeLength, 0, 0, 1, 0, 0}); //Top Right
    vertices.push_back({centerPosX + halfEdgeLength, centerPosY, centerPosZ + halfEdgeLength, 1, 1, 1, 0, 0}); //Bottom Left
    vertices.push_back({centerPosX + halfEdgeLength, centerPosY, centerPosZ + halfEdgeLength, 1, 1, 1, 0, 0}); //Bottom Left
    vertices.push_back({centerPosX + halfEdgeLength, centerPosY, centerPosZ - halfEdgeLength, 0, 1, 1, 0, 0}); //Bottom Right
    vertices.push_back({centerPosX + halfEdgeLength, centerPosY + heightLength, centerPosZ - halfEdgeLength, 0, 0, 1, 0, 0}); //Top Right

    
    //Top Face
    vertices.push_back({centerPosX - halfEdgeLength, centerPosY + heightLength, centerPosZ - halfEdgeLength, 0, 0, 0, 1, 0}); //Top Left
    vertices.push_back({centerPosX + halfEdgeLength, centerPosY + heightLength, centerPosZ - halfEdgeLength, 0, 0, 0, 1, 0}); //Top Right
    vertices.push_back({centerPosX - halfEdgeLength, centerPosY + heightLength, centerPosZ + halfEdgeLength, 0, 0, 0, 1, 0}); //Bottom Left
    vertices.push_back({centerPosX - halfEdgeLength, centerPosY + heightLength, centerPosZ + halfEdgeLength, 0, 0, 0, 1, 0}); //Bottom Left
    vertices.push_back({centerPosX + halfEdgeLength, centerPosY + heightLength, centerPosZ + halfEdgeLength, 0, 0, 0, 1, 0}); //Bottom Right
    vertices.push_back({centerPosX + halfEdgeLength, centerPosY + heightLength, centerPosZ - halfEdgeLength, 0, 0, 0, 1, 0}); //Top Right
    
    //Bottom Face
    vertices.push_back({centerPosX - halfEdgeLength, centerPosY, centerPosZ - halfEdgeLength, 0, 0, 0, -1, 0}); //Top Left
    vertices.push_back({centerPosX + halfEdgeLength, centerPosY, centerPosZ - halfEdgeLength, 0, 0, 0, -1, 0}); //Top Right
    vertices.push_back({centerPosX - halfEdgeLength, centerPosY, centerPosZ + halfEdgeLength, 0, 0, 0, -1, 0}); //Bottom Left
    vertices.push_back({centerPosX - halfEdgeLength, centerPosY, centerPosZ + halfEdgeLength, 0, 0, 0, -1, 0}); //Bottom Left
    vertices.push_back({centerPosX + halfEdgeLength, centerPosY, centerPosZ + halfEdgeLength, 0, 0, 0, -1, 0}); //Bottom Right
    vertices.push_back({centerPosX + halfEdgeLength, centerPosY, centerPosZ - halfEdgeLength, 0, 0, 0, -1, 0}); //Top Right

}

void Building::update(float dt)
{
    //Nothing Fancy to Find Here
}

/*
Loads Shaders and Vertices
and Also Describes It (VertexAttrib)
Also loads building texture
*/
void Building::initialize()
{
    /*
    Decision Block helps randomize building creation
    */
    textureStuff = wolf::TextureManager::CreateTexture(buildingTextures[arrayIndex]);
    Building::buildingWidth = buildingTypeWidths[arrayIndex];
    Building::buildingHeight = buildingTypeHeights[arrayIndex];
    createBuilding(Building::centerX, Building::centerY, Building::centerZ, Building::buildingWidth, Building::buildingHeight);
        
    
    shaderProgram = wolf::ProgramManager::CreateProgram("data/Building.vsh", "data/BuildingPixel.fsh");
    
    bVBO = wolf::BufferManager::CreateVertexBuffer(vertices.data(), sizeof(Vertex) * vertices.size());    

    bVAO = new wolf::VertexDeclaration();
    bVAO->Begin();
    bVAO->AppendAttribute(wolf::AT_Position, 3, wolf::CT_Float);
    bVAO->AppendAttribute(wolf::AT_TexCoord1, 2, wolf::CT_Float);
    bVAO->AppendAttribute(wolf::AT_Normal, 3, wolf::CT_Float);
    bVAO->SetVertexBuffer(bVBO);
    bVAO->End();

    //Depth Test
    glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
}

/*
Draws the building
*/
void Building::render(int width, int height, glm::mat4 view, glm::vec3 lightDir)
{
    glm::mat4 mProj = glm::perspective(glm::radians(60.0f), (float)width / (float)height, 0.1f, 500000.0f);
    glm::mat4 mView = view;
    glm::mat4 mWorld = glm::mat4(1.0f);
    mWorld = glm::scale(mWorld, glm::vec3(7, 7, 7));

    glm::vec3 lightColor = glm::vec3(0.9f, 0.9f, 0.9f);
    glm::vec3 lightDirection = glm::normalize(lightDir);
    glm::vec3 ambientLight = glm::normalize(glm::vec3(0.1f, 0.1f, 0.1f));

    //Use Shader Program and Texture
    shaderProgram->Bind();
    textureStuff->Bind(0);

    // Bind Uniforms
    shaderProgram->SetUniform("projection", mProj);
    shaderProgram->SetUniform("view", mView);
    shaderProgram->SetUniform("world", mWorld);
    shaderProgram->SetUniform("tex", 0);
    shaderProgram->SetUniform("LightColor", lightColor);
    shaderProgram->SetUniform("LightDir", lightDirection);
    shaderProgram->SetUniform("AmbientLight", ambientLight);

    //Set Up Source Data
    bVAO->Bind();
    bVBO->Bind();

    glDrawArrays(GL_TRIANGLES, 0, vertices.size());
    
}

Building::Building(GLfloat x, GLfloat y, GLfloat z) :
    buildingTextures{
        "data/TextureFiles/MidRise.png", "data/TextureFiles/Apartments.png",
        "data/TextureFiles/SkyScraper.png", "data/TextureFiles/Shop.png",
        "data/TextureFiles/RundownBuilding.png", "data/TextureFiles/Classical.png"
    }, 

    buildingTypeHeights{100.0f, 50.0f, 200.0f, 70.0f, 60.0f, 100.0f}, 
    buildingTypeWidths{50.0f, 50.0f, 70.0f, 110.0f, 70.0f, 100.0f}
{

    /*
    Random number that helps determine the height, width
    and texture of building
    */
    arrayIndex = rand() % 6;

    Building::centerX = x;
    Building::centerY = y;
    Building::centerZ = z;

    initialize();
    
}

Building::~Building()
{
    wolf::ProgramManager::DestroyProgram(shaderProgram);
	wolf::BufferManager::DestroyBuffer(bVBO);
    delete bVAO;
    wolf::TextureManager::DestroyTexture(textureStuff);
}
