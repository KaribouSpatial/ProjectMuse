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
class SceneNode;

//Class Declaration
class FacadeScene
{
public:

	//Typedef
	typedef std::unique_ptr<FacadeScene> Ptr;

	//Constructor
	FacadeScene();

	//Destructor
	~FacadeScene();

	//R-only access

	//R-W access

	//Setters

	//Function
	void renderScene() const;
	void updateScene(const double& dt);

	//Static Function

	//Operator Overload

	//Public Attribute

private:

	//Private Function
	void initializeScene();

	//Private Attribute
	std::unique_ptr<SceneNode> mScene;
};