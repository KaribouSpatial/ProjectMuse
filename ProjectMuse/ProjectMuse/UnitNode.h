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
#include "SceneNode.h"
#include "ResourceIdentifiers.hpp"

//Include Other

//Defines

//Const

//Prototypes

//Class Prototypes

//Class Declaration
class UnitNode: public SceneNode
{
public:

	//Constructor
	UnitNode();
	UnitNode(Textures::ID id);

	//Destructor
	~UnitNode();

	//R-only access

	//R-W access

	//Setters

	//Function

	//Static Function

	//Operator Overload

	//Public Attribute

private:

	//Private Function
	void updateCurrent(const double& dt) override;
	void drawCurrent() const override;

	//Private Attribute
	Texture* mTexture;
};