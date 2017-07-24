#pragma once
#include "GameState.h"
class StartState :
	public GameState
{
public:
	StartState();
	~StartState();
	virtual void update();
	virtual void render();
	virtual std::string getStateID() const;

private:
	static const std::string s_startID;
	bool m_bPressed{ true };
	std::string m_imageID;
};

