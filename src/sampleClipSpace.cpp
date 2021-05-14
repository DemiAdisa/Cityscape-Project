#include "sampleClipSpace.h"
#include "../samplefw/Grid2D.h"
#include "Building.h"
#include "Camera.h"
#include "SkyBox.h"
#include "Cityscape.h"

//Variables to help Lighting Animation
GLfloat m_currSunAngle = 0;
const GLfloat SUN_SPEED = 0.4f;
glm::vec3 lightDir;

//Grid Array and Camera Creation
Cityscape* city;
Camera* cameraStuff = new Camera();
//SkyBox* sky = new SkyBox(1, 2, 3);


SampleClipSpace::~SampleClipSpace()
{
	delete city;
	//delete sky;
	
}

void SampleClipSpace::init()
{
	srand(time(nullptr));
	
	//Initialize Grid
	city = new Cityscape(40, 40);
	
}

void SampleClipSpace::update(float dt) 
{
	//Lighting Animation
	m_currSunAngle += dt * SUN_SPEED;
	GLfloat sunX = 1000.0f * cos(m_currSunAngle);
	GLfloat sunY = 1000.0f * sin(m_currSunAngle);

	lightDir = glm::vec3(0.0f, 0.0f, 0.0f) - glm::vec3(sunX, sunY, 0.0f);

    //Regenerate Buildings
	if(m_pApp->isKeyDown('r'))
	{
		//delete whole cityscape
		delete city;

		//Re create buildings and replace the old ones with new ones		
		init();
	}	

    //Camera Stuff
	cameraStuff->mouseUpdate(m_pApp->getMousePos());
	if(m_pApp->isKeyDown('w'))
	{
		//Move camera forward
		cameraStuff->moveForward();
		
	}

	if(m_pApp->isKeyDown('a'))
	{
		//Move camera left
		cameraStuff->strafeLeft();

	}

	if(m_pApp->isKeyDown('s'))
	{
		//Move camera back
		cameraStuff->moveBackward();

	}

	if(m_pApp->isKeyDown('d'))
	{
		//Move camera right
		cameraStuff->strafeRight();

	}

	if(m_pApp->isKeyDown('q'))
	{
		//Move camera up
		cameraStuff->moveUp();

	}

	if(m_pApp->isKeyDown('e'))
	{
		//Move camera up
		cameraStuff->moveDown();

	}

}

void SampleClipSpace::render(int width, int height)
{
	
	glClearColor(0.3f, 0.3f, 0.3f, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//Generate View Matrix to Use 
	glm::mat4 view = cameraStuff->generateViewMatrix();
	
	//Draw City
	city->renderCity(width, height, view, lightDir);

	//sky->render(width, height, view);


}
