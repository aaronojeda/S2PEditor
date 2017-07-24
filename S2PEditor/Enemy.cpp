#include "Enemy.h"
//#include "Game.h"
#include "Player.h"
#include "LoaderParams.h"
#include "SoundManager.h"

void Enemy::load(std::unique_ptr<LoaderParams> const &pParams)
{
	// inherited load function
	GameObject::load(move(pParams));
	// Aliases
	m_damage = m_value;
	m_health = m_value2;
	m_sndHurt = m_sndID;
	m_sndAttack = m_snd2ID;
	// Set remaining health to initial health
	m_remHealth = m_health;
}


void Enemy::draw()
{
	GameObject::draw();
}

void Enemy::collision(Player *pPlayer)
{
	// Enemies with health=0 are unkillable and cause damage even if the player jumps over them
	if (m_health == 0)
	{
		pPlayer->hurt(m_damage, m_sndAttack);
	}
	else
	{
		// to know if jump attack was successful
		bool jAttack{ false };
		// If enemy is killable and player is falling, he can perform a jump attack
		if (pPlayer->falling() && !pPlayer->invulnerable() && !pPlayer->dying())
		{
			// get colliders' corners 
			int pRight = pPlayer->getPosition().x() + pPlayer->getCollider().x + pPlayer->getCollider().w;
			int pLeft = pPlayer->getPosition().x() + pPlayer->getCollider().x;
			int pTop = pPlayer->getPosition().y() + pPlayer->getCollider().y;
			int pBottom = pPlayer->getPosition().y() + pPlayer->getCollider().y + pPlayer->getCollider().h;
			int eRight = m_position.x() + getCollider().x + getCollider().w;
			int eLeft = m_position.x() + getCollider().x;
			int eBottom = m_position.y() + getCollider().y + getCollider().h;
			int eTop = m_position.y() + getCollider().y;
			// check if player is above enemy
			if (pTop < eTop)
			{
				// check if player collider's bottom and enemy collider's top are completely
				// overlapped, in which case the jump attack was successful
				if ((pLeft < eLeft && pRight > eRight) ||	// player is wider than enemy
					(pLeft > eLeft && pRight < eRight))		// enemy is wider than player
				{
					jAttack = true;
				}
				else
				{
					// player isn't completely above the enemy
					int xdiff = 0, ydiff = 0;
					// check player position
					if (pLeft < eLeft && pRight < eRight)
					{
						// player is to the left of the enemy
						xdiff = pRight - eLeft;
						ydiff = pBottom - eTop;
					}
					else if (pLeft > eLeft && pRight > eRight)
					{
						// player is to the right of the enemy
						xdiff = eRight - pLeft;
						ydiff = pBottom - eTop;
					}
					// if overlapped surface is bigger in x axis than in y axis, 
					// the jump attack succeed
					if (xdiff > ydiff)
					{
						jAttack = true;
					}
				}

			}
		}
		// if the jump attack was successful, hit the enemy
		if (jAttack)
		{
			// player hits enemy with a jumping attack (-1 enemy life)
			m_remHealth--;
			// play sound that enemy does when hurt
			TheSoundManager::Instance().playSound(m_sndHurt, 0);
			if (m_remHealth <= 0)
			{
				m_bDead = true;
			}
			// bounce after jump attack, either the enemy was killed or not
			pPlayer->bounce();
		}
		else
		{
			// there wasn't jump attack, so player has been hurt
			pPlayer->hurt(m_damage, m_sndAttack);
		}
	}
}