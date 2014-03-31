/////////////////////////////////////////////////////
/// 
/// 
/// 
/// 
/// 
/// 
/////////////////////////////////////////////////////

//Include My Code
#include "FacadeView.h"
#include "Camera.h"
#include "Projection.h"

//Include Other

//Defines

//Const

//Static Prototyping

//Prototypes

//Class Definition

//Constructor
FacadeView::FacadeView()
{
	mCamera = std::unique_ptr<Camera>(new Camera);
	mProjection = std::unique_ptr<Projection>(new Projection);
}

//Destructor
FacadeView::~FacadeView()
{
}

//R-only access
const vec2i& FacadeView::getWindowSize() const
{
	return mProjection->getWindowSize();
}

//R-W access

//Setters

//Function
void FacadeView::applyView() const
{
	mProjection->applyProjection();
	mCamera->applyCamera();
}

void FacadeView::resize(int width, int height)
{
	mProjection->resize(width, height);
}
//Static Function

//Private Function

//Operator Overload