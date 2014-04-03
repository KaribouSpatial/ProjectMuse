/////////////////////////////////////////////////////
/// 
/// 
/// 
/// 
/// 
/// 
/////////////////////////////////////////////////////

//Include My Code
#include "State.h"
#include "StateStack.h"

//Include Other

//Defines

//Const

//Static Prototyping

//Prototypes

//Class Definition

//Constructor
State::State()
{
}

//Destructor
State::~State()
{
}

//R-only access

//R-W access

//Setters

//Function
void State::requestStackPush(States::ID stateID)
{
	mStack->pushState(stateID);
}

void State::requestStackPop()
{
	mStack->popState();
}

void State::requestStateClear()
{
	mStack->clearStates();
}

State::Context State::getContext() const
{
	return mContext;
}

void State::onActivate()
{

}

void State::onDestroy()
{

}

//Static Function

//Private Function

//Operator Overload