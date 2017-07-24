#include "Game.h"
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "TextureManager.h"
#include "InputHandler.h"
#include "PlayState.h"
#include "EditorState.h"
#include "StartState.h"
#include "GameOverState.h"
#include "GameObjectFactory.h"
#include "Player.h"
#include "Enemy.h"
#include "SoundManager.h"
#include "LeftRight.h"
#include "Flying.h"
#include "Chaser.h"
#include "FlyingChaser.h"
#include "ScoreItem.h"
#include "HealthItem.h"
#include "LivesItem.h"
#include "KeyItem.h"
#include "LockedDoor.h"
#include "LevelFinish.h"
#include "CheckPoint.h"
#include "StaticBck.h"
#include "ParallaxBck.h"
#include "MovingBck.h"
#include "EditorParser.h"

using namespace std;

Game::Game() :
m_pWindow(nullptr),
m_pRenderer(nullptr),
m_bRunning(false),
m_pGameStateMachine(nullptr),
m_bLevelCompleted(false),
m_currentLevel(0)
{
}

Game& Game::Instance()
{
	static Game s_pInstance;	// Guaranteed to be destroyed
	// Instantiated on first use
	return s_pInstance;
}

Game::~Game()
{
	cout << "cleaning game\n";

	SDL_DestroyWindow(m_pWindow);
	m_pWindow = nullptr;

	SDL_DestroyRenderer(m_pRenderer);
	m_pRenderer = nullptr;
	
	delete m_pGameStateMachine;
	m_pGameStateMachine = nullptr;

	SDL_Quit();
}

bool Game::init(int xpos, int ypos, int width, int height, const char* title, bool fullscreen)
{
	if (initSDL())	// Attempts to initialize SDL, SDL_Image and SDL_TTF
	{
		int flags = 0;
		if (fullscreen)	flags = SDL_WINDOW_FULLSCREEN;

		// init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (m_pWindow != nullptr) // window init success
		{
			cout << "SDL window created successfully\n";
			// Show available renderers info
			showRenderDriversInfo();
			// Initialize renderer
			createGameRenderer();
			if (m_pRenderer != nullptr) // renderer init success
			{
				cout << "SDL renderer created successfully\n";
				// show created renderer info
				showRendererInfo(m_pRenderer);
				// set game mode
				m_gameMode = MODE_GAME;
				if (initResources())
				{
					// Set game window width and height
					m_gameWidth = width;
					m_gameHeight = height;
					// Load initial state
					m_pGameStateMachine->changeState(new StartState());
					
					// everything inited successfully, let the main loop start
					m_bRunning = true;
					// Framerate variables which couldn't be initialized before SDL_Init
					m_dt = (1. / m_FPS) * SDL_GetPerformanceFrequency();
					m_nextGameTick = SDL_GetPerformanceCounter();
					// Start render FPS timer
					m_fpsTimer.start();
					// return success
					return true;
				}
			}
			else
			{
				cout << "Couldn't create any renderer. SDL_Error: " << SDL_GetError() << endl;
				return false; // renderer init fail
			}
		}
		else
		{
			cout << "Couldn't create SDL window. SDL error: " << SDL_GetError() << endl;
			return false; // window init fail
		}
	}
	return false;
}

EditorState* Game::initEditor(void* winHandle, string levelName, int width, int height, int tileSize)
{
	if (initSDL())
	{
		m_pWindow = SDL_CreateWindowFrom(winHandle);
		if (m_pWindow != nullptr)
		{
			cout << "SDL window created successfully\n";
			// Show available renderers info
			showRenderDriversInfo();
			// Initialize renderer
			createGameRenderer();
			if (m_pRenderer != nullptr)
			{
				cout << "SDL renderer created successfully\n";
				// set game mode
				m_gameMode = MODE_QT;
				if (initResources())
				{
					EditorState* editor;
					if (width > 0 && height > 0 && tileSize > 0)
					{
						editor = new EditorState(levelName, width, height, tileSize, tileSize);
					}
					else
					{
						editor = new EditorState(levelName);
					}
					m_pGameStateMachine->changeState(editor);
					// everything inited successfully, let the main loop start
					m_bRunning = true;
					// Framerate variables which couldn't be initialized before SDL_Init
					m_dt = (1. / m_FPS) * SDL_GetPerformanceFrequency();
					m_nextGameTick = SDL_GetPerformanceCounter();
					// Start render FPS timer
					m_fpsTimer.start();
					// Return new editor state
					return editor;
				}
			}
			else
			{
				cout << "Couldn't create any renderer. SDL_Error: " << SDL_GetError() << endl;
			}
		}
		else
		{
			cout << "Couldn't create SDL Window. Error: " << SDL_GetError() << endl;
		}
	}
	return nullptr;
}

