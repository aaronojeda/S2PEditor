#pragma once
#include "GameState.h"
class EndState :
	public GameState
{
public:
	EndState();
	~EndState();
	virtual void update();
	virtual void render();
	virtual std::string getStateID() const;

private:
	static const std::string s_endID;
	bool m_bPressed{ true };
	std::string m_imageID;
};

