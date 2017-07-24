#include "StartState.h"
#include "Game.h"
#include "InputHandler.h"
#include "PlayState.h"
#include "TextureManager.h"

using namespace std;

const string StartState::s_startID = "START";

StartState::StartState()
{
	m_imageID = TheGame::Instance().getScreenIDStart();
	TheGame::Instance().clearStats();
}

StartState::~StartState()
{
}

void StartState::update()
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
		// The user wants to start the game
		TheGame::Instance().getStateMachine()->changeState(new PlayState(0));
	}
	TheGame::Instance().getStateMachine()->dequeState();
}

void StartState::render()
{
	TheTextureManager::Instance().draw(m_imageID, 0, 0, TheGame::Instance().getRenderer());
}

string StartState::getStateID() const
{
	return s_startID;
}