bool Game::initResources()
{
	// Register predefined editor types
	TheGameObjectFactory::Instance().registerType("Player", new PlayerCreator());
	TheGameObjectFactory::Instance().registerType("LeftRight", new LeftRightCreator());
	TheGameObjectFactory::Instance().registerType("Flying", new FlyingCreator());
	TheGameObjectFactory::Instance().registerType("Chaser", new ChaserCreator());
	TheGameObjectFactory::Instance().registerType("FlyingChaser", new FlyingChaserCreator());
	TheGameObjectFactory::Instance().registerType("ScoreItem", new ScoreItemCreator());
	TheGameObjectFactory::Instance().registerType("HealthItem", new HealthItemCreator());
	TheGameObjectFactory::Instance().registerType("LivesItem", new LivesItemCreator());
	TheGameObjectFactory::Instance().registerType("KeyItem", new KeyItemCreator());
	TheGameObjectFactory::Instance().registerType("LockedDoor", new LockedDoorCreator());
	TheGameObjectFactory::Instance().registerType("LevelFinish", new LevelFinishCreator());
	TheGameObjectFactory::Instance().registerType("CheckPoint", new CheckPointCreator());
	TheGameObjectFactory::Instance().registerType("StaticBck", new StaticBckCreator());
	TheGameObjectFactory::Instance().registerType("ParallaxBck", new ParallaxBckCreator());
	TheGameObjectFactory::Instance().registerType("MovingBck", new MovingBckCreator());
	 
	// Load font
	TheTextureManager::Instance().loadFont("fonts/karma suture.ttf", m_HUDFont);
	
	// Create Game State Machine
	m_pGameStateMachine = new GameStateMachine();

	// Render FPS text so it won't fail the first time
	m_fpsText = "FPS";
	TheTextureManager::Instance().renderText(m_fpsText, m_HUDFont, "FPSText");

	if (m_gameMode == MODE_GAME)
	{
		// Load game settings in game s2p file
		EditorParser parser;
		parser.parseGameFile(m_gameFile);
	}

	return true;
}

bool Game::initSDL()
{
	// attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "SDL init success\n";

		// Initialize PNG loading
		if (!IMG_Init(IMG_INIT_PNG))
		{
			cout << "SDL_image could not initialize. Error: " << IMG_GetError() << endl;
			return false;
		}
		cout << "SDL_image init success\n";

		//Initialize SDL_ttf
		if (TTF_Init() == -1)
		{
			cout << "SDL_ttf could not initialize. Error: " <<  TTF_GetError() << endl;
			return false;
		}
		else
		{
			cout << "SDL_ttf init success\n";
			// We want to get user input only when we ask
			SDL_StopTextInput();
			return true;
		}
	}
	else
	{
		cout << "Couldn't initialize SDL. Error: " << SDL_GetError() << endl;
		return false;
	}
}

void Game::render()
{
	// Set default rendering color to grey
	SDL_SetRenderDrawColor(m_pRenderer, 130, 120, 120, 255);
	// clear the renderer with render color
	SDL_RenderClear(m_pRenderer);
	// We use FSM rendering function to render current state
	m_pGameStateMachine->render();
	// Show rendering fps on top of everything
	//drawFPS();
	// Update screen
	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
	m_pGameStateMachine->update(); // We use FSM update function
}

// Fixed timestep independent on rendering FPS
void Game::iterate()
{
	m_skippedFrames = 0;
	// Keep updating while last frame time < delta time, until m_maxFrameSkip iterations
	while (SDL_GetPerformanceCounter() > m_nextGameTick && m_skippedFrames < m_maxFrameSkip)
	{
		handleEvents();
		update();
		m_nextGameTick += m_dt;
		m_skippedFrames++;
	}
	render();
}

