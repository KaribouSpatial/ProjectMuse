/////////////////////////////////////////////////////
/// 
/// 
/// 
/// 
/// 
/// 
/////////////////////////////////////////////////////

//Include My Code
#include "FacadeApplication.h"

//Include Other
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

//Defines

//Const

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	//Start the application
	FacadeApplication::Instance()->run();

	// le programme n'arrivera jamais jusqu'ici
	return EXIT_SUCCESS;
}