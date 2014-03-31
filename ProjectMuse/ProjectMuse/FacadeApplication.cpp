/////////////////////////////////////////////////////
/// 
/// 
/// 
/// 
/// 
/// 
/////////////////////////////////////////////////////

//Include My Code
#include "FacadeApplication.h"
#include "FacadeResources.h"
#include "FacadeView.h"
#include "FacadeScene.h"
#include "Application.h"

//Include Other

//Defines

//Const

//Static Prototyping
FacadeApplication* FacadeApplication::_instance = nullptr;

//Prototypes

//Class Definition

//Constructor
FacadeApplication::FacadeApplication()
{
	
}

void FacadeApplication::initialize()
{
	mFacadeView = std::unique_ptr<FacadeView>(new FacadeView);
	mApplication = std::unique_ptr<Application>(new Application);
	mFacadeResources = std::unique_ptr<FacadeResources>(new FacadeResources);
	mFacadeScene = std::unique_ptr<FacadeScene>(new FacadeScene);
}

//Destructor
FacadeApplication::~FacadeApplication()
{
	_instance = nullptr;
}

//Singleton specific
void FacadeApplication::erase()
{
	delete _instance;
}

FacadeApplication* FacadeApplication::Instance()
{
	if(_instance == nullptr)
	{
		_instance = new FacadeApplication();
		_instance->initialize();
	}
	return _instance;
}

//R-only access

//R-W access
FacadeResources* FacadeApplication::getFacadeResources()
{
	return mFacadeResources.get();
}

FacadeView* FacadeApplication::getFacadeView()
{
	return mFacadeView.get();
}

FacadeScene* FacadeApplication::getFacadeScene()
{
	return mFacadeScene.get();
}

//Setters
void FacadeApplication::setFacadeResources(unique(FacadeResources) facade)
{
	mFacadeResources = std::move(facade);
}

void FacadeApplication::setFacadeView(unique(FacadeView) facade)
{
	mFacadeView = std::move(facade);
}

void FacadeApplication::setFacadeScene(unique(FacadeScene) facade)
{
	mFacadeScene = std::move(facade);
}

//Function
void FacadeApplication::run()
{
	mApplication->run();
}
//Static Function

//Private Function

//Operator Overload