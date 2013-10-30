//
//  Paddle.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-01-09.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef PADDLE_H
#define PADDLE_H

#include "GameObject.h"

//Paddle class, inherits from GameObject, is controlled by the
//mouse input on the x-axis.
class Paddle : public GameObject
{
public:
    Paddle(float offsetX, bool computerController = false);
    ~Paddle();
    
    //Implementing the pure virtual lifecycle methods from GameObject
    void update(double delta);
    void paint();
    
    //Overriding the virtual reset method from GameObject
    void reset();
    
    //Implementing the pure virtual type method from GameObject
    const char* getType();
    
    //Input Event
    void keyUpEvent(int keyCode);
    void keyDownEvent(int keyCode);
    
    //Setter size methods
    void setSize(float width, float height);
    void setWidth(float width);
    void setHeight(float height);
    
    //Getter size methods
    void getSize(float &width, float &height);
    float getWidth();
    float getHeight();
    
protected:
    float m_Width;
    float m_Height;
    float m_OffsetPercentageX;
    float m_Speed;
    bool m_ComputerControlled;
    bool m_UpArrowPressed;
    bool m_DownArrowPressed;
	bool m_PageUpPressed;
	bool m_PageDownPressed;
};

#endif
