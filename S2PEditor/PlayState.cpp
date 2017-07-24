#include "PlayState.h"
#include <iostream>
#include <algorithm>
#include "Game.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "LevelParser.h"
#include "EditorState.h"
#include "Camera.h"
#include "InputHandler.h"
#include "ObjectLayer.h"
#include "Chaser.h"
#include "StartState.h"
#include "PauseState.h"
#include "EndState.h"
#include "GameOverState.h"
#include "SoundManager.h"

using namespace std;

const string PlayState::s_playID = "PLAY";

PlayState::PlayState(int level)
{
	TheGame::Instance().setCurrentLevel(level);
	m_levelFile = TheGame::Instance().getLevelFiles()[level].second;
	// load current level
	loadLevel(m_levelFile);
	// Play background music
	TheSoundManager::Instance().playMusic(m_pLevel->getMusic(), -1);
	// Get resources needed for drawing the HUD
	loadHUDResources();
}

PlayState::PlayState(string levelFile):
m_levelFile{ levelFile }
{
	// load current level
	loadLevel(m_levelFile);
	// Play background music
	TheSoundManager::Instance().playMusic(m_pLevel->getMusic(), -1);
	// Get resources needed for drawing the HUD
	loadHUDResources();
}

PlayState::~PlayState()
{
	// stop Music
	TheSoundManager::Instance().stopMusic();
	// delete level
	if (m_pLevel != nullptr)
	{
		delete m_pLevel;
	}
}

bool PlayState::loadLevel(int levelIndex)
{
	// Just a shortcut 
	return loadLevel(TheGame::Instance().getLevelFiles()[TheGame::Instance().getCurrentLevel()].second);
}

bool PlayState::loadLevel(string levelFile)
{
	// Delete previous level and free its resources
	if (m_pLevel != nullptr)
	{
		delete m_pLevel;
		m_pLevel = nullptr;
	}

	// Parse level
	LevelParser levelParser;
	m_pLevel = levelParser.parseLevel(levelFile.c_str());
	if (m_pLevel != nullptr)
	{
		// Inform Game about new level size
		TheGame::Instance().setMapWidth(m_pLevel->getWidth()*m_pLevel->getTileSize());
		TheGame::Instance().setMapHeight(m_pLevel->getHeight()* m_pLevel->getTileSize());
		// Check if there is a player in the level
		if (m_pLevel->getPlayer() != nullptr)
		{
			// Set player as camera target
			TheCamera::Instance().setTarget(&m_pLevel->getPlayer()->getPosition());
			// Look for Chaser enemies and set player as their target
			for (auto layer : *m_pLevel->getLayers())
			{
				if (layer->getLayerID() == "OBJECT")
				{
					ObjectLayer* oLayer = static_cast<ObjectLayer*>(layer);
					for (auto object : *oLayer->getGameObjects())
					{
						if (object->type() == "Chaser" || object->type() == "FlyingChaser")
						{
							// FlyingChaser inherits from chaser, so this cast should be fine
							static_cast<Chaser*>(object)->setTarget(m_pLevel->getPlayer()->getPosition());
						}
					}
				}
			}
			// Set player position
			if (TheGame::Instance().checkPoint())
			{
				m_pLevel->getPlayer()->setPosition(TheGame::Instance().getRespawnPos());
			}
		}
		else
		{
			// If the level has no player, set camera to coordinates origin
			TheCamera::Instance().setTarget(nullptr, mode::LEFT);
		}
	}
	// Return success if level was created
	return (m_pLevel != nullptr);
}

