#include "LevelFinish.h"
#include <iostream>
#include "Game.h"
#include "SoundManager.h"

LevelFinish::LevelFinish()
{
}

LevelFinish::~LevelFinish()
{
}

void LevelFinish::load(std::unique_ptr<LoaderParams> const &pParams)
{
	GameObject::load(std::move(pParams));
	if (m_animations.find("idle") == m_animations.end())
	{
		std::cout << "Error: Couldn't find idle animation\n";
	}
	else
	{
		m_currentAnim = m_animations["idle"];
	}
}

void LevelFinish::draw()
{
	// Do nothing. The deadly object will be represented by the tiles (spikes, lava, etc.)

	GameObject::draw();
}

void LevelFinish::update()
{
	m_currentAnim.setFrame(int(SDL_GetTicks() / m_currentAnim.getFrameTime()) % m_currentAnim.getNFrames());
}

std::string LevelFinish::type()
{
	return "LevelFinish";
}


void LevelFinish::collision(Player *pPlayer)
{
	if (pPlayer != nullptr)
	{
		// The player has completed the level
		TheGame::Instance().setLevelCompleted(true);
		// Play level completed sound
		TheSoundManager::Instance().playSound(m_sndID, 0);
	}
}

GameObject* LevelFinishCreator::createGameObject() const
{
	return new LevelFinish();
}