#pragma once
#include "GameObject.h"
#include "GameObjectFactory.h"

class HealthItem : public GameObject
{
public:
	HealthItem();
	~HealthItem();

	// load object parameters
	virtual void load(std::unique_ptr<LoaderParams> const &pParams);
	// draw the object
	virtual void draw();
	// do update stuff
	virtual void update();
	// object has collided, handle accordingly
	virtual void collision(Player *pPlayer);
	// get the type of the object
	virtual std::string type();
};

class HealthItemCreator : public BaseCreator
{
	GameObject* createGameObject() const;
};

