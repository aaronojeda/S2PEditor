#include "PauseState.h"
#include "Game.h"
#include "TextureManager.h"
#include "InputHandler.h"

using namespace std;

const string PauseState::s_pauseID = "PAUSE";

PauseState::PauseState()
{
	m_imageID = TheGame::Instance().getScreenIDPause();
}

PauseState::~PauseState()
{
}

void PauseState::update()
{
	if (TheInputHandler::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance().quit();
	}
	if (!TheInputHandler::Instance().isKeyDown(SDL_SCANCODE_RETURN))
	{
		// Pause key has been released
		m_bPressed = false;
	}
	else if (TheInputHandler::Instance().isKeyDown(SDL_SCANCODE_RETURN) & !m_bPressed)
	{
		// The user wants to resume the game
		TheGame::Instance().getStateMachine()->popState();
		TheGame::Instance().getStateMachine()->dequeState();
	}
}

void PauseState::render()
{
	TheTextureManager::Instance().draw(m_imageID, 0, 0, TheGame::Instance().getRenderer());
}

string PauseState::getStateID() const
{
	return s_pauseID;
}