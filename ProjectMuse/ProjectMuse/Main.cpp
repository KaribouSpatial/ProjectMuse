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
	// param�trage de l'affichage
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	// taille de la fenetre
	glutInitWindowSize(INIT_WINDOW_WIDTH, INIT_WINDOW_HEIGHT);
	// cr�ation de la fen�tre
	static const unsigned INIT_WINDOW_HEIGHT = glutCreateWindow("INF2705");

	// r�f�rencement de la fonction de rappel pour l'affichage
	//glutDisplayFunc( );

	// r�f�rencement de la fonction de rappel pour le redimensionnement
	//glutReshapeFunc( );

	// r�f�rencement de la fonction de gestion des touches
	//glutKeyboardFunc( );

	// r�f�rencement de la fonction de gestion des touches sp�ciales
	//glutSpecialFunc( );

	// r�f�rencement de la fonction de rappel pour le mouvement de la souris
	//glutMotionFunc( );

	// r�f�rencement de la fonction de rappel pour le clic de la souris
	//glutMouseFunc( );

	glewInit();

	//initialisation();

	// boucle principale de gestion des evenements
	glutMainLoop();

	// le programme n'arrivera jamais jusqu'ici
	return EXIT_SUCCESS;
}