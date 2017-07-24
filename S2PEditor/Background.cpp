#include "Background.h"
#include "TextureManager.h"
#include "Game.h"
#include "LoaderParams.h"
#include "Camera.h"

Background::Background() : GameObject()
{
}

void Background::load(std::unique_ptr<LoaderParams> const &pParams)
{
	GameObject::load(std::move(pParams));
	m_currentAnim = m_animations["idle"];
}

void Background::draw()
{
	// Static background that does not scroll with the camera
	TheTextureManager::Instance().drawFrame(getTextureID(),
		0, 0, getWidth(), getHeight(), m_currentAnim.getCurrentFrame(),
		TheGame::Instance().getRenderer(), m_sdlFlip);
}

void Background::update()
{
}

GameObject* BackgroundCreator::createGameObject() const
{
	return new Background();
}