//
//  GameObject.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-01-09.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "GameObject.h"


GameObject::GameObject() :
m_PositionX(0.0f),
m_PositionY(0.0f),
m_IsActive(false)
{
    reset();
}

GameObject::~GameObject()
{
    
}

void GameObject::reset()
{
    setX(0.0f);
    setY(0.0f);
    setIsActive(true); 
}

void GameObject::setPosition(float aX, float aY)
{
    setX(aX);
    setY(aY);
}

void GameObject::setX(float aX)
{
    m_PositionX = aX;
}

void GameObject::setY(float aY)
{
    m_PositionY = aY;
}

void GameObject::getPosition(float &aX, float &aY)
{
    aX = getX();
    aY = getY();
}

float GameObject::getX()
{
    return m_PositionX;
}

float GameObject::getY()
{
    return m_PositionY;
}

void GameObject::setIsActive(bool aIsActive)
{
    m_IsActive = aIsActive;
}

bool GameObject::getIsActive()
{
    return m_IsActive;
}

