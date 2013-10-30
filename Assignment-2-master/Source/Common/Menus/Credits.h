/*
DATE:	10/28/2013
CODE:	by Breanna Henry
FILE:	"Credits.h"
PURP:	Credits menu screen
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/


#ifndef _CREDITS_H_
#define _CREDITS_H_

#include "../Screen Manager/Screen.h"
#include "../UI/UIButton.h"

class UIButton;

class Credits : public Screen, public UIButtonListener
{
public:
	Credits();
	~Credits();

	//Pure virtuals inherited from screen
    const char* getName();
    void update(double delta);
    void paint();

	//Mouse and Key events
	void keyDownEvent(int keyCode);
	void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
	void mouseLeftClickUpEvent(float positionX, float positionY);

protected:
	//Button action
	void buttonAction(UIButton* button);

private:
	//Variable for key selection
	int m_SelectedButton;

	//Background
	OpenGLTexture* m_CreditsBackgroundTexture;

	//Buttons
	UIButton* m_Select_Exit;
    UIButton* m_Select_Go_Back;
};

#endif