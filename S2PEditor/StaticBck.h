#pragma once
#include "Background.h"
class StaticBck :
	public Background
{
public:
	StaticBck();
	~StaticBck();

	virtual void draw();
	virtual std::string type() { return "StaticBck"; }
};

class StaticBckCreator : public BaseCreator
{
public:
	virtual GameObject* createGameObject() const;
};

