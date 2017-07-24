#include "StaticBck.h"
#include "Game.h"
#include "TextureManager.h"

StaticBck::StaticBck()
{
}

StaticBck::~StaticBck()
{
}

void StaticBck::draw()
{
	// Static background that does not scroll with the camera
	TheTextureManager::Instance().draw(getTextureID(), 0, 0, TheGame::Instance().getRenderer(), m_sdlFlip);
}

GameObject* StaticBckCreator::createGameObject() const
{
	return new StaticBck();
}