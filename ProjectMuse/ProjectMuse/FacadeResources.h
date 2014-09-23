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
const GLfloat mat_ambiant_std[] = {0.1f, 0.0f, 0.1f, 1.0f};
const GLfloat mat_diffuse_std[] = {1.0f, 0.1f, 1.0f, 1.0f};
const GLfloat mat_specular_std[] = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat mat_emission_std[] = {0.0f, 0.0f, 0.0f, 1.0f};
const GLfloat mat_shininess_std[] = {100.0f};

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
		Rectangle,
		Unit,
		Axis,
		NbModels
	};

	//Constructor
	FacadeResources();

	//Destructor
	~FacadeResources();

	//R-only access
	const Texture& getTexture(Textures::ID id) const;

	//R-W access
	Texture& getTexture(Textures::ID id);

	//Setters

	//Function
	void draw(Models model, GLuint IDTexture = 0);

	//Static Function

	//Operator Overload

	//Public Attribute

private:

	//Private Function
	void drawSphere() const;
	void drawRectangle(GLuint IDTexture) const;
	void drawUnit() const;
	void drawAxis() const;

	TextureHolder mTextures;

	//Private Attribute
	GLUquadric* mQuad;
};