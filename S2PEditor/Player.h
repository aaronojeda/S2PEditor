#ifndef __Player__
#define __Player__

#include "GameObject.h"
#include "GameObjectFactory.h"

class Player : public GameObject // inherits from GameObject
{
public:
	Player();
	~Player();

	virtual void load(std::unique_ptr<LoaderParams> const &pParams);
	virtual void draw();
	virtual void update();

	void hurt(int damage, std::string sound);
	virtual std::string type() { return "Player"; }

	void setPosition(Vector2D pos) { m_position = pos; }
	int getJumpHeight(){ return m_jumpHeight; }
	int getJumpSpeed(){ return m_jumpSpeed; }
	std::string getJumpSound(){ return m_sndJmp; }

	// new functions adding jump attack
	bool falling(){ return m_bFalling; }
	void bounce();
	bool invulnerable(){ return m_bInvulnerable; }

private:

	// bring the player back to the last safe position or checkpoint
	void resurrect();
	
	// handle any input from the keyboard, mouse, or joystick
	void handleInput();
	
	// handle any animation for the player
	void handleAnimation();
	
	void handleMovement(Vector2D velocity);

	// player can be invulnerable for a time
	int m_bInvulnerable{ false };
	int m_invulnerableTime{ 0 };
	int m_invulnerableCounter{ 0 };

	bool m_bPressedJump{ true };
	int m_jumpHeight{ 0 };
	int m_jumpSpeed{ 0 };
	int m_beforeJumpY;
	int m_alpha{ 255 };
	bool m_bFalling{ false };

	int m_dyingAnimTime{ 0 };
	int m_deathTime{ 0 };

	// Sounds played when player jumps and dies
	std::string m_sndJmp, m_sndDeath;
};

class PlayerCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Player();
	}
};

#endif /* defined(__Player__) */