//SEE MAINMENU.H

#include "../Game/Game.h"
#include "MainMenu.h"
#include "Splash.h"
#include "../Constants/Constants.h"
#include "../Input/Input.h"
#include "../Screen Manager/ScreenManager.h"
#include "../UI/UIButton.h"
#include "../OpenGL/OpenGL.h"


//CONSTRUCTOR---------------------------------------------------------
MainMenu::MainMenu() :
	m_SelectedButton(0),
    m_Select_One_Player(NULL),
    m_Select_Two_Player(NULL),
    m_Select_Credits(NULL),
    m_Select_Exit(NULL)
{
	//Array of goddamn buttons?
	arrayButtons[0] = m_Select_One_Player;
	arrayButtons[1] = m_Select_Two_Player;
	arrayButtons[2] = m_Select_Credits;
	arrayButtons[3] = m_Select_Exit;

	//Create background texture
    m_MainMenuBackgroundTexture = new OpenGLTexture("MainMenu_ScreenBG");

	//Create buttons
	m_Select_One_Player = new UIButton(MAINMENU_SELECT_ONE_PLAYER); //1P
	m_Select_Two_Player = new UIButton(MAINMENU_SELECT_TWO_PLAYER); //2P
	m_Select_Credits = new UIButton(MAINMENU_SELECT_CREDITS); //CRED
	m_Select_Exit = new UIButton(MAINMENU_SELECT_EXIT); //EXIT

	//Place buttons on screen
	m_Select_One_Player->setCenterPosition(getWidth() / 2.0f, getHeight() * MAINMENU_SELECT_ONE_PLAYER_Y_PERCENTAGE); //1P
	m_Select_Two_Player->setCenterPosition(getWidth() / 2.0f, getHeight() * MAINMENU_SELECT_TWO_PLAYER_Y_PERCENTAGE); //2P
	m_Select_Credits->setCenterPosition(getWidth() / 2.0f, getHeight() * MAINMENU_SELECT_CREDITS_Y_PERCENTAGE); //CRED
	m_Select_Exit->setCenterPosition(getWidth() / 2.0f, getHeight() * MAINMENU_SELECT_EXIT_Y_PERCENTAGE); //EXIT

	//Set up button listener
	//if I used the array...??
	//arrayButtons->setListener(this);
	m_Select_One_Player->setListener(this); //1P
	m_Select_Two_Player->setListener(this); //2P
	m_Select_Credits->setListener(this); //CRED
	m_Select_Exit->setListener(this); //EXIT
}

//DESTRUCTOR----------------------------------------------------------
MainMenu::~MainMenu()
{
    //REMOVE BUTTONS
	//Array??
	//if(arrayButtons != NULL) ????
	if(m_Select_One_Player != NULL)
	{
		delete m_Select_One_Player;
		m_Select_One_Player = NULL;
	}

	if(m_Select_Two_Player != NULL)
	{
		delete m_Select_Two_Player;
		m_Select_Two_Player = NULL;
	}

	if(m_Select_Credits != NULL)
	{
		delete m_Select_Credits;
		m_Select_Credits = NULL;
	}

	if(m_Select_Exit != NULL)
	{
		delete m_Select_Exit;
		m_Select_Exit = NULL;
	}

	//REMOVE BACKGROUND
	if(m_MainMenuBackgroundTexture != NULL)
	{
		delete m_MainMenuBackgroundTexture;
		m_MainMenuBackgroundTexture = NULL;
	}
}

//GET NAME------------------------------------------------------------
const char* MainMenu::getName()
{
    return MAINMENU_SCREEN_NAME;
}

//UPDATE--------------------------------------------------------------
void MainMenu::update(double delta)
{
    
}

//PAINT---------------------------------------------------------------
void MainMenu::paint()
{
	//Paint Background
    OpenGLRenderer::getInstance()->drawTexture(m_MainMenuBackgroundTexture, 0.0f, 0.0f);

	//Paint Buttons
	m_Select_One_Player->paint();
	m_Select_Two_Player->paint(); 
	m_Select_Credits->paint(); 
	m_Select_Exit->paint(); 
}

//KEY DOWN EVENT - Key events-----------------------------------------
void MainMenu::keyDownEvent(int keyCode)
{
	//down arrow key
	if(keyCode == KEYCODE_DOWN_ARROW)
	{
		switch(m_SelectedButton)
		{
			case 0:
				m_Select_Exit->setIsSelected(false);
				m_Select_One_Player->setIsSelected(true);
				m_SelectedButton++;
				break;
			case 1:
				m_Select_One_Player->setIsSelected(false);
				m_Select_Two_Player->setIsSelected(true);
				m_SelectedButton++;
				break;
			case 2:
				m_Select_Two_Player->setIsSelected(false);
				m_Select_Credits->setIsSelected(true);
				m_SelectedButton++;
				break;
			case 3:
				m_Select_Credits->setIsSelected(false);
				m_Select_Exit->setIsSelected(true);
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
				ScreenManager::getInstance()->switchScreen(GAMESETTINGS_SCREEN_NAME);
				break;
			case 2:
				TWO_PLAYER_GAME = true;
				ScreenManager::getInstance()->switchScreen(GAMESETTINGS_TWOS_SCREEN_NAME);
				break;
			case 3:
				ScreenManager::getInstance()->switchScreen(CREDITS_SCREEN_NAME);
				break;
			case 0:
				exit(1);
				break;
		}
	}
}

//MOUSE MOVEMENT EVENT - Mouseover events-----------------------------
void MainMenu::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
    m_Select_One_Player->mouseMovementEvent(positionX, positionY); //1P
	m_Select_Two_Player->mouseMovementEvent(positionX, positionY); //2P
	m_Select_Credits->mouseMovementEvent(positionX, positionY); //CRED
	m_Select_Exit->mouseMovementEvent(positionX, positionY); //EXIT
}

//MOUSE LEFT CLICK UP EVENT - Finish left click-----------------------
void MainMenu::mouseLeftClickUpEvent(float positionX, float positionY)
{
    m_Select_One_Player->mouseLeftClickUpEvent(positionX, positionY); //1P
	m_Select_Two_Player->mouseLeftClickUpEvent(positionX, positionY); //2P
	m_Select_Credits->mouseLeftClickUpEvent(positionX, positionY); //CRED
	m_Select_Exit->mouseLeftClickUpEvent(positionX, positionY); //EXIT
}

//BUTTON ACTION - Click events----------------------------------------
void MainMenu::buttonAction(UIButton* button)
{
	//SINGLE PLAYER CLICKED -> single player game settings
    if(button == m_Select_One_Player)
	{
		ScreenManager::getInstance()->switchScreen(GAMESETTINGS_SCREEN_NAME);
	}

	//TWO PLAYER CLICKED -> two player game settings
    if(button == m_Select_Two_Player)
	{
		TWO_PLAYER_GAME = true;
		//Get game object
		Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);

		//Reset the game with settings
		game->reset();
		ScreenManager::getInstance()->switchScreen(GAMESETTINGS_TWOS_SCREEN_NAME);
	}

	//CREDITS CLICKED -> credit screen
    if(button == m_Select_Credits)
	{
		ScreenManager::getInstance()->switchScreen(CREDITS_SCREEN_NAME);
	}

	//EXIT CLICKED -> exit game
    if(button == m_Select_Exit)
	{
		exit(1);
	}
}