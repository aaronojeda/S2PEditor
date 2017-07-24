#include "ParallaxBck.h"
#include "Game.h"
#include "TextureManager.h"
#include "Camera.h"

ParallaxBck::ParallaxBck() : Background(),
m_scrollRatioX{ 1. },
m_scrollRatioY{ 1. }
{
}

ParallaxBck::~ParallaxBck()
{
}

void ParallaxBck::draw()
{
	TheTextureManager::Instance().draw(getTextureID(),
		-TheCamera::Instance().getPosition().x() / m_scrollRatioX,
		-TheCamera::Instance().getPosition().y() / m_scrollRatioY,
		TheGame::Instance().getRenderer(), m_sdlFlip);
}

void ParallaxBck::setScrollRatioX(float ratio) 
{ 
	m_scrollRatioX = ratio; 
}

void ParallaxBck::setScrollRatioY(float ratio) 
{
	m_scrollRatioY = ratio; 
}

GameObject* ParallaxBckCreator::createGameObject() const
{
	return new ParallaxBck();
}