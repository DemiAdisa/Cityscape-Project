#pragma once 
#include "Building.h"

class Cityscape
{
    public:
    void createCity(int sizeX, int sizeY);
    void renderCity(int width, int height, glm::mat4 view, glm::vec3 lightDir);
    void setScaleValue(int x, int y, int z);

    Cityscape();
    Cityscape(int x, int y);
    ~Cityscape();

    std::vector <Building*> city;

    private:

    //Grid Details
    const GLfloat GRID_START_X;
    const GLfloat GRID_START_Y;
    const GLfloat GRID_START_Z;
    const GLfloat SPACING;

    

};



