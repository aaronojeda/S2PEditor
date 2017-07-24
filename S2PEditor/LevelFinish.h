#pragma once
#include "GameObject.h"
#include "GameObjectFactory.h"

class LevelFinish :
	public GameObject
{
public:
	LevelFinish();
	~LevelFinish();

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

class LevelFinishCreator : public BaseCreator
{
	GameObject* createGameObject() const;
};
