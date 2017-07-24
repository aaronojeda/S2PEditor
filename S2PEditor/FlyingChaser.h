#pragma once
#include "Chaser.h"
#include <string>
#include "GameObjectFactory.h"
#include "Vector2D.h"

class FlyingChaser :
	public Chaser
{
public:
	FlyingChaser();
	~FlyingChaser();
	virtual void update();
	std::string type();
private:
	void handleMovement(Vector2D velocity);
};

class FlyingChaserCreator : public BaseCreator
{
	GameObject* createGameObject() const;
};

