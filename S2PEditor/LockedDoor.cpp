#include "LockedDoor.h"
#include <iostream>
#include "Game.h"
#include "Player.h"
#include "SoundManager.h"

LockedDoor::LockedDoor()
{
}

LockedDoor::~LockedDoor()
{
}

void LockedDoor::load(std::unique_ptr<LoaderParams> const &pParams)
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

void LockedDoor::draw()
{
	GameObject::draw();
}

void LockedDoor::update()
{
	m_currentAnim.setFrame(int(SDL_GetTicks() / m_currentAnim.getFrameTime()) % m_currentAnim.getNFrames());
}

std::string LockedDoor::type()
{
	return "LockedDoor";
}


void LockedDoor::collision(Player *pPlayer)
{
	if (pPlayer != nullptr)
	{
		// If the player has enough keys, open the door
		if (TheGame::Instance().getKeys() >= m_value)
		{
			m_bDead = true;
			// Substract keys from player inventory
			TheGame::Instance().addKeys(-m_value);
			// Play open sound
			TheSoundManager::Instance().playSound(m_sndID, 0);
		}
	}
}

GameObject* LockedDoorCreator::createGameObject() const
{
	return new LockedDoor();
}