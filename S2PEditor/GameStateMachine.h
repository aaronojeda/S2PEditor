#ifndef __GameStateMachine__
#define __GameStateMachine__

#include <vector>
#include "GameState.h"

class GameStateMachine
{
public:
	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();
	void update();
	void render();
	void clean();
	// Checks every state and erases the invalid ones
	void dequeState();

	GameStateMachine();
	~GameStateMachine();

	// For integration with Qt or other engines
	GameState* currentState();

private:
	std::vector<GameState*> m_gameStates;
};

#endif /* defined(__GameStateMachine__) */