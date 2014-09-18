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

//R-W access

//Setters

//Function
bool Texture::loadFromFile(const std::string& filename)
{
	sf::Image img;
	if(img.loadFromFile(filename))
		return true;
	else
		return false;
}

//Static Function

//Private Function

//Operator Overload