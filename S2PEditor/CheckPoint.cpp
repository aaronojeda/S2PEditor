#include "CheckPoint.h"
#include <iostream>
#include "Player.h"
#include "Game.h"
#include "SoundManager.h"

CheckPoint::CheckPoint()
{
}

CheckPoint::~CheckPoint()
{
}

void CheckPoint::load(std::unique_ptr<LoaderParams> const &pParams)
{
	GameObject::load(std::move(pParams));
	if (m_animations.find("idle") == m_animations.end())
	{
		std::cout << "Error: No se ha podido obtener la animación 'idle'\n";
	}
	else
	{
		m_currentAnim = m_animations["idle"];
	}
}

void CheckPoint::draw()
{
	GameObject::draw();
}

void CheckPoint::update()
{
	m_currentAnim.setFrame(int(SDL_GetTicks() / m_currentAnim.getFrameTime()) % m_currentAnim.getNFrames());
}

std::string CheckPoint::type()
{
	return "CheckPoint";
}


void CheckPoint::collision(Player *pPlayer)
{
	if (pPlayer != nullptr)
	{
		// Inform the game about a new checkPoint reached and its position
		TheGame::Instance().setCheckPoint(true, pPlayer->getPosition());

		// Play sound if it's the first time CP is reached or 4 secs has passed since last
		if (m_sndTimer.getMs() > 3000 || !m_sndPlayed)
		{
			// play sound
			TheSoundManager::Instance().playSound(m_sndID, 0);
			m_sndTimer.start();
			m_sndPlayed = true;
		}

	}
}

GameObject* CheckPointCreator::createGameObject() const
{
	return new CheckPoint();
}
