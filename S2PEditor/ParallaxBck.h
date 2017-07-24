#pragma once
#include "Background.h"

class ParallaxBck :
	public Background
{
public:
	ParallaxBck();
	~ParallaxBck();

	virtual void draw();
	virtual std::string type() { return "ParallaxBck"; }

	void setScrollRatioX(float ratio);
	void setScrollRatioY(float ratio);

private:
	float m_scrollRatioX;
	float m_scrollRatioY;
};

class ParallaxBckCreator : public BaseCreator
{
public:
	virtual GameObject* createGameObject() const;
};
