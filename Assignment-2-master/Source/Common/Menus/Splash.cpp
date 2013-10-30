//SEE SPLASH.H

#include "Splash.h"
#include "../Constants/Constants.h"
#include "../Input/Input.h"
#include "../Screen Manager/ScreenManager.h"
#include "../UI/UIButton.h"
#include "../OpenGL/OpenGL.h"


//CONSTRUCTOR-------------------------------------------------------
Splash::Splash() : m_PressSpace(NULL)
{
	//Create background texture
    m_SplashScreenBackgroundTexture = new OpenGLTexture("Splash_ScreenBG");

	//Create buttons
	m_PressSpace = new UIButton(SPLASH_PRESS_SPACE);

	//Place buttons on screen
	m_PressSpace->setCenterPosition(getWidth() / 2.0f, getHeight() * SPLASH_PRESS_SPACE_Y_PERCENTAGE);

	//Set up button listener
	m_PressSpace->setListener(this);
}

//DESTRUCTOR--------------------------------------------------------
Splash::~Splash()
{
	//Remove Buttons
	if(m_PressSpace != NULL)
	{
		delete m_PressSpace;
		m_PressSpace = NULL;
	}

	//Remove Background
	if(m_SplashScreenBackgroundTexture != NULL)
	{
		delete m_SplashScreenBackgroundTexture;
		m_SplashScreenBackgroundTexture = NULL;
	}
}

//GET NAME----------------------------------------------------------
const char* Splash::getName()
{
	return SPLASH_SCREEN_NAME;
}

//UPDATE------------------------------------------------------------
void Splash::update(double delta)
{

}

//PAINT-------------------------------------------------------------
void Splash::paint()
{
	//Paint background
	OpenGLRenderer::getInstance()->drawTexture(m_SplashScreenBackgroundTexture, 0.0f, 0.0f);

	//Paint buttons
	m_PressSpace->paint();
}

//KEY DOWN EVENT - Key events---------------------------------------
void Splash::keyDownEvent(int keyCode)
{
	//enter key
	if(keyCode == KEYCODE_SPACE)
	{
		ScreenManager::getInstance()->switchScreen(MAINMENU_SCREEN_NAME);
	}
}

//MOUSE MOVEMENT EVENT - Mouseover events---------------------------
void Splash::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
	m_PressSpace->mouseMovementEvent(positionX, positionY);
}

//MOUSE LEFT CLICK UP EVENT - Finish left click---------------------
void Splash::mouseLeftClickUpEvent(float positionX, float positionY)
{
	m_PressSpace->mouseLeftClickUpEvent(positionX, positionY);
}

//BUTTON ACTION - Click events--------------------------------------
void Splash::buttonAction(UIButton* button)
{
	//PRESS SPACE -> main menu screen
	if(button == m_PressSpace)
	{
		ScreenManager::getInstance()->switchScreen(MAINMENU_SCREEN_NAME);
	}
}