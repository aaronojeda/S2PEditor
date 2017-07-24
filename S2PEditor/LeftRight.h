#pragma once
#include "Enemy.h"
#include "GameObjectFactory.h"

class LeftRight :
	public Enemy
{
public:
	LeftRight();
	~LeftRight();
	virtual std::string type();
	virtual void update();
	virtual void load(std::unique_ptr<LoaderParams> const &pParams);

protected:

	bool m_bXCollision{ false };
	Animation m_walkingAnim;

	// To know if and where the enemy landed
	bool m_bLanded{ false };
	int m_landedY;

	virtual void handleMovement(Vector2D velocity);
	void handleAnimation();
	// Check if enemy has reached an edge
	bool checkEdgeTile(int x);
};

class LeftRightCreator : public BaseCreator
{
	GameObject* createGameObject() const;
};
