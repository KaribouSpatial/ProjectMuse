/////////////////////////////////////////////////////
/// 
/// 
/// 
/// 
/// 
/// 
/////////////////////////////////////////////////////

//Include My Code
#include "FacadeScene.h"
#include "SceneNode.h"
#include "UnitNode.h"

//Include Other

//Defines

//Const

//Static Prototyping

//Prototypes

//Class Definition

//Constructor
FacadeScene::FacadeScene()
{
	initializeScene();
}

//Destructor
FacadeScene::~FacadeScene()
{
}

//R-only access

//R-W access

//Setters

//Function
void FacadeScene::render() const
{
	mScene->draw();
}

//Static Function

//Private Function
void FacadeScene::initializeScene()
{
	mScene = std::move(std::unique_ptr<SceneNode>(new UnitNode));
}

//Operator Overload