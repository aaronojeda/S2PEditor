#pragma once

#include <map>
#include <vector>
#include "tinyxml2.h"
#include "Level.h"

struct QAnimStruct
{
	int row;
	int nFrames;
	int frameTime;
};

struct GameObjCfg
{
	std::string name;
	std::string type;
	std::string textureID;
	std::string soundID;
	std::string sound2ID;
	int frameWidth{ 0 };
	int frameHeight{ 0 };
	SDL_Rect collider{ { 0, 0, 0, 0 } };
	std::map<std::string, QAnimStruct> animations;
	int xSpeed{ 0 };
	int ySpeed{ 0 };
	int value{ 0 };
	int value2{ 0 };
	int value3{ 0 };
};

// This parser will read and write elements needed to the Qt interface (textures, added objects, custom types)
class EditorParser
{
public:
	EditorParser();
	~EditorParser();

	// parse project file
	tinyxml2::XMLError parseProjectFile(const std::string file,
		std::vector<std::pair<std::string, std::string>> &editorLevels,
		std::map<std::string, std::string> &textures,
		std::vector<Tileset> &tilesets,
		std::map<std::string, GameObjCfg> &objConfigs,
		std::map<std::string, std::string> &sounds,
		std::map<std::string, std::string> &music);
	// write project file
	bool writeProjectFile(const std::string fileName, const std::map<std::string, GameObjCfg> &objConfigs,
		const std::map<std::string, std::string> &projectTextures,
		const std::vector<Tileset> &tilesets,
		const std::vector<std::pair<std::string, std::string>> &levels,
		const std::map<std::string, std::string> &sfxs,
		const std::map<std::string, std::string> &music);

	// parse game file
	tinyxml2::XMLError parseGameFile(const std::string gameFile);
	// write game file
	tinyxml2::XMLError writeGameFile(const std::string settingsFile,
		const std::map<std::string, std::string> &textures,
		const std::vector<Tileset> &tilesets,
		const std::vector<std::pair<std::string, std::string>> &levels,
		const std::map<std::string, std::string> &sfxs,
		const std::map<std::string, std::string> &music);

	// parse game window size
	tinyxml2::XMLError parseWindowSize(const std::string settingsFile, int &width, int &height);

	// parse level size
	tinyxml2::XMLError parseLevelSize(const std::string levelName, int &width, int &height, int &tileSize);

	// parse editor levels
	tinyxml2::XMLError parseEditorLevels(std::string file, std::vector<std::pair<std::string, std::string>> &levels);

	// Last edited project and level
	tinyxml2::XMLError parseLastProject(std::string file, std::string &lastProject);
	tinyxml2::XMLError parseLastLevel(std::string file, std::string &lastLevel);
	tinyxml2::XMLError writeLastEdited(std::string file, std::string lastProject, std::string lastLevel);

private:
	// Parse levels
	tinyxml2::XMLError parseLevels(tinyxml2::XMLElement* pLevelsElem, std::vector<std::pair<std::string, std::string>> &levels);
	tinyxml2::XMLError parseLevel(tinyxml2::XMLElement* pLevelElem, std::pair<std::string, std::string> &level);
	// Parse textures
	tinyxml2::XMLError parseTextures(tinyxml2::XMLElement* pTexturesElement, std::map<std::string, std::string> &textureMap);
	tinyxml2::XMLError parseTexture(tinyxml2::XMLElement* pTextureElement, std::pair<std::string, std::string> &texture);
	// Parse sounds. Valid for sfxs and music
	tinyxml2::XMLError parseSounds(tinyxml2::XMLElement* pSoundsElement, std::map<std::string, std::string> &soundMap, std::string childValue);
	tinyxml2::XMLError parseSound(tinyxml2::XMLElement* pSoundElement, std::pair<std::string, std::string> &sound);
	// Parse editor object configurations
	tinyxml2::XMLError parseEditorObjects(tinyxml2::XMLElement* pObjectsElement, std::map<std::string, GameObjCfg> &objConfigs);
	tinyxml2::XMLError parseEditorObject(tinyxml2::XMLElement* pObjectElement, GameObjCfg &object, std::string &objName);
	tinyxml2::XMLError parseAnimation(tinyxml2::XMLElement* pAnimElem, GameObjCfg &objCfg);
	// Parse tilesets
	tinyxml2::XMLError parseTilesets(tinyxml2::XMLElement* pTilesetsElement, std::vector<Tileset> &tilesets);
	tinyxml2::XMLError parseTileset(tinyxml2::XMLElement* pTilesetElement, Tileset &tileset);
	// Parse game settings
	tinyxml2::XMLError parseWindowSize(tinyxml2::XMLElement* pWindowElement, int &width, int &height);
	tinyxml2::XMLError parseScreens(tinyxml2::XMLElement* pScreensElem, std::string &sStart,
		std::string &sPause, std::string &sGameover, std::string &sEnd);
	tinyxml2::XMLError parseHUD(tinyxml2::XMLElement* pHUDElem, std::string &sHealth, std::string &sLives,
		std::string &sScore, std::string &sKeys);
	tinyxml2::XMLError parseValues(tinyxml2::XMLElement* pValuesElem, int &health, int &lives, int &score, int &keys);

	// Auxiliar writing functions
	void writeAnimation(tinyxml2::XMLElement* pAnimElem, QAnimStruct animation);
	void writeLevels(tinyxml2::XMLElement* pElem, const std::vector<std::pair<std::string, std::string>> &levels);
	void writeValues(tinyxml2::XMLElement* pElem, int health, int lives, int score, int keys);
	void writeScreens(tinyxml2::XMLElement* pElem, std::string start, std::string pause, std::string gameover, std::string end);
	void writeHUD(tinyxml2::XMLElement* pElem, std::string health, std::string lives, std::string score, std::string keys);
};

