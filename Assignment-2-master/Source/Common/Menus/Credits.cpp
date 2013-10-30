//SEE CREDITS.H

#include "Credits.h"
#include "Splash.h"
#include "../Constants/Constants.h"
#include "../Input/Input.h"
#include "../Screen Manager/ScreenManager.h"
#include "../UI/UIButton.h"
#include "../OpenGL/OpenGL.h"

//CONSTRUCTOR-------------------------------------------------------
Credits::Credits() : 
		m_SelectedButton(0),
		m_Select_Exit(NULL), 
		m_Select_Go_Back(NULL)
{
	//Create background texture
    m_CreditsBackgroundTexture = new OpenGLTexture("Credits_ScreenBG");

	//Create buttons
	m_Select_Go_Back = new UIButton(CREDITS_SELECT_GOBACK); //BACK
	m_Select_Exit = new UIButton(CREDITS_SELECT_EXIT); //EXIT

	//Place buttons on screen
	m_Select_Go_Back->setCenterPosition(getWidth() / 2.0f, getHeight() * CREDITS_SELECT_GOBACK_Y_PERCENTAGE); //BACK
	m_Select_Exit->setCenterPosition(getWidth() / 2.0f, getHeight() * CREDITS_SELECT_EXIT_Y_PERCENTAGE); //EXIT

	//Set up button listener
	m_Select_Go_Back->setListener(this); //BACK
	m_Select_Exit->setListener(this); //EXIT
}

//DESTRUCTOR--------------------------------------------------------
Credits::~Credits()
{
	//REMOVE BUTTONS
	if(m_Select_Go_Back != NULL)
	{
		delete m_Select_Go_Back;
		m_Select_Go_Back = NULL;
	}

	if(m_Select_Exit != NULL)
	{
		delete m_Select_Exit;
		m_Select_Exit = NULL;
	}

	//REMOVE BACKGROUND
	if(m_CreditsBackgroundTexture != NULL)
	{
		delete m_CreditsBackgroundTexture;
		m_CreditsBackgroundTexture = NULL;
	}

}

//GET NAME----------------------------------------------------------
const char* Credits::getName()
{
	return CREDITS_SCREEN_NAME;
}

//UPDATE------------------------------------------------------------
void Credits::update(double delta)
{

}

//PAINT-------------------------------------------------------------
void Credits::paint()
{
	//Paint Background
    OpenGLRenderer::getInstance()->drawTexture(m_CreditsBackgroundTexture, 0.0f, 0.0f);

	//Paint Buttons
	m_Select_Go_Back->paint(); //BACK
	m_Select_Exit->paint(); //EXIT
}

//KEY DOWN EVENT - Key events---------------------------------------
void Credits::keyDownEvent(int keyCode)
{
	//down arrow
	if(keyCode == KEYCODE_DOWN_ARROW)
	{
		switch(m_SelectedButton)
		{
			case 0:
				m_Select_Exit->setIsSelected(false);
				m_Select_Go_Back->setIsSelected(true);
				m_SelectedButton++;
				break;
			case 1:
				m_Select_Exit->setIsSelected(true);
				m_Select_Go_Back->setIsSelected(false);
				m_SelectedButton = 0;
				break;
		}
	}

	//enter key
	if(keyCode == KEYCODE_RETURN)
	{
		switch(m_SelectedButton)
		{
			case 1:
				ScreenManager::getInstance()->switchScreen(MAINMENU_SCREEN_NAME);
				break;
			case 0:
				exit(1);
				break;
		}
	}
}

//MOUSE MOVEMENT EVENT - Mouseover events---------------------------
void Credits::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
	m_Select_Go_Back->mouseMovementEvent(positionX, positionY); //BACK
	m_Select_Exit->mouseMovementEvent(positionX, positionY); //EXIT
}

//MOUSE LEFT CLICK UP EVENT - Finish left click---------------------
void Credits::mouseLeftClickUpEvent(float positionX, float positionY)
{
	m_Select_Go_Back->mouseLeftClickUpEvent(positionX, positionY); //Back
	m_Select_Exit->mouseLeftClickUpEvent(positionX, positionY); //EXIT
}

//BUTTON ACTION - Click events--------------------------------------
void Credits::buttonAction(UIButton* button)
{
	//GO BACK CLICKED -> main menu screen
    if(button == m_Select_Go_Back)
	{
		ScreenManager::getInstance()->switchScreen(MAINMENU_SCREEN_NAME);
	}

	//EXIT CLICKED -> exits game
    if(button == m_Select_Exit)
	{
		exit(1);
	}
}