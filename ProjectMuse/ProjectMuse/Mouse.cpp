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
#include "Mouse.h"
#include "Vector.hpp"

//Include Other

//Defines

//Const

//Prototypes
Mouse* Mouse::_instance = nullptr;

//Class Prototypes

//Class Declaration

//Constructor
Mouse::Mouse():
mPreviousPosition(0, 0),
mPreviousClicPosition(0, 0)
{
}

//Destructor
Mouse::~Mouse()
{
	_instance = nullptr;
}

//Singleton specific
Mouse* Mouse::Instance()
{
	if(_instance == nullptr)
	{
		_instance = new Mouse();
	}
	return _instance;
}

void Mouse::erase()
{
	delete _instance;
}

//R-only access
vec2i Mouse::getPreviousPosition() const
{
	return mPreviousPosition;
}

vec2i Mouse::getPreviousClicPosition() const
{
	return mPreviousClicPosition;
}

//R-W access

//Setters
void Mouse::setPreviousPosition(const vec2i& pos)
{
	mPreviousPosition = pos;
}

void Mouse::setPreviousClicPosition(const vec2i& pos)
{
	mPreviousClicPosition = pos;
}

//Function

//Static Function

//Operator Overload

//Public Attribute
