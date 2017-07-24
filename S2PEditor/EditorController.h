#pragma once

#include <string>
#include <map>
#include <vector>
#include "EditorParser.h"
#include "Level.h"

class EditorState;

class EditorController
{
public:
	static EditorController& Instance();
	
	// Init S2P loading 'levelName' level. If default parameters are greater than zero, creates new level
	bool init(void* winHandle, const std::string& levelName, int width = -1, int height = -1, int tileSize = -1);
	// Creates new level and make it current
	bool newLevel(std::string levelName, std::string levelPath, int width, int height, int tileSize);
	// Load existing level
	bool loadLevel(std::string levelFile);
	// Save current level to xml file with the given name
	bool saveLevel(std::string levelFile);
	// Change from EditorState to PlayState to test the level
	bool runLevel(std::string levelPath);
	// Stops level testing and come back to Editor State 
	bool stopLevel();
	// Makes an iteration of the handleEvents/update/render loop
	void update();
	// Add texture to Texture Manager and Editor State current level
	bool loadTexture(std::string id, std::string source);
	// Update textures according to map textures <id, source>
	bool updateTextures(const std::map<std::string, std::string>& textures);
	// Load sfx
	bool loadSfx(std::string id, std::string source);
	// Load music
	bool loadMusic(std::string id, std::string source);
	// Update sfxs and musics
	bool updateSounds(const std::map<std::string, std::string> &sfxs,
		const std::map<std::string, std::string> &music);
	// Set the attributes for the current selected (and next added) object
	bool setObject(std::string objectID);
	// Will clear current object so no object will be added on left click
	bool clearObject();
	// Add new tileset to the level and make it current
	void addTileset(Tileset tileset);
	// Make tileset with the given index current
	bool setCurrentTileset(int index);
	// Remove tileset with the given index
	bool removeTileset(int index);
	// Inform if tiles are collidable or not	
	bool setCollisionTiles(bool collidable);
	// Informs that horizontal scroll bar has moved
	bool hScroll(int value);
	// Informs that vertical scroll bar has moved
	bool vScroll(int value);
	// Inform S2P that the game size has changed
	void setViewArea(int width, int height);
	// Set selected tile column and row
	bool setTile(int row, int column);
	// Change insertion mode to objects
	bool selectObject(bool checked);
	// Change insertion mode to tiles
	bool selectTile(bool checked);
	// Get the width of an Editor's texture
	int getTextureWidth(std::string id);
	// Get the height of an Editor's texture
	int getTextureHeight(std::string id);

	// Getters
	int getLevelWidth();	// Level width in tiles
	int getLevelWidthPx();	// Level width in pixels
	int getLevelHeight();	// Level height in tiles
	int getLevelHeightPx();	// Level height in pixels
	int getTileSize();		// Tile size in pixels
	const std::vector<Tileset>& getTilesets();

	// Bck
	std::vector<GameObjCfg> getBackgrounds();
	bool updateBackgrounds(const std::vector<GameObjCfg>& bcks);
	// Set parallax bcks scroll ratios according to game/window size
	bool updateBckScroll();

	// Max & init values setters & getters
	void setMaxValues(int maxHealth, int maxLives, int maxScore, int maxKeys);
	void getMaxValues(int &maxHealth, int &maxLives, int &maxScore, int &maxKeys);
	void setInitValues(int initHealth, int initLives, int initScore, int initKeys);
	void getInitValues(int &initHealth, int &initLives, int &initScore, int &initKeys);

	// HUD setters & getters
	void getHUDIcons(std::string &health, std::string &lives, std::string &score, std::string &keys);
	void setHUDIcons(std::string health, std::string lives, std::string score, std::string keys);

	// Screens
	void getScreenTextureIDs(std::string &start, std::string &pause, std::string &gameOver, std::string &end);
	void setScreenTextureIDs(std::string start, std::string pause, std::string gameOver, std::string end);

	// Window size
	int getWindowWidth();
	int getWindowHeight();
	void setWindowSize(int w, int h);

	const std::map<std::string, std::string> &getTextures() { return m_textures; }
	const std::map<std::string, std::string> &getSfxs(){ return m_sfxs; }
	const std::map<std::string, std::string> &getMusic(){ return m_music; }
	const std::map<std::string, GameObjCfg> &getObjectCfgs() { return m_objConfigs; }
	void addObjCfg(std::string id, GameObjCfg object);
	void deleteObjCfg(std::string id);

	void clearTilesets();
	void removeTiles(int firstGridID);

	// Levels
	const std::vector<std::pair<std::string, std::string>> &getGameLevels();
	const std::vector<std::pair<std::string, std::string>> &getLevels();
	void setLevelFiles(const std::vector<std::pair<std::string, std::string>> &levelFiles);
	bool deleteLevel(std::string id, std::string source);
	void addLevel(std::string id, std::string source);
	bool levelExists(std::string id);

	// General
	void clear();
	void updateGameSettings();
	void saveProject(std::string projectFile);
	bool loadProject(std::string projectFile);
	void stop();

	// Music
	void setLevelMusic(std::string musicID);
	std::string getLevelMusic();

private:
	bool m_bRunning{ false };
	// EditorController is a singleton so its constructor must be private
	EditorController();
	~EditorController();

	// Delete the methods we don't want (new in C++ 11)
	EditorController(const EditorController&) = delete;
	EditorController& operator=(const EditorController&) = delete;

	// S2P Editor State
	EditorState* m_Editor{ nullptr };
	
	std::map<std::string, std::string> m_textures;		// <id, source>
	std::map<std::string, GameObjCfg> m_objConfigs;	// <name, objectConfig>
	std::map<std::string, std::string> m_sfxs;	// <id, source>
	std::map<std::string, std::string> m_music;	// <id, source>

	// Tilesets in current project
	std::vector<Tileset> m_tilesets;
	// Levels in current project
	std::vector<std::pair<std::string, std::string>> m_levels;

	// guardar en el mismo sitio que lastEdited.cfg.
	std::string m_testLevel;
};

typedef EditorController TheEditor;

