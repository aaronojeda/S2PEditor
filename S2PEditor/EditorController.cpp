#include "EditorController.h"
#include <iostream>
#include <QFile>
#include "Game.h"
#include "EditorState.h"
#include "TextureManager.h"
#include "LevelParser.h"
#include "EditorParser.h"
#include "TestState.h"
#include "BckLayer.h"
#include "SoundManager.h"

using namespace std;

EditorController::EditorController()
{
}
 
EditorController::~EditorController()
{
}

EditorController& EditorController::Instance()
{
	static EditorController s_pInstance;	// Guaranteed to be destroyed
	// Instantiated on first use
	return s_pInstance;
}

bool EditorController::loadProject(string projectFile)
{
	// Clear previous project assets
	clear();

	// Load new project assets
	EditorParser parser;
	if (!parser.parseProjectFile(projectFile, m_levels, m_textures,	m_tilesets, m_objConfigs, m_sfxs, m_music))	// success
	{
		// Load textures to texture manager
		for (auto texture : m_textures)
		{
			TheTextureManager::Instance().load(texture.second, texture.first, TheGame::Instance().getRenderer());
		}

		// Load sfxs and music to sound manager
		for (auto sfx : m_sfxs)
		{
			TheSoundManager::Instance().load(sfx.second, sfx.first, SOUND_SFX);
		}
		for (auto msc : m_music)
		{
			TheSoundManager::Instance().load(msc.second, msc.first, SOUND_MUSIC);
		}

		// Load tilesets to Game
		TheGame::Instance().setTilesets(m_tilesets);

		// Set current tileset
		if (m_Editor != nullptr)
		{
			Tileset currentTileset;
			if (m_tilesets.size())
			{
				// First tileset will be default
				currentTileset = m_tilesets.front();
			}
			else
			{
				// no tilesets, make current invalid
				currentTileset.firstGridID = 0;
			}
			m_Editor->setCurrentTileset(currentTileset);
			return true;
		}
	}
	else
	{
		// Clear again because parseProjectFile could have changed members
		clear();
	}
	return false;
}


bool EditorController::init(void* winHandle, const std::string& levelName, int width, int height, int tileSize)
{
	if (m_Editor == nullptr)
	{
		// Create editor state
		m_Editor = TheGame::Instance().initEditor(winHandle, levelName, width, height, tileSize);
		if (m_Editor != nullptr)
		{
			m_bRunning = true;
			return true;
		}
		cout << "Editor initialization error: couldn't get Editor State\n";
		return false;
	}
	cout << "Editor initialization error: editor already initialized\n";
	return false;
}

bool EditorController::newLevel(string levelName, string levelPath, int width, int height, int tileSize)
{
	// Save current tileset and insertion mode to load them to the new level
	Tileset currentTileset = m_Editor->getCurrentTileset();
	auto insertionMode = m_Editor->getInsertMode();
	// Create new level with given name and size
	EditorState* editor = new EditorState(levelName, width, height, tileSize, tileSize);
	if (editor)
	{
		TheGame::Instance().getStateMachine()->changeState(editor);
		m_bRunning = true;
		// add level to editor levels
		m_levels.push_back(make_pair(levelName, levelPath));
		m_Editor = editor;
		// load current tileset and insertion mode
		m_Editor->setCurrentTileset(currentTileset);
		m_Editor->setInsertMode(insertionMode);
		return true;
	}
	return false;
}


bool EditorController::loadLevel(string levelFile)
{
	// Load new level in the Editor State
	if (m_Editor->loadLevel(levelFile))
	{
		m_bRunning = true;
		return true;
	}
	return false;
}

bool EditorController::saveLevel(std::string levelFile)
{
	if (m_Editor != nullptr)
	{
		return m_Editor->saveLevel(levelFile);
	}
	return false;
}

