#include "TestState.h"
#include "Game.h"
#include "InputHandler.h"

const std::string TestState::s_testID = "TEST";

TestState::TestState(std::string levelFile) : PlayState(levelFile)
{
}

TestState::~TestState()
{
	// We don't want to keep the stats for next test
	TheGame::Instance().clearStats();
}

void TestState::update()
{
	if (TheGame::Instance().gameOver())
	{
		// Reset level and player stats
		TheGame::Instance().clearStats();
		loadLevel(m_levelFile);
		TheGame::Instance().setGameOver(false);
	}
	if (TheGame::Instance().resurrected())
	{
		// Reload level and reset player resurrected flag
		loadLevel(m_levelFile);
		TheGame::Instance().setResurrected(false);
		// Reset keys to zero
		TheGame::Instance().clearKeys();
	}
	else if (TheGame::Instance().levelCompleted())
	{
		// Put level completed and checkPoint flags as false
		TheGame::Instance().setLevelCompleted(false);
		TheGame::Instance().clearStats();
		// Start level from the beginning
		loadLevel(m_levelFile);
	}
	else
	{
		m_pLevel->update();
	}
}