void Game::quit()
{
	m_bRunning = false;
}

void Game::handleEvents()
{
	TheInputHandler::Instance().update();
}

void Game::setCurrentLevel(int currentLevel)
{ 
	m_currentLevel = currentLevel;
	m_bLevelCompleted = false;
}

//void Game::addLevelFile(std::string levelName)
//{
//	m_levelFiles.push_back(levelName);
//}

void Game::addLevelFile(string levelName, string levelFile)
{
	m_levelFiles.push_back(make_pair(levelName, levelFile));
}

// Health

void Game::addHealth(int health)
{
	int newHealth = m_health + health;
	if (newHealth > m_maxHealth)
	{
		newHealth = m_maxHealth;
	}
	else if (newHealth <= 0)
	{
		addLives(-1);
		newHealth = m_initHealth;
	}
	m_health = newHealth;
}

int Game::getHealth()
{ 
	return m_health; 
}

//void Game::setMaxHealth(int maxHealth)
//{ 
//	m_maxHealth = maxHealth; 
//}

int Game::getMaxHealth()
{
	return m_maxHealth;
}

//void Game::setInitHealth(int initHealth)
//{
//	// Initial value can't be greater than max value
//	if (initHealth <= m_maxHealth)
//	{
//		m_initHealth = initHealth;
//	}
//	else
//	{
//		m_initHealth = m_maxHealth;
//	}
//}

int Game::getInitHealth()
{
	return m_initHealth;
}

void Game::clearHealth()
{
	m_health = m_initHealth;
}

// Lives

void Game::addLives(int lives)
{
	int newLives = m_lives + lives;
	if (newLives > m_maxLives)
	{
		newLives = m_maxLives;
	}
	m_lives = newLives;
}

int Game::getLives()
{
	return m_lives;
}

//void Game::setMaxLives(int maxLives)
//{
//	m_maxLives = maxLives;
//}

int Game::getMaxLives()
{
	return m_maxLives;
}

//void Game::setInitLives(int initLives)
//{
//	// Initial value can't be greater than max value
//	if (initLives <= m_maxLives)
//	{
//
//		m_initLives = initLives;
//	}
//	else
//	{
//		m_initLives = m_maxLives;
//	}
//}

int Game::getInitLives()
{
	return m_initLives;
}

void Game::clearLives()
{
	m_lives = m_initLives;
}

// Score

void Game::addScore(int score)
{
	int newScore = m_score + score;
	// It is a while to include the rare case that score is much greater than max_score
	while (newScore >= m_maxScore)
	{
		// Get a new life and reset score adding the offset
		m_lives++;
		newScore = newScore - m_maxScore;
	}
	m_score = newScore;
}

int Game::getScore()
{
	return m_score;
}

//void Game::setMaxScore(int maxScore)
//{
//	m_maxScore = maxScore;
//}

int Game::getMaxScore()
{
	return m_maxScore;
}

//void Game::setInitScore(int initScore)
//{
//	// Initial value can't be greater than max value
//	if (initScore <= m_maxScore)
//	{
//		m_initScore = initScore;
//	}
//	else
//	{
//		m_initScore = m_maxScore;
//	}
//}

int Game::getInitScore()
{
	return m_initScore;
}

void Game::clearScore()
{
	m_score = m_initScore;
}

// Keys

void Game::addKeys(int keys)
{
	int newKeys = m_keys + keys;
	if (newKeys >= 0)
	{
		if (newKeys > m_maxKeys)
		{
			newKeys = m_maxKeys;
		}
	}
	else
	{
		newKeys = 0;
	}
	m_keys = newKeys;
}

int Game::getKeys()
{
	return m_keys;
}

//void Game::setMaxKeys(int maxKeys)
//{
//	m_maxKeys = maxKeys;
//}

int Game::getMaxKeys()
{
	return m_maxKeys;
}

//void Game::setInitKeys(int initKeys)
//{
//	// Initial value can't be greater than max value
//	if (initKeys <= m_maxKeys)
//	{
//		m_initKeys = initKeys;
//	}
//	else
//	{
//		m_initKeys = m_maxKeys;
//	}
//}

int Game::getInitKeys()
{
	return m_initKeys;
}

void Game::clearKeys()
{
	m_keys = m_initKeys;
}

