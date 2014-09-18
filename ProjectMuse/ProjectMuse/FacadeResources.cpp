/////////////////////////////////////////////////////
/// 
/// 
/// 
/// 
/// 
/// 
/////////////////////////////////////////////////////

//Include My Code
#include "FacadeResources.h"

//Include Other
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <fstream>
#include <iostream>

//Defines

//Const

//Static Prototyping

//Prototypes

//Class Definition

//Constructor
FacadeResources::FacadeResources()
{
	mQuad = gluNewQuadric();
	
	//Loading all textures
	{
		std::ifstream textureNamesList("Assets/textureNamesList.txt");
		std::string tmp;
		try
		{
			if(textureNamesList.fail())
				throw std::exception("Failed to open \"textureNamesList.txt\"\n");
			
			for(int i = 0; i < Textures::TextureNumber; i++)
			{
				std::getline(textureNamesList, tmp);
				if(textureNamesList.fail())
					throw std::exception(("Failed to read \"" + tmp + "\"\n").c_str());
				mTextures.load(Textures::ID(i), "Assets/" + tmp);
			}
		}
		catch(std::exception ex)
		{
			std::cout << ex.what() << std::endl;
			throw ex;
		}
	}
}

//Destructor
FacadeResources::~FacadeResources()
{
}

//R-only access

//R-W access

//Setters

//Function
void FacadeResources::draw(Models model)
{
	switch(model)
	{
	case FacadeResources::Sphere:
		drawSphere();
		break;
	case Unit:
		drawUnit();
		break;
	default:
		break;
	}
	glPushAttrib(GL_LINE_BIT);
	{
		glLineWidth(3.0);

		// tracer les trois axes ET une ligne vers la source lumineuse
		GLfloat coords[] =
		{
			-15.0, 0.0, 0.0, 15.0, 0.0, 0.0,
			0.0, -15.0, 0.0, 0.0, 15.0, 0.0,
			0.0, 0.0, -15.0, 0.0, 0.0, 15.0,
		};
		GLfloat couleurs[] =
		{
			1.0, 0.0, 0.0, 1.0, 0.0, 0.0,
			0.0, 1.0, 0.0, 0.0, 1.0, 0.0,
			0.0, 0.0, 1.0, 0.0, 0.0, 1.0,
		};
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, coords);
		glColorPointer(3, GL_FLOAT, 0, couleurs);
		glDrawArrays(GL_LINES, 0, 8);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
	}
	glPopAttrib();
}

//Static Function

//Private Function
void FacadeResources::drawSphere() const
{
	glPushMatrix();
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glColor4d(0.922, 0.484, 0.712, 1.0);
		glutSolidSphere(1.5, 36, 36);
	}
	glPopMatrix();
}

void FacadeResources::drawUnit() const
{
	glColor4d(0.922, 0.484, 0.712, 1.0);
	glPushMatrix();
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		//right leg
		glPushMatrix();
		{
			glTranslated(0.075, 0.0, 0.0);
			//right foot
			glPushMatrix();
			{
				glTranslated(0.0, 0.09, 0.0);
				glRotated(90.0, 1.0, 0.0, 0.0);
				gluCylinder(mQuad, 0.05, 0.037, 0.295, 36, 5);
				glutSolidSphere(0.05, 36, 36);
				glTranslated(0.0, 0.0, 0.295);
				glutSolidSphere(0.037, 36, 36);
			}
			glPopMatrix();
			glTranslated(0.0, 0.0, 0.04);
			glutSolidSphere(0.042, 36, 36);
			//right low half leg
			glRotated(5, 1, 0, 0);
			gluCylinder(mQuad, 0.042, 0.0625, 0.37, 36, 5);
			glTranslated(0.0, 0.0, 0.37);
			glutSolidSphere(0.0625, 36, 36);
			//right high half leg
			glRotated(-7, 1, 0, 0);
			gluCylinder(mQuad, 0.0625, 0.084, 0.440, 36, 5);
			glTranslated(0.0, 0.0, 0.44);
			glutSolidSphere(0.084, 36, 36);
		}
		glPopMatrix();

		//left leg
		glPushMatrix();
		{
			glTranslated(-0.075, 0.0, 0.0);
			//left foot
			glPushMatrix();
			{
				glTranslated(0.0, 0.09, 0.0);
				glRotated(90.0, 1.0, 0.0, 0.0);
				gluCylinder(mQuad, 0.05, 0.037, 0.295, 36, 5);
				glutSolidSphere(0.05, 36, 36);
				glTranslated(0.0, 0.0, 0.295);
				glutSolidSphere(0.037, 36, 36);
			}
			glPopMatrix();
			glTranslated(0.0, 0.0, 0.04);
			glutSolidSphere(0.042, 36, 36);
			//left low half leg
			glRotated(5, 1, 0, 0);
			gluCylinder(mQuad, 0.042, 0.0625, 0.37, 36, 5);
			glTranslated(0.0, 0.0, 0.37);
			glutSolidSphere(0.0625, 36, 36);
			//left high half leg
			glRotated(-7, 1, 0, 0);
			gluCylinder(mQuad, 0.0625, 0.084, 0.440, 36, 5);
			glTranslated(0.0, 0.0, 0.44);
			glutSolidSphere(0.084, 36, 36);
		}
		glPopMatrix();

		glTranslated(0.0, 0.0, 0.85);
		//Torso
		glPushMatrix();
		{
			glutSolidCylinder(0.20, 0.555, 36, 5);

			//Head & Neck
			glTranslated(0.0, 0.0, 0.555);
			glutSolidCylinder(0.065, 0.1, 36, 2);
			glTranslated(0.0, 0.0, 0.18);
			glutSolidSphere(0.12, 36, 36);

		}
		glPopMatrix();

		//Left Arm
		glPushMatrix();
		{
			glTranslated(0.0, 0.0, 0.555);
			//Right Arm
			glPushMatrix();
			{
				glTranslated(-0.24, 0.0, 0.0);
				glRotated(175, 0, -1, 0);
				glutSolidCylinder(0.045, 0.535, 36, 2);
				glTranslated(0.0, 0.0, 0.53);
				glRotated(5, 0, -1, 0);
				glutSolidCylinder(0.055, 0.11, 36, 2);
			}
			glPopMatrix();
			glTranslated(0.24, 0.0, 0.0);
			glRotated(175, 0, 1, 0);
			glutSolidCylinder(0.045, 0.535, 36, 2);
			glTranslated(0.0, 0.0, 0.53);
			glRotated(5, 0, 1, 0);
			glutSolidCylinder(0.055, 0.11, 36, 2);
		}
		glPopMatrix();
	}
	glPopMatrix();
}
	//Operator Overload