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

//Include Other

//Defines

//Const

//Prototypes

//Class Prototypes
class StateStack;

//Class Declaration
class State
{
public:

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