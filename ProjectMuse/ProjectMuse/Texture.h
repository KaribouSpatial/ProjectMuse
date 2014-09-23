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
#include "Resource.h"

//Include Other
#include <GL\glew.h>
#include <GL\glut.h>
#include <string>

//Defines

//Const

//Prototypes

//Class Prototypes

//Class Declaration
class Texture: Resource
{
public:

	//Constructor
	Texture();

	//Destructor
	~Texture();

	//R-only access
	int getWidth() const;
	int getHeight() const;
	int getColumns() const;
	int getRows() const;
	GLuint getID() const;

	//R-W access

	//Setters
	void setWidth(int width);
	void setHeight(int height);

	//Function
	bool loadFromFile(const std::string& filename);

	//Static Function

	//Operator Overload

	//Public Attribute

private:

	//Private Function

	//Private Attribute
	GLuint mIDTexture;
	
	int mWidth;
	int mHeight;
	int mColumns;
	int mRows;
};