#ifndef __Game__
#define __Game__

// Gameobject

#include <vector>
#include <sstream>
#include <map>
#include "SDL.h"
#include "GameStateMachine.h"
#include "LTimer.h"
#include "Vector2D.h"
#include "Level.h"

class EditorState;

enum gameMode
{
	MODE_QT,
	MODE_GAME,
	NO_MODE
};

class Game
{
public:

	// Create the public instance function
	static Game& Instance();

	// Init in normal (play) mode
	bool init(int xpos = SDL_WINDOWPOS_UNDEFINED, int ypos = SDL_WINDOWPOS_UNDEFINED,
		int width = 640, int height = 480, const char* title = "", bool fullscreen = false);
	
	// Init in editor (Qt) mode
	EditorState* initEditor(void* winHandle, std::string levelName, 
		int width = -1, int height = -1, int tileSize = -1);

	// Get S2P current mode: editing or playing
	gameMode getMode() { return m_gameMode; }

	// game loop functions
	void handleEvents();
	void update();
	void render();
	void quit();
	void iterate();
	bool running() { return m_bRunning; }
	
	// Get Finite State Machine with game states
	GameStateMachine* getStateMachine(){ return m_pGameStateMachine; }
	
	// Get SDL game window
	SDL_Window* getWindow() { return m_pWindow; }
	
	// Get SDL renderer created from game window
	SDL_Renderer* getRenderer() const
	{
		return m_pRenderer; 
	}
	
	// Levels info
	void setCurrentLevel(int currentLevel);
	const int getCurrentLevel() { return m_currentLevel; }
	void setNextLevel(int nextLevel) { m_nextLevel = nextLevel; }
	const int getNextLevel() { return m_nextLevel; }
	void setLevelCompleted(bool levelComplete) { m_bLevelCompleted = levelComplete; }
	const bool levelCompleted() { return m_bLevelCompleted; }
	const std::vector<std::pair<std::string, std::string>> &getLevelFiles() { return m_levelFiles; }
	void addLevelFile(std::string levelName, std::string levelFile);
	void setLevelFiles(const std::vector<std::pair<std::string, std::string>> &levelFiles);
	
	// Current level map size
	const int getMapWidth() { return m_currentMapWidth; }
	void setMapWidth(int width) { m_currentMapWidth = width; }
	const int getMapHeight() { return m_currentMapHeight; }
	void setMapHeight(int height) { m_currentMapHeight = height; }
	
	// SDL Window size
	int getGameWidth() { return m_gameWidth; }
	void setGameWidth(int width) { m_gameWidth = width; }
	int getGameHeight() { return m_gameHeight; }
	void setGameHeight(int height) { m_gameHeight = height; }
	
	// Maximum values
	void setMaxValues(int maxHealth, int maxLives, int maxScore, int maxKeys);
	void getMaxValues(int &maxHealth, int &maxLives, int &maxScore, int &maxKeys);

	// Initial values
	void setInitValues(int initHealth, int initLives, int initScore, int initKeys);
	void getInitValues(int &initHealth, int &initLives, int &initScore, int &initKeys);

	// Lives
	void addLives(int lives);
	int getLives();
	//void setMaxLives(int maxLives);
	int getMaxLives();
	//void setInitLives(int initLives);
	int getInitLives();
	void clearLives();
	
	// Health
	void addHealth(int health);
	int getHealth(); 
	//void setMaxHealth(int maxHealth);
	int getMaxHealth();
	//void setInitHealth(int initHealth);
	int getInitHealth();
	void clearHealth();

	// Score
	void addScore(int score);
	int getScore();
	//void setMaxScore(int maxScore);
	int getMaxScore();
	//void setInitScore(int initScore);
	int getInitScore();
	void clearScore();

	// Keys
	void addKeys(int keys);
	int getKeys();
	//void setMaxKeys(int maxKeys);
	int getMaxKeys();
	//void setInitKeys(int initKeys);
	int getInitKeys();
	void clearKeys();

	// HUD setters & getters
	void getHUDIcons(std::string &health, std::string &lives, std::string &score, std::string &keys);
	void setHUDIcons(const std::string health, const std::string lives, const std::string score, const std::string keys);
	std::string getLivesID();
	std::string getHealthID();
	std::string getScoreID();
	std::string getKeysID();

