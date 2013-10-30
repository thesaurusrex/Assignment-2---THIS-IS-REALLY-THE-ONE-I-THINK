#include "Game.h"
#include "../Input/Input.h"
#include "../Menus/GameSettings.h"
#include "GameObject.h"
#include "Paddle.h"
#include "Ball.h"
#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include "..//Utils/Utils.h"
#include "../Screen Manager/ScreenManager.h"

Game::Game() :
    m_AlgonquinLogo(NULL),
    m_ScoreInfoBackground(NULL),
    m_ScoreInfoGoal(NULL),
    m_ScoreInfoLeft(NULL),
    m_ScoreInfoRight(NULL),
    m_ScoreInfoNumbers(NULL),
    m_ScoreInfoTimer(0.0),
    m_ScoreInfoAlpha(0.0f),
    m_LeftGoalsScored(0),
    m_RightGoalsScored(0)
	//m_GameTime(0)
{
	//create background texture
	m_GameBackgroundTexture = new OpenGLTexture("Game_ScreenBG");
	
	//here is what i thought
	if(TWO_PLAYER_GAME == true)
	{
		//Create a new paddle and ball----------------------------------------------------
		addGameObject(new Paddle(GAME_LEFT_PADDLE_X_PERCENTAGE));
		addGameObject(new Paddle(GAME_RIGHT_PADDLE_X_PERCENTAGE, false));
	}
	else
	{
		addGameObject(new Paddle(GAME_LEFT_PADDLE_X_PERCENTAGE));
		addGameObject(new Paddle(GAME_RIGHT_PADDLE_X_PERCENTAGE, true));
	}

	addGameObject(new Ball());

    //Create the score info textures
    m_AlgonquinLogo = new OpenGLTexture(GAME_ALGONQUIN_LOGO);
    m_ScoreInfoBackground = new OpenGLTexture(GAME_SCORE_INFO_BACKGROUND);
    m_ScoreInfoGoal = new OpenGLTexture(GAME_SCORE_INFO_GOAL);
    m_ScoreInfoLeft = new OpenGLTexture(GAME_SCORE_INFO_LEFT);
    m_ScoreInfoRight = new OpenGLTexture(GAME_SCORE_INFO_RIGHT);
    
    //Create the number texture array and create the texture's in the array for each numer
    m_ScoreInfoNumbers = new OpenGLTexture *[GAME_SCORE_INFO_NUMBER_OF_NUMBERS];
    for(int i = 0; i < GAME_SCORE_INFO_NUMBER_OF_NUMBERS; i++)
    {
        m_ScoreInfoNumbers[i] = new OpenGLTexture(GAME_SCORE_INFO_NUMBERS[i]);
    }
    
    //Reset the game
	reset();
}

Game::~Game()
{
    //Delete all the GameObject's in the vector, any GameObject add
    //to this vector will be automatically deleted here, DO NOT try
    //and delete and GameObjects yourself elsewhere.
    for(int i = 0; i < m_GameObjects.size(); i++)
    {
        delete m_GameObjects.at(i);
        m_GameObjects.at(i) = NULL;
    }
    
    //Clear the pointers from the vector
    m_GameObjects.clear();
    
	//Delete background texture
	if(m_GameBackgroundTexture != NULL)
	{
		delete m_GameBackgroundTexture;
		m_GameBackgroundTexture = NULL;
	}

    //Delete the score info background texture
    if(m_ScoreInfoBackground != NULL)
    {
        delete m_ScoreInfoBackground;
        m_ScoreInfoBackground = NULL;
    }
    
    //Delete the score info goal texture
    if(m_ScoreInfoGoal != NULL)
    {
        delete m_ScoreInfoGoal;
        m_ScoreInfoGoal = NULL;
    }
    
    //Delete the score info left texture
    if(m_ScoreInfoLeft != NULL)
    {
        delete m_ScoreInfoLeft;
        m_ScoreInfoLeft = NULL;
    }
    
    //Delete the score info right texture
    if(m_ScoreInfoRight != NULL)
    {
        delete m_ScoreInfoRight;
        m_ScoreInfoRight = NULL;
    }
    
    //Delete the score info number textures array
    if(m_ScoreInfoNumbers != NULL)
    {
        for(int i = 0; i < GAME_SCORE_INFO_NUMBER_OF_NUMBERS; i++)
        {
            delete m_ScoreInfoNumbers[i];
            m_ScoreInfoNumbers[i] = NULL;
        }
        
        delete[] m_ScoreInfoNumbers;
        m_ScoreInfoNumbers = NULL;
    }
}