bool EditorController::runLevel(string levelPath)
{
	if (m_Editor != nullptr)
	{
		// Create a copy of the level being edited
		auto lastSeparator = levelPath.find_last_of("/\\");
		m_testLevel = levelPath.substr(0, lastSeparator + 1) + "test.xml";
		// Save copy of the level 
		m_Editor->saveLevel(m_testLevel);
		// Reset stats
		TheGame::Instance().clearStats();
		// Test the copied level
		TheGame::Instance().getStateMachine()->pushState(new TestState(m_testLevel));
		// Make m_Editor nullptr to indicate that current state is not Editor State
		m_Editor = nullptr;
		return true;
	}
	return false;
}

bool EditorController::stopLevel()
{
	// In this case m_Editor should be nullptr because we have to be in Play State to stop
	if (m_Editor == nullptr)
	{
		// m_Editor can be nullptr because we are in Test State (good) or because it hasn't been initialized 
		if (TheGame::Instance().getStateMachine()->currentState()->getStateID() == "TEST")
		{
			TheGame::Instance().getStateMachine()->popState();
			TheGame::Instance().getStateMachine()->dequeState();
			// Delete test copy level
			QFile::remove(QString::fromStdString(m_testLevel));
			// Get Editor State again
			m_Editor = dynamic_cast<EditorState*>(TheGame::Instance().getStateMachine()->currentState());
			if (m_Editor != nullptr)
			{
				m_Editor->centerCamera();
				return true;
			}
			else
			{
				cout << "Error stopping level: couldn't return to editor state\n";
			}
		}
		else
		{
			cout << "Error stopping level: current state is not Test State\n";
		}
	}
	return false;
}

int EditorController::getLevelWidth()
{
	if (m_Editor != nullptr)
	{
		return m_Editor->getLevelWidth();
	}
	return -1;
}

int EditorController::getLevelWidthPx()
{
	if (m_Editor != nullptr)
	{
		return (m_Editor->getLevelWidth() * m_Editor->getTileSize());
	}
	return -1;
}

int EditorController::getLevelHeight()
{
	if (m_Editor != nullptr)
	{
		return m_Editor->getLevelHeight();
	}
	return -1;
}

int EditorController::getLevelHeightPx()
{
	if (m_Editor != nullptr)
	{
		return (m_Editor->getLevelHeight() * m_Editor->getTileSize());
	}
	return -1;
}

int EditorController::getTileSize()
{
	if (m_Editor != nullptr)
	{
		return m_Editor->getTileSize();
	}
	return -1;
}

void EditorController::update()
{
	if (m_bRunning)
	{
		TheGame::Instance().iterate();
	}
}

// Textures

bool EditorController::loadTexture(std::string id, std::string source)
{
	m_textures[id] = source;
	return TheTextureManager::Instance().load(source, id, TheGame::Instance().getRenderer());
}

bool EditorController::updateTextures(const std::map<std::string, std::string>& textures)
{
	// m_textures have textures before update
	for (auto previousTexture : m_textures)
	{
		// Check if previous texture has been deleted
		if (textures.find(previousTexture.first) == textures.end())
		{
			TheTextureManager::Instance().clearFromTextureMap(previousTexture.first);
		}
	}
	// We load all textures, even old ones because the user could've changed the id
	for (auto texture : textures)
	{
		TheTextureManager::Instance().load(texture.second, texture.first, TheGame::Instance().getRenderer());
	}
	// update texture map
	m_textures = textures;
	return true;
}

// sounds

bool EditorController::loadSfx(string id, string source)
{
	m_sfxs[id] = source;
	return TheSoundManager::Instance().load(source, id, SOUND_SFX);
}

bool EditorController::loadMusic(string id, string source)
{
	m_music[id] = source;
	return TheSoundManager::Instance().load(source, id, SOUND_MUSIC);
}

