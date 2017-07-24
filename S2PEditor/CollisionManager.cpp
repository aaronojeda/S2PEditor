#include "CollisionManager.h"
#include "Collision.h"
#include "Player.h"

void CollisionManager::checkCollision(Player* pPlayer, const std::vector<GameObject*> &objects)
{
	if (pPlayer != nullptr)
	{
		SDL_Rect pRect1;
		pRect1.x = pPlayer->getPosition().x() + pPlayer->getCollider().x;
		pRect1.y = pPlayer->getPosition().y() + pPlayer->getCollider().y;
		pRect1.w = pPlayer->getCollider().w;
		pRect1.h = pPlayer->getCollider().h;

		for (auto object : objects)
		{
			if (object == pPlayer || !object->updating())
			{
				continue;
			}

			// Second rectangle to RectRect collision function (each of the enemy objects)
			SDL_Rect pRect2;
			pRect2.x = object->getPosition().x() + object->getCollider().x;
			pRect2.y = object->getPosition().y() + object->getCollider().y;
			pRect2.w = object->getCollider().w;
			pRect2.h = object->getCollider().h;

			if (RectRect(pRect1, pRect2))
			{
				if (!object->dead() && !object->dying()) 
				{
					object->collision(pPlayer);
				}
			}
		}
	}
}
