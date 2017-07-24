#pragma once
#include "Enemy.h"
#include <string>
#include "GameObjectFactory.h"
#include "Animation.h"
#include "Vector2D.h"

class Chaser :	public Enemy
{
public:
	Chaser();
	~Chaser();
	virtual void load(std::unique_ptr<LoaderParams> const &pParams);
	virtual void update();
	virtual std::string type();
	void setTarget(Vector2D& target);

protected:
	Vector2D* m_playerPos{ nullptr };
	int m_viewDistance{ 0 };	// Distance of view in pixels
	int m_treshold{ 5 };
	virtual void handleMovement(Vector2D velocity);
	void handleAnimation();
};

class ChaserCreator : public BaseCreator
{
	GameObject* createGameObject() const;
};

