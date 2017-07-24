#include "Chaser.h"
#include "Game.h"
#include "TextureManager.h"
#include "Camera.h"
#include "TileLayer.h"

Chaser::Chaser() : Enemy()
{
}

Chaser::~Chaser()
{
}

std::string Chaser::type()
{
	return "Chaser";
}

void Chaser::load(std::unique_ptr<LoaderParams> const &pParams)
{
	Enemy::load(std::move(pParams));
	// Alias
	m_viewDistance = m_value3;
	m_currentAnim = m_animations["idle"];
}

void Chaser::setTarget(Vector2D& target)
{
	m_playerPos = &target;
}

void Chaser::update()
{
	if (m_playerPos != nullptr)
	{
		Vector2D diff = *m_playerPos - m_position;
		// Check if player is inside Chaser field of vision
		if (diff.length() <= m_viewDistance)
		{
			if (abs(diff.x()) < m_treshold)
			{
				// Player caught in x axis, stop
				m_velocity.x(0);
			}
			else
			{
				if (diff.x() < 0)
				{
					// x speed can be negative so we have to take abs value
					m_velocity.x(-abs(m_xSpeed));
				}
				else if (diff.x() > 0)
				{
					//m_velocity.x(m_xSpeed);
					m_velocity.x(abs(m_xSpeed));
				}
			}
		}
		else
		{
			// Player is outside Chaser's vision camp
			m_velocity.x(0);
		}
		m_velocity.y(m_ySpeed);
		handleMovement(m_velocity);
	}
	handleAnimation();
}

void Chaser::handleMovement(Vector2D velocity)
{
	Vector2D newPos = m_position;
	newPos.x(m_position.x() + velocity.x());

	if (newPos.x() == m_playerPos->x())
	{
		m_velocity.x(0);
	}
	else
	{
		// check if the chaser is trying to go off the map
		if (newPos.x() + getCollider().x < 0)
		{
			m_position.x(-getCollider().x);
		}
		else if (newPos.x() + getCollider().x + getCollider().w > TheGame::Instance().getMapWidth())
		{
			m_position.x(TheGame::Instance().getMapWidth() - getCollider().w - getCollider().x);
		}
		else
		{
			if (checkCollideTile(newPos) || checkCollideObject(newPos))
			{
				// collision, stop x movement
				m_velocity.x(0);

				if (checkCollideTile(newPos))
				{
					// Collision with the map, move to contact
					if (m_position.x() < newPos.x())	// Collision with tile to the right
					{
						m_position.x(m_position.x() + (
							abs(m_xSpeed) - (int(newPos.x() + getCollider().x + getCollider().w) % (*m_pCollisionLayers->begin())->getTileSize())));

					}
					else   // Collision with tile to the left
					{
						m_position.x(m_position.x() -
							(int(m_position.x() + getCollider().x) % (*m_pCollisionLayers->begin())->getTileSize()));
					}
				}
			}
			else
			{
				// no collision, add to the actual x position
				m_position.x(newPos.x());
			}
		}
	}

	newPos.x(m_position.x());
	newPos.y(m_position.y() + velocity.y());

	// check if the chaser is going below map limits
	if (newPos.y() + getCollider().y + getCollider().h > TheGame::Instance().getMapHeight())
	{
		m_position.y(TheGame::Instance().getMapHeight() - getCollider().h - getCollider().y);
		m_velocity.y(0);
	}
	else
	{
		if (checkCollideTile(newPos) || checkCollideObject(newPos))
		{
			// Collision, stop y movement
			m_velocity.y(0);

			if (checkCollideTile(newPos))
			{
				// Collision with map, move to contact. Chaser doesn't jump so it's a lower tile
				m_position.y(m_position.y() +
					(m_ySpeed - (int(newPos.y() + getCollider().y + getCollider().h) % (*m_pCollisionLayers->begin())->getTileSize())));
			}
		}
		else
		{
			// no collision, add to the actual y position
			m_position.y(newPos.y());
		}
	}
}

void Chaser::handleAnimation()
{
	if (m_velocity.x() == 0)
	{
		m_currentAnim = m_animations["idle"];
	}
	else
	{
		m_currentAnim = m_animations["walk"];
		// Set flip depending on moving direction
		(m_velocity.x() > 0) ? (m_sdlFlip = SDL_FLIP_NONE) : (m_sdlFlip = SDL_FLIP_HORIZONTAL);
	}

	// Frame is float so no error if divission by zero occurs (resulting frame will be 0)
	m_currentAnim.setFrame(int(SDL_GetTicks() / m_currentAnim.getFrameTime()) % m_currentAnim.getNFrames());
}

GameObject* ChaserCreator::createGameObject() const
{
	return new Chaser();
}