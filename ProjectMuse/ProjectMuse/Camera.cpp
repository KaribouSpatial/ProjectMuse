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
mPosition(-10, 10, 10),
mTargetPoint(0,0,0),
mOrientation(90, 0, 0),
mRollEpsilon(M_PI/2.0)
{
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
	
	gluLookAt(mPosition[X], mPosition[Y], mPosition[Z],
			  mTargetPoint[X], mTargetPoint[Y], mTargetPoint[Z],
			  /*std::cos(mRollEpsilon)*/0, /*std::sin(mRollEpsilon)*/1, 0);

	glRotated(90, 1, 0, 0);
}

void Camera::rotateCamera(const vec2& coord)
{
#if 1
	mOrientation = mTargetPoint - mPosition;
#else
	mOrientation[Theta] += coord[Theta] / 5.0;

	if(mOrientation[Theta] >= 360.0)
		mOrientation[Theta] -= 360;
	else if(mOrientation[Theta] < 0)
		mOrientation[Theta] += 360;
	mOrientation[Phi] += coord[Phi] / 5.0;
	if(mOrientation[Phi] >= 360.0)
		mOrientation[Phi] -= 360;
	else if(mOrientation[Phi] < 0)
		mOrientation[Phi] += 360;
#endif
}

//Static Function

//Private Function

//Operator Overload