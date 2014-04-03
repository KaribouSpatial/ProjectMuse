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

//Const

//Prototypes

//Class Prototypes

//Class Declaration
class SceneNode
{
public:

	//Typedef
	typedef std::unique_ptr<SceneNode> Ptr;

	//Enum
	enum NodeType
	{
		Scene = 0,
		Unit
	};

	//Constructor
	SceneNode();

	//Destructor
	virtual ~SceneNode();

	//R-only access

	//R-W access

	//Setters

	//Function
	virtual void draw() const;

	//Static Function

	//Operator Overload

	//Public Attribute

private:

	//Private Function

	//Private Attribute
	typedef unsigned ID; 
	ID mID;
	NodeType mTpye;
};