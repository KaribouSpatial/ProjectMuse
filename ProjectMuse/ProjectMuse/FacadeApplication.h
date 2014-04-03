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

//Defines

//Const

//Prototypes

//Class Prototypes
class FacadeResources;
class FacadeView;
class FacadeScene;
class Application;

//Class Declaration
class FacadeApplication
{
public:
	//Singleton specific
	static FacadeApplication* Instance();
	void erase();

	//Constructor
	FacadeApplication();
	void initialize();

	//Destructor
	~FacadeApplication();

	//R-only access
	const vec2i& getPreviousMousePosition() const;
	const vec2i& getPreviousMouseClicPosition() const;

	//R-W access
	Application* getApplication();
	FacadeResources* getFacadeResources();
	FacadeView* getFacadeView();
	FacadeScene* getFacadeScene();


	//Setters

	//Function
	void run();
	
	//Static Function

	//Operator Overload

	//Public Attribute

private:

	//Private Function

	//Private Attribute
	std::unique_ptr<Application> mApplication;
	std::unique_ptr<FacadeResources> mFacadeResources;
	std::unique_ptr<FacadeView> mFacadeView;
	std::unique_ptr<FacadeScene> mFacadeScene;

	//Singleton specific
	static FacadeApplication* _instance;
};