/////////////////////////////////////////////////////
/// 
/// 
/// 
/// 
/// 
/// 
/////////////////////////////////////////////////////

//Include My Code
#include "Texture.h"

//Include Other
#include <SFML\Graphics.hpp>

//Defines

//Const

//Static Prototyping

//Prototypes

//Class Definition

//Constructor
Texture::Texture()
{
}

//Destructor
Texture::~Texture()
{
}

//R-only access
int Texture::getWidth() const
{
	return mWidth;
}

int Texture::getHeight() const
{
	return mHeight;
}

GLuint Texture::getID() const
{
	return mIDTexture;
}

int Texture::getColumns() const
{
	return mColumns;
}

int Texture::getRows() const
{
	return mRows;
}

//R-W access

//Setters
void Texture::setWidth(int width)
{
	mWidth = width;
}

void Texture::setHeight(int height)
{
	mHeight = height;
}

//Function
bool Texture::loadFromFile(const std::string& filename)
{
	sf::Image img;
	if(img.loadFromFile(filename))
	{
		// création de la texture OpenGL
		glEnable(GL_TEXTURE_2D);

		glGenTextures(1, &mIDTexture);
		glBindTexture(GL_TEXTURE_2D, mIDTexture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.getSize().x, img.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, img.getPixelsPtr());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

		glDisable(GL_TEXTURE_2D);

		if(((mWidth = img.getSize().x) > 96) && ((mHeight = img.getSize().y) > 128))
		{
			mColumns = 8;
			mRows = 2;
		}
		else
		{
			mColumns = 3;
			mRows = 4;
		}
		return true;
	}
	else
		return false;
}

//Static Function

//Private Function

//Operator Overload