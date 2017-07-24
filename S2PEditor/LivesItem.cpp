#include "LivesItem.h"
#include <iostream>
#include "Game.h"
#include "SoundManager.h"

LivesItem::LivesItem()
{
}


LivesItem::~LivesItem()
{
}

void LivesItem::load(std::unique_ptr<LoaderParams> const &pParams)
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

void LivesItem::draw()
{
	GameObject::draw();
}

void LivesItem::update()
{
	m_currentAnim.setFrame(int(SDL_GetTicks() / m_currentAnim.getFrameTime()) % m_currentAnim.getNFrames());
}

std::string LivesItem::type()
{
	return "LivesItem";
}


void LivesItem::collision(Player *pPlayer)
{
	if (TheGame::Instance().getLives() < TheGame::Instance().getMaxLives())
	{
		TheGame::Instance().addLives(m_value);
		m_bDead = true;
		// play sound
		TheSoundManager::Instance().playSound(m_sndID, 0);
	}
}

GameObject* LivesItemCreator::createGameObject() const
{
	return new LivesItem();
}