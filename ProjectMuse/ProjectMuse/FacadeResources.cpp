

//Include My Code
#include "FacadeResources.h"

//Include Other
#include <GL\glew.h>
#include <GL\freeglut.h>

//Defines

//Const

//Static Prototyping

//Prototypes

//Class Definition

//Constructor
FacadeResources::FacadeResources()
{
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
	case FacadeResources::Cube:
	{
								  glPushAttrib(GL_LINE_BIT); {
									  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
									  glColor4d(0.922, 0.484, 0.712, 1.0);
									  glutSolidSphere(1.5, 36, 36);

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
								  break;

	}
	default:
		break;
	}
}

//Static Function

//Operator Overload