bool EditorController::updateSounds(const map<string, string> &sfxs, const map<string, string> &music)
{
	// Look for deleted sfxs to free them
	for (auto previousSfx : m_sfxs)
	{
		// Check if previous sound has been deleted
		if (sfxs.find(previousSfx.first) == sfxs.end())
		{
			TheSoundManager::Instance().clearSfx(previousSfx.first);
		}
	}
	// Look for deleted music to free them
	for (auto prevMusic : m_music)
	{
		// Check if previous music has been deleted
		if (music.find(prevMusic.first) == music.end())
		{
			TheSoundManager::Instance().clearMusic(prevMusic.first);
		}
	}

	// We load all sounds, even old ones because the user could've changed the id
	for (auto sfx : sfxs)
	{
		TheSoundManager::Instance().load(sfx.second, sfx.first, SOUND_SFX);
	}
	for (auto msc : music)
	{
		TheSoundManager::Instance().load(msc.second, msc.first, SOUND_MUSIC);
	}
	// update sfx and music maps
	m_sfxs = sfxs;
	m_music = music;
	return true;
}

bool EditorController::updateBackgrounds(const std::vector<GameObjCfg>& bcks)
{
	if (m_Editor != nullptr)
	{
		// Clear previous backgrounds
		m_Editor->clearBck();
		for (auto bck : bcks)
		{
			m_Editor->addBck(bck.type, bck.textureID, bck.xSpeed, bck.ySpeed);
		}
		updateBckScroll();
		return true;
	}
	return false;
}

bool EditorController::setObject(string objectID)
{
	if (m_Editor != nullptr)
	{
		if (m_objConfigs.find(objectID) != m_objConfigs.end())
		{
			auto object = m_objConfigs.at(objectID);
			map<string, Animation> animations;
			// Create animations and put them in map<string, Animation> format
			for (auto anim : object.animations)
			{
				// Deduce frames from object and animation attributes
				vector<SDL_Rect> frames;
				for (int i = 0; i < anim.second.nFrames; i++)
				{
					SDL_Rect frame;
					frame.x = i*object.frameWidth;
					frame.y = anim.second.row*object.frameHeight;
					frame.w = object.frameWidth;
					frame.h = object.frameHeight;
					frames.push_back(frame);
				}
				// Create animation and add it to map
				Animation animation(object.textureID, anim.second.row, frames, anim.second.frameTime, object.collider);
				animations[anim.first] = animation;
			}
			// Set current object attributes
			m_Editor->setObject(object, animations);
		}
	}
	return false;
}

void EditorController::addObjCfg(std::string id, GameObjCfg object)
{
	m_objConfigs[id] = object;
}

void EditorController::deleteObjCfg(std::string id)
{
	m_objConfigs.erase(id);
}

bool EditorController::clearObject()
{
	if (m_Editor != nullptr)
	{
		GameObjCfg emptyObj;
		map<string, Animation> emptyAnims;
		// Passing empty string as type will result in EditorState ignoring object addition 
		m_Editor->setObject(emptyObj, emptyAnims);
		return true;
	}
	return false;
}

void EditorController::addTileset(Tileset tileset)
{
	m_tilesets.push_back(tileset);
	TheGame::Instance().setTilesets(m_tilesets);
}

bool EditorController::setCurrentTileset(int index)
{
	if (m_Editor != nullptr)
	{
		Tileset currentTileset;
		if (m_tilesets.empty() ||
			index < 0 || index > m_tilesets.size() - 1)
		{
			// If index out of range, set fristGridID to 0 to point that no tileset is selected
			currentTileset.firstGridID = 0;
		}
		else
		{
			currentTileset = m_tilesets[index];
		}
		m_Editor->setCurrentTileset(currentTileset);
		return true;
	}
	return false;
}

const std::vector<Tileset>& EditorController::getTilesets()
{
	return m_tilesets;
}

bool EditorController::removeTileset(int index)
{
	if (index >= 0 && index < m_tilesets.size())
	{
		// Remove tiles from current level
		if (m_Editor != nullptr)
		{
			m_Editor->removeTileset(m_tilesets[index]);
		}
		else
		{
			return false;
		}
		// Remove tiles from remaining project levels
		removeTiles(m_tilesets[index].firstGridID);
		// Remove tileset from Editor and Game vectors
		m_tilesets.erase(m_tilesets.begin() + index);
		TheGame::Instance().setTilesets(m_tilesets);
		return true;
	}
	else
	{
		cout << "Tileset index out of range\n";
		return false;
	}
}

