#include "LeftRight.h"
#include "TextureManager.h"
#include "Game.h"
#include "Camera.h"
#include "TileLayer.h"
#include "LoaderParams.h"

using namespace std;

LeftRight::LeftRight() : Enemy()
{
}

LeftRight::~LeftRight()
{
}

void LeftRight::load(unique_ptr<LoaderParams> const &pParams)
{
	Enemy::load(move(pParams));
	if (m_animations.find("walk") == m_animations.end())
	{
		cout << "Error: No se ha podido obtener la animación 'walk' para el tipo LeftRight\n";
	}
	else
	{
		m_walkingAnim = m_animations["walk"];
		m_currentAnim = m_walkingAnim;
	}
	// Maybe the user gave a negative gravity, which is not possible since LeftRight don't fly
	if (m_ySpeed < 0) m_ySpeed *= -1;
}

string LeftRight::type()
{
	return "LeftRight";
}

void LeftRight::update()
{
	if (m_bXCollision)
	{
		m_velocity.x(-m_xSpeed);
	}
	else
	{
		m_velocity.x(m_xSpeed);
	}
	
	m_velocity.y(m_ySpeed);

	handleMovement(m_velocity);
	handleAnimation();
}

void LeftRight::handleMovement(Vector2D velocity)
{
	Vector2D newPos = m_position;
	newPos.y(newPos.y() + velocity.y());
	
	// Check if object is going below the map limits
	if (!m_bLanded)
	{
		if (newPos.y() + getCollider().y + getCollider().h >= TheGame::Instance().getMapHeight())
		{
			m_position.y(TheGame::Instance().getMapHeight() - getCollider().h - getCollider().y);
		}
		else
		{
			if (checkCollideTile(newPos) || checkCollideObject(newPos))
			{
				// Collision, stop y movement
				m_velocity.y(0);

				if (checkCollideTile(newPos))
				{
					// Collision with map, move to contact. LeftRight doesn't jump so it's a lower tile
					m_position.y(m_position.y() +
						(m_ySpeed - (int(newPos.y() + getCollider().y + getCollider().h) % (*m_pCollisionLayers->begin())->getTileSize())));
					// The enemy has landed
					m_bLanded = true;
					m_landedY = m_position.y() + getCollider().y + getCollider().h;
				}
			}
			else
			{
				//No collision, move to new y position
				m_position.y(newPos.y());
			}
		}
	}

	// get the current position after y movement
	newPos = m_position;
	newPos.x(m_position.x() + velocity.x());
	// After correcting y position, check if there is collision in x axis
	if (newPos.x() + getCollider().x <= 0
		|| newPos.x() + getCollider().x + getCollider().w >= TheGame::Instance().getMapWidth()
		|| checkCollideTile(newPos)
		|| checkCollideObject(newPos)
		|| (m_bLanded && checkEdgeTile(newPos.x())))
	{
		// There have been a collision or an edge, so change direction
		m_bXCollision = !m_bXCollision;
	}
	else
	{
		// No collision, move to new x position
		m_position.x(newPos.x());
	}
}

void LeftRight::handleAnimation()
{
	if (m_velocity.x() < 0)
	{
		m_sdlFlip = SDL_FLIP_HORIZONTAL;
	}
	else if (m_velocity.x() > 0)
	{
		m_sdlFlip = SDL_FLIP_NONE;
	}

	// Frame is float so no error if divission by zero occurs (resulting frame will be 0)
	m_currentAnim.setFrame(int(SDL_GetTicks() / m_currentAnim.getFrameTime()) % m_currentAnim.getNFrames());
}

bool LeftRight::checkEdgeTile(int x)
{
	int xBorder;
	if (m_velocity.x() > 0)
	{
		xBorder = x + getCollider().x + getCollider().w;
	}
	else //if (m_velocity.x() < 0) 
	{
		xBorder = x + getCollider().x;
	}

	for (auto pTileLayer : *m_pCollisionLayers)
	{
		// Get tile column 
		int tileColumn = xBorder / pTileLayer->getTileSize();
		// Get tile row
		int tileRow = m_landedY / pTileLayer->getTileSize();
		// Get layer tiles
		auto tileIDs = pTileLayer->getTileIDs();

		// We don't add 1 to tileRow because m_landedY is the first pixel (and thus tileRow
		// the first tile) below the enemy collision box
		return (tileIDs[tileRow][tileColumn] == 0);
	}
	return false;
}

GameObject* LeftRightCreator::createGameObject() const
{
	return new LeftRight();
}