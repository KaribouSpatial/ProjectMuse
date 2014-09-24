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
}

//Destructor
FacadeView::~FacadeView()
{
}

//R-only access
const vec2i& FacadeView::getWindowSize() const
{
	return mProjection.getWindowSize();
}

const vec3& FacadeView::getCameraPosition() const
{
	return mCamera.getPosition();
}

//R-W access

//Setters

//Function
void FacadeView::renderView() const
{
	mProjection.applyProjection();
	mCamera.applyCamera();
}

void FacadeView::resize(int width, int height)
{
	mProjection.resize(width, height);
}

void FacadeView::rotateCamera(const vec2& coord)
{
	mCamera.rotateCamera(coord);
}

void FacadeView::moveCamera(const vec2& coord)
{
	mCamera.move(coord);
}

void FacadeView::flattenCamera()
{
	mCamera.flatten();
}
//Static Function

//Private Function

//Operator Overload