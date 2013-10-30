//
//  Ball.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-01-09.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Ball.h"
#include "Game.h"
#include "Paddle.h"
#include "../Constants/Constants.h"
#include "../Screen Manager/ScreenManager.h"
#include "../OpenGL/OpenGL.h"
#include "../Utils/Utils.h"


Ball::Ball() : GameObject(),
    m_Radius(0.0f),
    m_Speed(0.0f),
    m_DirectionX(0.0f),
    m_DirectionY(0.0f)
{
    setDirectionX(1.0f);
    setDirectionY(1.0f);
}

Ball::~Ball()
{

}

void Ball::update(double aDelta)
{
  //Calculate the ball's x and y position
  setX(getX() + (getDirectionX() * getSpeed() * aDelta));
  setY(getY() + (getDirectionY() * getSpeed() * aDelta));
  
  //Vertical bounds check
  if(getY() - getRadius() < 0.0f)
  {
    //There was a collision at the top, reverse the y-direction
	  setY(getRadius());
	  setDirectionY(getDirectionY() * -1.0f);
  }
  else if(getY() > ScreenManager::getInstance()->getScreenHeight() - getRadius())
  {
    //There was a collision at the bottom, reverse the y-direction
	  setY(ScreenManager::getInstance()->getScreenHeight() - getRadius());
	  setDirectionY(getDirectionY() * -1.0f);
  }
  
  //Horizontal bounds check
  if(getX() + getRadius() < 0.0f)
  {
    //The ball went off the left side of the screen, that means the right side scored
    Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
    game->rightGoal();
  }
  else if(getX() > ScreenManager::getInstance()->getScreenWidth() + getRadius())
  {
    //The ball went off the right side of the screen, that means the left side scored
    Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
    game->leftGoal();
  }
}

void Ball::paint()
{
  //Draw an the puck in black
  OpenGLRenderer::getInstance()->setForegroundColor(OpenGLColorWhite());
  OpenGLRenderer::getInstance()->drawCircle(getX(), getY(), getRadius());
}

void Ball::reset()
{
  //Get the screen width and height
  float screenWidth = ScreenManager::getInstance()->getScreenWidth();
  float screenHeight = ScreenManager::getInstance()->getScreenHeight();

  //Reset the radius
  setRadius(screenWidth * GAME_BALL_RADIUS_PERCENTAGE);
  
  //Reset the x and y position
  setX(screenWidth / 2.0f);
  setY(screenHeight / 2.0f);
  
  //Reset the speed
  setSpeed(GAME_BALL_DEFAULT_SPEED);
  
  //Set the ball back to being active
  setIsActive(true);
}

const char* Ball::getType()
{
  return GAME_BALL_TYPE;
}

void Ball::checkCollision(GameObject* aGameObject)
{
  //Make sure the ball is active, the gameObject isn't NULL and that it is also active
  if(getIsActive() == true && aGameObject != NULL && aGameObject->getIsActive() == true)
  {
    //Determine if the gameObject is a Paddle
    if(strcmp(aGameObject->getType(), GAME_PADDLE_TYPE) == 0)
    {
      handlePaddleCollision((Paddle*)aGameObject);
    }
  }
}

void Ball::handlePaddleCollision(Paddle* aPaddle)
{
  //Calculate the ball's distance from the paddle
  float distanceX = fabsf(getX() - aPaddle->getX() - (aPaddle->getWidth() / 2.0f));
  float distanceY = fabsf(getY() - aPaddle->getY() - (aPaddle->getHeight() / 2.0f));
  
  //If the distance on the x-axis is greater than half-the-width of the paddle + the ball's radius, then 
  //there is no way they can be colliding and return out of this method, no more collision handling is needed.
  if(distanceX > ((aPaddle->getWidth() / 2.0f) + getRadius()))
  {
    return; 
  }
  
  //If the distance on the y-axis is greater than half-the-height of the paddle + the ball's radius, then 
  //there is no way they can be colliding and return out of this method, no more collision handling is needed.
  if(distanceY > ((aPaddle->getHeight() / 2.0f) + getRadius())) 
  {
    return; 
  }
  
  //If we got here (passed the previous 2 if checks), then there is a good chance that a collision has occured.

  //If the distance on the x-axis is less than half-the-width of the paddle, then we have a collision on top of 
  //the paddle, set the ball's Y value and y-direction accordingly.
  if(distanceX <= (aPaddle->getWidth() / 2.0f))
  {
    //Bottom
    if(getY() > aPaddle->getY() + (aPaddle->getHeight() / 2.0f))
    {
      setY(aPaddle->getY() + aPaddle->getHeight() + getRadius());
    }
    //Top
    else 
    {
      setY(aPaddle->getY() - getRadius());
    }
  
    //Change the ball's direction and increase the ball's speed
    setDirectionY(getDirectionY() * -1.0f);
    increaseSpeed();
    return;
  } 
  
  //If the distance on the y-axis is less than half-the-height of the paddle, then we have a collision on either 
  //side of the paddle, set the x-direction accordingly.
  if(distanceY <= (aPaddle->getHeight() / 2.0f))
  {
    //Right
    if(getX() > aPaddle->getX() + (aPaddle->getWidth() / 2.0f))
    {
      setX(aPaddle->getX() + aPaddle->getWidth() + getRadius());
    }
    //Left
    else 
    {
      setX(aPaddle->getX() - getRadius());
    }
  
    //Change the ball's direction and increase the ball's speed
    setDirectionX(getDirectionX() * -1.0f);
    increaseSpeed();
    return;
  }
}

void Ball::increaseSpeed()
{
  setSpeed(getSpeed() + GAME_BALL_SPEED_INCREMENT);
}

void Ball::setRadius(float aRadius)
{
  m_Radius = aRadius;
}

float Ball::getRadius()
{
  return m_Radius;
}

void Ball::setSpeed(float aSpeed)
{
  m_Speed = aSpeed;
}

float Ball::getSpeed()
{
  return m_Speed;
}

void Ball::setDirection(float aDirectionX, float aDirectionY)
{
  setDirectionX(aDirectionX);
  setDirectionY(aDirectionY);
}

void Ball::setDirectionX(float aDirectionX)
{
  m_DirectionX = aDirectionX;
}

void Ball::setDirectionY(float aDirectionY)
{
  m_DirectionY = aDirectionY;
}

void Ball::getDirection(float &aDirectionX, float &aDirectionY)
{
  aDirectionX = getDirectionX();
  aDirectionY = getDirectionY();
}

float Ball::getDirectionX()
{
  return m_DirectionX;
}

float Ball::getDirectionY()
{
  return m_DirectionY;
}
