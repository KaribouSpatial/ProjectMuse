/////////////////////////////////////////////////////
/// 
/// 
/// 
/// 
/// 
/// 
/////////////////////////////////////////////////////

//Include My Code
#include "Application.h"
#include "FacadeApplication.h"
#include "FacadeResources.h"
#include "FacadeView.h"
#include "FacadeScene.h"
#include "Mouse.h"

//Include Other
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

//Defines
#define min(x,y) (x < y ? x : y)
#define max(x,y) (x >= y ? x : y)
#define KEY_DOWN true
#define KEY_UP false

//Const

//Static Prototyping

//Prototypes

//Namespace
namespace GlutCallback
{
	static Application* s_Application = nullptr;

	void idle()
	{
		s_Application->idle();
	}

	void processKeyboard(unsigned char touche, int x, int y)
	{
		s_Application->processKeyboard(touche, KEY_DOWN, x, y);
	}

	void processKeyboardRelease(unsigned char touche, int x, int y)
	{
		s_Application->processKeyboard(touche, KEY_UP, x, y);
	}

	void processSpecKeyboard(int touche, int x, int y)
	{
		s_Application->processSpecKeyboard(touche, KEY_DOWN, x, y);
	}

	void processSpecKeyboardRelease(int touche, int x, int y)
	{
		s_Application->processSpecKeyboard(touche, KEY_UP, x, y);
	}

	void processMouseClic(int button, int state, int x, int y)
	{
		s_Application->processMouseClic(button, state, x, y);
	}

	void processMouseDrag(int x, int y)
	{
		s_Application->processMouseDrag(x, y);
	}

	void processMouseMove(int x, int y)
	{
		s_Application->processMouseMove(x, y);
	}

	void render()
	{
		s_Application->render();
	}

	void resize(GLsizei width, GLsizei height)
	{
		s_Application->resize(width, height);
	}
}

//Class Definition
//Constructor
Application::Application():
mPrevTime(0),
mTimeSinceLastUpdate(0)
{
	GlutCallback::s_Application = this;

	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(
		FacadeApplication::Instance()->getFacadeView()->getWindowSize()[X],
		FacadeApplication::Instance()->getFacadeView()->getWindowSize()[Y]);
	mGLWindow = glutCreateWindow("ProjectMuse");
}

//Destructor
Application::~Application()
{
	glutDestroyWindow(mGLWindow);
}

//R-only access

//R-W access

//Setters

//Function
void Application::run()
{
	glutDisplayFunc(GlutCallback::render);

	glutReshapeFunc(GlutCallback::resize);

	glutKeyboardFunc(GlutCallback::processKeyboard);

	glutKeyboardUpFunc(GlutCallback::processKeyboardRelease);

	glutSpecialFunc(GlutCallback::processSpecKeyboard);

	glutSpecialUpFunc(GlutCallback::processSpecKeyboardRelease);

	glutMotionFunc(GlutCallback::processMouseDrag);

	glutPassiveMotionFunc(GlutCallback::processMouseMove);

	glutMouseFunc(GlutCallback::processMouseClic);

	glutIdleFunc(GlutCallback::idle);

	glewInit();

	mStateStack.pushState(States::Game);

	//initialisation();
	
	glutMainLoop();
}

//Glut Function
void Application::idle()
{
	int time = glutGet(GLUT_ELAPSED_TIME);
	mTimeSinceLastUpdate += min(64,time - mPrevTime);
	mPrevTime = time;
	if(mTimeSinceLastUpdate > TimePerFrame)
	{
		mTimeSinceLastUpdate -= TimePerFrame;
		update(TimePerFrame);
	}
	else
	{
		//updateStatistics(dt)
		glutPostRedisplay();
	}
}

void Application::update(int dt)
{
	mStateStack.update(dt/1000.0);
}

void Application::processKeyboard(unsigned char touche, bool state, int x, int y)
{
	mStateStack.processKeyboard(touche, state, x, y);
	std::cout << "processKeyboard " << touche << std::endl;
}

void Application::processSpecKeyboard(int touche, bool state, int x, int y)
{
	mStateStack.processSpecKeyboard(touche, state, x, y);
	std::cout << "processSpecKeyboard " << touche << std::endl;
}

void Application::processMouseClic(int button, int state, int x, int y)
{
	mStateStack.processMouseClic(button, state, x, y);
	Mouse::Instance()->setPreviousClicPosition(vec2i(x, y));
	Mouse::Instance()->setPreviousPosition(vec2i(x, y));
	std::cout << "processMouseClic " << x << " " << y << std::endl;
}

void Application::processMouseDrag(int x, int y)
{
	mStateStack.processMouseDrag(x, y);
	Mouse::Instance()->setPreviousPosition(vec2i(x, y));
	std::cout << "processMouseDrag " << x << " " << y << std::endl;
}

void Application::processMouseMove(int x, int y)
{
	mStateStack.processMouseMove(x, y);
	Mouse::Instance()->setPreviousPosition(vec2i(x, y));
	std::cout << "processMouseMove " << x << " " << y << std::endl;
}

void Application::render() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	mStateStack.render();
	std::cout << "Rendered" << std::endl;

	glutSwapBuffers();
}

void Application::resize(GLsizei width, GLsizei height)
{
	FacadeApplication::Instance()->getFacadeView()->resize(width, height);
}

//Private Function
void Application::registerStates()
{

}


//Operator Overload