/*
DATE:	10/28/2013
CODE:	by Breanna Henry
FILE:	"GameOverP2.h"
PURP:	Game over screen, case player 2 wins
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/


#ifndef _GameOverP2_H_
#define _GameOverP2_H_

#include "../Screen Manager/Screen.h"
#include "../UI/UIButton.h"

class UIButton;

class GameOverP2 : public Screen, public UIButtonListener
{
public:
	GameOverP2();
	~GameOverP2();

	//Pure virtuals inherited from screen
    const char* getName();
    void update(double delta);
    void paint();

	//Mouse and Key events
	void keyDownEvent(int keyCode);
	void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
	void mouseLeftClickUpEvent(float positionX, float positionY);

protected:
	//Button Action
	void buttonAction(UIButton* button);

private:
	//Variable for key selection
	int m_SelectedButton;

	//Background
	OpenGLTexture* m_GameOverP2WinsBackgroundTexture;

	//Buttons
	UIButton* m_Replay;
	UIButton* m_ReturnMainMenu;
	UIButton* m_Exit;
};

#endif