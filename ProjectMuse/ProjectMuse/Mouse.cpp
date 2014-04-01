/////////////////////////////////////////////////////
/// 
/// 
/// 
/// 
/// 
/// 
/////////////////////////////////////////////////////

//Include My Code
#include "Mouse.h"

//Include Other

//Defines

//Const

//Static Prototyping

//Prototypes

//Class Definition

//Constructor
Mouse::Mouse()
{
	mPreviousPosition = vec2i();
}

//Destructor
Mouse::~Mouse()
{
}

//R-only access
vec2i Mouse::getPreviousPosition() const
{
	return mPreviousPosition;
}

//R-W access

//Setters
void Mouse::setPreviousPosition(const vec2i& pos)
{
	mPreviousPosition = pos;
}

//Function

//Static Function

//Private Function

//Operator Overload