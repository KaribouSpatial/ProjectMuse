/////////////////////////////////////////////////////
/// 
/// 
/// 
/// 
/// 
/// 
/////////////////////////////////////////////////////

//Include My Code
#include "Camera.h"

//Include Other
#include <GL/glew.h>

//Defines
#define M_PI 3.14159265358979323846
#define M2_PI 3.14159265358979323846*2
#define ToDegree(x) x*180.0/M_PI

//Const

//Static Prototyping

//Prototypes

//Class Definition

//Constructor
Camera::Camera():
mPosition(-3, 3, 3),
mOrientation(1.0, -1.0, -1.0)
{
	mOrientation.normalize();
}

//Destructor
Camera::~Camera()
{
}

//R-only access

//R-W access

//Setters

//Function
void Camera::applyCamera() const
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
#if 0
	//Camera transformations in reverse order
	glRotated(ToDegree(mOrientation.getTheta()), 0, 1, 0);
	glRotated(ToDegree(mOrientation.getPhi()), 0, 0, 1);


	glTranslated(-mPosition[X], -mPosition[Y], -mPosition[Z]);
#else

	gluLookAt(mPosition[X], mPosition[Y], mPosition[Z],
			  mPosition[X] + mOrientation[X],
			  mPosition[Y] + mOrientation[Y],
			  mPosition[Z] + mOrientation[Z],
			  0, 1, 0);
#endif

	//glRotated(90, -1, 0, 0);
}
//Static Function

//Private Function

//Operator Overload