/*
DATE:	10/28/2013
CODE:	by Breanna Henry
FILE:	"Pause.h"
PURP:	Pause menu screen
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/


#ifndef _PAUSE_H_
#define _PAUSE_H_

#include "../Screen Manager/Screen.h"
#include "../UI/UIButton.h"

class UIButton;

class Pause : public Screen, public UIButtonListener
{
public:
	Pause();
	~Pause();

	//Pure virtuals inherited from screen
    const char* getName();
    void update(double delta);
    void paint();

	//Mouse and Key events
	void keyDownEvent(int keyCode);
	void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
	void mouseLeftClickUpEvent(float positionX, float positionY);

protected:
	//Buttons action
	void buttonAction(UIButton* button);

private:
	//Variable for key selection
	int m_SelectedButton;

	//Background
	OpenGLTexture* m_PauseScreenBackgroundTexture;

	//Buttons
	UIButton* m_Resume;
	UIButton* m_Restart;
	UIButton* m_BackToSettings;
	UIButton* m_BackToMainMenu;
};

#endif