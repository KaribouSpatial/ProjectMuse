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
#include "StateStack.h"

#include <NoCopy.hpp>

//Include Other
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <memory>

//Defines

//Const
const int TimePerFrame = 1000 / 60;

//Prototypes

//Class Prototypes
class FacadeApplication;

//Class Declaration
class Application: private NoCopy
{
public:
	//Constructor
	Application();

	//Destructor
	~Application();

	//R-only access

	//R-W access

	//Setters

	//Function
	void run();

	void idle();
	void update(int dt);
	void processKeyboard(unsigned char, int, int);
	void processSpecKeyboard(int, int, int);
	void processMouseClic(int, int, int, int);
	void processMouseDrag(int, int);
	void processMouseMove(int, int);
	void render() const;
	void resize(GLsizei width, GLsizei height);

	//Static Function

	//Operator Overload

	//Public Attribute

private:

	//Private Function
	void registerStates();

	//Static Private Function
	
	//Private Attribute
	int mPrevTime;
	int mTimeSinceLastUpdate;
	unsigned mGLWindow;
	StateStack mStateStack;
};