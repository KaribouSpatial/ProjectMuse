/////////////////////////////////////////////////////
/// 
/// 
/// 
/// 
/// 
/// 
/////////////////////////////////////////////////////

//Include My Code
#include "UnitNode.h"
#include "FacadeApplication.h"
#include "FacadeResources.h"

//Include Other

//Defines

//Const

//Static Prototyping

//Prototypes

//Class Definition

//Constructor
UnitNode::UnitNode(): SceneNode()
{
}

//Destructor
UnitNode::~UnitNode()
{
}

//R-only access

//R-W access

//Setters

//Function
void UnitNode::draw() const
{
	FacadeApplication::Instance()->getFacadeResources()->draw(FacadeResources::Unit);
}

//Static Function

//Private Function

//Operator Overload