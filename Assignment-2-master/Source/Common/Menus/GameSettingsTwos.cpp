//SEE GAMESETTINGSTWOS.H

#include "GameSettingsTwos.h"
#include "Splash.h"
#include "../Game/Game.h"
#include "../Constants/Constants.h"
#include "../Input/Input.h"
#include "../Screen Manager/ScreenManager.h"
#include "../UI/UIButton.h"
#include "../OpenGL/OpenGL.h"


//CONSTRUCTOR-------------------------------------------------------
GameSettingsTwos::GameSettingsTwos() :
					m_SelectedButton(0),
					m_Twos_ScoreLimit_Low(NULL),
					m_Twos_ScoreLimit_Mid(NULL),
					m_Twos_ScoreLimit_None(NULL),
					m_Twos_TimeLimit_Low(NULL),
					m_Twos_TimeLimit_Mid(NULL),
					m_Twos_TimeLimit_None(NULL),
					m_P1_ControlSelect_Mouse(NULL),
					m_P1_ControlSelect_Keys(NULL),
					m_P2_ControlSelect_Mouse(NULL),
					m_P2_ControlSelect_Keys(NULL),
					m_Twos_Start(NULL),
					m_Twos_GoBack(NULL)
{
	//Create background texture
    m_GameSettingsTwosBackgroundTexture = new OpenGLTexture("GameSettingsTwos_ScreenBG");

	//Create buttons
	m_Twos_Start = new UIButton(GAMESETTINGS_TWOS_SELECT_START); //START
	m_Twos_GoBack = new UIButton(GAMESETTINGS_TWOS_SELECT_GOBACK); //BACK
	m_Twos_ScoreLimit_Low = new UIButton(GAMESETTINGS_TWOS_SCORELIMIT_LOW); //score
	m_Twos_ScoreLimit_Mid = new UIButton(GAMESETTINGS_TWOS_SCORELIMIT_MID);
	m_Twos_ScoreLimit_None = new UIButton(GAMESETTINGS_TWOS_SCORELIMIT_NONE);
	m_Twos_TimeLimit_Low = new UIButton(GAMESETTINGS_TWOS_TIMELIMIT_LOW); //time
	m_Twos_TimeLimit_Mid = new UIButton(GAMESETTINGS_TWOS_TIMELIMIT_MID);
	m_Twos_TimeLimit_None = new UIButton(GAMESETTINGS_TWOS_TIMELIMIT_NONE);
	m_P1_ControlSelect_Mouse = new UIButton(GAMESETTINGS_TWOS_P1_CONTROLSELECT_MOUSE); //controls
	m_P1_ControlSelect_Keys = new UIButton(GAMESETTINGS_TWOS_P1_CONTROLSELECT_KEYS);
	m_P2_ControlSelect_Mouse = new UIButton(GAMESETTINGS_TWOS_P2_CONTROLSELECT_MOUSE);
	m_P2_ControlSelect_Keys = new UIButton(GAMESETTINGS_TWOS_P2_CONTROLSELECT_KEYS);

	//Place buttons on screen
	m_Twos_Start->setCenterPosition(getWidth() / 1.7f, getHeight() * GAMESETTINGS_TWOS_SELECT_START_Y_PERCENTAGE); //START
	m_Twos_GoBack->setCenterPosition(getWidth() / 2.8f, getHeight() * GAMESETTINGS_TWOS_SELECT_GOBACK_Y_PERCENTAGE); //BACK

	m_Twos_ScoreLimit_Low->setCenterPosition(getWidth() / 1.32f, getHeight() * GAMESETTINGS_TWOS_SCORELIMIT_LOW_Y_PERCENTAGE); //scores
	m_Twos_ScoreLimit_Mid->setCenterPosition(getWidth() / 1.32f, getHeight() * GAMESETTINGS_TWOS_SCORELIMIT_MID_Y_PERCENTAGE);
	m_Twos_ScoreLimit_None->setCenterPosition(getWidth() / 1.32f, getHeight() * GAMESETTINGS_TWOS_SCORELIMIT_NONE_Y_PERCENTAGE);

	m_Twos_TimeLimit_Low->setCenterPosition(getWidth() / 4.6f, getHeight() * GAMESETTINGS_TWOS_TIMELIMIT_LOW_Y_PERCENTAGE); //times
	m_Twos_TimeLimit_Mid->setCenterPosition(getWidth() / 4.6f, getHeight() * GAMESETTINGS_TWOS_TIMELIMIT_MID_Y_PERCENTAGE);
	m_Twos_TimeLimit_None->setCenterPosition(getWidth() / 4.6f, getHeight() * GAMESETTINGS_TWOS_TIMELIMIT_NONE_Y_PERCENTAGE);

	m_P1_ControlSelect_Mouse->setCenterPosition(getWidth() / 4.6f, getHeight() * GAMESETTINGS_TWOS_P1_CONTROLSELECT_MOUSE_Y_PERCENTAGE); //p1 controls
	m_P1_ControlSelect_Keys->setCenterPosition(getWidth() / 4.6f, getHeight() * GAMESETTINGS_TWOS_P1_CONTROLSELECT_KEYS_Y_PERCENTAGE);

	m_P2_ControlSelect_Mouse->setCenterPosition(getWidth() / 1.32f, getHeight() * GAMESETTINGS_TWOS_P2_CONTROLSELECT_MOUSE_Y_PERCENTAGE); //p2 controls
	m_P2_ControlSelect_Keys->setCenterPosition(getWidth() / 1.32f, getHeight() * GAMESETTINGS_TWOS_P2_CONTROLSELECT_KEYS_Y_PERCENTAGE);

	//Set up button listener
	m_Twos_Start->setListener(this); //START
	m_Twos_GoBack->setListener(this); //BACK
	m_Twos_ScoreLimit_Low->setListener(this); //scores 
	m_Twos_ScoreLimit_Mid->setListener(this); 
	m_Twos_ScoreLimit_None->setListener(this); 
	m_Twos_TimeLimit_Low->setListener(this); //time
	m_Twos_TimeLimit_Mid->setListener(this); 
	m_Twos_TimeLimit_None->setListener(this); 
	m_P1_ControlSelect_Mouse->setListener(this); //controls
	m_P1_ControlSelect_Keys->setListener(this); 
	m_P2_ControlSelect_Mouse->setListener(this); 
	m_P2_ControlSelect_Keys->setListener(this); 
}

