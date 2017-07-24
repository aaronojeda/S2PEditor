#pragma once
#include "GameState.h"
class PauseState :
	public GameState
{
public:
	PauseState();
	~PauseState();
	virtual void update();
	virtual void render();
	virtual std::string getStateID() const;

private:
	static const std::string s_pauseID;
	bool m_bPressed{ true };
	std::string m_imageID;
};

