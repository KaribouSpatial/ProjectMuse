/////////////////////////////////////////////////////
/// 
/// 
/// 
/// 
/// 
/// 
/////////////////////////////////////////////////////

//Include My Code
#include "GameState.h"
#include "FacadeApplication.h"
#include "FacadeView.h"
#include "FacadeScene.h"
#include "Mouse.h"

//Include Other
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <SFML\Window.hpp>

//Defines

//Const

//Static Prototyping

//Prototypes

//Class Definition

//Constructor
GameState::GameState()
{
}

//Destructor
GameState::~GameState()
{
}

//R-only access

//R-W access

//Setters

//Function
bool GameState::update(const double& dt)
{
	handleRealTime(dt);

	return true;
}

void GameState::draw()
{
	FacadeApplication::Instance()->getFacadeView()->renderView();

	//Lighting the scene
	GLfloat LumiAmbiant[] = {0.5f, 0.5f, 0.5f, 1.0f};
	GLfloat LumiDiffuse[] = {0.7f, 0.7f, 0.7f, 1.0f};
	GLfloat LumiSpeculaire[] = {0.5f, 0.5f, 0.5f, 1.0f};
	glLightfv(GL_LIGHT0, GL_AMBIENT, LumiAmbiant);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LumiDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, LumiSpeculaire);
	glEnable(GL_LIGHT0);

	//Rendering the scene
	FacadeApplication::Instance()->getFacadeScene()->renderScene();
}

bool GameState::processKeyboard(unsigned char touche, bool state, int x, int y)
{
	if(state == GLUT_UP)
	{
		switch(touche)
		{
		case '\x1b':
		case '\e':
			exit(1);
		case ' ':
			FacadeApplication::Instance()->getFacadeView()->flattenCamera();
			break;
		default:
			break;
		}
	}

	return true;
}

bool GameState::processSpecKeyboard(int touche, bool state, int x, int y)
{
	if(state == GLUT_UP)
	{
		switch(touche)
		{
		default:
			break;
		}
	}

	return true;
}

bool GameState::processMouseClic(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN)
	{
		//Mouse::Instance()->setPreviousClicPosition(vec2i(x, y));
	}
	else
	{
		vec2i current(x, y);
		current -= Mouse::Instance()->getPreviousClicPosition();
		if(current[X] < 4 && current[Y] < 4)
			;//do something really intelligent here
	}

	return true;
}

bool GameState::processMouseDrag(int x, int y)
{
	vec2i current(x, y);

	vec2i delta = current - Mouse::Instance()->getPreviousPosition();
	if(delta != current)
		FacadeApplication::Instance()->getFacadeView()->rotateCamera(delta);
	Mouse::Instance()->setPreviousPosition(current);
	return true;
}

bool GameState::processMouseMove(int x, int y)
{
	Mouse::Instance()->setPreviousPosition(vec2i(x, y));
	//sf::Mouse::setPosition(sf::Vector2i(640, 512));
	return true;
}

void GameState::handleRealTime(const double& dt)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		FacadeApplication::Instance()->getFacadeView()->moveCamera(vec2(0, dt));
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		FacadeApplication::Instance()->getFacadeView()->moveCamera(vec2(0, -dt));
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		FacadeApplication::Instance()->getFacadeView()->moveCamera(vec2(dt, 0));
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		FacadeApplication::Instance()->getFacadeView()->moveCamera(vec2(-dt, 0));
	}
}

//Static Function

//Operator Overload