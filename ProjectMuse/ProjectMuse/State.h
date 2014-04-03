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
#include "StatesID.h"
#include "IEventHandler.h"

//Include Other
#include <memory>

//Defines

//Const

//Prototypes

//Class Prototypes
class StateStack;

//Class Declaration
class State : public IEventHandler
{
public:
	//Typedef
	typedef std::unique_ptr<State> Ptr;

	//Structure
	struct Context
	{
		// Context();
		// TextureHolder* textures;
		// FontHolder* fonts;
		// MusicPlayer* music;
		// SoundPlayer* sounds;
		// KeyBinding* keys1;
		// KeyBinding* keys2;
	};

	//Constructor
	State();

	//Destructor
	~State();

	//R-only access

	//R-W access

	//Setters

	//Function
	virtual void draw() = 0;
	virtual bool update(const double& dt) = 0;

	virtual void onActivate();
	virtual void onDestroy();

	//Static Function

	//Operator Overload

	//Public Attribute

protected:

	//Protected Function
	void requestStackPush(States::ID stateID);
	void requestStackPop();
	void requestStateClear();
	Context getContext() const;

private:

	//Private Function

	//Private Attribute
	StateStack* mStack;
	Context mContext;
};