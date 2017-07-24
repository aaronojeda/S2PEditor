#include "Player.h"
#include <iostream>
#include "Game.h"
#include "InputHandler.h"
#include "SoundManager.h"
#include "TileLayer.h"
#include "Camera.h"
#include "TextureManager.h"
#include "LoaderParams.h"

using namespace std;

Player::Player() : GameObject(),
m_beforeJumpY{ m_position.y() }
{
}

Player::~Player()
{
}

void Player::load(unique_ptr<LoaderParams> const &pParams)
{
	// inherited load function
	GameObject::load(move(pParams));

	// Aliases for code readability
	m_invulnerableTime = m_value;
	m_jumpHeight = m_value2;
	m_jumpSpeed = m_value3;
	m_sndDeath = m_sndID;
	m_sndJmp = m_snd2ID;

	// Set current animation
	m_currentAnim = m_animations["idle"];
	// Get time that takes dying animation
	m_dyingAnimTime = m_animations["death"].getFrameTime() * m_animations["death"].getNFrames();
}

void Player::draw()
{
	if (!TheGame::Instance().resurrected() && !TheGame::Instance().gameOver())
	{
		TheTextureManager::Instance().drawFrame(getTextureID(),
			m_position.x() - TheCamera::Instance().getPosition().x(),
			m_position.y() - TheCamera::Instance().getPosition().y(),
			getWidth(), getHeight(), m_currentAnim.getCurrentFrame(),
			TheGame::Instance().getRenderer(), m_sdlFlip, 0.0, m_alpha);
	}
}

void Player::handleInput()
{
	if (TheInputHandler::Instance().isKeyDown(SDL_SCANCODE_LEFT))
	{
		if (TheInputHandler::Instance().isKeyDown(SDL_SCANCODE_RIGHT))
		{
			m_bMoveRight = false;
			m_bMoveLeft = false;
		}
		else
		{
			if (TheInputHandler::Instance().isKeyDown(SDL_SCANCODE_LSHIFT))
			{
				m_bRunning = true;
			}
			else
			{
				m_bRunning = false;
			}

			m_bMoveRight = false;
			m_bMoveLeft = true;
		}
	}
	else if (TheInputHandler::Instance().isKeyDown(SDL_SCANCODE_RIGHT))
	{
		if (TheInputHandler::Instance().isKeyDown(SDL_SCANCODE_LSHIFT))
		{
			m_bRunning = true;
		}
		else
		{
			m_bRunning = false;
		}

		m_bMoveRight = true;
		m_bMoveLeft = false;
	}
	else
	{
		m_bMoveLeft = false;
		m_bMoveRight = false;
	}

	if (TheInputHandler::Instance().isKeyDown(SDL_SCANCODE_SPACE) && m_bCanJump && !m_bPressedJump)
	{
		// Actions just before jumping
		TheSoundManager::Instance().playSound(m_sndJmp, 0);
		m_bJumping = true;
		m_bCanJump = false;
		m_beforeJumpY = m_position.y();
		m_bPressedJump = true;
	}
	if (!TheInputHandler::Instance().isKeyDown(SDL_SCANCODE_SPACE) && m_bCanJump)
	{
		// Jump key has been released and player can jump in that position
		m_bPressedJump = false;
	}
}


void Player::update()
{
	//if (m_bFalling) cout << "falling\n";
	//else cout << "\n";
	if (!m_bDying)
	{	
		// get the player input
		handleInput();

		if (m_bMoveLeft)
		{
			if (m_bRunning)
			{
				m_velocity.x(-(m_xSpeed * 2));
			}
			else
			{
				m_velocity.x(-m_xSpeed);
			}
		}
		else if (m_bMoveRight)
		{
			if (m_bRunning)
			{
				m_velocity.x(m_xSpeed * 2);
			}
			else
			{
				m_velocity.x(m_xSpeed);
			}
		}
		else // not moving
		{
			m_velocity.x(0);
		}

		if (!m_bJumping)
		{
			m_velocity.y(m_jumpSpeed);
		}
		else
		{
			// if we are higher than the jump height set jumping to false
			if (m_position.y() < m_beforeJumpY - m_jumpHeight)
			{
				m_bJumping = false;
			}

			m_velocity.y(-m_jumpSpeed);
		}

		handleMovement(m_velocity);
	}
	else   // Dying
	{
		m_velocity.x(0);
		if ( (SDL_GetTicks() - m_deathTime) > m_dyingAnimTime)
		{
			// Death animation finished. Resurrect the player
			resurrect();
		}
	}

	handleAnimation();
}