void PlayState::update()
{
	if (TheGame::Instance().resurrected())
	{
		// Reload level and reset player resurrected flag
		loadLevel(m_levelFile);
		TheGame::Instance().setResurrected(false);
		// Reset keys to zero
		TheGame::Instance().clearKeys();
	}
	else if (TheGame::Instance().gameOver())
	{
		// Reset game over flag to false again
		TheGame::Instance().setGameOver(false);
		// Show game over screen
		TheGame::Instance().getStateMachine()->changeState(new GameOverState());
		TheGame::Instance().getStateMachine()->dequeState();
	}
	else if (TheGame::Instance().levelCompleted())
	{
		// Put level completed and checkPoint flags as false
		TheGame::Instance().setLevelCompleted(false);
		TheGame::Instance().setCheckPoint(false);
		// Check if last level
		if (TheGame::Instance().getCurrentLevel() < TheGame::Instance().getLevelFiles().size() - 1)
		{
			// Still levels remaining
			int newLevel = TheGame::Instance().getCurrentLevel() + 1;
			TheGame::Instance().setCurrentLevel(newLevel); 
			// Reset player health to initial value unless he has more
			if (TheGame::Instance().getHealth() < TheGame::Instance().getInitHealth())
			{
				TheGame::Instance().clearHealth();
			}
			m_levelFile = TheGame::Instance().getLevelFiles()[newLevel].second;
			loadLevel(newLevel);
			// Play new level's background music
			TheSoundManager::Instance().playMusic(m_pLevel->getMusic(), -1);
		}
		else
		{
			// Game completed
			TheGame::Instance().getStateMachine()->changeState(new EndState());
			TheGame::Instance().getStateMachine()->dequeState();
		}
	}
	else
	{
		// Handle input and update level
		if (TheInputHandler::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
		{
			TheGame::Instance().quit();
		}
		if (!TheInputHandler::Instance().isKeyDown(SDL_SCANCODE_RETURN))
		{
			m_bPausePressed = false;
		}
		if (TheInputHandler::Instance().isKeyDown(SDL_SCANCODE_RETURN) && !m_bPausePressed)
		{
			m_bPausePressed = true;
			TheGame::Instance().getStateMachine()->pushState(new PauseState());
		}
		else
		{
			m_pLevel->update();
		}
	}
}

void PlayState::render()
{
	// Draw level objects and terrain
	if (m_pLevel != 0)
	{
		m_pLevel->render();
	}
	drawHUD();
}

void PlayState::drawHUD()
{
	// If we are in a playerless level we don't need the HUD
	if (m_pLevel->getPlayer() != nullptr)
	{
		int windowWidth = min(TheGame::Instance().getGameWidth(), TheGame::Instance().getMapWidth());

		// If player is dying then health = initial value, but we don't draw it until player resurrects
		if (!m_pLevel->getPlayer()->dying())
		{
			// Draw health icons reagarding on player's health
			for (auto i = 0; i < TheGame::Instance().getHealth(); i++)
			{
				TheTextureManager::Instance().draw(m_sHealthIcon, i*m_healthWidth, 0, m_healthWidth, m_healthHeight, m_pRenderer);
			}
		}

		// Draw lives icon
		TheTextureManager::Instance().draw(m_sLivesIcon, 0, m_healthHeight, m_livesWidth, m_livesHeight, m_pRenderer);
		// If lives number has changed we have to render text again
		if (TheGame::Instance().getLives() != m_prevLives)
		{
			int lives = TheGame::Instance().getLives();
			// We don't want to draw "-1" while dying before gameOver
			if (lives < 0) lives = 0;
			TheTextureManager::Instance().renderText(" x " + to_string(lives), m_sHUDFont, m_sLives);
			m_prevLives = TheGame::Instance().getLives();
		}
		// Draw text with number of lives
		TheTextureManager::Instance().draw(m_sLives, m_livesWidth, m_healthHeight + m_livesHeight - TheTextureManager::Instance().getHeight(m_sLives), m_pRenderer);

		// Draw score icon
		TheTextureManager::Instance().draw(m_sScoreIcon, windowWidth - m_scoreWidth - TheTextureManager::Instance().getWidth(m_sScore) - 4,
			0, m_scoreWidth, m_scoreHeight, m_pRenderer);
		// If score has changed we have to render text again
		if (TheGame::Instance().getScore() != m_prevScore)
		{
			TheTextureManager::Instance().renderText(" x " + to_string(TheGame::Instance().getScore()), m_sHUDFont, m_sScore);
			m_prevScore = TheGame::Instance().getScore();
		}
		// Draw text with score
		TheTextureManager::Instance().draw(m_sScore, windowWidth - TheTextureManager::Instance().getWidth(m_sScore) - 4,
			m_scoreHeight - TheTextureManager::Instance().getHeight(m_sScore), m_pRenderer);

		// Draw keys icon
		TheTextureManager::Instance().draw(m_sKeysIcon, windowWidth - m_keysWidth - TheTextureManager::Instance().getWidth(m_sKeys) - 4,
			m_scoreHeight, m_pRenderer);
		// If number of keys has changed we have to render text again
		if (TheGame::Instance().getKeys() != m_prevKeys)
		{
			TheTextureManager::Instance().renderText(" x " + to_string(TheGame::Instance().getKeys()), m_sHUDFont, m_sKeys);
			m_prevKeys = TheGame::Instance().getKeys();
		}
		// Draw text with number of keys
		TheTextureManager::Instance().draw(m_sKeys, windowWidth - TheTextureManager::Instance().getWidth(m_sKeys) - 4,
			m_scoreHeight + m_keysHeight - TheTextureManager::Instance().getHeight(m_sKeys), m_pRenderer);
	}
}

void PlayState::loadHUDResources()
{
	// Get HUD icon texture IDs, width and height

	// Health
	m_sHealthIcon = TheGame::Instance().getHealthID();
	m_healthWidth = TheTextureManager::Instance().getWidth(m_sHealthIcon);
	m_healthHeight = TheTextureManager::Instance().getHeight(m_sHealthIcon);
	// Lives
	m_sLivesIcon = TheGame::Instance().getLivesID();
	m_livesWidth = TheTextureManager::Instance().getWidth(m_sLivesIcon);
	m_livesHeight = TheTextureManager::Instance().getHeight(m_sLivesIcon);
	// Score
	m_sScoreIcon = TheGame::Instance().getScoreID();
	m_scoreWidth = TheTextureManager::Instance().getWidth(m_sScoreIcon);
	m_scoreHeight = TheTextureManager::Instance().getHeight(m_sScoreIcon);
	// Keys
	m_sKeysIcon = TheGame::Instance().getKeysID();
	m_keysWidth = TheTextureManager::Instance().getWidth(m_sKeysIcon);
	m_keysHeight = TheTextureManager::Instance().getHeight(m_sKeysIcon);	

	// Get game renderer
	m_pRenderer = TheGame::Instance().getRenderer();

	// Get HUD font
	m_sHUDFont = TheGame::Instance().getHUDFont();

	// Render initial text for lives, score and keys
	TheTextureManager::Instance().renderText(" x " + to_string(TheGame::Instance().getLives()), m_sHUDFont, m_sLives);
	m_prevLives = TheGame::Instance().getLives();
	TheTextureManager::Instance().renderText(" x " + to_string(TheGame::Instance().getScore()), m_sHUDFont, m_sScore);
	m_prevScore = TheGame::Instance().getScore();
	TheTextureManager::Instance().renderText(" x " + to_string(TheGame::Instance().getKeys()), m_sHUDFont, m_sKeys);
	m_prevKeys = TheGame::Instance().getKeys();
}