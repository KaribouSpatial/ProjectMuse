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
#include "Player.h"

#include <Vector.hpp>

//Include Other
#include <memory>

//Defines
#define unique(x) std::unique_ptr<x>

//Const

//Prototypes

//Class Prototypes

//Class Declaration
class FacadePlayer
{
public:

	//Constructor
	FacadePlayer();

	//Destructor
	~FacadePlayer();

	//R-only access
	const vec2i& getPreviousMousePosition() const;

	//R-W access

	//Setters
	void setPreviousMousePosition(int x, int y);

	//Function
	void processMouseDrag(int x, int y);
	//Static Function

	//Operator Overload

	//Public Attribute

private:

	//Private Function

	//Private Attribute
	Mouse mMouse;
	Player mPlayer;
};