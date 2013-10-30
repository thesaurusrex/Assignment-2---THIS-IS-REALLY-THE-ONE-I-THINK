//SEE GAMESETTINGS.H

#include "GameSettings.h"
#include "../Game/Paddle.h"
#include "Splash.h"
#include "../Constants/Constants.h"
#include "../Input/Input.h"
#include "../Screen Manager/ScreenManager.h"
#include "../UI/UIButton.h"
#include "../OpenGL/OpenGL.h"
#include "../Game/Game.h"

//CONSTRUCTOR-------------------------------------------------------
GameSettings::GameSettings() : 
			m_SelectedButton(0),
			m_Select_Start(NULL),
			m_Select_GoBack(NULL),
			m_ScoreLimit_Low(NULL),
			m_ScoreLimit_Mid(NULL),
			m_ScoreLimit_None(NULL),
			m_TimeLimit_Low(NULL),
			m_TimeLimit_Mid(NULL),
			m_TimeLimit_None(NULL),
			m_Difficulty_Low(NULL),
			m_Difficulty_Mid(NULL),
			m_Difficulty_High(NULL),
			m_ControlSelect_Mouse(NULL),
			m_ControlSelect_Keys(NULL)
{
	//Create background textures
    m_GameSettingsBackgroundTexture = new OpenGLTexture("GameSettings_ScreenBG");

	//Create buttons
	m_Select_Start = new UIButton(GAMESETTINGS_SELECT_START); //START
	m_Select_GoBack = new UIButton(GAMESETTINGS_SELECT_GOBACK); //BACK
	m_ScoreLimit_Low = new UIButton(GAMESETTINGS_SCORELIMIT_LOW); //scores
	m_ScoreLimit_Mid = new UIButton(GAMESETTINGS_SCORELIMIT_MID);
	m_ScoreLimit_None = new UIButton(GAMESETTINGS_SCORELIMIT_NONE);
	m_TimeLimit_Low = new UIButton(GAMESETTINGS_TIMELIMIT_LOW); //times
	m_TimeLimit_Mid = new UIButton(GAMESETTINGS_TIMELIMIT_MID);
	m_TimeLimit_None = new UIButton(GAMESETTINGS_TIMELIMIT_NONE);
	m_Difficulty_Low = new UIButton(GAMESETTINGS_DIFFICULTY_LOW);//difficulty
	m_Difficulty_Mid = new UIButton(GAMESETTINGS_DIFFICULTY_MID);
	m_Difficulty_High = new UIButton(GAMESETTINGS_DIFFICULTY_HIGH);
	m_ControlSelect_Mouse = new UIButton(GAMESETTINGS_CONTROLSELECT_MOUSE); //mouse
	m_ControlSelect_Keys = new UIButton(GAMESETTINGS_CONTROLSELECT_KEYS); //keys

	//Place buttons on screen
	m_Select_Start->setCenterPosition(getWidth() / 1.35f, getHeight() * GAMESETTINGS_SELECT_START_Y_PERCENTAGE); //START
	m_Select_GoBack->setCenterPosition(getWidth() / 4.0f, getHeight() * GAMESETTINGS_SELECT_GOBACK_Y_PERCENTAGE); //BACK

	m_ScoreLimit_Low->setCenterPosition(getWidth() / 1.35f, getHeight() * GAMESETTINGS_SCORELIMIT_LOW_Y_PERCENTAGE); //scores
	m_ScoreLimit_Mid->setCenterPosition(getWidth() / 1.35f, getHeight() * GAMESETTINGS_SCORELIMIT_MID_Y_PERCENTAGE); 
	m_ScoreLimit_None->setCenterPosition(getWidth() / 1.35f, getHeight() * GAMESETTINGS_SCORELIMIT_NONE_Y_PERCENTAGE); 

	m_TimeLimit_Low->setCenterPosition(getWidth() / 4.0f, getHeight() * GAMESETTINGS_TIMELIMIT_LOW_Y_PERCENTAGE); //times
	m_TimeLimit_Mid->setCenterPosition(getWidth() / 4.0f, getHeight() * GAMESETTINGS_TIMELIMIT_MID_Y_PERCENTAGE); 
	m_TimeLimit_None->setCenterPosition(getWidth() / 4.0f, getHeight() * GAMESETTINGS_TIMELIMIT_NONE_Y_PERCENTAGE); 

	m_Difficulty_Low->setCenterPosition(getWidth() / 4.0f, getHeight() * GAMESETTINGS_DIFFICULTY_LOW_Y_PERCENTAGE); //diffuculty
	m_Difficulty_Mid->setCenterPosition(getWidth() / 4.0f, getHeight() * GAMESETTINGS_DIFFICULTY_MID_Y_PERCENTAGE); 
	m_Difficulty_High->setCenterPosition(getWidth() / 4.0f, getHeight() * GAMESETTINGS_DIFFICULTY_HIGH_Y_PERCENTAGE); 

	m_ControlSelect_Mouse->setCenterPosition(getWidth() / 1.35f, getHeight() * GAMESETTINGS_CONTROLSELECT_MOUSE_Y_PERCENTAGE); //mouse
	m_ControlSelect_Keys->setCenterPosition(getWidth() / 1.35f, getHeight() * GAMESETTINGS_CONTROLSELECT_KEYS_Y_PERCENTAGE); //keys

	//Set up button listener
	m_Select_Start->setListener(this); //START
	m_Select_GoBack->setListener(this); //BACK
	m_ScoreLimit_Low->setListener(this); //scores
	m_ScoreLimit_Mid->setListener(this); 
	m_ScoreLimit_None->setListener(this); 
	m_TimeLimit_Low->setListener(this); //times
	m_TimeLimit_Mid->setListener(this); 
	m_TimeLimit_None->setListener(this); 
	m_Difficulty_Low->setListener(this); //difficulty
	m_Difficulty_Mid->setListener(this); 
	m_Difficulty_High->setListener(this); 
	m_ControlSelect_Mouse->setListener(this); //mouse
	m_ControlSelect_Keys->setListener(this); //keys
}

