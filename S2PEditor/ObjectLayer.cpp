#include "ObjectLayer.h"
#include <algorithm>
#include "GameObject.h"
#include "Vector2D.h"
#include "Game.h"
#include "Level.h"
#include "Camera.h"

const std::string ObjectLayer::s_objectLayerID = "OBJECT";

ObjectLayer::~ObjectLayer()
{
	for (auto object : m_gameObjects)
	{
		delete object;
	}
	m_gameObjects.clear();
}

void ObjectLayer::update(Level* pLevel)
{
	m_collisionManager.checkCollision(pLevel->getPlayer(), (const std::vector<GameObject*>&)m_gameObjects);

	// iterate through the objects
	if (!m_gameObjects.empty())
	{
		//for (std::vector<GameObject*>::iterator it = m_gameObjects.begin(); it != m_gameObjects.end();)
		for (auto it = m_gameObjects.begin(); it != m_gameObjects.end();)
		{
			// check if dead
			if ((*it)->dead())
			{
				// If the object is collidable, erase-remove it from the collision objects vector
				if ((*it)->collidable())
				{
					auto collObjects = pLevel->getCollisionObjects();
					// erase-remove idiom
					collObjects->erase(std::remove(collObjects->begin(), collObjects->end(), *it), collObjects->end());
				}
				delete *it;	// eliminate game object
				it = m_gameObjects.erase(it); // erase from vector and get new iterator
			}
			else
			{
				if ((*it)->updating())	// Previously on camera
				{
					(*it)->update();
				}
				else   // Hasn't been on camera yet
				{
					// If the object is within the camera or to the left
					if ((*it)->getPosition().x() <= TheCamera::Instance().getPosition().x() + TheGame::Instance().getGameWidth())
					{
						(*it)->setUpdating(true);
						(*it)->update();
					}
					else
					{
						// The object is to the right of the camera and it is not updating, i.e. it has not appeared yet
						(*it)->setUpdating(false);
					}
				}
				++it; // increment 
			}
		}
	}
}

void ObjectLayer::render()
{
	GameObject* pPlayer = nullptr;
	for (auto object : m_gameObjects)
	{
		// Check if object is inside the viewable area
		if ((object->getPosition().x() + object->getWidth() > TheCamera::Instance().getPosition().x() &&
			object->getPosition().x() < TheCamera::Instance().getPosition().x() + TheGame::Instance().getGameWidth() &&
			object->getPosition().y() + object->getHeight() > TheCamera::Instance().getPosition().y() &&
			object->getPosition().y() < TheCamera::Instance().getPosition().y() + TheGame::Instance().getGameHeight()))
		{
			// The player will be drawn at the end
			if (object->type() == "Player")
			{
				pPlayer = object;
			}
			else
			{
				object->draw();
			}
		}
	}
	// Draw player if any
	if (pPlayer != nullptr)
	{
		pPlayer->draw();
	}
}
