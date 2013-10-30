#include "UIButton.h"
#include "../OpenGL/OpenGL.h"
#include <stdlib.h>
#include <string>
#include "../Utils/Utils.h"

UIButton::UIButton(const char* textureFile) :
	m_Listener(NULL),
	m_NormalState(NULL),
	m_SelectedState(NULL),
	m_CenterPositionX(0.0f),
	m_CenterPositionY(0.0f),
	m_IsSelected(false)
{
	//Create normal state texture object
	m_NormalState = new OpenGLTexture(textureFile);
	//Large texture of the same name with "-Large" appended to it
	std::string largeTextureFile = std::string(textureFile);
	largeTextureFile += "-Large";
	//Create selected state texture object
	m_SelectedState = new OpenGLTexture(largeTextureFile.c_str());
}

UIButton::~UIButton()
{
	if(m_NormalState != NULL)
	{
		delete m_NormalState;
		m_NormalState = NULL;
	}

	if(m_SelectedState != NULL)
	{
		delete m_SelectedState;
		m_SelectedState = NULL;
	}
}

void UIButton::paint()
{
	if(m_IsSelected == true)
	{
		float x = m_CenterPositionX - m_SelectedState->getSourceWidth() / 2.0f;
		float y = m_CenterPositionY - m_SelectedState->getSourceHeight() / 2.0f;
		OpenGLRenderer::getInstance()->drawTexture(m_SelectedState, x, y);
	}
	else
	{
		float x = m_CenterPositionX - m_NormalState->getSourceWidth() / 2.0f;
		float y = m_CenterPositionY - m_NormalState->getSourceHeight() / 2.0f;
		OpenGLRenderer::getInstance()->drawTexture(m_NormalState, x, y);
	}
}

void UIButton::mouseMovementEvent(float positionX, float positionY)
{
	float left = m_CenterPositionX - m_SelectedState->getSourceWidth() / 2.0f;
	float right = m_CenterPositionX + m_SelectedState->getSourceWidth() / 2.0f;
	float top = m_CenterPositionY - m_SelectedState->getSourceHeight() / 2.0f;
	float bottom = m_CenterPositionY + m_SelectedState->getSourceHeight() / 2.0f;

	if(positionX >= left && positionX <= right && positionY >= top && positionY <= bottom)
	{
		setIsSelected(true);
	}
	else
	{
		setIsSelected(false);
	}
}

void UIButton::mouseLeftClickUpEvent(float positionX, float positionY)
{
	float left = m_CenterPositionX - m_SelectedState->getSourceWidth() / 2.0f;
	float right = m_CenterPositionX + m_SelectedState->getSourceWidth() / 2.0f;
	float top = m_CenterPositionY - m_SelectedState->getSourceHeight() / 2.0f;
	float bottom = m_CenterPositionY + m_SelectedState->getSourceHeight() / 2.0f;

	if(positionX >= left && positionX <= right && positionY >= top && positionY <= bottom)
	{
		if(m_Listener != NULL)
		{
			m_Listener->buttonAction(this);
		}
	}
}

void UIButton::setListener(UIButtonListener* listener)
{
	m_Listener = listener;
}

void UIButton::setCenterPosition(float centerX, float centerY)
{
	m_CenterPositionX = centerX;
	m_CenterPositionY = centerY;
}

void UIButton::setIsSelected(bool isSelected)
{
	m_IsSelected = isSelected;
}

bool UIButton::getIsSelected()
{
	return m_IsSelected;
}