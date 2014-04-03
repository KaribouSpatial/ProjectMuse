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
class FacadeResources
{
public:
	
	//Typedef
	typedef std::unique_ptr<FacadeResources> Ptr;

	//Enum
	enum Models
	{
		Cube
	};


	//Constructor
	FacadeResources();

	//Destructor
	~FacadeResources();

	//R-only access

	//R-W access

	//Setters

	//Function
	void draw(Models);

	//Static Function

	//Operator Overload

	//Public Attribute

private:

	//Private Function

	//Private Attribute

};