void EditorController::removeTiles(int firstGridID)
{
	for (auto level : m_levels)
	{
		if (level.second == m_Editor->getLevelFile())
		{
			// Current level tiles will be deleted by EditorState
			continue;
		}
		LevelParser parser;
		auto pLevel = parser.parseLevel(level.second.c_str());
		// Remove tiles that belong to removed tileset
		pLevel->removeTiles(firstGridID);
		// Overwrite level
		parser.writeLevel(*pLevel, level.second);
	}
}

bool EditorController::setCollisionTiles(bool collidable)
{
	if (m_Editor != nullptr)
	{
		m_Editor->setCollisionTiles(collidable);
		return true;
	}
	return false;
}

bool EditorController::hScroll(int value)
{
	if (m_Editor != nullptr)
	{
		m_Editor->hScroll(value);
		return true;
	}
	return false;
}

bool EditorController::vScroll(int value)
{
	if (m_Editor != nullptr)
	{
		m_Editor->vScroll(value);
		return true;
	}
	return false;
}

void EditorController::setViewArea(int width, int height)
{
	// We have to do this regardless of state (Editor or Play)
	TheGame::Instance().setGameWidth(width);
	TheGame::Instance().setGameHeight(height);
}

bool EditorController::setTile(int row, int column)
{
	if (m_Editor != nullptr)
	{
		m_Editor->setTile(row, column);
		return true;
	}
	return false;
}

bool EditorController::selectObject(bool checked)
{
	if (m_Editor != nullptr)
	{
		if (checked)
		{
			// Change insertion mode to 'object'
			m_Editor->setInsertMode(INSERT_OBJECT);
		}
		else
		{
			m_Editor->setInsertMode(INSERT_NONE);
		}
		return true;
	}
	return false;
}

bool EditorController::selectTile(bool checked)
{
	if (m_Editor != nullptr)
	{
		if (checked)
		{
			// Change insertion mode to 'tile'
			m_Editor->setInsertMode(INSERT_TILE);
		}
		else
		{
			m_Editor->setInsertMode(INSERT_NONE);
		}
		return true;
	}
	return false;
}

int EditorController::getTextureWidth(string id)
{
	return TheTextureManager::Instance().getWidth(id);
}

int EditorController::getTextureHeight(string id)
{
	return TheTextureManager::Instance().getHeight(id);
}

vector<GameObjCfg> EditorController::getBackgrounds()
{
	vector<GameObjCfg> bcks;
	if (m_Editor != nullptr)
	{
		auto bckLayer = m_Editor->getBckLayer();
		auto bckNumber = 1;
		for (auto bck : *bckLayer->getGameObjects())
		{
			GameObjCfg bckCfg;
			// Background name will be the same as its textureID
			bckCfg.name = bck->getTextureID();
			bckNumber++;
			bckCfg.type = bck->type();
			bckCfg.textureID = bck->getTextureID();
			bckCfg.xSpeed = bck->getXSpeed();
			bckCfg.ySpeed = bck->getYSpeed();
			bcks.push_back(bckCfg);
		}
	}
	return bcks;
}

bool EditorController::updateBckScroll()
{
	if (m_Editor != nullptr)
	{
		m_Editor->updateBckScroll();
		return true;
	}
	return false;
}

// Max values setters & getters
void EditorController::setMaxValues(int maxHealth, int maxLives, int maxScore, int maxKeys)
{
	TheGame::Instance().setMaxValues(maxHealth, maxLives, maxScore, maxKeys);
}

void EditorController::getMaxValues(int &maxHealth, int &maxLives, int &maxScore, int &maxKeys)
{
	TheGame::Instance().getMaxValues(maxHealth, maxLives, maxScore, maxKeys);
}

// Initial values setters & getters
void EditorController::setInitValues(int initHealth, int initLives, int initScore, int initKeys)
{
	TheGame::Instance().setInitValues(initHealth, initLives, initScore, initKeys);
}

void EditorController::getInitValues(int &initHealth, int &initLives, int &initScore, int &initKeys)
{
	TheGame::Instance().getInitValues(initHealth, initLives, initScore, initKeys);
}

