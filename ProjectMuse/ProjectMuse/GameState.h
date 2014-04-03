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

//Include Other

//Defines

//Const

//Prototypes

//Class Prototypes

//Class Declaration
class GameState: public State
{
public:

	//Constructor
	GameState();

	//Destructor
	~GameState();

	//R-only access

	//R-W access

	//Setters

	//Function
	bool update(const double& dt) override;
	void draw() override;

	bool processKeyboard(unsigned char touche, bool state, int x, int y) override;
	bool processSpecKeyboard(int touche, bool state, int x, int y) override;
	bool processMouseClic(int button, int state, int x, int y) override;
	bool processMouseDrag(int x, int y) override;
	bool processMouseMove(int x, int y) override;
	void handleRealTime(const double& dt) override;

	//Static Function

	//Operator Overload

	//Public Attribute

private:

	//Private Function

	//Private Attribute
};