// HUD setters & setters

string Game::getLivesID()
{
	return m_HUDIconLives;
}

string Game::getHealthID()
{
	return m_HUDIconHealth;
}

string Game::getScoreID()
{
	return m_HUDIconScore;
}

string Game::getKeysID()
{
	return m_HUDIconKeys;
}

// Settings

void Game::setLevelFiles(const std::vector<std::pair<std::string, std::string>> &levelFiles)
{
	m_levelFiles = levelFiles;
}

const string Game::getSettingsFile()
{
	return m_gameFile;
}

// General

void Game::clearStats()
{
	clearLives();
	clearHealth();
	clearScore();
	clearKeys();
	setCheckPoint(false);
}

void Game::clearSettings()
{
	// clear stats
	clearStats();
	// clear levels
	m_levelFiles.clear();
	// clear tilesets
	m_tilesets.clear();
	// clear screens
	m_screenIDStart.clear();
	m_screenIDPause.clear();
	m_screenIDGameOver.clear();
	m_screenIDEnd.clear();
	// clear hud 
	m_HUDIconHealth.clear();
	m_HUDIconLives.clear();
	m_HUDIconScore.clear();
	m_HUDIconKeys.clear();
	// Max/init values and window size will be left with previous
	// project's values, since we don't really care
}

////////// Screens //////////
void Game::getScreenTextureIDs(std::string &start, std::string &pause, std::string &gameOver, std::string &end)
{
	start = m_screenIDStart;
	pause = m_screenIDPause;
	gameOver = m_screenIDGameOver;
	end = m_screenIDEnd;
}

void Game::setScreenTextureIDs(const std::string start, const std::string pause, const std::string gameOver, const std::string end)
{
	m_screenIDStart = start;
	m_screenIDPause = pause;
	m_screenIDGameOver = gameOver;
	m_screenIDEnd = end;
}

// start
string Game::getScreenIDStart()
{
	return m_screenIDStart;
}

void Game::setScreenIDStart(string id)
{
	m_screenIDStart = id;
}

// pause
string Game::getScreenIDPause()
{
	return m_screenIDPause;
}

void Game::setScreenIDPause(string id)
{
	m_screenIDPause = id;
}

// gameOver
string Game::getScreenIDGameOver()
{
	return m_screenIDGameOver;
}

void Game::setScreenIDGameOver(string id)
{
	m_screenIDGameOver = id;
}

// end
string Game::getScreenIDEnd()
{
	return m_screenIDEnd;
}

void Game::setScreenIDEnd(string id)
{
	m_screenIDEnd = id;
}

//////////// HUD icons /////////////
void Game::getHUDIcons(std::string &health, std::string &lives, std::string &score, std::string &keys)
{
	health = m_HUDIconHealth;
	lives = m_HUDIconLives;
	score = m_HUDIconScore;
	keys = m_HUDIconKeys;
}

void Game::setHUDIcons(const std::string health, const std::string lives, const std::string score, const std::string keys)
{
	m_HUDIconHealth = health;
	m_HUDIconLives = lives;
	m_HUDIconScore = score;
	m_HUDIconKeys = keys;
}


// User defined window size
void Game::setWindowSize(int width, int height)
{
	m_windowWidth = width;
	m_windowHeight = height;
}

int Game::getWindowWidth()
{
	return m_windowWidth;
}

int Game::getWindowHeight()
{
	return m_windowHeight;
}

// CheckPoint
Vector2D Game::getRespawnPos()
{ 
	return m_respawnPos; 
}

bool Game::checkPoint()
{ 
	return m_checkPointFlag; 
}

void Game::setCheckPoint(bool cp, Vector2D respawnPos)
{
	m_checkPointFlag = cp;
	m_respawnPos = respawnPos; 
}

bool Game::gameOver()
{ 
	return m_gameOver; 
}

void Game::setGameOver(bool go)
{
	m_gameOver = go; 
}

bool Game::resurrected()
{
	return m_resurrected;
}

void Game::setResurrected(bool r)
{
	m_resurrected = r;
}

// Auxiliar