//DESTRUCTOR--------------------------------------------------------
GameSettingsTwos::~GameSettingsTwos()
{
	//REMOVE BUTTONS
	//PROBOBOLY SHOULD HAVE WORKED OUT THAT ARRAY/VECTOR THING...
	if(m_Twos_Start != NULL) //1P
	{
		delete m_Twos_Start;
		m_Twos_Start = NULL;
	}

	if(m_Twos_GoBack != NULL) //2P
	{
		delete m_Twos_GoBack;
		m_Twos_GoBack = NULL;
	}

	if(m_Twos_ScoreLimit_Low != NULL)
	{
		delete m_Twos_ScoreLimit_Low;
		m_Twos_ScoreLimit_Low = NULL;
	}
	
	if(m_Twos_ScoreLimit_Mid != NULL)
	{
		delete m_Twos_ScoreLimit_Mid;
		m_Twos_ScoreLimit_Mid = NULL;
	}
	
	if(m_Twos_ScoreLimit_None != NULL)
	{
		delete m_Twos_ScoreLimit_None;
		m_Twos_ScoreLimit_None = NULL;
	}
	
	if(m_Twos_TimeLimit_Low != NULL)
	{
		delete m_Twos_TimeLimit_Low;
		m_Twos_TimeLimit_Low = NULL;
	}
	
	if(m_Twos_TimeLimit_Mid != NULL)
	{
		delete m_Twos_TimeLimit_Mid;
		m_Twos_TimeLimit_Mid = NULL;
	}
	
	if(m_Twos_TimeLimit_None != NULL)
	{
		delete m_Twos_TimeLimit_None;
		m_Twos_TimeLimit_None = NULL;
	}
	
	if(m_P1_ControlSelect_Mouse != NULL)
	{
		delete m_P1_ControlSelect_Mouse;
		m_P1_ControlSelect_Mouse = NULL;
	}
	
	if(m_P1_ControlSelect_Keys != NULL)
	{
		delete m_P1_ControlSelect_Keys;
		m_P1_ControlSelect_Keys = NULL;
	}
	
	if(m_P2_ControlSelect_Mouse != NULL)
	{
		delete m_P2_ControlSelect_Mouse;
		m_P2_ControlSelect_Mouse = NULL;
	}
	
	if(m_P2_ControlSelect_Keys != NULL)
	{
		delete m_P2_ControlSelect_Keys;
		m_P2_ControlSelect_Keys = NULL;
	}

	//REMOVE BACKGROUND
	if(m_GameSettingsTwosBackgroundTexture != NULL)
	{
		delete m_GameSettingsTwosBackgroundTexture;
		m_GameSettingsTwosBackgroundTexture = NULL;
	}
}

