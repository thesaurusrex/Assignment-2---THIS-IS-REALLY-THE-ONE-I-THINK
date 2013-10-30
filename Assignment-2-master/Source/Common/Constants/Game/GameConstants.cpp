//SEE GAMECONSTANTS.H

#include "GameConstants.h"

//Game Constants
const char* GAME_SCREEN_NAME = "Game";
double GAME_OVER_TIMER = 30;
const double GAME_SCORE_INFO_TIMER = 2.0;
const double GAME_SCORE_INFO_FADE_OUT_TIME = 0.5;
//Not constant because i am bad
int GAME_MAX_SCORE = 5;

//PLEASE USE A BUCKET FOR YOUR BARF AND NOT THE KEYBOARD
//Game Settings (1P)
bool SETTINGS_ARE_SELECTED = false;
bool SCORELIMIT_LOW = false;
bool SCORELIMIT_MID = false;
bool SCORELIMIT_NONE = false;
bool TIMELIMIT_LOW = false;
bool TIMELIMIT_MID = false;
bool TIMELIMIT_NONE = false;
bool DIFFICULTY_LOW = false;
bool DIFFICULTY_MID = false;
bool DIFFICULTY_HIGH = false;
bool CONTROLS_MOUSE = false;
bool CONTROLS_KEYS = false;

//Extra Game Settings (2P)
bool TWO_PLAYER_GAME = false;
bool PLAYER_TWO_CONTROLS_MOUSE = false;
bool PLAYER_TWO_CONTROLS_KEYS = false;

//Ball Constants
const float GAME_BALL_RADIUS_PERCENTAGE = 0.012f;
const float GAME_BALL_DEFAULT_SPEED = 250.0f;
const float GAME_BALL_SPEED_INCREMENT = 50.0f;
const char* GAME_BALL_TYPE = "Ball";

//Paddle Constants
const float GAME_PADDLE_WIDTH_PERCENTAGE = 0.025f;
const float GAME_LEFT_PADDLE_X_PERCENTAGE = 0.05f;
const float GAME_RIGHT_PADDLE_X_PERCENTAGE = 0.95f;
const float GAME_PADDLE_Y_PERCENTAGE = 0.5f;
const float GAME_PADDLE_ACCELERATION = 50.0f;
const float GAME_PADDLE_MAX_SPEED = 200.0f;
const char* GAME_PADDLE_TYPE = "Paddle";
//Not constant for difficulty because i am bad
float GAME_PADDLE_HEIGHT_PERCENTAGE = 0.2f;