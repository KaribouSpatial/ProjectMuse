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

//Defines

//Const

//Prototypes

//Class Prototypes

//Class Declaration
class NoCopy
{
protected:
	//Constructor
	NoCopy()
	{
	};

private:
	//Disable copy
	NoCopy(const NoCopy&);
	NoCopy& operator=(const NoCopy&);
};