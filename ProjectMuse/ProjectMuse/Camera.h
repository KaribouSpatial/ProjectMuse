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

	//Static Function

	//Operator Overload

	//Public Attribute

private:

	//Private Function

	//Private Attribute
	vec3 mPosition;
	vec3 mOrientation;
};