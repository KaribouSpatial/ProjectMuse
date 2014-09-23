/////////////////////////////////////////////////////
/// 
/// 
/// 
/// 
/// 
/// 
/////////////////////////////////////////////////////

//Include My Code
#include "UnitNode.h"
#include "FacadeApplication.h"
#include "FacadeResources.h"

//Include Other

//Defines

//Const

//Static Prototyping

//Prototypes

//Class Definition

//Constructor
UnitNode::UnitNode(): SceneNode()
{
	mTexture = nullptr;
}

UnitNode::UnitNode(Textures::ID id) : SceneNode()
{
	mTexture = &FacadeApplication::Instance()->getFacadeResources()->getTexture(id);
}

//Destructor
UnitNode::~UnitNode()
{
}

//R-only access

//R-W access

//Setters


//Function
void UnitNode::updateCurrent(double dt)
{

}

void UnitNode::drawCurrent() const
{
	if(mTexture != nullptr)
	{
		const GLdouble vertexCoords[] =
		{
			//X    Y    Z
			-0.75, 0.0, 0.0,
			0.75, 0.0, 0.0,
			0.75, 0.0, 1.5,
			-0.75, 0.0, 1.5
		};

		const GLdouble textureCoords[] =
		{
			//  S          T
			2.0 / 3.0, 1.0 / 4.0,
			1.0 / 3.0, 1.0 / 4.0,
			1.0 / 3.0, 0.0,
			2.0 / 3.0, 0.0
		};

		const GLdouble normals[] =
		{
			//X    Y    Z
			0.0, -1.0, 0.0,
			0.0, -1.0, 0.0,
			0.0, -1.0, 0.0,
			0.0, -1.0, 0.0
		};

		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_ALPHA_TEST);

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glAlphaFunc(GL_GREATER, 0.1f);
		glBindTexture(GL_TEXTURE_2D, mTexture->getID());

		//Apply Materials
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambiant_std);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse_std);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular_std);
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_emission_std);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess_std);

		//Apply Transformation Matrices
		glTranslated(mPosition[X], mPosition[Y], mPosition[Z]);

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glTexCoordPointer(2, GL_DOUBLE, 0, textureCoords);
		glVertexPointer(3, GL_DOUBLE, 0, vertexCoords);
		glNormalPointer(GL_DOUBLE, 0, normals);
		glDrawArrays(GL_QUADS, 0, 4);

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);

		glDisable(GL_ALPHA_TEST);
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_BLEND);
		glDisable(GL_TEXTURE_2D);
	}
	else
		//No texture is associated with the unit, draw the 3d model
	{
		FacadeApplication::Instance()->getFacadeResources()->draw(FacadeResources::Unit);
	}
}

//Static Function

//Private Function

//Operator Overload