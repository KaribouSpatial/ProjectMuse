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
#include <Vector.hpp>

//Include Other
#include <memory>

//Defines
#define unique(x) std::unique_ptr<x>

//Const

//Prototypes

//Class Prototypes
class Camera;
class Projection;

//Class Declaration
class FacadeView
{
public:

	//Constructor
	FacadeView();

	//Destructor
	~FacadeView();

	//R-only access
	const vec2i& getWindowSize() const;

	//R-W access

	//Setters

	//Function
	void applyView() const;
	void resize(int x, int y);
	void rotateCamera(const vec2& coord);

	//Static Function

	//Operator Overload

	//Public Attribute

private:

	//Private Function

	//Private Attribute
	unique(Camera) mCamera;
	unique(Projection) mProjection;
};