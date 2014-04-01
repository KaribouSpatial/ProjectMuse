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
class Mouse
{
public:

	//Constructor
	Mouse();

	//Destructor
	~Mouse();

	//R-only access
	vec2i getPreviousPosition() const;

	//R-W access

	//Setters
	void setPreviousPosition(const vec2i&);

	//Function

	//Static Function

	//Operator Overload

	//Public Attribute

private:

	//Private Function

	//Private Attribute
	vec2i mPreviousPosition;
};