/////////////////////////////////////////////////////
/// 
/// 
/// 
/// 
/// 
/// 
/////////////////////////////////////////////////////

#pragma once

//Include My Code
#include <Vector.hpp>

//Include Other

//Defines

//Const

//Prototypes

//Class Prototypes

//Class Declaration
class Camera
{
public:

	//Constructor
	Camera();

	//Destructor
	~Camera();

	//R-only access

	//R-W access

	//Setters

	//Function
	void applyCamera() const;
	void rotateCamera(const vec2& coord);

	//Static Function

	//Operator Overload

	//Public Attribute

private:

	//Private Enum
	enum SphericAngle
	{
		Theta,
		Phi,
		Epsilon
	};

	//Private Function

	//Private Attribute
	vec3 mPosition;
	vec3 mTargetPoint;
	vec3 mOrientation;
	double mRollEpsilon; //RAD
};