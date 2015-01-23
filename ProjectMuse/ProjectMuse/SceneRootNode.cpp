/////////////////////////////////////////////////////
/// 
/// 
/// 
/// 
/// 
/// 
/////////////////////////////////////////////////////

//Include My Code
#include "SceneRootNode.h"
#include "FacadeApplication.h"
#include "FacadeResources.h"

//Include Other

//Defines

//Const

//Static Prototyping

//Prototypes

//Class Definition

//Constructor
SceneRootNode::SceneRootNode(): SceneNode()
{

}

//Destructor
SceneRootNode::~SceneRootNode()
{
}

//R-only access

//R-W access

//Setters

//Function

//Static Function

//Private Function
void SceneRootNode::updateCurrent(const double& dt)
{

}

void SceneRootNode::drawCurrent() const
{
	//Draw the skybox
	//...drawing the skybox

	//Draw the 3-axis
	FacadeApplication::Instance()->getFacadeResources()->draw(FacadeResources::Axis);
}

//Operator Overload