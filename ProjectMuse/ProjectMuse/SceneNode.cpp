/////////////////////////////////////////////////////
/// 
/// 
/// 
/// 
/// 
/// 
/////////////////////////////////////////////////////

//Include My Code
#include "SceneNode.h"

//Include Other
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <algorithm>

//Defines

//Const

//Static Prototyping

//Prototypes

//Class Definition

//Constructor
SceneNode::SceneNode()
{
}

//Destructor
SceneNode::~SceneNode()
{
}

//R-only access
const std::vector<SceneNode::Ptr>& SceneNode::getChildren() const
{
	return mChildren;
}

//R-W access
std::vector<SceneNode::Ptr>& SceneNode::getChildren()
{
	return mChildren;
}

//Setters
void SceneNode::setPosition(double x, double y, double z)
{
	mPosition[X] = x;
	mPosition[Y] = y;
	mPosition[Z] = z;
}

void SceneNode::setPosition(vec3 pos)
{
	mPosition = pos;
}

//Function
void SceneNode::attachChild(Ptr child)
{
	child->mParent = this;
	mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node)
{
	auto found = find_if(mChildren.begin(), mChildren.end(),
						 [&] (Ptr& p) -> bool
	{
		return p.get() == &node;
	});

	if(found == mChildren.end())
		return nullptr;

	Ptr result = move(*found);
	result->mParent = nullptr;
	mChildren.erase(found);
	return result;
}

void SceneNode::draw() const
{
	glPushMatrix();
	{
		//Fire-up opengl draw states
		glEnable(GL_LIGHTING);
		glEnable(GL_COLOR_MATERIAL);

		drawCurrent();

		glDisable(GL_LIGHTING);
		glDisable(GL_COLOR_MATERIAL);

		drawChildren();
	}
	glPopMatrix();
}

void SceneNode::drawCurrent() const
{
	//SceneNode is abstract
}

void SceneNode::drawChildren() const
{
	for(const auto& child : mChildren)
	{
		child->draw();
	}
}

void SceneNode::update(double dt)
{
	updateChildren(dt);
	updateCurrent(dt);
}

void SceneNode::updateCurrent(double dt)
{
	//SceneNode is abstract;
}

void SceneNode::updateChildren(double dt)
{
	for(auto& child : mChildren)
		child->update(dt);
}

//Static Function

//Private Function

//Operator Overload
bool SceneNode::operator==(SceneNode node)
{
	return (mID == node.mID ? true : false);
	/*
	if(mID == node.mID)
		return true;
	else return false;
	*/
}