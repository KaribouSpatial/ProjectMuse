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
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"

//Include Other
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <memory>

//Defines

//Const

//Prototypes

//Class Prototypes

//Class Declaration
class FacadeResources
{
public:
	
	//Typedef
	typedef std::unique_ptr<FacadeResources> Ptr;

	//Enum
	enum Models
	{
		Sphere,
		Unit,
		NbModels
	};

	//Constructor
	FacadeResources();

	//Destructor
	~FacadeResources();

	//R-only access

	//R-W access

	//Setters

	//Function
	void draw(Models);

	//Static Function

	//Operator Overload

	//Public Attribute

private:

	//Private Function
	void drawSphere() const;
	void drawUnit() const;

	TextureHolder mTextures;

	//Private Attribute
	GLUquadric* mQuad;
};