// HUD setters & getters

void EditorController::getHUDIcons(string &health, string &lives, string &score, string &keys)
{
	TheGame::Instance().getHUDIcons(health, lives, score, keys);
}

void EditorController::setHUDIcons(string health, string lives, string score, string keys)
{
	TheGame::Instance().setHUDIcons(health, lives, score, keys);
}

// Screens

void EditorController::getScreenTextureIDs(string &start, string &pause, string &gameOver, string &end)
{
	TheGame::Instance().getScreenTextureIDs(start, pause, gameOver, end);
}

void EditorController::setScreenTextureIDs(string start, string pause, string gameOver, string end)
{
	TheGame::Instance().setScreenTextureIDs(start, pause, gameOver, end);
}

// Levels

const vector<pair<string, string>> &EditorController::getLevels()
{
	return m_levels;
}

const std::vector<pair<string, string>> &EditorController::getGameLevels()
{
	return TheGame::Instance().getLevelFiles();
}


void EditorController::setLevelFiles(const std::vector<std::pair<std::string, std::string>> &levelFiles)
{
	TheGame::Instance().setLevelFiles(levelFiles);
}

// WindowSize

int EditorController::getWindowWidth()
{
	return TheGame::Instance().getWindowWidth();
}

int EditorController::getWindowHeight()
{
	return TheGame::Instance().getWindowHeight();
}

void EditorController::setWindowSize(int w, int h)
{
	TheGame::Instance().setWindowSize(w, h);
}

void EditorController::clearTilesets()
{
	m_tilesets.clear();
}

bool EditorController::deleteLevel(string id, string source)
{
	auto level = make_pair(id, source);
	// erase-remove idiom
	auto retIt = m_levels.erase(remove(m_levels.begin(), m_levels.end(), level), m_levels.end());
	if (retIt != m_levels.end())
	{
		// There isn't a level with the given id
		return false;
	}
	else
	{
		// Remove the level also from the game if necessary
		vector<pair<string, string>> newGameLevels;
		for (auto level : TheGame::Instance().getLevelFiles())
		{
			// If the level has the same id as the deleted, don't add to new levels vector
			if (level.first != id)
			{
				newGameLevels.push_back(level);
			}
		}
		TheGame::Instance().setLevelFiles(newGameLevels);
		return true;
	}
}

void EditorController::addLevel(std::string id, std::string source)
{
	m_levels.push_back(make_pair(id, source));
}

bool EditorController::levelExists(string id)
{
	for (auto level : m_levels)
	{
		if (level.first == id)
		{
			return true;
		}
	}
	// Reaching here means level was not found
	return false;
}

// General

void EditorController::clear()
{
	// Clear textures from texture manager map
	for (auto texture : m_textures)
	{
		TheTextureManager::Instance().clearFromTextureMap(texture.first);
	}
	// Clear sfxs and music from sound manager map
	for (auto sfx : m_sfxs)
	{
		TheSoundManager::Instance().clearSfx(sfx.first);
	}
	for (auto msc : m_music)
	{
		TheSoundManager::Instance().clearMusic(msc.first);
	}
	// Clear member data
	m_textures.clear();
	m_objConfigs.clear();
	m_tilesets.clear();
	m_levels.clear();
	m_sfxs.clear();
	m_music.clear();
	// Clear game settings
	TheGame::Instance().clearSettings();
}


void EditorController::updateGameSettings()
{
	// Set current values to new init values for the next time we test the level
	TheGame::Instance().clearStats();
}

void EditorController::saveProject(string projectFile)
{
	EditorParser parser;
	parser.writeProjectFile(projectFile, m_objConfigs, m_textures, 
		m_tilesets, m_levels, m_sfxs, m_music);
}

void EditorController::stop()
{
	m_bRunning = false;
}

void EditorController::setLevelMusic(string musicID)
{
	if (m_Editor != nullptr)
	{
		m_Editor->setMusic(musicID);
	}
}

string EditorController::getLevelMusic()
{
	if (m_Editor != nullptr)
	{
		return m_Editor->getMusic();
	}
	return "";
}
