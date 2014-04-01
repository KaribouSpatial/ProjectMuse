/////////////////////////////////////////////////////
/// 
/// 
/// 
/// 
/// 
/// 
/////////////////////////////////////////////////////

//Include My Code
#include "FacadePlayer.h"

//Include Other

//Defines

//Const

//Static Prototyping

//Prototypes

//Class Definition

//Constructor
FacadePlayer::FacadePlayer()
{
	mPlayer = Player();
	mMouse = Mouse();
}

//Destructor
FacadePlayer::~FacadePlayer()
{
}

//R-only access
const vec2i& FacadePlayer::getPreviousMousePosition() const
{
	return mMouse.getPreviousPosition();
}

//R-W access

//Setters
void FacadePlayer::setPreviousMousePosition(int x, int y)
{
	mMouse.setPreviousPosition(vec2i(x, y));
}

//Function
void FacadePlayer::processMouseDrag(int x, int y)
{
	vec2i prev = getPreviousMousePosition();
	vec2i current(x, y);
	vec2i delta = current - prev;
	if(delta != current)
		mPlayer.processMouseDrag(delta);
	mMouse.setPreviousPosition(current);
}
//Static Function

//Private Function

//Operator Overload