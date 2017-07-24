#pragma once
#include "GameObject.h"
#include "GameObjectFactory.h"
#include "LTimer.h"

class CheckPoint :
	public GameObject
{
public:
	CheckPoint();
	~CheckPoint();

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

private:
	LTimer m_sndTimer;
	bool m_sndPlayed{ false };
};

class CheckPointCreator : public BaseCreator
{
	GameObject* createGameObject() const;
};