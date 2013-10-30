/*
DATE:	10/28/2013
CODE:	by Breanna Henry
FILE:	"GameSettings.h"
PURP:	Single player game setttings screen
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/


#ifndef _GAMESETTINGS_H_
#define _GAMESETTINGS_H_

#include "../Screen Manager/Screen.h"
#include "../UI/UIButton.h"

class UIButton;

class GameSettings : public Screen, public UIButtonListener
{
public:
	GameSettings();
	~GameSettings();

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
	OpenGLTexture* m_GameSettingsBackgroundTexture;

	//Buttons
	UIButton* m_ScoreLimit_Low;
	UIButton* m_ScoreLimit_Mid;
	UIButton* m_ScoreLimit_None;
	UIButton* m_TimeLimit_Low;
	UIButton* m_TimeLimit_Mid;
	UIButton* m_TimeLimit_None;
	UIButton* m_Difficulty_Low;
	UIButton* m_Difficulty_Mid;
	UIButton* m_Difficulty_High;
	UIButton* m_ControlSelect_Mouse;
	UIButton* m_ControlSelect_Keys;
	UIButton* m_Select_Start;
	UIButton* m_Select_GoBack;
};

#endif