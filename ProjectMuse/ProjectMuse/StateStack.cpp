/////////////////////////////////////////////////////
/// 
/// 
/// 
/// 
/// 
/// 
/////////////////////////////////////////////////////

//Include My Code
#include "StateStack.h"
#include "GameState.h"

//Include Other
#include <iostream>
#include <assert.h>
#include <functional>

//Defines

//Const

//Static Prototyping

//Prototypes

//Class Definition

//Constructor
StateStack::StateStack()
{
}

//Destructor
StateStack::~StateStack()
{
}

//R-only access

//R-W access

//Setters

//Function
void StateStack::update(const double& dt)
{
	for(auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr)
	{
		if(!(*itr)->update(dt))
			break;
	}

	applyPendingChanges();
	std::cout << "Update timer: " << dt << std::endl;
}

void StateStack::render() const
{
	for(auto& state : mStack)
		state->draw();
}

void StateStack::processKeyboard(unsigned char touche, bool state, int x, int y)
{
	for(auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr)
	{
		if(!(*itr)->processKeyboard(touche, state, x, y))
			break;
	}

	applyPendingChanges();
}

void StateStack::processSpecKeyboard(int touche, bool state, int x, int y)
{
	for(auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr)
	{
		if(!(*itr)->processSpecKeyboard(touche, state, x, y))
			break;
	}

	applyPendingChanges();
}

void StateStack::processMouseClic(int button, int state, int x, int y)
{
	for(auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr)
	{
		if(!(*itr)->processMouseClic(button, state, x, y))
			break;
	}

	applyPendingChanges();
}

void StateStack::processMouseDrag(int x, int y)
{
	for(auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr)
	{
		if(!(*itr)->processMouseDrag(x, y))
			break;
	}

	applyPendingChanges();
}

void StateStack::processMouseMove(int x, int y)
{
	for(auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr)
	{
		if(!(*itr)->processMouseMove(x, y))
			break;
	}

	applyPendingChanges();
}

void StateStack::pushState(States::ID stateID)
{
	mPendingList.push_back(PendingChange(Push, stateID));
}

void StateStack::popState()
{
	mPendingList.push_back(PendingChange(Pop));
}

void StateStack::clearStates()
{
	mPendingList.push_back(PendingChange(Clear));
}

bool StateStack::isEmpty() const
{
	return mStack.empty();
}

//Static Function

//Private Function
State::Ptr StateStack::createState(States::ID stateID)
{
#ifdef VISUAL_STUDIO_2012
	auto found = mFactories.find(stateID);
	assert(found != mFactories.end());

	return (found->second)();
#else
	switch(stateID)
	{
	case States::None:
		break;
	case States::Title:
		break;
	case States::Menu:
		break;
	case States::Game:
		return State::Ptr(new GameState);
	case States::Loading:
		break;
	case States::Pause:
		break;
	case States::NetworkPause:
		break;
	case States::Settings:
		break;
	case States::GameOver:
		break;
	case States::MissionSuccess:
		break;
	case States::HostGame:
		break;
	case States::JoinGame:
		break;
	default:
		break;
	}
	return State::Ptr(new GameState);
#endif //VISUAL_STUDIO_2012
}

void StateStack::applyPendingChanges()
{
	for(auto change: mPendingList)
	{
		switch(change.mAction)
		{
		case Push:
			mStack.push_back(createState(change.mStateID));
			break;

		case Pop:
			mStack.back()->onDestroy();
			mStack.pop_back();

			if(!mStack.empty())
				mStack.back()->onActivate();
			break;

		case Clear:
			for(auto& state: mStack)
				state->onDestroy();

			mStack.clear();
			break;
		}
	}

	mPendingList.clear();
}

//Operator Overload