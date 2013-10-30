/*
DATE:	10/28/2013
CODE:	by Breanna Henry
FILE:	"GameSettingsTwos.h"
PURP:	Two player game settings screen
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/

#ifndef _GAMESETTINGSTWOS_H_
#define _GAMESETTINGSTWOS_H_

#include "../Screen Manager/Screen.h"
#include "../UI/UIButton.h"

class UIButton;

class GameSettingsTwos : public Screen, public UIButtonListener
{
public:
	GameSettingsTwos();
	~GameSettingsTwos();

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
	OpenGLTexture* m_GameSettingsTwosBackgroundTexture;

	//Buttons
	UIButton* m_Twos_ScoreLimit_Low;
	UIButton* m_Twos_ScoreLimit_Mid;
	UIButton* m_Twos_ScoreLimit_None;
	UIButton* m_Twos_TimeLimit_Low;
	UIButton* m_Twos_TimeLimit_Mid;
	UIButton* m_Twos_TimeLimit_None;
	UIButton* m_P1_ControlSelect_Mouse;
	UIButton* m_P1_ControlSelect_Keys;
	UIButton* m_P2_ControlSelect_Mouse;
	UIButton* m_P2_ControlSelect_Keys;
	UIButton* m_Twos_Start;
	UIButton* m_Twos_GoBack;
};

#endif