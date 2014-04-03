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
class Mouse
{
public:

	//Singleton specific
	static Mouse* Instance();
	void erase();

	//Destructor
	~Mouse();

	//R-only access
	vec2i getPreviousPosition() const;
	vec2i getPreviousClicPosition() const;

	//R-W access

	//Setters
	void setPreviousPosition(const vec2i& pos);
	void setPreviousClicPosition(const vec2i& pos);

	//Function

	//Static Function

	//Operator Overload

	//Public Attribute

protected:

	//Constructor
	Mouse();

private:

	//Private Function

	//Private Attribute
	vec2i mPreviousPosition;
	vec2i mPreviousClicPosition;

	//Singleton specific
	static Mouse* _instance;
};