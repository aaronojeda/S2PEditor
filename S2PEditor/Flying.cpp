#include "Flying.h"
#include "Game.h"

Flying::Flying() : LeftRight()
{
}


Flying::~Flying()
{
}

std::string Flying::type()
{
	return "Flying";
}

void Flying::load(std::unique_ptr<LoaderParams> const &pParams)
{
	Enemy::load(move(pParams));
	if (m_animations.find("walk") == m_animations.end())
	{
		std::cout << "Error: No se ha podido obtener la animación 'walk' para el tipo Flying\n";
	}
	else
	{
		m_walkingAnim = m_animations["walk"];
		m_currentAnim = m_walkingAnim;
	}
}

void Flying::handleMovement(Vector2D velocity)
{
	Vector2D newPos = m_position;
	newPos.y(newPos.y() + velocity.y());
	// Check collisions in y axis
	if (newPos.y() + getCollider().y <= 0
		|| newPos.y() + getCollider().y + getCollider().h >= TheGame::Instance().getMapHeight()
		|| checkCollideTile(newPos)
		|| checkCollideObject(newPos))
	{
		m_bYCollision = !m_bYCollision;
	}
	else
	{
		m_position.y(newPos.y());
	}

	// Update new position
	newPos = m_position;
	newPos.x(m_position.x() + velocity.x());
	// Check collisions in x axis
	if (newPos.x() + getCollider().x <= 0
		|| newPos.x() + getCollider().x + getCollider().w >= TheGame::Instance().getMapWidth()
		|| checkCollideTile(newPos)
		|| checkCollideObject(newPos))
	{
		// There have been a collision, so change direction
		m_bXCollision = !m_bXCollision;
	}
	else
	{
		// Move to new x position
		m_position.x(newPos.x());
	}
}


void Flying::update()
{
	if (m_bXCollision)
	{
		m_velocity.x(-m_xSpeed);
	}
	else
	{
		m_velocity.x(m_xSpeed);
	}

	if (m_bYCollision)
	{
		m_velocity.y(m_ySpeed);
	}
	else
	{
		m_velocity.y(-m_ySpeed);
	}

	handleMovement(m_velocity);
	handleAnimation();
}

GameObject* FlyingCreator::createGameObject() const
{
	return new Flying();
}