#include "EndState.h"
#include "Game.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "StartState.h"

using namespace std;

const string EndState::s_endID = "END";

EndState::EndState()
{
	m_imageID = TheGame::Instance().getScreenIDEnd();
}

EndState::~EndState()
{
}

void EndState::update()
{
	if (TheInputHandler::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance().quit();
	}
	// We don't want to propagate the key state from the previous state
	if (!TheInputHandler::Instance().isKeyDown(SDL_SCANCODE_SPACE))
	{
		// Start key has been released
		m_bPressed = false;
	}
	else if (TheInputHandler::Instance().isKeyDown(SDL_SCANCODE_SPACE) && !m_bPressed)
	{
		// The user wants to restart the game
		TheGame::Instance().getStateMachine()->changeState(new StartState());
		TheGame::Instance().getStateMachine()->dequeState();
	}
}

void EndState::render()
{
	TheTextureManager::Instance().draw(m_imageID, 0, 0, TheGame::Instance().getRenderer());
}

string EndState::getStateID() const
{
	return s_endID;
}