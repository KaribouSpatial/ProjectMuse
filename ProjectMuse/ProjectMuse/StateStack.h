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
#include "State.h"
#include "StatesID.h"
#include "IEventHandler.h"
#include "NoCopy.hpp"

//Include Other
#include <vector>
#include <map>
#include <memory>
#include <functional>

//Defines
//#define VISUAL_STUDIO_2012

//Const

//Prototypes

//Class Prototypes

//Class Declaration
class StateStack: private NoCopy
{
public:
	enum Action
	{
		Push,
		Pop,
		Clear,
	};
	//Constructor
	StateStack();

#ifdef VISUAL_STUDIO_2012
	template <typename T>
	void registerState(States::ID stateID);
	template <typename T, typename Param1>
	void registerState(States::ID stateID, Param1 arg1);
#endif //VISUAL_STUDIO_2012

	//Destructor
	~StateStack();

	//R-only access

	//R-W access

	//Setters

	//Function
	void update(const double& dt);
	void render() const;

	void processKeyboard(unsigned char touche, bool state, int x, int y);
	void processSpecKeyboard(int touche, bool state, int x, int y);
	void processMouseClic(int button, int state, int x, int y);
	void processMouseDrag(int x, int y);
	void processMouseMove(int x, int y);

	void pushState(States::ID stateID);
	void popState();
	void clearStates();

	bool isEmpty() const;

	//Static Function

	//Operator Overload

	//Public Attribute

private:
	struct PendingChange
	{
		PendingChange(Action action, States::ID stateID = States::None)
		{
			mAction = action;
			mStateID = stateID;
		};

		Action mAction;
		States::ID mStateID;
	};

	//Private Function
	State::Ptr createState(States::ID stateID);
	void applyPendingChanges();

	//Private Attribute
	std::vector<State::Ptr> mStack;
	std::vector<PendingChange> mPendingList;
	State::Context mContext;
#ifdef VISUAL_STUDIO_2012
	//typedef std::function<typename std::remove_pointer<State::Ptr>::type> function_t;
	std::map<States::ID, function_t> mFactories;
#endif
};

#ifdef VISUAL_STUDIO_2012
template <typename T>
void StateStack::registerState(States::ID stateID)
{
	mFactories[stateID] = [this] ()
	{
		return State::Ptr(new T(*this, mContext));
	};
}

template <typename T, typename Param1>
void StateStack::registerState(States::ID stateID, Param1 arg1)
{
	mFactories[stateID] = [this, arg1] ()
	{
		return State::Ptr(new T(*this, mContext, arg1));
	};
}
#endif //VISUAL_STUDIO_2012