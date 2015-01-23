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

//Include Other
#include <memory>
#include <vector>

//Defines

//Const

//Prototypes

//Class Prototypes

//Class Declaration
class SceneRootNode: public SceneNode
{
public:

	//Typedef
	typedef std::unique_ptr<SceneRootNode> Ptr;

	//Enum

	//Constructor
	SceneRootNode();

	//Destructor
	~SceneRootNode();

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
};