//GET NAME----------------------------------------------------------
const char* GameSettingsTwos::getName()
{
	return GAMESETTINGS_TWOS_SCREEN_NAME;
}

//UPDATE------------------------------------------------------------
void GameSettingsTwos::update(double delta)
{

}

//PAINT-------------------------------------------------------------
void GameSettingsTwos::paint()
{
	//Paint Background
    OpenGLRenderer::getInstance()->drawTexture(m_GameSettingsTwosBackgroundTexture, 0.0f, 0.0f);

	//Paint Buttons
	m_Twos_Start->paint(); //START
	m_Twos_GoBack->paint(); //BACK
	m_Twos_ScoreLimit_Low->paint(); //scores
	m_Twos_ScoreLimit_Mid->paint();
	m_Twos_ScoreLimit_None->paint();
	m_Twos_TimeLimit_Low->paint(); //time
	m_Twos_TimeLimit_Mid->paint();
	m_Twos_TimeLimit_None->paint();
	m_P1_ControlSelect_Mouse->paint(); //controls
	m_P1_ControlSelect_Keys->paint();
	m_P2_ControlSelect_Mouse->paint();
	m_P2_ControlSelect_Keys->paint();
}

//KEY DOWN EVENT - Key events---------------------------------------
void GameSettingsTwos::keyDownEvent(int keyCode)
{
	//ON LEFT ARROW
	//On left arrow, you see that i totally suck
    if(keyCode == KEYCODE_RIGHT_ARROW)
	{
		switch(m_SelectedButton)
		{
			case 0:
				m_Twos_Start->setIsSelected(false);
				m_Twos_GoBack->setIsSelected(true);
				m_SelectedButton++;
				break;
			case 1:
				m_Twos_GoBack->setIsSelected(false);
				m_Twos_Start->setIsSelected(true);
				m_SelectedButton = 0;
				break;
		}
	}
	
	//ON ENTER KEY
	if(keyCode == KEYCODE_RETURN)
	{
		switch(m_SelectedButton)
		{
			case 0:
				TWO_PLAYER_GAME = true;
				SETTINGS_ARE_SELECTED = true;

				ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
				break;
			case 1:
				ScreenManager::getInstance()->switchScreen(MAINMENU_SCREEN_NAME);
				break;
		}
	}
}

//MOUSE MOVEMENT EVENT - Mouseover events---------------------------
void GameSettingsTwos::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
	m_Twos_Start->mouseMovementEvent(positionX, positionY); //START
	m_Twos_GoBack->mouseMovementEvent(positionX, positionY); //BACK
}

//MOUSE LEFT CLICK UP EVENT - Finish left click---------------------
void GameSettingsTwos::mouseLeftClickUpEvent(float positionX, float positionY)
{
	m_Twos_Start->mouseLeftClickUpEvent(positionX, positionY); //START
	m_Twos_GoBack->mouseLeftClickUpEvent(positionX, positionY); //BACK
	m_Twos_ScoreLimit_Low->mouseLeftClickUpEvent(positionX, positionY); //scores
	m_Twos_ScoreLimit_Mid->mouseLeftClickUpEvent(positionX, positionY);
	m_Twos_ScoreLimit_None->mouseLeftClickUpEvent(positionX, positionY);
	m_Twos_TimeLimit_Low->mouseLeftClickUpEvent(positionX, positionY); //time
	m_Twos_TimeLimit_Mid->mouseLeftClickUpEvent(positionX, positionY);
	m_Twos_TimeLimit_None->mouseLeftClickUpEvent(positionX, positionY);
	m_P1_ControlSelect_Mouse->mouseLeftClickUpEvent(positionX, positionY); //controls
	m_P1_ControlSelect_Keys->mouseLeftClickUpEvent(positionX, positionY);
	m_P2_ControlSelect_Mouse->mouseLeftClickUpEvent(positionX, positionY);
	m_P2_ControlSelect_Keys->mouseLeftClickUpEvent(positionX, positionY);
}