void Player::handleMovement(Vector2D velocity)
{
	// get the current position
	Vector2D newPos = m_position;
	
	// add velocity to the x position
	newPos.x(m_position.x() + velocity.x());

	// check if the player is trying to go off the map
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
			// Collision, stop x movement
			m_velocity.x(0);
			
			if (checkCollideTile(newPos))
			{
				// Collision with the map, move to contact
				if (m_position.x() < newPos.x())	// Collision with tile to the right
				{
					if (m_bRunning)
					{
						m_position.x(m_position.x() +
							(m_xSpeed * 2 - (int(newPos.x() + getCollider().x + getCollider().w) % (*m_pCollisionLayers->begin())->getTileSize())));
					}
					else
					{
						m_position.x(m_position.x() + (
							m_xSpeed - (int(newPos.x() + getCollider().x + getCollider().w) % (*m_pCollisionLayers->begin())->getTileSize())));
					}

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
			// No collision, add to the actual x position
			m_position.x(newPos.x());
		}
	}

	// get the current position after x movement
	newPos = m_position;

	// It is important to check x and y separately to make sure an x collision doesn't stop y movement and vice versa.

	// add velocity to y position
	newPos.y(newPos.y() + velocity.y());

	// check if the player is trying to go off the map
	if (newPos.y() + getCollider().y < 0)
	{
		m_position.y(-getCollider().y);
		m_bJumping = false;
	}
	else if (newPos.y() + getCollider().y + getCollider().h > TheGame::Instance().getMapHeight())
	{
		// Collision with the bottom of the map
		m_position.y(TheGame::Instance().getMapHeight() - getCollider().h - getCollider().y);
		m_velocity.y(0);
		m_bCanJump = true;
		m_bFalling = false;
	}
	else
	{
		if (checkCollideTile(newPos) || checkCollideObject(newPos))
		{
			// Collision, stop y movement
			m_velocity.y(0);

			// Check if collision was with player's feet
			if (m_position.y() < newPos.y())
			{
				// allow the player to jump again
				m_bCanJump = true;	
				m_bFalling = false;
				// Check if collision was with the map
				if (checkCollideTile(newPos))
				{
					// move to contact so that the player doesn't seem to be levitating
					m_position.y(m_position.y() + 
						(m_jumpSpeed - (int(newPos.y() + getCollider().y + getCollider().h) %
						(*m_pCollisionLayers->begin())->getTileSize())));
				}
			}
			//Either the player collided with his head (start falling) or his feet(reach ground), it has to stop ascending (jumping)
			m_bJumping = false;
		}
		else
		{
			// if the player if falling, he cannot jump
			if (m_position.y() < newPos.y())
			{
				m_bCanJump = false;
				m_bFalling = true;
			}

			// no collision, add to the actual y position
			m_position.y(newPos.y());
		}
	}
}

void Player::handleAnimation()
{
	// if the player is invulnerable we can flash its alpha to let people know
	if (m_bInvulnerable)
	{
		// invulnerability is finished, set values back
		if (m_invulnerableCounter == m_invulnerableTime)
		{
			m_bInvulnerable = false;
			m_invulnerableCounter = 0;
			m_alpha = 255;
		}
		else // otherwise, flash the alpha on and off
		{
			if (m_alpha == 255)
			{
				m_alpha = 0;
			}
			else
			{
				m_alpha = 255;
			}
		}

		// increment our counter
		m_invulnerableCounter++;
	}

	if (!m_bDying)
	{
		// Check orientation and flip sprite if necessary
		if (m_velocity.x() < 0)
		{
			// Going left
			m_sdlFlip = SDL_FLIP_HORIZONTAL;
		}
		else if (m_velocity.x() > 0)
		{
			// Going right
			m_sdlFlip = SDL_FLIP_NONE;
		}
		// Check if jumping or falling
		if (m_velocity.y() != 0)
		{
			// Jumping
			m_currentAnim = m_animations["jump"];
		}
		else
		{
			// Not jumping nor falling
			if (m_velocity.x() == 0)
			{
				// Stopped
				m_currentAnim = m_animations["idle"];
			}
			else
			{
				// Moving left or right
				m_currentAnim = m_animations["walk"];
				// Check if running
				if (m_bRunning)
				{
					m_currentAnim.setFrame(int(SDL_GetTicks() / m_currentAnim.getFrameTime()) % m_currentAnim.getNFrames());
				}
				else
				{
					m_currentAnim.setFrame(int(SDL_GetTicks() / (m_currentAnim.getFrameTime()*2)) % m_currentAnim.getNFrames());
				}
			}
		}
	}
	else   // Dying
	{
		m_currentAnim.setFrame(int((SDL_GetTicks() - m_deathTime) / m_currentAnim.getFrameTime()) % m_currentAnim.getNFrames());
	}
}

void Player::resurrect()
{
	// Check if player has lost all of his lives. We do it here because we want the dying animation to finish
	if (TheGame::Instance().getLives() < 0)
	{
		// No more lives. Game Over :(
		TheGame::Instance().setGameOver(true);
	}
	else
	{
		// Report that player has been resurrected, so PlayState can check it
		TheGame::Instance().setResurrected(true);
	}
}


void Player::hurt(int damage, string sound)
{
	if (!m_bDying && !m_bInvulnerable && damage > 0)
	{
		// Player has been hurt
		int prevLives = TheGame::Instance().getLives();
		TheGame::Instance().addHealth(-damage);
		// addHealth can make player lose a life
		if (TheGame::Instance().getLives() < prevLives)
		{
			// Player has dead
			m_currentAnim = m_animations["death"];
			m_deathTime = SDL_GetTicks();
			m_bDying = true;
			m_bJumping = false; // to avoid jumping after respawn	
			// play death sound
			TheSoundManager::Instance().playSound(m_sndDeath, 0);
		}
		else
		{
			// play enemy attack sound
			TheSoundManager::Instance().playSound(sound, 0);
			// Prevents being hitted more than once in one collision
			m_bInvulnerable = true;
		}
	}
}

void Player::bounce()
{
	m_bJumping = true;
	// Bouncing height will be half of jump height
	m_beforeJumpY = m_position.y() + m_jumpHeight/2;
}