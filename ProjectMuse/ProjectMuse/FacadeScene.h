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

//Include Other
#include <memory>

//Defines
#define unique(x) std::unique_ptr<x>

//Const

//Prototypes

//Class Prototypes
class SceneNode;

//Class Declaration
class FacadeScene
{
public:

	//Constructor
	FacadeScene();

	//Destructor
	~FacadeScene();

	//R-only access

	//R-W access

	//Setters

	//Function
	void render() const;

	//Static Function

	//Operator Overload

	//Public Attribute

private:

	//Private Function
	void initializeScene();

	//Private Attribute
	unique(SceneNode) mScene;
};