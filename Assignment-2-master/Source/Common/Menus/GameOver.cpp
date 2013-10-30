//SEE GAMEOVER.H


#include "GameOver.h"
#include "../Constants/Constants.h"
#include "../Input/Input.h"
#include "../Screen Manager/ScreenManager.h"
#include "../UI/UIButton.h"
#include "../OpenGL/OpenGL.h"


//CONSTRUCTOR------------------------------------------
GameOver::GameOver() : 
			m_Replay(NULL),
			m_ReturnMainMenu(NULL),
			m_Exit(NULL),
			m_SelectedButton(0)
{
	//Create background texture
    m_GameOverP1WinsBackgroundTexture = new OpenGLTexture("GameOver_P1Wins_ScreenBG");

	//Create buttons
	m_Replay = new UIButton(GAMEOVER_REPLAY);
	m_ReturnMainMenu = new UIButton(GAMEOVER_RETURN);
	m_Exit = new UIButton(GAMEOVER_EXIT);

	//Place buttons on screen
	m_Replay->setCenterPosition(getWidth() / 4.0f, getHeight() * GAMEOVER_REPLAY_Y_PERCENTAGE);
	m_ReturnMainMenu->setCenterPosition(getWidth() / 2.0f, getHeight() * GAMEOVER_RETURN_Y_PERCENTAGE);
	m_Exit->setCenterPosition(getWidth() / 1.3f, getHeight() * GAMEOVER_EXIT_Y_PERCENTAGE);

	//Set up button listener
	m_Replay->setListener(this);
	m_ReturnMainMenu->setListener(this);
	m_Exit->setListener(this);
}

//DESTRUCTOR-------------------------------------------
GameOver::~GameOver()
{
	//Remove Buttons
	if(m_Replay != NULL)
	{
		delete m_Replay;
		m_Replay = NULL;
	}

	if(m_ReturnMainMenu != NULL)
	{
		delete m_ReturnMainMenu;
		m_ReturnMainMenu = NULL;
	}

	if(m_Exit != NULL)
	{
		delete m_Exit;
		m_Exit = NULL;
	}

	//Remove Background
	if(m_GameOverP1WinsBackgroundTexture != NULL)
	{
		delete m_GameOverP1WinsBackgroundTexture;
		m_GameOverP1WinsBackgroundTexture = NULL;
	}
}

//GET NAME---------------------------------------------
const char* GameOver::getName()
{
	return GAMEOVER_SCREEN_NAME;
}

//UPDATE-----------------------------------------------
void GameOver::update(double delta)
{

}

//PAINT------------------------------------------------
void GameOver::paint()
{
	//Paint BG
	OpenGLRenderer::getInstance()->drawTexture(m_GameOverP1WinsBackgroundTexture, 0.0f, 0.0f);
	
	//Paint buttons
	m_Replay->paint();
	m_ReturnMainMenu->paint();
	m_Exit->paint();
}

//KEY DOWN EVENT - Key events--------------------------
void GameOver::keyDownEvent(int keyCode)
{
	//right arrow
	if(keyCode == KEYCODE_RIGHT_ARROW)
	{
		switch(m_SelectedButton)
		{
		case 0:
			m_Replay->setIsSelected(true);
			m_Exit->setIsSelected(false);
			m_SelectedButton++;
			break;
		case 1:
			m_ReturnMainMenu->setIsSelected(true);
			m_Replay->setIsSelected(false);
			m_SelectedButton++;
			break;
		case 2:
			m_ReturnMainMenu->setIsSelected(false);
			m_Exit->setIsSelected(true);
			m_SelectedButton = 0;
		}
	}

	//enter key
	if(keyCode == KEYCODE_RETURN)
	{
		switch(m_SelectedButton)
		{
			case 0:
				exit(1);
				break;
			case 1:
				ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
				break;
			case 2:
				ScreenManager::getInstance()->switchScreen(MAINMENU_SCREEN_NAME);
				break;
		}
	}
}

//MOUSE MOVEMENT EVENT - Mouseover Events--------------
void GameOver::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
	m_Replay->mouseMovementEvent(positionX, positionY);
	m_ReturnMainMenu->mouseMovementEvent(positionX, positionY);
	m_Exit->mouseMovementEvent(positionX, positionY);
}

//MOUSE LEFT CLICK UP EVENT - Finish left click--------
void GameOver::mouseLeftClickUpEvent(float positionX, float positionY)
{
	m_Replay->mouseLeftClickUpEvent(positionX, positionY);
	m_ReturnMainMenu->mouseLeftClickUpEvent(positionX, positionY);
	m_Exit->mouseLeftClickUpEvent(positionX, positionY);
}

//BUTTON ACTION - Click events-------------------------
void GameOver::buttonAction(UIButton* button)
{
	//REPLAY
	if(button == m_Replay)
	{
		ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
	}

	//RETURN
	if(button == m_ReturnMainMenu)
	{
		ScreenManager::getInstance()->switchScreen(MAINMENU_SCREEN_NAME);
	}

	//EXIT
	if(button == m_Exit)
	{
		exit(1);
	}
}