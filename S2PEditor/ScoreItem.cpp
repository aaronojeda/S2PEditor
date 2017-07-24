#include "ScoreItem.h"
#include "Game.h"
#include <iostream>
#include "SoundManager.h"

ScoreItem::ScoreItem()
{
}

ScoreItem::~ScoreItem()
{
}

void ScoreItem::load(std::unique_ptr<LoaderParams> const &pParams)
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

void ScoreItem::collision(Player *pPlayer)
{
	TheGame::Instance().addScore(m_value);
	m_bDead = true;
	// play sound
	TheSoundManager::Instance().playSound(m_sndID, 0);
}

void ScoreItem::draw()
{
	GameObject::draw();
}

void ScoreItem::update()
{
	m_currentAnim.setFrame(int(SDL_GetTicks() / m_currentAnim.getFrameTime()) % m_currentAnim.getNFrames());
}

std::string ScoreItem::type()
{
	return "ScoreItem";
}

GameObject* ScoreItemCreator::createGameObject() const
{
	return new ScoreItem();
}