//DESTRUCTOR--------------------------------------------------------
GameSettings::~GameSettings()
{
    //REMOVE BUTTONS
	if(m_Select_Start != NULL) //START
	{
		delete m_Select_Start;
		m_Select_Start = NULL;
	}

	if(m_Select_GoBack != NULL)
	{
		delete m_Select_GoBack;
		m_Select_GoBack = NULL;
	}

	if(m_ScoreLimit_Low != NULL)
	{
		delete m_ScoreLimit_Low;
		m_ScoreLimit_Low = NULL;
	}

	if(m_ScoreLimit_Mid != NULL)
	{
		delete m_ScoreLimit_Mid;
		m_ScoreLimit_Mid = NULL;
	}

	if(m_ScoreLimit_None != NULL)
	{
		delete m_ScoreLimit_None;
		m_ScoreLimit_None = NULL;
	}

	if(m_TimeLimit_Low != NULL)
	{
		delete m_TimeLimit_Low;
		m_TimeLimit_Low = NULL;
	}

	if(m_TimeLimit_Mid != NULL)
	{
		delete m_TimeLimit_Mid;
		m_TimeLimit_Mid = NULL;
	}

	if(m_TimeLimit_None != NULL)
	{
		delete m_TimeLimit_None;
		m_TimeLimit_None = NULL;
	}

	if(m_Difficulty_Low != NULL)
	{
		delete m_Difficulty_Low;
		m_Difficulty_Low = NULL;
	}

	if(m_Difficulty_Mid != NULL)
	{
		delete m_Difficulty_Mid;
		m_Difficulty_Mid = NULL;
	}

	if(m_Difficulty_High != NULL)
	{
		delete m_Difficulty_High;
		m_Difficulty_High = NULL;
	}

	if(m_ControlSelect_Mouse != NULL)
	{
		delete m_ControlSelect_Mouse;
		m_ControlSelect_Mouse = NULL;
	}

	if(m_ControlSelect_Keys != NULL)
	{
		delete m_ControlSelect_Keys;
		m_ControlSelect_Keys = NULL;
	}

	//REMOVE BACKGROUND
	if(m_GameSettingsBackgroundTexture != NULL)
	{
		delete m_GameSettingsBackgroundTexture;
		m_GameSettingsBackgroundTexture = NULL;
	}
}

