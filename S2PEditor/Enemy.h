#ifndef __Enemy__
#define __Enemy__

#include "GameObject.h"
#include <iostream>

class Player;
class LoaderParams;

// Enemy base class
class Enemy : public GameObject // Inherits from GameObject
{
public:
	virtual void load(std::unique_ptr<LoaderParams> const &pParams);
	virtual std::string type() { return "Enemy"; }
	virtual void draw();
	virtual void collision(Player *pPlayer);

protected:
	// Damage that the enemy causes the player on contact
	int m_damage{ 0 };
	// Initial health of the enemy
	int m_health{ 0 };
	// Remaining health of the enemy
	int m_remHealth{ 0 };
	std::string m_sndHurt, m_sndAttack;

	Enemy() : GameObject()
	{
		m_deadly = true;
	}
	virtual ~Enemy() {}
};

#endif /* defined(__Enemy__) */