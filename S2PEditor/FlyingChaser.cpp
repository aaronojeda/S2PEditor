#include "FlyingChaser.h"
#include "Game.h"
#include "TileLayer.h"

FlyingChaser::FlyingChaser() : Chaser()
{
}

FlyingChaser::~FlyingChaser()
{
}

std::string FlyingChaser::type()
{
	return "FlyingChaser";
}

void FlyingChaser::update()
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
					//m_velocity.x(-m_xSpeed);
					m_velocity.x(-abs(m_xSpeed));
				}
				else if (diff.x() > 0)
				{
					//m_velocity.x(m_xSpeed);
					m_velocity.x(abs(m_xSpeed));
				}
			}
		
			if (abs(diff.y()) < m_treshold)
			{
				// Player caught in y axis, stop
				m_velocity.y(0);
			}
			else
			{
				if (diff.y() < 0)
				{
					m_velocity.y(-m_ySpeed);
				}
				else if (diff.y() > 0)
				{
					m_velocity.y(m_ySpeed);
				}
			}
		}
		else
		{
			m_velocity = { 0, 0 };
		}
		handleMovement(m_velocity);
	}
	handleAnimation();
}

void FlyingChaser::handleMovement(Vector2D velocity)
{
	Vector2D newPos = m_position;
	newPos.x(m_position.x() + velocity.x());

	if (checkCollideTile(newPos) || checkCollideObject(newPos))
	{
		// Collision, stop x movement
		m_velocity.x(0);

		if (checkCollideTile(newPos))
		{
			// Collision with map. Move to contact
			if (m_position.x() < newPos.x())	
			{
				// Collision with tile to the right
				m_position.x(m_position.x() + (
					abs(m_xSpeed) - (int(newPos.x() + getCollider().x + getCollider().w) % (*m_pCollisionLayers->begin())->getTileSize())));
			}
			else  
			{
				// Collision with tile to the left
				m_position.x(m_position.x() -
					(int(m_position.x() + getCollider().x) % (*m_pCollisionLayers->begin())->getTileSize()));
			}
		}
	}
	else
	{
		// No collision, add to the actual x position
		m_position.x(newPos.x());
	}

	newPos = m_position;	// update newPos after x movement
	newPos.y(m_position.y() + velocity.y());

	if (checkCollideTile(newPos) || checkCollideObject(newPos))
	{
		// Collision, stop y movement
		m_velocity.y(0);

		if (checkCollideTile(newPos))
		{
			// Collision with the map, move to contact
			if (m_position.y() < newPos.y())
			{
				// Collision with lower tile
				m_position.y(m_position.y() +
					(m_ySpeed - (int(newPos.y() + getCollider().y + getCollider().h) %
					(*m_pCollisionLayers->begin())->getTileSize())));
			}
			else
			{
				// Collision with upper tile
				m_position.y(m_position.y() -
					(int(m_position.y() + getCollider().y) % (*m_pCollisionLayers->begin())->getTileSize()));
			}
		}
	}
	else
	{
		// No collision, add to the actual y position
		m_position.y(newPos.y());
	}
}

GameObject* FlyingChaserCreator::createGameObject() const
{
	return new FlyingChaser();
}
