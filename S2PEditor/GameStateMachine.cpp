#include "GameStateMachine.h"
#include "InputHandler.h"

GameStateMachine::GameStateMachine()
{
}

GameStateMachine::~GameStateMachine()
{
	clean();
	dequeState();
}

void GameStateMachine::pushState(GameState *pState)
{
	m_gameStates.push_back(pState);
}

// We first check if there are any states available to remove,
// and if so, we remove it
void GameStateMachine::popState()
{
	if (!m_gameStates.empty())
	{
		if (m_gameStates.back()->getIsValid())
		{
			m_gameStates.back()->setIsValid(false);	// Mark the state as invalid
		}
	}
}

// Check if there are already any states in the array, and if 
// there are, remove the current state and add our new pState
void GameStateMachine::changeState(GameState *pState)
{
	if (!m_gameStates.empty())
	{
		if (m_gameStates.back()->getIsValid())
		{
			m_gameStates.back()->setIsValid(false);	// Mark the state as invalid
		}
	}

	// push back our new state
	m_gameStates.push_back(pState);
}

/* The following two functions simply check if there are any states, and if so, they update and render the current state.*/
void GameStateMachine::update()
{
	if (!m_gameStates.empty())
	{
		m_gameStates.back()->update();
	}
}

void GameStateMachine::render()
{
	if (!m_gameStates.empty())
	{
		m_gameStates.back()->render();
	}
}

void GameStateMachine::clean()
{
	for (auto state : m_gameStates)
	{
		state->setIsValid(false);
	}
}

void GameStateMachine::dequeState()
{
	// Delete states flag as invalid
	for (auto it = m_gameStates.begin(); it != m_gameStates.end();)
	{
		if (!(*it)->getIsValid())
		{
			delete *it;						// delate state calling its destructor
			it = m_gameStates.erase(it);	// erase from vector and get new iterator
		}
		else
		{
			++it;
		}
	}
}

GameState* GameStateMachine::currentState()
{
	return m_gameStates.back();
}