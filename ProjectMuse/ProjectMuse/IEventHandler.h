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
__interface IEventHandler
{
	virtual bool processKeyboard(unsigned char touche, bool state, int x, int y) = 0;
	virtual bool processSpecKeyboard(int touche, bool state, int x, int y) = 0;
	virtual bool processMouseClic(int button, int state, int x, int y) = 0;
	virtual bool processMouseDrag(int x, int y) = 0;
	virtual bool processMouseMove(int x, int y) = 0;
	virtual void handleRealTime(const double& dt) = 0;

	/*
	//.h
	virtual bool processKeyboard(unsigned char touche, bool state, int x, int y) override;
	virtual bool processSpecKeyboard(int touche, bool state, int x, int y) override;
	virtual bool processMouseClic(int button, int state, int x, int y) override;
	virtual bool processMouseDrag(int x, int y) override;
	virtual bool processMouseMove(int x, int y) override;
	virtual void handleRealTime(const double& dt) override;

	bool processKeyboard(unsigned char touche, bool state, int x, int y) override;
	bool processSpecKeyboard(int touche, bool state, int x, int y) override;
	bool processMouseClic(int button, int state, int x, int y) override;
	bool processMouseDrag(int x, int y) override;
	bool processMouseMove(int x, int y) override;
	void handleRealTime(const double& dt) override;
	
	//.cpp
	bool classname::processKeyboard(unsigned char touche, bool state, int x, int y)
	{
	}
	bool classname::processSpecKeyboard(int touche, bool state, int x, int y)
	{
	}
	bool classname::processMouseClic(int button, int state, int x, int y)
	{
	}
	bool classname::processMouseDrag(int x, int y)
	{
	}
	bool classname::processMouseMove(int x, int y)
	{
	}
	void classname::handleRealTime(const double& dt)
	{
	}
	*/
};