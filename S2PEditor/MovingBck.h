#pragma once
#include "Background.h"
#include "GameObjectFactory.h"

class MovingBck :
	public Background
{
public:
	MovingBck();
	~MovingBck();

	virtual void draw();
	virtual void update();
	virtual void load(std::unique_ptr<LoaderParams> const &pParams);
	virtual std::string type() { return "MovingBck"; }

private:
	int m_scrollSpeed{ 0 };

	SDL_Rect m_srcRect1;
	SDL_Rect m_srcRect2;

	SDL_Rect m_destRect1;
	SDL_Rect m_destRect2;

	int m_srcRect1Width;	// No se usa
	int m_srcRect2Width;

	int m_destRect1Width;
	int m_destRect2Width;
};

class MovingBckCreator : public BaseCreator
{
public:
	virtual GameObject* createGameObject() const;
};