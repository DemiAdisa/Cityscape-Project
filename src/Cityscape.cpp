#include "Cityscape.h"

GLfloat newX, newY, newZ;
int sizeX, sizeY;

/*
    Creates a grid metropolis 
    sizeX is the width of the Grid
    sizeY is the length of the Grid
*/
void Cityscape::createCity(int sizeX, int sizeY)
{
    newY = GRID_START_Y;

    
    //Initialize Grid
	for(int i = 0; i < sizeX; i++)
	{
        newX = GRID_START_X;
		for(int j = 0; j < sizeY; j++)
		{
            city.push_back(new Building(newX, newY, newZ));
            newX += SPACING;
		}

		newZ += SPACING;
	}

    //Reset the starting point of the city
    newX = GRID_START_X;
    newY = GRID_START_Y;
    newZ = GRID_START_Z;


}

void Cityscape::renderCity(int width, int height, glm::mat4 view, glm::vec3 lightDir)
{
    int totalGridSize = sizeX * sizeY;

    //Draw Calls for Every Building Created
	for(int i = 0; i < totalGridSize; i++)
	{
		city[i]->render(width, height, view, lightDir);
		
	}

    
}

/*
Default Constructor
I put this here in the event a grid size is not given
*/
Cityscape::Cityscape() :
    GRID_START_X{-100.0f},
    GRID_START_Y{-100.0f},
    GRID_START_Z{-100.0f},
    SPACING{130.0f}
{
    sizeX = 25;
    sizeY = 25;
    createCity(sizeX, sizeY);

}

/*
Constructor takes integers to size the Cityscape Grid
*/
Cityscape::Cityscape(int x, int y):
    GRID_START_X{-100.0f},
    GRID_START_Y{-100.0f},
    GRID_START_Z{-100.0f},
    SPACING{130.0f}
{
    //Nothing Fancy in Here
    sizeX = x;
    sizeY = y;
    createCity(x, y);
    
}

Cityscape::~Cityscape()
{
    //This was meant to delete the city vector but 
    //they self delete so i didnt bother

}



