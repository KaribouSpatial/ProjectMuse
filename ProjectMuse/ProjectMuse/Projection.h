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
class Projection
{
public:

	//Constructor
	Projection();

	//Destructor
	~Projection();

	//R-only access
	const vec2i& getWindowSize() const;

	//R-W access

	//Setters

	//Function
	void applyProjection() const;
	void resize(int width, int height);

	//Static Function

	//Operator Overload

	//Public Attribute

private:

	//Private Function

	//Private Attribute
	vec2i mWindowSize;
};