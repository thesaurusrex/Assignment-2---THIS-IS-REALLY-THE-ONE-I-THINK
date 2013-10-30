/*
DATE:	10/28/2013
CODE:	by Breanna Henry
FILE:	"MainMenu.h"
PURP:	Main Menu screen
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/


#ifndef _MAINMENU_H_
#define _MAINMENU_H_

#include "../Screen Manager/Screen.h"
#include "../UI/UIButton.h"

class UIButton;

class MainMenu : public Screen, public UIButtonListener
{
public:
	MainMenu();
	~MainMenu();

	//Pure virtuals inherited from screen
    const char* getName();
    void update(double delta);
    void paint();

	//Mouse and Key events
	void keyDownEvent(int keyCode);
	void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
	void mouseLeftClickUpEvent(float positionX, float positionY);

protected:
	//Button events
	void buttonAction(UIButton* button);

private:
	//Variable used for key selection
	int m_SelectedButton;

	//Background
	OpenGLTexture* m_MainMenuBackgroundTexture;

	//Buttons
	UIButton* m_Select_One_Player;
    UIButton* m_Select_Two_Player;
    UIButton* m_Select_Credits;
    UIButton* m_Select_Exit;

	//I attempted to use an array for creating the buttons
	//but ended up sticking with my hideous, non pragmatic style
	UIButton* arrayButtons[4];

	//Vector to hold the goddamn buttons that i also attempted and failed
    std::vector<UIButton*> m_UIButtons;
};

#endif