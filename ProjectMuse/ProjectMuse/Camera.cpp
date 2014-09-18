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
#include <assert.h>

//Defines
#define M_PI 3.14159265358979323846
#define M_HALF_PI 3.14159265358979323846/2
#define M2_PI 3.14159265358979323846*2
#define ToDegree(x) x*180.0/M_PI

#define VerifiyExtremums(value, min, max) if(value >= max) value -= max; else if(value < min) value += max;

//Const

//Static Prototyping

//Prototypes

//Class Definition

//Constructor
Camera::Camera():
mPosition(-1, -1, 0),
mFront(1, 1, 0),
mRight(1, -1, 0),
mUp(0, 0, 1)
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

	lookAt(mPosition, mPosition + mFront, mUp);
}

void Camera::rotateCamera(const vec2& coord)
{
	if(coord[Phi] != 0)
	{
		mFront = mFront.rotate(-coord[Phi] / 500.0, mRight);
		mUp = mUp.rotate(-coord[Phi] / 500.0, mRight);
	}

	if(coord[Theta] != 0)
	{
		mFront = mFront.rotate(-coord[Theta] / 500.0, mUp);
		mRight = mRight.rotate(-coord[Theta] / 500.0, mUp);
	}
}

void Camera::move(const vec2& coord)
{
	if(coord[X])
	{
		vec3 move = mRight;
		double factor = coord[X] / move.norme();
		move *= factor;
		mPosition += move;
	}
	else
	{
		vec3 move = mFront;
		double factor = coord[Y] / move.norme();
		move *= factor;
		mPosition += move;
	}
}

void Camera::flatten()
{


	if(mRight[Z] < 0)
	while(mRight[Z] < -0.01)
	{
		mRight = mRight.rotate(0.01, mFront);
		mUp = mUp.rotate(0.01, mFront);
	}
	else
	while(mRight[Z] > 0.01)
	{
		mRight = mRight.rotate(-0.01, mFront);
		mUp = mUp.rotate(-0.01, mFront);
	}

	if(mUp[Z] < 0)
	{
		mRight = mRight.rotate(M_PI, mFront);
		mUp = mUp.rotate(M_PI, mFront);
	}

	assert(std::abs(mRight[Z]) < 0.01);
}

//Static Function

//Private Function
void Camera::lookAt(const vec3& position, const vec3& target, const vec3& upVector) const
{
	gluLookAt(
		position[X], position[Y], position[Z],
		target[X], target[Y], target[Z],
		upVector[X], upVector[Y], upVector[Z]);
}

//Operator Overload