void Game::update(double aDelta)
{
	//increase timer
	//m_GameTime++;
	//if(m_GameTime == GAME_OVER_TIMER)
	//{
		//gameOver();
	//}

	//ONLY UPDATE WHEN THE SELTTINGS HAVE BEEN SELECTED
	if(SETTINGS_ARE_SELECTED == true)
	{
		//If the score timer is greater than zero, countdown
		if(m_ScoreInfoTimer > 0.0)
		{
			m_ScoreInfoTimer -= aDelta;
        
			//If the score timer is less than the fade out time, calculate the alpha value to fade out the score info
			if(m_ScoreInfoTimer < GAME_SCORE_INFO_FADE_OUT_TIME)
			{
				m_ScoreInfoAlpha = m_ScoreInfoTimer / GAME_SCORE_INFO_FADE_OUT_TIME;
			}
        
			//If the score info timer is less than zero, set it to zero
			if(m_ScoreInfoTimer < 0.0)
			{
				m_ScoreInfoTimer = 0.0;
				m_ScoreInfoAlpha = 0.0f;
			}
			return;
		}

		//Get the ball GameObject, we'll use this for collision detection
		Ball* ball = (Ball*)getGameObjectByType(GAME_BALL_TYPE);
    
		//Cycle through all the game objects update them and check their collision detection
		for(int i = 0; i < m_GameObjects.size(); i++)
		{
			//Make sure the GameObject is active
			if(m_GameObjects.at(i)->getIsActive() == true)
			{
				//Update the GameObject
				m_GameObjects.at(i)->update(aDelta);
            
				//Check collision detection against the ball
				if(m_GameObjects.at(i) != ball)
				{
					ball->checkCollision(m_GameObjects.at(i));
				}
			}
		}
	}
}

void Game::paint()
{
	//Draw the background
	OpenGLRenderer::getInstance()->drawTexture(m_GameBackgroundTexture, 0.0f, 0.0f);

    //Cycle through and draw all the game objects
    for(int i = 0; i < m_GameObjects.size(); i++)
    {
        if(m_GameObjects.at(i)->getIsActive() == true)
        {
            m_GameObjects.at(i)->paint();
        }
    }
    
    //Draw the score info if the alpha value is greater than zero
    if(m_ScoreInfoAlpha > 0.0f)
    {
        paintScoreInfo(m_ScoreInfoAlpha);
    }
}

void Game::reset()
{
	//Cycle through and reset all the game objects
    for(int i = 0; i < m_GameObjects.size(); i++)
    {
        m_GameObjects.at(i)->reset();
    }
    
    //Reset the score info timer and alpha variables
    m_ScoreInfoTimer = 0.0f;
    m_ScoreInfoAlpha = 0.0f;
    
    //Reset the score
    m_LeftGoalsScored = 0;
    m_RightGoalsScored = 0;
}

void Game::resetBall(bool leftGoal)
{
    //Get the ball GameObject, we need to reset it and set the current speed
    Ball* ball = (Ball*)getGameObjectByType(GAME_BALL_TYPE);
    ball->reset();
    
    //Which direction does the ball go in?
    leftGoal == true ? ball->setDirectionX(1.0f) : ball->setDirectionX(-1.0f);
    
    //Set the score info timer and alpha
    m_ScoreInfoTimer = GAME_SCORE_INFO_TIMER;
    m_ScoreInfoAlpha = 1.0f;
}