//BUTTON ACTION - Click events--------------------------------------
void GameSettingsTwos::buttonAction(UIButton* button)
{
	//START BUTTON CLICKED -> game
	if(button == m_Twos_Start)
	{
		//settings are selected
		SETTINGS_ARE_SELECTED = true;
		
		//two player game
		TWO_PLAYER_GAME = true;
		
		//Get game object
		Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);

		//Reset the game with settings
		game->reset();
		
		//get game screen
		ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
	}

	//GO BACK CLICKED -> main menu
	if(button == m_Twos_GoBack)
	{
		ScreenManager::getInstance()->switchScreen(MAINMENU_SCREEN_NAME);
	}

	//score - low
	if(button == m_Twos_ScoreLimit_Low)
	{
		//settings
		SCORELIMIT_LOW = true;
		SCORELIMIT_MID = false;
		SCORELIMIT_NONE = false;
		m_Twos_ScoreLimit_Low->setIsSelected(true);
		m_Twos_ScoreLimit_Mid->setIsSelected(false);
		m_Twos_ScoreLimit_None->setIsSelected(false);
	}

	//score - mid
	if(button == m_Twos_ScoreLimit_Mid)
	{
		//settings
		SCORELIMIT_LOW = false;
		SCORELIMIT_MID = true;
		SCORELIMIT_NONE = false;
		m_Twos_ScoreLimit_Low->setIsSelected(false);
		m_Twos_ScoreLimit_Mid->setIsSelected(true);
		m_Twos_ScoreLimit_None->setIsSelected(false);
	}

	//score - none
	if(button == m_Twos_ScoreLimit_None)
	{
		//settings
		SCORELIMIT_LOW = false;
		SCORELIMIT_MID = false;
		SCORELIMIT_NONE = true;
		m_Twos_ScoreLimit_Low->setIsSelected(false);
		m_Twos_ScoreLimit_Mid->setIsSelected(false);
		m_Twos_ScoreLimit_None->setIsSelected(true);
	}

	//time - low
	if(button == m_Twos_TimeLimit_Low)
	{
		TIMELIMIT_LOW = true;
		TIMELIMIT_MID = false;
		TIMELIMIT_NONE = false;
		m_Twos_TimeLimit_Low->setIsSelected(true);
		m_Twos_TimeLimit_Mid->setIsSelected(false);
		m_Twos_TimeLimit_None->setIsSelected(false);
	}

	//time - mid
	if(button == m_Twos_TimeLimit_Mid)
	{
		TIMELIMIT_LOW = false;
		TIMELIMIT_MID = true;
		TIMELIMIT_NONE = false;
		m_Twos_TimeLimit_Low->setIsSelected(false);
		m_Twos_TimeLimit_Mid->setIsSelected(true);
		m_Twos_TimeLimit_None->setIsSelected(false);
	}

	//time - high
	if(button == m_Twos_TimeLimit_None)
	{
		//settings
		TIMELIMIT_LOW = false;
		TIMELIMIT_MID = false;
		TIMELIMIT_NONE = true;
		m_Twos_TimeLimit_Low->setIsSelected(false);
		m_Twos_TimeLimit_Mid->setIsSelected(false);
		m_Twos_TimeLimit_None->setIsSelected(true);
	}

	//p1 mouse
	if(button == m_P1_ControlSelect_Mouse)
	{
		CONTROLS_MOUSE = true;
		CONTROLS_KEYS = false;
		PLAYER_TWO_CONTROLS_MOUSE = false;
		PLAYER_TWO_CONTROLS_KEYS = true;
		m_P1_ControlSelect_Mouse->setIsSelected(true);
		m_P1_ControlSelect_Keys->setIsSelected(false);
		m_P2_ControlSelect_Mouse->setIsSelected(false);
	}

	//p1 keys
	if(button == m_P1_ControlSelect_Keys)
	{
		CONTROLS_MOUSE = false;
		CONTROLS_KEYS = true;
		m_P1_ControlSelect_Mouse->setIsSelected(false);
		m_P1_ControlSelect_Keys->setIsSelected(true);
	}

	//p2 mouse
	if(button == m_P2_ControlSelect_Mouse)
	{
		CONTROLS_MOUSE = false;
		CONTROLS_KEYS = true;
		PLAYER_TWO_CONTROLS_MOUSE = true;
		PLAYER_TWO_CONTROLS_KEYS = false;
		m_P2_ControlSelect_Mouse->setIsSelected(true);
		m_P2_ControlSelect_Keys->setIsSelected(false);
		m_P1_ControlSelect_Mouse->setIsSelected(false);
	}

	//p2 keys
	if(button == m_P2_ControlSelect_Keys)
	{
		PLAYER_TWO_CONTROLS_MOUSE = false;
		PLAYER_TWO_CONTROLS_KEYS = true;
		m_P2_ControlSelect_Mouse->setIsSelected(false);
		m_P2_ControlSelect_Keys->setIsSelected(true);
	}

}