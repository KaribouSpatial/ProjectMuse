/////////////////////////////////////////////////////
/// 
/// 
/// 
/// 
/// 
/// 
/////////////////////////////////////////////////////

//Include My Code
#include "Projection.h"

//Include Other
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

//Defines

//Const
const int INIT_WINDOW_WIDTH = 1280;
const int INIT_WINDOW_HEIGHT = 1024;
const int INIT_NEAR = 927;

//Static Prototyping

//Prototypes

//Class Definition

//Constructor
Projection::Projection():
mWindowSize(INIT_WINDOW_WIDTH, INIT_WINDOW_HEIGHT)
{
}

//Destructor
Projection::~Projection()
{
}

//R-only access
const vec2i& Projection::getWindowSize() const
{
	return mWindowSize;
}

//R-W access

//Setters

//Function
void Projection::applyProjection() const
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
#if 0
	glFrustum(
		-INIT_WINDOW_WIDTH / 2.0,
		INIT_WINDOW_WIDTH / 2.0,
		-INIT_WINDOW_HEIGHT / 2.0,
		INIT_WINDOW_HEIGHT / 2.0,
		INIT_NEAR,
		INIT_NEAR * 2.5);
#else
	gluPerspective(45, INIT_WINDOW_WIDTH / INIT_WINDOW_HEIGHT, 0.0001, 100);
#endif
}

void Projection::resize(int width, int height)
{
	glViewport(0, 0, width, height);

	mWindowSize[X] = width;
	mWindowSize[Y] = height;

	glutPostRedisplay();
}

//Static Function

//Private Function

//Operator Overload