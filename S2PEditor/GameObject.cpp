#include "GameObject.h"
#include "Game.h"
#include "TextureManager.h"
#include "TileLayer.h"
#include "LoaderParams.h"
#include "Camera.h"
#include "Collision.h"

using namespace std;

GameObject::GameObject() :
m_bJumping{ false },
m_sdlFlip{ SDL_FLIP_NONE }
{
}

void GameObject::load(unique_ptr<LoaderParams> const &pParams)
{
	m_position = Vector2D(pParams->getX(), pParams->getY());
	m_animations = pParams->getAnimations();
	m_xSpeed = pParams->getXSpeed();
	m_ySpeed = pParams->getYSpeed();
	m_value = pParams->getValue();
	m_value2 = pParams->getValue2();
	m_value3 = pParams->getValue3();
	m_sndID = pParams->getSoundID();
	m_snd2ID = pParams->getSound2ID();
	if (m_xSpeed < 0)
	{
		m_sdlFlip = SDL_FLIP_HORIZONTAL;
	}
}

// draw the object to the screen
void GameObject::draw()
{
	TheTextureManager::Instance().drawFrame(getTextureID(),
		m_position.x() - TheCamera::Instance().getPosition().x(),
		m_position.y() - TheCamera::Instance().getPosition().y(),
		getWidth(), getHeight(), m_currentAnim.getCurrentFrame(),
		TheGame::Instance().getRenderer(), m_sdlFlip);
}

void GameObject::collision(Player *pPlayer) {}

bool GameObject::checkCollideTile(Vector2D newPos)
{
	// Top left collider position
	Vector2D startPos(newPos.x() + getCollider().x, newPos.y() + getCollider().y);
	// Bottom right collider position
	Vector2D endPos(startPos.x() + getCollider().w, startPos.y() + getCollider().h);
	for (auto pTileLayer : *m_pCollisionLayers)
	{
		int tileColumn, tileRow, tileid = 0;
		int tileSize = pTileLayer->getTileSize();

		// Check if collidable area gets out the map. This can happen due to bounding box exceeding frame size.
		if (endPos.x() > TheGame::Instance().getMapWidth())
		{
			endPos.x(TheGame::Instance().getMapWidth());
		}
		else if (endPos.y() > TheGame::Instance().getMapHeight())
		{
			endPos.y(TheGame::Instance().getMapHeight());
		}

		// Get layer tiles. 
		const vector<vector<int>> &tiles = pTileLayer->getTileIDs();
		// Check for the whole collidable surface of the object if there is collision with a tile
		for (int i = startPos.x(); i < endPos.x(); i++)
		{
			for (int j = startPos.y(); j < endPos.y(); j++)
			{
				tileColumn = i / tileSize;
				tileRow = j / tileSize;
				tileid = tiles[tileRow][tileColumn];
				if (tileid != 0)
				{
					return true;
				}
			}
		}
	}

	return false;
}

bool GameObject::checkCollideObject(Vector2D newPos)
{
	SDL_Rect playerRect, objectRect;
	playerRect.x = newPos.x() + getCollider().x;
	playerRect.y = newPos.y() + getCollider().y;
	playerRect.w = getCollider().w;
	playerRect.h = getCollider().h;

	for (auto pObject : *m_pCollisionObjects)
	{
		// Second rectangle to RectRect collision function (each of the enemy objects)
		SDL_Rect objectRect;
		objectRect.x = pObject->getPosition().x() + pObject->getCollider().x;
		objectRect.y = pObject->getPosition().y() + pObject->getCollider().y;
		objectRect.w = pObject->getCollider().w;
		objectRect.h = pObject->getCollider().h;

		if (RectRect(playerRect, objectRect))
		{
			//Make actions related with collision before returning true
			if (type() == "Player")
			{
				// Collision with player
				pObject->collision(static_cast<Player*>(pObject));	// No need for player pointer
			}
			else
			{
				// Collision with enemy
				pObject->collision(nullptr);
			}
			return true;
		}
	}

	return false;
}

// getters for common variables
Vector2D& GameObject::getPosition() { return m_position; }
Vector2D& GameObject::getVelocity() { return m_velocity; }

int GameObject::getXSpeed(){ return m_xSpeed; }
int GameObject::getYSpeed(){ return m_ySpeed; }

string GameObject::getTextureID()
{ 
	return m_currentAnim.getTextureID(); 
}

// is the object currently being updated?
bool GameObject::updating() { return m_bUpdating; }

// is the object dead?
bool GameObject::dead() { return m_bDead; }

// is the object doing a death animation?
bool GameObject::dying() { return m_bDying; }
bool GameObject::deadly() { return m_deadly; }
//bool GameObject::pickable() { return m_pickable; }

// set whether to update the object or not
void GameObject::setUpdating(bool updating) { m_bUpdating = updating; }

void GameObject::setCollisionLayers(vector<TileLayer*>* layers) { m_pCollisionLayers = layers; }
void GameObject::setCollisionObjects(vector<GameObject*>* objects) { m_pCollisionObjects = objects; }

GameObject::~GameObject() {}

SDL_Rect GameObject::getCollider()
{
	return m_currentAnim.getCollider();
}

int GameObject::getWidth()
{
	return m_currentAnim.getWidth();
}

int GameObject::getHeight()
{
	return m_currentAnim.getHeight();
}

map<string, Animation> GameObject::getAnimations()
{
	return m_animations;
}

int GameObject::getValue()
{
	return m_value;
}

int GameObject::getValue2()
{
	return m_value2;
}

int GameObject::getValue3()
{
	return m_value3;
}

string GameObject::getSoundID()
{
	return m_sndID;
}

string GameObject::getSound2ID()
{
	return m_snd2ID;
}

void GameObject::setCollidable(bool coll)
{
	m_collidable = coll;
}

bool GameObject::collidable()
{
	return m_collidable;
}