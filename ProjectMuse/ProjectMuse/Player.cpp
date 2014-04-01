/////////////////////////////////////////////////////
/// 
/// 
/// 
/// 
/// 
/// 
/////////////////////////////////////////////////////

//Include My Code
#include "Player.h"
#include "FacadeApplication.h"
#include "FacadeView.h"

//Include Other

//Defines

//Const

//Static Prototyping

//Prototypes

//Class Definition

//Constructor
Player::Player()
{
}

//Destructor
Player::~Player()
{
}

//R-only access

//R-W access

//Setters

//Function
void Player::processMouseDrag(const vec2& deltaPixel)
{
	FacadeApplication::Instance()->getFacadeView()->rotateCamera(deltaPixel);
}

//Static Function

//Private Function

//Operator Overload