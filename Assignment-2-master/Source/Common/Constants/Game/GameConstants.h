/*
DATE:	10/28/2013
CODE:	by Breanna Henry & Brad Flood
FILE:	"GameConstants.h"
PURP:	Constants for game
RITE:	Copyright (c) 2013 Algonquin College. All rights reserved.
*/

#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

//Game Constants
extern const char* GAME_SCREEN_NAME;
extern double GAME_OVER_TIMER;
extern const double GAME_SCORE_INFO_TIMER;
extern const double GAME_SCORE_INFO_FADE_OUT_TIME;
//This is changed for score limit
extern int GAME_MAX_SCORE;

//HORRIBLE THINGS THAT WILL MAKE YOUR EYES BLEED
//Used for Game Settings (1P)
extern bool SETTINGS_ARE_SELECTED;
extern bool DIFFICULTY_LOW;
extern bool SETTINGS_ARE_SELECTED;
extern bool SCORELIMIT_LOW;
extern bool SCORELIMIT_MID;
extern bool SCORELIMIT_NONE;
extern bool TIMELIMIT_LOW;
extern bool TIMELIMIT_MID;
extern bool TIMELIMIT_NONE;
extern bool DIFFICULTY_LOW;
extern bool DIFFICULTY_MID;
extern bool DIFFICULTY_HIGH;
extern bool CONTROLS_MOUSE;
extern bool CONTROLS_KEYS;

//Used for Extra Game Settings (2P)
extern bool TWO_PLAYER_GAME;
extern bool PLAYER_TWO_CONTROLS_MOUSE;
extern bool PLAYER_TWO_CONTROLS_KEYS;

//Ball Constants
extern const float GAME_BALL_RADIUS_PERCENTAGE;
extern const float GAME_BALL_DEFAULT_SPEED;
extern const float GAME_BALL_SPEED_INCREMENT;
extern const char* GAME_BALL_TYPE;

//Paddle Constants
extern const float GAME_PADDLE_WIDTH_PERCENTAGE;
extern const float GAME_LEFT_PADDLE_X_PERCENTAGE;
extern const float GAME_RIGHT_PADDLE_X_PERCENTAGE;
extern const float GAME_PADDLE_Y_PERCENTAGE;
extern const float GAME_PADDLE_ACCELERATION;
extern const float GAME_PADDLE_MAX_SPEED;
extern const char* GAME_PADDLE_TYPE;
//This is changed for difficulty
extern float GAME_PADDLE_HEIGHT_PERCENTAGE;

#endif 