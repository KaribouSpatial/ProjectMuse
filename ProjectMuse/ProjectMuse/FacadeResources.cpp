

//Include My Code
#include "FacadeResources.h"

//Include Other
#include <GL\glew.h>
#include <GL\freeglut.h>

//Defines

//Const

//Static Prototyping

//Prototypes

//Class Definition

//Constructor
FacadeResources::FacadeResources()
{
}

//Destructor
FacadeResources::~FacadeResources()
{
}

//R-only access

//R-W access

//Setters

//Function
void FacadeResources::draw(Models model)
{
	switch(model)
	{
	case FacadeResources::Cube:
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glColor4d(0.922,0.484,0.712,1.0);
		glutSolidSphere(1.5, 36, 36);
		break;
	default:
		break;
	}
}

//Static Function

//Operator Overload