void Game::drawFPS()
{
	// Update FPS value shown in screen
	int avgFPS = m_countedFrames / (double(m_fpsTimer.getTicks()) / SDL_GetPerformanceFrequency());
	// Create new texture only if FPS have changed
	if (avgFPS != m_lastAvgFPS)
	{
		m_fpsText = to_string(avgFPS) + " FPS";
		TheTextureManager::Instance().renderText(m_fpsText, m_HUDFont, "FPSText");
		// Update last average fps
		m_lastAvgFPS = avgFPS;
	}
	// Show rendering FPS
	TheTextureManager::Instance().draw("FPSText", m_gameWidth/2, 0, m_pRenderer);

	// To avoid undefined behavior (theorically signed ints can't overflow)
	if (m_countedFrames == INT_MAX)
	{
		m_countedFrames = 1;
		m_fpsTimer.start();
	}
	else
	{
		m_countedFrames++;	// increment frame counter
	}
}

void Game::showRenderDriversInfo()
{
	// Get render drivers info
	int nRD = SDL_GetNumRenderDrivers();
	cout << "//////////// Render drivers ///////////\n";
	for (int i = 0; i<nRD; i++)
	{
		SDL_RendererInfo info;
		if (!SDL_GetRenderDriverInfo(i, &info))
		{
			cout << info.name << endl;
			cout << "\tHardware accelerated: " << (info.flags & SDL_RENDERER_ACCELERATED) << endl;
			cout << "\tVsync: " << (info.flags & SDL_RENDERER_PRESENTVSYNC) << endl;
			cout << "\tSoftware: " << (info.flags & SDL_RENDERER_SOFTWARE) << endl;
			cout << "\tTarget texture: " << (info.flags & SDL_RENDERER_TARGETTEXTURE) << endl;
		}
	}
	cout << "///////////////////////////////////////\n";
}

void Game::showRendererInfo(SDL_Renderer* pRenderer)
{
	// Get renderer info
	SDL_RendererInfo rInfo;
	if (!SDL_GetRendererInfo(pRenderer, &rInfo))	// success
	{
		cout << "Hardware accelerated: " << (rInfo.flags & SDL_RENDERER_ACCELERATED) << endl;
		cout << "Vsync: " << (rInfo.flags & SDL_RENDERER_PRESENTVSYNC) << endl;
		cout << "Software: " << (rInfo.flags & SDL_RENDERER_SOFTWARE) << endl;
		cout << "Target texture: " << (rInfo.flags & SDL_RENDERER_TARGETTEXTURE) << endl;
	}
	else
	{
		cout << "Couldn't get rederer information. SDL error: " << SDL_GetError();
	}
}

void Game::createGameRenderer()
{
	// First we try to create a hardware accelerated renderer (default) with vsync
	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_PRESENTVSYNC);
	if (m_pRenderer == nullptr)
	{
		cout << "Couldn't create hw-accelerated VSynched renderer. SDL_Error: " << SDL_GetError() << endl;
		// With 0 flags, if no hw-accelerated renderers available, it will create a software fallback
		m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		if (m_pRenderer == nullptr)
		{
			cout << "Couldn't create any renderer. SDL_Error: " << SDL_GetError() << endl;
		}
	}
}

const vector<Tileset> &Game::getTilesets()
{
	return m_tilesets;
}

void Game::setTilesets(const std::vector<Tileset> &tilesets)
{
	m_tilesets = tilesets;
}

void Game::setMaxValues(int maxHealth, int maxLives, int maxScore, int maxKeys)
{
	m_maxHealth = maxHealth;
	m_maxLives = maxLives;
	m_maxScore = maxScore;
	m_maxKeys = maxKeys;
}

void Game::getMaxValues(int &maxHealth, int &maxLives, int &maxScore, int &maxKeys)
{
	maxHealth = m_maxHealth;
	maxLives = m_maxLives;
	maxScore = m_maxScore;
	maxKeys = m_maxKeys;
}

void Game::setInitValues(int initHealth, int initLives, int initScore, int initKeys)
{
	m_initHealth = initHealth;
	m_initLives = initLives;
	m_initScore = initScore;
	m_initKeys = initKeys;
}

void Game::getInitValues(int &initHealth, int &initLives, int &initScore, int &initKeys)
{
	initHealth = m_initHealth;
	initLives = m_initLives;
	initScore = m_initScore;
	initKeys = m_initKeys;
}