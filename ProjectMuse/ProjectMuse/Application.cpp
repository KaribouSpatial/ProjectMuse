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
#include "FacadePlayer.h"


//Include Other
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

//Defines
#define FRAME_RATE 1000/60
#define min(x,y) (x < y ? x : y)
#define max(x,y) (x >= y ? x : y)

//Const

//Static Prototyping

//Prototypes

//Class Definition

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
		s_Application->processKeyboard(touche, x, y);
	}

	void processSpecKeyboard(int touche, int x, int y)
	{
		s_Application->processSpecKeyboard(touche, x, y);
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

	glutSpecialFunc(GlutCallback::processSpecKeyboard);

	glutMotionFunc(GlutCallback::processMouseDrag);

	glutPassiveMotionFunc(GlutCallback::processMouseMove);

	glutMouseFunc(GlutCallback::processMouseClic);

	glutIdleFunc(GlutCallback::idle);

	glewInit();

	//initialisation();

	update(FRAME_RATE);
	
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
	std::cout << mPrevTime << std::endl;
	std::cout << dt << std::endl;
}

void Application::processKeyboard(unsigned char touche, int x, int y)
{
	std::cout << "processKeyboard " << touche << std::endl;
}

void Application::processSpecKeyboard(int touche, int x, int y)
{
	std::cout << "processSpecKeyboard " << touche << std::endl;
}

void Application::processMouseClic(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN)
		FacadeApplication::Instance()->getFacadePlayer()->setPreviousMousePosition(x, y);
	std::cout << "processMouseClic " << x << " " << y << std::endl;
}

void Application::processMouseDrag(int x, int y)
{
	FacadeApplication::Instance()->getFacadePlayer()->processMouseDrag(x, y);
	std::cout << "processMouseDrag " << x << " " << y << std::endl;
}

void Application::processMouseMove(int x, int y)
{
	std::cout << "processMouseMove " << x << " " << y << std::endl;
}

void Application::render() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	FacadeApplication::Instance()->getFacadeView()->applyView();
	FacadeApplication::Instance()->getFacadeScene()->render();
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