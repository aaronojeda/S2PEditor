#pragma once
#include "GameObject.h"
#include "GameObjectFactory.h"

class Player;

class ScoreItem :
	public GameObject
{
public:
	ScoreItem();
	~ScoreItem();
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

class ScoreItemCreator : public BaseCreator
{
	GameObject* createGameObject() const;
};