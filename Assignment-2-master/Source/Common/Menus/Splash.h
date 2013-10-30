/*
DATE:	10/28/2013
CODE:	by Breanna Henry
FILE:	"Splash.h"
PURP:	Splash menu screen
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/


#ifndef _SPLASH_H_
#define _SPLASH_H_

#include "../Screen Manager/Screen.h"
#include "../UI/UIButton.h"

class UIButton;

class Splash : public Screen, public UIButtonListener
{
public:
	Splash();
	~Splash();

	//Pure virtuals inherited from screen
    const char* getName();
    void update(double delta);
    void paint();

	//Mouse and Key events
	void keyDownEvent(int keyCode);
	void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
	void mouseLeftClickUpEvent(float positionX, float positionY);

protected:
	//Button actions
	void buttonAction(UIButton* button);

private:
	//Background
	OpenGLTexture* m_SplashScreenBackgroundTexture;

	//Buttons
	UIButton* m_PressSpace;
};

#endif