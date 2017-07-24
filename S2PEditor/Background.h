#pragma once
#include <iostream>
#include "GameObject.h"
#include "GameObjectFactory.h"

class Background : public GameObject
{
public:
	virtual ~Background() {}
	Background();

	virtual void draw();
	virtual void update();
	virtual void load(std::unique_ptr<LoaderParams> const &pParams);
	virtual std::string type() { return "Background"; }
};

class BackgroundCreator : public BaseCreator
{
public:
	virtual GameObject* createGameObject() const;
};

