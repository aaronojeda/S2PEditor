#pragma once
#include "PlayState.h"
class TestState :
	public PlayState
{
public:
	TestState(std::string levelFile);
	~TestState();
	virtual void update();
	virtual std::string getStateID() const { return s_testID; }
private:
	static const std::string s_testID;
};

