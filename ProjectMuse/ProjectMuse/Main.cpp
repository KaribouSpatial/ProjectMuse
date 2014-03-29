//not mine
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

//Mine

//zExternal
#include <ExVector.h>

//Defines

//Const
const unsigned INIT_WINDOW_WIDTH = 1024;
const unsigned INIT_WINDOW_HEIGHT = 768;

int main(int argc, char* argv[])
{
	// initialisation de GLUT
	glutInit(&argc, argv);
	// paramétrage de l'affichage
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	// taille de la fenetre
	glutInitWindowSize(INIT_WINDOW_WIDTH, INIT_WINDOW_HEIGHT);
	// création de la fenêtre
	static const unsigned INIT_WINDOW_HEIGHT = glutCreateWindow("INF2705");

	// référencement de la fonction de rappel pour l'affichage
	//glutDisplayFunc( );

	// référencement de la fonction de rappel pour le redimensionnement
	//glutReshapeFunc( );

	// référencement de la fonction de gestion des touches
	//glutKeyboardFunc( );

	// référencement de la fonction de gestion des touches spéciales
	//glutSpecialFunc( );

	// référencement de la fonction de rappel pour le mouvement de la souris
	//glutMotionFunc( );

	// référencement de la fonction de rappel pour le clic de la souris
	//glutMouseFunc( );

	glewInit();

	//initialisation();

	// boucle principale de gestion des evenements
	glutMainLoop();

	// le programme n'arrivera jamais jusqu'ici
	return EXIT_SUCCESS;
}