#ifndef _UIBUTTON_H_
#define _UIBUTTON_H_

class OpenGLTexture;
class UIButtonListener;

class UIButton
{
public:
	UIButton(const char* textureFile);
	~UIButton();

	void paint();

	void setListener(UIButtonListener* listener);
	void mouseMovementEvent(float positionX, float positionY);
	void mouseLeftClickUpEvent(float positionX, float positionY);
	//void mouseLeftClickDownEvent(float positionX, float positionY);

	void setCenterPosition(float centerX, float centerY);
	void setIsSelected(bool isSelected);
	bool getIsSelected();

private:
	UIButtonListener* m_Listener;
	OpenGLTexture* m_NormalState;
	OpenGLTexture* m_SelectedState;
	float m_CenterPositionX;
	float m_CenterPositionY;
	bool m_IsSelected;
};

class UIButtonListener
{
public:
	virtual void buttonAction(UIButton* button) = 0;
};

#endif