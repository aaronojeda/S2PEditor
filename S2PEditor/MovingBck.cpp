#include "MovingBck.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "Game.h"

MovingBck::MovingBck()
{
}

MovingBck::~MovingBck()
{
}

void MovingBck::load(std::unique_ptr<LoaderParams> const &pParams)
{
	Background::load(std::move(pParams));
	// Specific load actions for moving bcks
	m_scrollSpeed = pParams->getXSpeed();
	//m_maxcount = pParams->getValue();
	// Initializing first rect
	m_srcRect1.x = 0;
	m_destRect1.x = m_position.x();
	m_srcRect1.y = 0;
	m_destRect1.y = m_position.y();
	m_srcRect1.w = m_destRect1.w = m_srcRect2Width = m_destRect1Width = getWidth();
	m_srcRect1.h = m_destRect1.h = getHeight();
	// Initializing second rect
	m_srcRect2.x = 0;
	m_destRect2.x = m_position.x() + getWidth();
	m_srcRect2.y = 0;
	m_destRect2.y = m_position.y();
	m_srcRect2.w = m_destRect2.w = m_srcRect2Width = m_destRect2Width = 0;
	m_srcRect2.h = m_destRect2.h = getHeight();
}

void MovingBck::draw()
{
	// draw first rect
	SDL_RenderCopyEx(TheGame::Instance().getRenderer(), TheTextureManager::Instance().getTextureMap()[getTextureID()], &m_srcRect1, &m_destRect1, 0, 0, SDL_FLIP_NONE);
	// draw second rect
	SDL_RenderCopyEx(TheGame::Instance().getRenderer(), TheTextureManager::Instance().getTextureMap()[getTextureID()], &m_srcRect2, &m_destRect2, 0, 0, SDL_FLIP_NONE);	
}

void MovingBck::update()
{
	// make first rectangle smaller
	m_srcRect1.x += m_scrollSpeed;
	m_srcRect1.w -= m_scrollSpeed;
	m_destRect1.w -= m_scrollSpeed;
		
	// make second rectangle bigger
	m_srcRect2.w += m_scrollSpeed;
	m_destRect2.w += m_scrollSpeed;
	m_destRect2.x -= m_scrollSpeed;

	// If the expanding rectangle has reached its full width, reset and start again
	if (m_destRect2.w >= getWidth())
	{
		m_srcRect1.x = 0;
		m_destRect1.x = m_position.x();
		m_srcRect1.y = 0;
		m_destRect1.y = m_position.y();

		m_srcRect1.w = m_destRect1.w = m_srcRect2Width = m_destRect1Width = getWidth();
		m_srcRect1.h = m_destRect1.h = getHeight();

		m_srcRect2.x = 0;
		m_destRect2.x = m_position.x() + getWidth();
		m_srcRect2.y = 0;
		m_destRect2.y = m_position.y();

		m_srcRect2.w = m_destRect2.w = m_srcRect2Width = m_destRect2Width = 0;
		m_srcRect2.h = m_destRect2.h = getHeight();
	}
}

GameObject* MovingBckCreator::createGameObject() const
{
	return new MovingBck();
}