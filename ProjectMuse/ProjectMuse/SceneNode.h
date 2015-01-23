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
#include "ResourceIdentifiers.hpp"

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
	void update(const double& dt);

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
	Directions::ID mDirection;

private:

	//Private Function

	//Private Attribute
	ID mID;
	NodeTypes::ID mType;

	//Composite Specific
	std::vector<Ptr> mChildren;
	SceneNode* mParent;
	virtual void updateCurrent(const double& dt);
	virtual void drawCurrent() const;
	void updateChildren(const double& dt);
	void drawChildren() const;
};