void Game::paintScoreInfo(float aAlpha)
{
    //Draw the score info background
    float backgroundX = (getWidth() - m_ScoreInfoBackground->getSourceWidth()) * 0.5f;
    float backgroundY = (getHeight() - m_ScoreInfoBackground->getSourceHeight()) * 0.5f;
    m_ScoreInfoBackground->setAlpha(aAlpha);
    OpenGLRenderer::getInstance()->drawTexture(m_ScoreInfoBackground, backgroundX, backgroundY);
    
    //Draw the goal title at the top
    float goalX = (getWidth() - m_ScoreInfoGoal->getSourceWidth()) * 0.5f;
    float goalY = backgroundY + (m_ScoreInfoBackground->getSourceHeight() * 0.15f) - (m_ScoreInfoLeft->getSourceHeight() / 2.0f);
    m_ScoreInfoGoal->setAlpha(aAlpha);
    OpenGLRenderer::getInstance()->drawTexture(m_ScoreInfoGoal, goalX, goalY);
    
    //Draw the left title
    float leftX = backgroundX + (m_ScoreInfoBackground->getSourceWidth() * 0.25f) - (m_ScoreInfoLeft->getSourceWidth() / 2.0f);
    float leftY = backgroundY + ((m_ScoreInfoBackground->getSourceHeight() - m_ScoreInfoLeft->getSourceHeight()) / 2.0f);
    m_ScoreInfoLeft->setAlpha(aAlpha);
    OpenGLRenderer::getInstance()->drawTexture(m_ScoreInfoLeft, leftX, leftY);
    
    //Draw the right title
    float rightX = backgroundX + (m_ScoreInfoBackground->getSourceWidth() * 0.75f) - (m_ScoreInfoRight->getSourceWidth() / 2.0f);
    float rightY = backgroundY + ((m_ScoreInfoBackground->getSourceHeight() - m_ScoreInfoRight->getSourceHeight()) / 2.0f);
    m_ScoreInfoRight->setAlpha(aAlpha);
    OpenGLRenderer::getInstance()->drawTexture(m_ScoreInfoRight, rightX, rightY);
    
    //Draw the left team's score
    if(m_LeftGoalsScored < GAME_SCORE_INFO_NUMBER_OF_NUMBERS)
    {
        OpenGLTexture* score = m_ScoreInfoNumbers[m_LeftGoalsScored];
        float scoreX = backgroundX + (m_ScoreInfoBackground->getSourceWidth() * 0.25f) - (score->getSourceWidth() / 2.0f);
        float scoreY = leftY + 50.0f;
        score->setAlpha(aAlpha);
        OpenGLRenderer::getInstance()->drawTexture(score, scoreX, scoreY);
    }
    
    //Draw the right team's score
    if(m_RightGoalsScored < GAME_SCORE_INFO_NUMBER_OF_NUMBERS)
    {
        OpenGLTexture* score = m_ScoreInfoNumbers[m_RightGoalsScored];
        float scoreX = backgroundX + (m_ScoreInfoBackground->getSourceWidth() * 0.75f) - (score->getSourceWidth() / 2.0f);
        float scoreY = rightY + 50.0f;
        score->setAlpha(aAlpha);
        OpenGLRenderer::getInstance()->drawTexture(score, scoreX, scoreY);
    }
}

void Game::gameOver()
{
	//diplay the score... doesnt work
	paintScoreInfo(1.0f);

	//if p1 wins
	if(m_LeftGoalsScored == GAME_MAX_SCORE)
	//|| m_GameTime == GAME_OVER_TIMER && m_LeftGoalsScored > m_RightGoalsScored)
	{
		ScreenManager::getInstance()->switchScreen(GAMEOVER_SCREEN_NAME);
	}

	//if p2 wins
	else //if(m_GameTime == GAME_OVER_TIMER && m_RightGoalsScored > m_LeftGoalsScored)
	{
		ScreenManager::getInstance()->switchScreen(GAMEOVER_P2_SCREEN_NAME);
	}
}

