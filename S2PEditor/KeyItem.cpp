#include "KeyItem.h"
#include <iostream>
#include "Game.h"
#include "SoundManager.h"

KeyItem::KeyItem()
{
}


KeyItem::~KeyItem()
{
}

void KeyItem::load(std::unique_ptr<LoaderParams> const &pParams)
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

void KeyItem::draw()
{
	GameObject::draw();
}

void KeyItem::update()
{
	m_currentAnim.setFrame(int(SDL_GetTicks() / m_currentAnim.getFrameTime()) % m_currentAnim.getNFrames());
}

std::string KeyItem::type()
{
	return "KeyItem";
}


void KeyItem::collision(Player *pPlayer)
{
	if (TheGame::Instance().getKeys() < TheGame::Instance().getMaxKeys())
	{
		TheGame::Instance().addKeys(m_value);
		m_bDead = true;
		// play sound
		TheSoundManager::Instance().playSound(m_sndID, 0);
	}
}

GameObject* KeyItemCreator::createGameObject() const
{
	return new KeyItem();
}