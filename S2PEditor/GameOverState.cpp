#include "GameOverState.h"
#include "Game.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "StartState.h"

using namespace std;

const string GameOverState::s_gameOverID = "GAMEOVER";

GameOverState::GameOverState()
{
	m_imageID = TheGame::Instance().getScreenIDGameOver();
}

GameOverState::~GameOverState()
{
}

void GameOverState::update()
{
	if (TheInputHandler::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance().quit();
	}
	if (!TheInputHandler::Instance().isKeyDown(SDL_SCANCODE_SPACE))
	{
		// To prevent key state propagation from previous state
		m_bPressed = false;
	}
	else
	{
		if (TheInputHandler::Instance().isKeyDown(SDL_SCANCODE_SPACE) && !m_bPressed)
		{
			// The user wants to restart the game
			TheGame::Instance().getStateMachine()->changeState(new StartState());
			TheGame::Instance().getStateMachine()->dequeState();
		}
	}
}

void GameOverState::render()
{
	TheTextureManager::Instance().draw(m_imageID, 0, 0, TheGame::Instance().getRenderer());
}

string GameOverState::getStateID() const
{
	return s_gameOverID;
}

