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
#include "SceneRootNode.h"

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
void FacadeScene::renderScene() const
{
	mScene->draw();
}

void FacadeScene::updateScene(const double& dt)
{
	mScene->update(dt);
}

//Static Function

//Private Function
void FacadeScene::initializeScene()
{
	mScene = std::move(SceneNode::Ptr(new SceneRootNode()));
	mScene->attachChild(std::move(SceneNode::Ptr(new UnitNode(Textures::Neydala_Fight_Mask))));
	auto it = mScene->getChildren().front().get();
	it->setPosition(vec3(2, 2, 0));
	it->attachChild(std::move(SceneNode::Ptr(new UnitNode(Textures::Ray_Armor_Plate))));
	it->getChildren().front().get()->setPosition(vec3(0, 2, 0));
	mScene->attachChild(std::move(SceneNode::Ptr(new UnitNode(Textures::Cellia_Boucle_Cape3_Mage))));
	mScene->getChildren().back().get()->setPosition(0, 1, 0);
}

//Operator Overload