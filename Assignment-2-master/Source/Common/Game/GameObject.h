//
//  GameObject.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-01-09.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

//Abstract GameObject class, all objects drawn in game
//should inherit from this class.
class GameObject
{
public:
    GameObject();
    virtual ~GameObject();
    
    //Game lifecycle methods
    virtual void update(double delta) = 0;
    virtual void paint() = 0;
    virtual void reset();
    
    //Pure virtual method to easily determine type of object
    virtual const char* getType() = 0;
    
    //Setter position methods
    virtual void setPosition(float x, float y);
    virtual void setX(float x);
    virtual void setY(float y);
    
    //Getter position methods
    virtual void getPosition(float &x, float &y);
    virtual float getX();
    virtual float getY();
    
    //Get and set isActive methods
    virtual void setIsActive(bool isActive);
    virtual bool getIsActive();
    
protected:
    float m_PositionX;
    float m_PositionY;
    bool m_IsActive;
};

#endif /* defined(__GAM_1532_OSX_Game__GameObject__) */