//GET NAME----------------------------------------------------------
const char* GameSettings::getName()
{
    return GAMESETTINGS_SCREEN_NAME;
}

//UPDATE------------------------------------------------------------
void GameSettings::update(double delta)
{
    
}

//PAINT-------------------------------------------------------------
void GameSettings::paint()
{
	//Paint Background
    OpenGLRenderer::getInstance()->drawTexture(m_GameSettingsBackgroundTexture, 0.0f, 0.0f);

	//Paint Buttons
	m_Select_Start->paint(); //START
	m_Select_GoBack->paint(); //BACK
	m_ScoreLimit_Low->paint(); //scores
	m_ScoreLimit_Mid->paint(); 
	m_ScoreLimit_None->paint(); 
	m_TimeLimit_Low->paint(); //times
	m_TimeLimit_Mid->paint(); 
	m_TimeLimit_None->paint(); 
	m_Difficulty_Low->paint(); //difficulty
	m_Difficulty_Mid->paint(); 
	m_Difficulty_High->paint(); 
	m_ControlSelect_Mouse->paint(); //mouse
	m_ControlSelect_Keys->paint(); //keys
}

//KEY DOWN EVENT - Key events---------------------------------------
void GameSettings::keyDownEvent(int keyCode)
{
	//ON LEFT ARROW
	//On left arrow, you see that i totally suck
    if(keyCode == KEYCODE_RIGHT_ARROW)
	{
		switch(m_SelectedButton)
		{
			case 0:
				m_Select_Start->setIsSelected(false);
				m_Select_GoBack->setIsSelected(true);
				m_SelectedButton++;
				break;
			case 1:
				m_Select_GoBack->setIsSelected(false);
				m_Select_Start->setIsSelected(true);
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
void GameSettings::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
    m_Select_Start->mouseMovementEvent(positionX, positionY); //START
	m_Select_GoBack->mouseMovementEvent(positionX, positionY); //BACK
}

//MOUSE LEFT CLICK UP EVENT - Finish left click---------------------
void GameSettings::mouseLeftClickUpEvent(float positionX, float positionY)
{
    m_Select_Start->mouseLeftClickUpEvent(positionX, positionY); //START
	m_Select_GoBack->mouseLeftClickUpEvent(positionX, positionY); //BACK
	m_ScoreLimit_Low->mouseLeftClickUpEvent(positionX, positionY); //scores
	m_ScoreLimit_Mid->mouseLeftClickUpEvent(positionX, positionY); 
	m_ScoreLimit_None->mouseLeftClickUpEvent(positionX, positionY); 
	m_TimeLimit_Low->mouseLeftClickUpEvent(positionX, positionY); //times
	m_TimeLimit_Mid->mouseLeftClickUpEvent(positionX, positionY); 
	m_TimeLimit_None->mouseLeftClickUpEvent(positionX, positionY); 
	m_Difficulty_Low->mouseLeftClickUpEvent(positionX, positionY); //difficulty
	m_Difficulty_Mid->mouseLeftClickUpEvent(positionX, positionY); 
	m_Difficulty_High->mouseLeftClickUpEvent(positionX, positionY); 
	m_ControlSelect_Mouse->mouseLeftClickUpEvent(positionX, positionY); //mouse
	m_ControlSelect_Keys->mouseLeftClickUpEvent(positionX, positionY); //keys
}

//BUTTON ACTION - Click events--------------------------------------
void GameSettings::buttonAction(UIButton* button)
{
	//START CLICKED - single player game
    if(button == m_Select_Start)
	{
		//not two player
		TWO_PLAYER_GAME = false;

		//Set settings to selected
		SETTINGS_ARE_SELECTED = true;

		//Get game object
		Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);

		//Reset the game with settings
		game->reset();
		
		//Get the game screen
		ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
	}

	//GO BACK CLICKED -> main menu screen
    if(button == m_Select_GoBack)
	{
		ScreenManager::getInstance()->switchScreen(MAINMENU_SCREEN_NAME);
	}

	//SCORE LIMIT LOW
	if(button == m_ScoreLimit_Low)
	{
		//Set score limit to low
		SCORELIMIT_LOW = true;
		SCORELIMIT_MID = false;
		SCORELIMIT_NONE = false;
		//Show button as selected, make other options non-selectable
		m_ScoreLimit_Low->setIsSelected(true);
		m_ScoreLimit_Mid->setIsSelected(false);
		m_ScoreLimit_None->setIsSelected(false);
	}

	//SCORE LIMIT MID
	if(button == m_ScoreLimit_Mid)
	{
		//Set settings
		SCORELIMIT_LOW = false;
		SCORELIMIT_MID = true;
		SCORELIMIT_NONE = false;
		//Show button as selected, make other options non-selectable
		m_ScoreLimit_Low->setIsSelected(false);
		m_ScoreLimit_Mid->setIsSelected(true);
		m_ScoreLimit_None->setIsSelected(false);
	}

	//SCORE LIMIT NONE
	if(button == m_ScoreLimit_None)
	{
		//Set settings
		SCORELIMIT_LOW = false;
		SCORELIMIT_MID = false;
		SCORELIMIT_NONE = true;
		//Show button as selected, make other options non-selectable
		m_ScoreLimit_Low->setIsSelected(false);
		m_ScoreLimit_Mid->setIsSelected(false);
		m_ScoreLimit_None->setIsSelected(true);
	}

	//TIME LIMIT LOW
	if(button == m_TimeLimit_Low)
	{
		TIMELIMIT_LOW = true;
		TIMELIMIT_MID = false;
		TIMELIMIT_NONE = false;
		m_TimeLimit_Low->setIsSelected(true);
		m_TimeLimit_Mid->setIsSelected(false);
		m_TimeLimit_None->setIsSelected(false);
	}

	//TIME LIMIT MID
	if(button == m_TimeLimit_Mid)
	{
		TIMELIMIT_LOW = false;
		TIMELIMIT_MID = true;
		TIMELIMIT_NONE = false;
		m_TimeLimit_Low->setIsSelected(false);
		m_TimeLimit_Mid->setIsSelected(true);
		m_TimeLimit_None->setIsSelected(false);
	}

	//TIME LIMIT NONE
	if(button == m_TimeLimit_None)
	{
		TIMELIMIT_LOW = false;
		TIMELIMIT_MID = false;
		TIMELIMIT_NONE = true;
		m_TimeLimit_Low->setIsSelected(false);
		m_TimeLimit_Mid->setIsSelected(false);
		m_TimeLimit_None->setIsSelected(true);
	}
	
	//DIFFICULTY LOW
	if(button == m_Difficulty_Low)
	{
		DIFFICULTY_LOW = true;
		DIFFICULTY_MID = false;
		DIFFICULTY_HIGH = false;
		m_Difficulty_Low->setIsSelected(true);
		m_Difficulty_Mid->setIsSelected(false);
		m_Difficulty_High->setIsSelected(false);
	}

	//DIFFICULTY MID
	if(button == m_Difficulty_Mid)
	{
		DIFFICULTY_LOW = false;
		DIFFICULTY_MID = true;
		DIFFICULTY_HIGH = false;
		m_Difficulty_Low->setIsSelected(false);
		m_Difficulty_Mid->setIsSelected(true);
		m_Difficulty_High->setIsSelected(false);
	}

	//DIFFICULTY HIGH
	if(button == m_Difficulty_High)
	{
		DIFFICULTY_LOW = false;
		DIFFICULTY_MID = false;
		DIFFICULTY_HIGH = true;
		m_Difficulty_Low->setIsSelected(false);
		m_Difficulty_Mid->setIsSelected(false);
		m_Difficulty_High->setIsSelected(true);

	}
	
	//CONTROLS MOUSE
	if(button == m_ControlSelect_Mouse)
	{
		CONTROLS_MOUSE = true;
		CONTROLS_KEYS = false;
		m_ControlSelect_Mouse->setIsSelected(true);
		m_ControlSelect_Keys->setIsSelected(false);
	}
	
	//CONTROLS KEY
	if(button == m_ControlSelect_Keys)
	{
		CONTROLS_MOUSE = false;
		CONTROLS_KEYS = true;
		m_ControlSelect_Keys->setIsSelected(true);
		m_ControlSelect_Mouse->setIsSelected(false);
	}
}