void Game::leftGoal()
{
	//Low score limit
	if(SCORELIMIT_LOW == true)
	{
		GAME_MAX_SCORE = 5;
	}

	//Mid score limit
	if(SCORELIMIT_MID == true)
	{
		GAME_MAX_SCORE = 20;
	}

	//"No" score limit
	if(SCORELIMIT_NONE == true)
	{
		//ok so it's not technically infinite....
		GAME_MAX_SCORE = 9999999999;
	}

    //Increment the left side's score
    m_LeftGoalsScored++;

    //Reset the ball
    resetBall(true);
    
    //If the left side has reached the goal max, end the game
    if(m_LeftGoalsScored == GAME_MAX_SCORE)
    {
		gameOver();
    }
}

void Game::rightGoal()
{
	//Low score limit
	if(SCORELIMIT_LOW == true)
	{
		GAME_MAX_SCORE = 5;
	}

	//Mid score limit
	if(SCORELIMIT_MID == true)
	{
		GAME_MAX_SCORE = 20;
	}

	//"No" score limit
	if(SCORELIMIT_NONE == true)
	{
		//ok so it's not technically infinite....
		GAME_MAX_SCORE = 999999999;
	}

    //Increment the left side's score
    m_RightGoalsScored++;
   
    //Reset the ball
    resetBall(false);
    
    //If the right side has reached the goal max, end the game
    if(m_RightGoalsScored == GAME_MAX_SCORE)
    {
		gameOver();
    }
}

const char* Game::getName()
{
	return GAME_SCREEN_NAME;
}

void Game::screenWillAppear()
{
    OpenGLRenderer::getInstance()->setBackgroundColor(OpenGLColorWhite());
}

void Game::addGameObject(GameObject* aGameObject)
{
    if(aGameObject != NULL)
    {
        m_GameObjects.push_back(aGameObject);
    }
}

GameObject* Game::getGameObjectByType(const char* aType)
{
    //Cycle through a find the game object (if it exists)
    for(unsigned int i = 0; i < m_GameObjects.size(); i++)
    {
        if(strcmp(m_GameObjects.at(i)->getType(), aType) == 0)
        {
            return m_GameObjects.at(i);
        }
    }
    return NULL;
}

void Game::keyUpEvent(int aKeyCode)
{
	//Only if Keys are selected
	if(CONTROLS_KEYS == true || PLAYER_TWO_CONTROLS_KEYS == true)
	{
		//Cycle through all the game objects update them and check their collision detection
		for(int i = 0; i < m_GameObjects.size(); i++)
		{
			//Make sure the GameObject is active
			if(m_GameObjects.at(i)->getIsActive() == true && strcmp(m_GameObjects.at(i)->getType(), GAME_PADDLE_TYPE) == 0)
			{
				Paddle* paddle = (Paddle*)m_GameObjects.at(i);
				paddle->keyUpEvent(aKeyCode);
			}
		}
	}
}

void Game::keyDownEvent(int aKeyCode)
{
	//Only when Keys are selected
	if(CONTROLS_KEYS == true || PLAYER_TWO_CONTROLS_KEYS == true)
	{
		//Cycle through all the game objects update them and check their collision detection
		for(int i = 0; i < m_GameObjects.size(); i++)
		{
			//Make sure the GameObject is active
			if(m_GameObjects.at(i)->getIsActive() == true && strcmp(m_GameObjects.at(i)->getType(), GAME_PADDLE_TYPE) == 0)
			{
				Paddle* paddle = (Paddle*)m_GameObjects.at(i);
				paddle->keyDownEvent(aKeyCode);
			}
		}
	}

	//ESCAPE PRESSED -> go to pause menu
	if(aKeyCode == KEYCODE_ESCAPE)
	{
		ScreenManager::getInstance()->switchScreen(PAUSE_SCREEN_NAME);
	}
}

void Game::mouseMovementEvent(float aDeltaX, float aDeltaY, float aPositionX, float aPositionY)
{
	if(CONTROLS_MOUSE == true || PLAYER_TWO_CONTROLS_MOUSE == true)
	{
		//Set the paddle to the y position of the mouse
		Paddle* paddle = (Paddle*)getGameObjectByType(GAME_PADDLE_TYPE);

		//Safety check, paddle could be NULL
		if(paddle != NULL)
		{
			paddle->setY(aPositionY - (paddle->getHeight() / 2.0f));
		}
	}
}

