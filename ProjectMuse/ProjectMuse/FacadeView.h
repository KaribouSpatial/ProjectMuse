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
#include "Camera.h"
#include "Projection.h"
#include "Vector.hpp"

//Include Other
#include <memory>

//Defines

//Const

//Prototypes

//Class Prototypes

//Class Declaration
class FacadeView
{
public:

	//Typedef
	typedef std::unique_ptr<FacadeView> Ptr;

	//Constructor
	FacadeView();

	//Destructor
	~FacadeView();

	//R-only access
	const vec2i& getWindowSize() const;

	//R-W access

	//Setters

	//Function
	void renderView() const;
	void resize(int x, int y);
	void rotateCamera(const vec2& coord);
	void moveCamera(const vec2& coord);
	void flattenCamera();

	//Static Function

	//Operator Overload

	//Public Attribute

private:

	//Private Function

	//Private Attribute
	Camera mCamera;
	Projection mProjection;
};