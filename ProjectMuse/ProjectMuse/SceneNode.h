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
#include "Vector.hpp"

//Include Other
#include <memory>
#include <vector>

//Defines

//Const

//Namespaces
namespace NodeTypes
{
	enum ID
	{
		Root = 0,
		Unit
	};
}

//Prototypes

//Class Prototypes

//Class Declaration
class SceneNode
{
public:

	//Typedef
	typedef std::unique_ptr<SceneNode> Ptr;
	typedef unsigned ID;

	//Constructor
	SceneNode();

	//Destructor
	virtual ~SceneNode();

	//R-only access
	ID getID() const;
	const std::vector<Ptr>& getChildren() const;

	//R-W access
	std::vector<Ptr>& getChildren();

	//Setters
	void setPosition(double x, double y, double z);
	void setPosition(vec3 pos);

	//Function
	void draw() const;
	void update(double dt);

	//Composite Function
	void attachChild(Ptr child);
	Ptr detachChild(const SceneNode& node);

	//Static Function

	//Operator Overload
	virtual bool operator==(SceneNode node);

	//Public Attribute

protected:
	//Protected Attribute
	vec3 mPosition;

private:

	//Private Function

	//Composite Private
	virtual void updateCurrent(double dt);
	virtual void drawCurrent() const;
	void updateChildren(double dt);
	void drawChildren() const;

	//Private Attribute
	ID mID;
	NodeTypes::ID mType;

	//Composite Attribute
	std::vector<Ptr> mChildren;
	SceneNode* mParent;
};