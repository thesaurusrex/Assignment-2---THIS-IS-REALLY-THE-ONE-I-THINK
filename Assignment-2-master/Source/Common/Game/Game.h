#ifndef GAME_H
#define GAME_H

#include <vector>
#include "../Screen Manager/Screen.h"

class GameObject;
class OpenGLTexture;
class GameSettings;

class Game : public Screen, public InputListener
{
public:
    Game();
    ~Game();

    //Game lifecycle methods-
    void update(double delta);
    void paint();
    void reset();

    //Game Over method, call this when to end the game
    void gameOver();
    void leftGoal();
	void setLeftGoal();
    void rightGoal();
	void setRightGoal();
    
    //Screen name, must be implemented, it's a pure
    //virtual method in the Screen class
    const char* getName();

    //Screen event method, inherited from the screen class
    void screenWillAppear();
    
	//Conveniance method used to paint the score info, drawn after
    //a goal is scored to update the user on the current score
    void paintScoreInfo(float alpha);

    //GameObject Methods
    void addGameObject(GameObject* gameObject);
    GameObject* getGameObjectByType(const char* type);
    
private:
    //Key Events
    void keyUpEvent(int keyCode);
    void keyDownEvent(int keyCode);

	//Mouse Events
	void mouseMovementEvent(float aDeltaX, float aDeltaY, float aPositionX, float aPositionY);
    
    //Method to reset the ball, called after a goal is scored. The
    //parameter determines which direction the ball will go in
    //after a goal is scored.
    void resetBall(bool leftGoal);
    
    //Vector to hold the GameObjects
    std::vector<GameObject*> m_GameObjects;
    
	//Background textures
	OpenGLTexture* m_GameBackgroundTexture;

    //Texture's used for the score info
    OpenGLTexture* m_AlgonquinLogo;
    OpenGLTexture* m_ScoreInfoBackground;
    OpenGLTexture* m_ScoreInfoGoal;
    OpenGLTexture* m_ScoreInfoLeft;
    OpenGLTexture* m_ScoreInfoRight;
    OpenGLTexture** m_ScoreInfoNumbers;

    //Score Info variables
    double m_ScoreInfoTimer;
    float m_ScoreInfoAlpha;
	
	//for timer
	double m_GameTime;
    
    //Score variables
    short m_LeftGoalsScored;
    short m_RightGoalsScored;
};

#endif