	// Screens
	void getScreenTextureIDs(std::string &start, std::string &pause, std::string &gameOver, std::string &end);
	void setScreenTextureIDs(const std::string start, const std::string pause, const std::string gameOver, const std::string end);
	std::string getScreenIDStart();
	void setScreenIDStart(std::string id);
	std::string getScreenIDPause();
	void setScreenIDPause(std::string id);
	std::string getScreenIDGameOver();
	void setScreenIDGameOver(std::string id);
	std::string getScreenIDEnd();
	void setScreenIDEnd(std::string id);

	// Settings
	const std::string getSettingsFile();

	// General
	void clearStats();

	// User defined window size
	void setWindowSize(int width, int height);
	int getWindowWidth();
	int getWindowHeight();

	// Checkpoint management
	Vector2D getRespawnPos();
	bool checkPoint();
	void setCheckPoint(bool cp, Vector2D respawnPos = { 0, 0 });

	bool gameOver();
	void setGameOver(bool go);
	bool resurrected();
	void setResurrected(bool r);

	const std::vector<Tileset> &getTilesets();
	void setTilesets(const std::vector<Tileset> &tilesets);

	std::string getHUDFont(){ return m_HUDFont; }
	// Call when creating a new project
	void clearSettings();
private:

	// Game is a singleton so its constructor must be private
	Game();
	~Game();

	// Delete the methods we don't want (new in C++ 11)
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	// Rendering with SDL
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	// Game current window size in pixels
	int m_gameWidth;
	int m_gameHeight;
	// Finite State Machine of game states
	GameStateMachine* m_pGameStateMachine;	
	// Get current level size in pixels
	int m_currentMapWidth;
	int m_currentMapHeight;
	// Main loop flag
	bool m_bRunning;
	// To know if we are on game mode
	gameMode m_gameMode{ MODE_GAME };
	// Levels vector<id, route>
	std::vector<std::pair<std::string, std::string>> m_levelFiles;
	int m_currentLevel;
	int m_nextLevel;
	bool m_bLevelCompleted;
	// Player stats
	int m_lives{ 1 };
	int m_maxLives{ 99 };
	int m_initLives{ 3 };
	int m_health{ 1 };
	int m_maxHealth{ 5 };
	int m_initHealth{ 3 };
	int m_score{ 0 };
	int m_maxScore{ 1000 };
	int m_initScore{ 0 };
	int m_keys{ 0 };
	int m_maxKeys{ 99 };
	int m_initKeys{ 0 };
	// HUD icons
	std::string m_HUDIconLives;
	std::string m_HUDIconHealth;
	std::string m_HUDIconScore;
	std::string m_HUDIconKeys;
	// File with game settings
	std::string m_gameFile{ "game.s2p" };
	// State screens
	std::string m_screenIDStart;
	std::string m_screenIDPause;
	std::string m_screenIDGameOver;
	std::string m_screenIDEnd;
	// For tracking render FPS
	LTimer m_fpsTimer;
	int m_countedFrames;
	std::string m_fpsText;
	const std::string m_HUDFont{ "HUDFont" };
	int m_lastAvgFPS{ 0 };
	// Update frame rate (do not confuse with render frame rate)
	const int m_FPS{ 50 };
	Uint64 m_dt;		// delta time in platform-specific count units
	const int m_maxFrameSkip{ 10 };
	int m_skippedFrames;
	Uint64 m_nextGameTick;

	bool initSDLWindow(void* winHandle);
	bool initResources();
	bool initSDL();

	int m_windowWidth;
	int m_windowHeight;

	// Checkponit
	Vector2D m_respawnPos{ 0, 0 };
	bool m_checkPointFlag{ false };

	// game & player status variables
	bool m_gameOver{ false };
	bool m_resurrected{ false };

	// Initialize m_pRenderer according to m_pWindow and computer render drivers
	void createGameRenderer();
	// Draw render average FPS on the screen
	void drawFPS();
	// Show render drivers info in the shell
	void showRenderDriversInfo();
	// Show renderer info
	void showRendererInfo(SDL_Renderer* pRenderer);

	std::vector<Tileset> m_tilesets;
};

typedef Game TheGame;

#endif /* defined(__Game__) */