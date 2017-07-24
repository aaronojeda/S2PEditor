#include "HealthItem.h"
#include <iostream>
#include "Game.h"
#include "SoundManager.h"

HealthItem::HealthItem()
{
}


HealthItem::~HealthItem()
{
}

void HealthItem::load(std::unique_ptr<LoaderParams> const &pParams)
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

void HealthItem::draw()
{
	GameObject::draw();
}

void HealthItem::update()
{
	m_currentAnim.setFrame(int(SDL_GetTicks() / m_currentAnim.getFrameTime()) % m_currentAnim.getNFrames());
}

std::string HealthItem::type()
{
	return "HealthItem";
}


void HealthItem::collision(Player *pPlayer)
{
	// If the player is at full health, do nothing
	if (TheGame::Instance().getHealth() < TheGame::Instance().getMaxHealth())
	{
		TheGame::Instance().addHealth(m_value);
		m_bDead = true;
		// play sound
		TheSoundManager::Instance().playSound(m_sndID, 0);
	}
}

GameObject* HealthItemCreator::createGameObject() const
{
	return new HealthItem();
}