#pragma once
#include "GameState.h"
class GameOverState :
	public GameState
{
public:
	GameOverState();
	~GameOverState();
	virtual void update();
	virtual void render();
	virtual std::string getStateID() const;

private:
	static const std::string s_gameOverID;
	bool m_bPressed{ true };
	std::string m_imageID;
};

