#pragma once
#include "LeftRight.h"

class Flying :
	public LeftRight
{
public:
	Flying();
	~Flying();
	virtual void load(std::unique_ptr<LoaderParams> const &pParams);
	virtual std::string type();
	virtual void update();
private:
	virtual void handleMovement(Vector2D velocity);

	bool m_bYCollision{ true };
};

class FlyingCreator : public BaseCreator
{
	GameObject* createGameObject() const;
};
