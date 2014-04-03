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
#include "Vector.hpp"

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
	void move(const vec2& coord);
	void flatten();

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
	inline void lookAt(const vec3& position, const vec3& target, const vec3& upVector) const;

	//Private Attribute
	vec3 mPosition;

	vec3 mFront;
	vec3 mRight;
	vec3 mUp;
};