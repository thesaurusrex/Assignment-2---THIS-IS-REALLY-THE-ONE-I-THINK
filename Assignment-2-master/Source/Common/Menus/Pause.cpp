//SEE PAUSE.H

#include "../Game/Game.h"
#include "Pause.h"
#include "../Constants/Constants.h"
#include "../Input/Input.h"
#include "../Screen Manager/ScreenManager.h"
#include "../UI/UIButton.h"
#include "../OpenGL/OpenGL.h"


//CONSTRUCTOR-------------------------------------------------------
Pause::Pause() : 
		m_SelectedButton(0),
		m_Resume(NULL),
		m_Restart(NULL),
		m_BackToSettings(NULL),
		m_BackToMainMenu(NULL)
{
	//Create background texture
    m_PauseScreenBackgroundTexture = new OpenGLTexture("Pause_ScreenBG");

	//Create buttons
	m_Resume = new UIButton(PAUSE_RESUME);
	m_Restart = new UIButton(PAUSE_RESTART);
	m_BackToSettings = new UIButton(PAUSE_GOBACK_SETTINGS);
	m_BackToMainMenu = new UIButton(PAUSE_GOBACK_MAINMENU);

	//Place buttons on screen
	m_Resume->setCenterPosition(getWidth() / 1.3f, getHeight() * PAUSE_RESUME_Y_PERCENTAGE);
	m_Restart->setCenterPosition(getWidth() / 1.3f, getHeight() * PAUSE_RESTART_Y_PERCENTAGE);
	m_BackToSettings->setCenterPosition(getWidth() / 1.3f, getHeight() * PAUSE_GOBACK_SETTINGS_Y_PERCENTAGE);
	m_BackToMainMenu->setCenterPosition(getWidth() / 1.3f, getHeight() * PAUSE_GOBACK_MAINMENU_Y_PERCENTAGE);

	//Set up button listener
	m_Resume->setListener(this);
	m_Restart->setListener(this);
	m_BackToSettings->setListener(this);
	m_BackToMainMenu->setListener(this);
}

//DESTRUCTOR--------------------------------------------------------
Pause::~Pause()
{
	//Remove Buttons
	if(m_Resume != NULL)
	{
		delete m_Resume;
		m_Resume = NULL;
	}

	if(m_Restart != NULL)
	{
		delete m_Restart;
		m_Restart = NULL;
	}

	if(m_BackToSettings != NULL)
	{
		delete m_BackToSettings;
		m_BackToSettings = NULL;
	}

	if(m_BackToMainMenu != NULL)
	{
		delete m_BackToMainMenu;
		m_BackToMainMenu = NULL;
	}

	//Remove Background
	if(m_PauseScreenBackgroundTexture != NULL)
	{
		delete m_PauseScreenBackgroundTexture;
		m_PauseScreenBackgroundTexture = NULL;
	}
}

//GET NAME----------------------------------------------------------
const char* Pause::getName()
{
	return PAUSE_SCREEN_NAME;
}

//UPDATE------------------------------------------------------------
void Pause::update(double delta)
{

}

//PAINT-------------------------------------------------------------
void Pause::paint()
{
	//Paint Background
	OpenGLRenderer::getInstance()->drawTexture(m_PauseScreenBackgroundTexture, 0.0f, 0.0f);

	//Paint Buttons
	m_Resume->paint();
	m_Restart->paint();
	m_BackToSettings->paint();
	m_BackToMainMenu->paint();
}

//KEY DOWN EVENT - Key events---------------------------------------
void Pause::keyDownEvent(int keyCode)
{
	//Down arrow
	if(keyCode == KEYCODE_DOWN_ARROW)
	{
		switch(m_SelectedButton)
		{
			case 0:
				m_BackToMainMenu->setIsSelected(false);
				m_Resume->setIsSelected(true);
				m_SelectedButton++;
				break;
			case 1:
				m_Resume->setIsSelected(false);
				m_Restart->setIsSelected(true);
				m_SelectedButton++;
				break;
			case 2:
				m_Restart->setIsSelected(false);
				m_BackToSettings->setIsSelected(true);
				m_SelectedButton++;
				break;
			case 3:
				m_BackToSettings->setIsSelected(false);
				m_BackToMainMenu->setIsSelected(true);
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
				ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
				break;
			case 2:
				ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
				break;
			case 3:
				ScreenManager::getInstance()->switchScreen(GAMESETTINGS_SCREEN_NAME);
				break;
			case 0:
				ScreenManager::getInstance()->switchScreen(MAINMENU_SCREEN_NAME);
				break;
		}
	}
}

//MOUSE MOVEMENT EVENT - Mouseover events---------------------------
void Pause::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
	m_Resume->mouseMovementEvent(positionX, positionY);
	m_Restart->mouseMovementEvent(positionX, positionY);
	m_BackToSettings->mouseMovementEvent(positionX, positionY);
	m_BackToMainMenu->mouseMovementEvent(positionX, positionY);
}

//MOUSE LEFT CLICK UP EVENT - Finish left click---------------------
void Pause::mouseLeftClickUpEvent(float positionX, float positionY)
{
	m_Resume->mouseLeftClickUpEvent(positionX, positionY);
	m_Restart->mouseLeftClickUpEvent(positionX, positionY);
	m_BackToSettings->mouseLeftClickUpEvent(positionX, positionY);
	m_BackToMainMenu->mouseLeftClickUpEvent(positionX, positionY);
}

//BUTTON ACTION - Click events--------------------------------------
void Pause::buttonAction(UIButton* button)
{
	//RESUME -> continues game
	if(button == m_Resume)
	{
		ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
	}

	//RESTART -> restarts game with same settings
	if(button == m_Restart)
	{
		//Get game object
		Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);

		//Reset the game with settings
		game->reset();

		ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
	}

	//BACK TO SETTINGS -> goes back to settings, theres no return to pause
	if(button == m_BackToSettings)
	{
		//if one player game
		ScreenManager::getInstance()->switchScreen(GAMESETTINGS_SCREEN_NAME);
		//if two player game
	}

	//BACK TO MAIN MENU -> goes back to main menu
	if(button == m_BackToMainMenu)
	{
		//call game over?
		ScreenManager::getInstance()->switchScreen(MAINMENU_SCREEN_NAME);
	}
}