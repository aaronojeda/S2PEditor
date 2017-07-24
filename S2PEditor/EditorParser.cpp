#include "EditorParser.h"
#include <iostream>
#include "EditorParser.h"
#include "Game.h"
#include "TextureManager.h"
#include "SoundManager.h"

using namespace std;
using namespace tinyxml2;

// Macro for returning errors during XML loading/writing
#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { return a_eResult; }
#endif

// Macro for returning and printing errors during XML loading/writing
#ifndef XMLCheckPrintResult
#define XMLCheckPrintResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("TinyXML Error: %i\n", a_eResult); return a_eResult; }
#endif

EditorParser::EditorParser()
{
}

EditorParser::~EditorParser()
{
}

XMLError EditorParser::parseProjectFile(const string file,
	vector<pair<string, string>> &editorLevels,
	map<string, string> &textures,
	vector<Tileset> &tilesets,
	map<string, GameObjCfg> &objConfigs,
	map<string, string> &sounds,
	map<string, string> &music)
{
	// open xml file
	XMLDocument xmlDoc;
	XMLError eResult = xmlDoc.LoadFile(file.c_str());
	XMLCheckPrintResult(eResult);
	XMLNode * pRoot = xmlDoc.FirstChild();
	if (pRoot == nullptr) XMLCheckPrintResult(XML_ERROR_FILE_READ_ERROR);

	/////////////////// editor resources //////////////////////

	// parse editor levels
	XMLElement * pElement = pRoot->FirstChildElement("levels");
	eResult = parseLevels(pElement, editorLevels);
	XMLCheckPrintResult(eResult);

	// parse textures
	pElement = pRoot->FirstChildElement("textures");
	eResult = parseTextures(pElement, textures);
	XMLCheckPrintResult(eResult);

	// parse sounds
	pElement = pRoot->FirstChildElement("sounds");
	eResult = parseSounds(pElement, sounds, "sound");
	XMLCheckPrintResult(eResult);

	// parse music
	pElement = pRoot->FirstChildElement("music");
	eResult = parseSounds(pElement, music, "msc");

	// parse tilesets
	pElement = pRoot->FirstChildElement("tilesets");
	eResult = parseTilesets(pElement, tilesets);
	XMLCheckPrintResult(eResult);

	// parse editor object configurations
	pElement = pRoot->FirstChildElement("editorobjects");
	eResult = parseEditorObjects(pElement, objConfigs);
	XMLCheckPrintResult(eResult);

	///////////////// game settings///////////////////////

	// parse game window size
	pElement = pRoot->FirstChildElement("window");
	int wWidth, wHeight;
	eResult = parseWindowSize(pElement, wWidth, wHeight);
	XMLCheckPrintResult(eResult);

	// parse initial values
	pElement = pRoot->FirstChildElement("initvalues");
	int initHealth, initLives, initScore, initKeys;
	eResult = parseValues(pElement, initHealth, initLives, initScore, initKeys);
	XMLCheckPrintResult(eResult);

	// parse maximum values
	pElement = pRoot->FirstChildElement("maxvalues");
	int maxHealth, maxLives, maxScore, maxKeys;
	eResult = parseValues(pElement, maxHealth, maxLives, maxScore, maxKeys);
	XMLCheckPrintResult(eResult);

	// parse game levels 
	pElement = pRoot->FirstChildElement("gamelevels");
	vector<pair<string, string>> gameLevels;
	eResult = parseLevels(pElement, gameLevels);
	XMLCheckPrintResult(eResult);

	// parse hud icons
	pElement = xmlDoc.FirstChild()->FirstChildElement("hud");
	string sHealth, sLives, sScore, sKeys;
	eResult = parseHUD(pElement, sHealth, sLives, sScore, sKeys);
	XMLCheckPrintResult(eResult);

	// parse game screens
	pElement = pRoot->FirstChildElement("screens");
	string sStart, sPause, sGameOver, sEnd;
	eResult = parseScreens(pElement, sStart, sPause, sGameOver, sEnd);
	XMLCheckPrintResult(eResult);

	// No parsing errors, so load values to Game

	// Load game window size
	TheGame::Instance().setWindowSize(wWidth, wHeight);
	// Load initial values
	TheGame::Instance().setInitValues(initHealth, initLives, initScore, initKeys);
	// Load maximum values
	TheGame::Instance().setMaxValues(maxHealth, maxLives, maxScore, maxKeys);
	// Load level files
	TheGame::Instance().setLevelFiles(gameLevels);
	// Load HUD icons
	TheGame::Instance().setHUDIcons(sHealth, sLives, sScore, sKeys);
	// Load screen texture ids
	TheGame::Instance().setScreenTextureIDs(sStart, sPause, sGameOver, sEnd);

	return XML_SUCCESS;
}

XMLError EditorParser::parseGameFile(const std::string gameFile)
{
	XMLDocument xmlDoc;
	XMLError eResult = xmlDoc.LoadFile(gameFile.c_str());
	XMLCheckPrintResult(eResult);

	XMLNode * pRoot = xmlDoc.FirstChild();
	if (pRoot == nullptr) XMLCheckPrintResult(XML_ERROR_FILE_READ_ERROR);

	// Parse level files
	XMLElement *pElement = pRoot->FirstChildElement("levels");
	vector<pair<string, string>> levels;
	eResult = parseLevels(pElement, levels);
	XMLCheckPrintResult(eResult);
	// Load level files
	TheGame::Instance().setLevelFiles(levels);

	// Parse textures
	pElement = pRoot->FirstChildElement("textures");
	map<string, string> textures;
	eResult = parseTextures(pElement, textures);
	XMLCheckPrintResult(eResult);
	// Load game textures into texture manager
	for (auto texture : textures)
	{
		TheTextureManager::Instance().load(texture.second, texture.first, TheGame::Instance().getRenderer());
	}

	// Parse sounds
	pElement = pRoot->FirstChildElement("sounds");
	map<string, string> sounds;
	eResult = parseSounds(pElement, sounds, "sound");
	XMLCheckPrintResult(eResult);
	// Load game sound effects into sound manager
	for (auto sound : sounds)
	{
		TheSoundManager::Instance().load(sound.second, sound.first, SOUND_SFX);
	}

	// Parse music
	pElement = pRoot->FirstChildElement("music");
	map<string, string> music;
	eResult = parseSounds(pElement, music, "msc");
	// Load game music into sound manager
	for (auto msc : music)
	{
		TheSoundManager::Instance().load(msc.second, msc.first, SOUND_MUSIC);
	}

	// Parse tilesets
	pElement = pRoot->FirstChildElement("tilesets");
	vector<Tileset> tilesets;
	eResult = parseTilesets(pElement, tilesets);
	XMLCheckPrintResult(eResult);
	TheGame::Instance().setTilesets(tilesets);

	// Parse window width and height
	pElement = pRoot->FirstChildElement("window");
	int wWidth, wHeight;
	eResult = parseWindowSize(pElement, wWidth, wHeight);
	XMLCheckPrintResult(eResult);
	TheGame::Instance().setWindowSize(wWidth, wHeight);

	// Parse initial values
	pElement = pRoot->FirstChildElement("initvalues");
	int initHealth, initLives, initScore, initKeys;
	eResult = parseValues(pElement, initLives, initHealth, initScore, initKeys);
	XMLCheckPrintResult(eResult);
	// Load initial values
	TheGame::Instance().setInitValues(initHealth, initLives, initScore, initKeys);

	// Parse max values
	pElement = pRoot->FirstChildElement("maxvalues");
	int maxHealth, maxLives, maxScore, maxKeys;
	eResult = parseValues(pElement, maxHealth, maxLives, maxScore, maxKeys);
	XMLCheckPrintResult(eResult);
	// Load maximum values
	TheGame::Instance().setMaxValues(maxHealth, maxLives, maxScore, maxKeys);

	// Parse screen images
	pElement = pRoot->FirstChildElement("screens");
	string sStart, sPause, sGameOver, sEnd;
	eResult = parseScreens(pElement, sStart, sPause, sGameOver, sEnd);
	XMLCheckPrintResult(eResult);
	// Load screen texture ids
	TheGame::Instance().setScreenTextureIDs(sStart, sPause, sGameOver, sEnd);

	// Parse HUD icons
	pElement = xmlDoc.FirstChild()->FirstChildElement("hud");
	if (pElement == nullptr) return XML_ERROR_PARSING_ELEMENT;
	string sLives, sHealth, sScore, sKeys;
	eResult = parseHUD(pElement, sHealth, sLives, sScore, sKeys);
	XMLCheckResult(eResult);
	// Load HUD icons
	TheGame::Instance().setHUDIcons(sHealth, sLives, sScore, sKeys);

	return XML_SUCCESS;
}

XMLError EditorParser::parseLevels(XMLElement* pLevelsElem, vector<pair<string, string>> &levels)
{
	// check levels element
	if (pLevelsElem == nullptr) return XML_ERROR_PARSING_ELEMENT;

	XMLError eResult = XML_SUCCESS;
	// Parse each level
	for (XMLElement * pLevel = pLevelsElem->FirstChildElement(); pLevel != NULL; pLevel = pLevel->NextSiblingElement())
	{
		if (!strcmp(pLevel->Value(), "level"))
		{
			pair<string, string> newLevel;
			XMLCheckResult(parseLevel(pLevel, newLevel));
			// If level was successfully parsed, add it to vector
			levels.push_back(newLevel);
		}
	}
	return eResult;
}

XMLError EditorParser::parseLevel(XMLElement* pLevelElem, pair<string, string> &level)
{
	const char *attributeText = nullptr;
	attributeText = pLevelElem->Attribute("name");
	if (attributeText == nullptr) return XML_ERROR_PARSING_ATTRIBUTE;
	level.first = attributeText;

	attributeText = pLevelElem->Attribute("file");
	if (attributeText == nullptr) return XML_ERROR_PARSING_ATTRIBUTE;
	level.second = attributeText;

	return XML_SUCCESS;
}

XMLError EditorParser::parseEditorObjects(XMLElement* pObjectsElement, std::map<std::string, GameObjCfg> &objConfigs)
{
	// Check XML element
	if (pObjectsElement == nullptr) return XML_ERROR_PARSING_ELEMENT;
	// Parse objects
	for (XMLElement * pObject = pObjectsElement->FirstChildElement(); pObject != NULL; pObject = pObject->NextSiblingElement())
	{
		if (!strcmp(pObject->Value(), "editorobject"))
		{
			GameObjCfg object;
			string objName;
			XMLCheckResult(parseEditorObject(pObject, object, objName));
			// If object configuration is successfully parsed, add it to the map
			objConfigs.insert(make_pair(objName, object));
		}
	}

	return XML_SUCCESS;
}

XMLError EditorParser::parseEditorObject(XMLElement* pObjectElement, GameObjCfg &object, string &objName)
{
	const char * configName = nullptr;
	configName = pObjectElement->Attribute("name");
	// If the name of the configuration is missing or empty, we don't parse it
	if (configName == nullptr || !strcmp(configName, ""))
	{
		return XML_ERROR_PARSING_ATTRIBUTE;
	}
	else
	{
		// Get object configuration name
		objName = configName;

		// Fill objectCfg attributes
		object.name = configName;
		XMLError eResult = pObjectElement->QueryIntAttribute("frameWidth", &object.frameWidth);
		XMLCheckResult(eResult);
		eResult = pObjectElement->QueryIntAttribute("frameHeight", &object.frameHeight);
		XMLCheckResult(eResult);
		eResult = pObjectElement->QueryIntAttribute("xBB", &object.collider.x);
		XMLCheckResult(eResult);
		eResult = pObjectElement->QueryIntAttribute("yBB", &object.collider.y);
		XMLCheckResult(eResult);
		eResult = pObjectElement->QueryIntAttribute("widthBB", &object.collider.w);
		XMLCheckResult(eResult);
		eResult = pObjectElement->QueryIntAttribute("heightBB", &object.collider.h);
		XMLCheckResult(eResult);
		eResult = pObjectElement->QueryIntAttribute("xSpeed", &object.xSpeed);
		XMLCheckResult(eResult);
		eResult = pObjectElement->QueryIntAttribute("ySpeed", &object.ySpeed);
		XMLCheckResult(eResult);
		eResult = pObjectElement->QueryIntAttribute("value", &object.value);
		XMLCheckResult(eResult);
		eResult = pObjectElement->QueryIntAttribute("value2", &object.value2);
		eResult = pObjectElement->QueryIntAttribute("value3", &object.value3);

		// Attribute() returns null if not found and std::string cannot be initialized with nullptr.
		const char* type = nullptr;
		type = pObjectElement->Attribute("type");
		if (type == nullptr) return XML_ERROR_PARSING_ATTRIBUTE;
		object.type = type;

		const char* textureID = nullptr;
		textureID = pObjectElement->Attribute("textureID");
		if (textureID == nullptr) return XML_ERROR_PARSING_ATTRIBUTE;
		object.textureID = textureID;

		const char* soundID = nullptr;
		soundID = pObjectElement->Attribute("soundID");
		if (soundID == nullptr) soundID = "";
		//if (soundID == nullptr) return XML_ERROR_PARSING_ATTRIBUTE;
		object.soundID = soundID;

		const char* sound2ID = nullptr;
		sound2ID = pObjectElement->Attribute("sound2ID");
		if (sound2ID == nullptr) sound2ID = "";
		//if (sound2ID == nullptr) return XML_ERROR_PARSING_ATTRIBUTE;
		object.sound2ID = sound2ID;

		// Parse object animations
		XMLElement * pAnimations = pObjectElement->FirstChildElement("animations");
		if (pAnimations == nullptr) return XML_ERROR_PARSING_ELEMENT;

		for (XMLElement * pAnim = pAnimations->FirstChildElement(); pAnim != NULL; pAnim = pAnim->NextSiblingElement())
		{
			if (!strcmp(pAnim->Value(), "animation"))
			{
				XMLCheckResult(parseAnimation(pAnim, object));
			}
		}

		return XML_SUCCESS;
	}
}

XMLError EditorParser::parseAnimation(XMLElement* pAnimElem, GameObjCfg &objCfg)
{
	QAnimStruct animation;
	int nFrames{ 1 };
	int frameTime{ 0 };

	XMLError eResult = XML_SUCCESS;
	// Parse animation nodes
	eResult = pAnimElem->QueryIntAttribute("row", &animation.row);
	XMLCheckResult(eResult);
	eResult = pAnimElem->QueryIntAttribute("nFrames", &animation.nFrames);
	XMLCheckResult(eResult);
	eResult = pAnimElem->QueryIntAttribute("frameTime", &animation.frameTime);
	XMLCheckResult(eResult);

	const char* name = pAnimElem->Attribute("name");
	if (name != nullptr)
	{
		objCfg.animations[name] = animation;
		return eResult;
	}
	else return XML_ERROR_PARSING_ATTRIBUTE;
}

XMLError EditorParser::parseTextures(XMLElement* pTexturesElement, map<string, string> &textureMap)
{
	// check XML element
	if (pTexturesElement == nullptr) return XML_ERROR_PARSING_ELEMENT;
	// Parse each texture
	for (XMLElement * pTexture = pTexturesElement->FirstChildElement(); pTexture != NULL; pTexture = pTexture->NextSiblingElement())
	{
		if (!strcmp(pTexture->Value(), "texture"))
		{
			pair<string, string> texture;
			XMLCheckResult(parseTexture(pTexture, texture));
			// If the texture was successfully parsed, insert it in the map
			textureMap.insert(texture);
		}
		else
		{
			XMLCheckResult(XML_ERROR_ELEMENT_MISMATCH);
		}
	}
	return XML_SUCCESS;
}

XMLError EditorParser::parseTexture(XMLElement* pTextureElement, pair<string, string> &texture)
{
	// Assigning nullptr to an std::string will raise an error so we have to check
	const char* id = pTextureElement->Attribute("id");
	if (id == nullptr) return XML_ERROR_PARSING_ATTRIBUTE;
	const char* source = pTextureElement->Attribute("source");
	if (source == nullptr) return XML_ERROR_PARSING_ATTRIBUTE;
	// id and source are valid
	texture = make_pair(id, source);
	return XML_SUCCESS;
}

XMLError EditorParser::parseSounds(XMLElement* pSoundsElement, map<string, string> &soundMap, string childValue)
{
	// check XML element
	if (pSoundsElement == nullptr) return XML_ERROR_PARSING_ELEMENT;
	// Parse each sound
	for (XMLElement * pSound = pSoundsElement->FirstChildElement(); pSound != NULL; pSound = pSound->NextSiblingElement())
	{
		if (!strcmp(pSound->Value(), childValue.c_str()))
		{
			pair<string, string> sound;
			XMLCheckResult(parseSound(pSound, sound));
			// If the sound was successfully parsed, insert it in the map
			soundMap.insert(sound);
		}
		else
		{
			XMLCheckResult(XML_ERROR_ELEMENT_MISMATCH);
		}
	}
	return XML_SUCCESS;
}

XMLError EditorParser::parseSound(XMLElement* pSoundElement, pair<string, string> &sound)
{
	// Assigning nullptr to an std::string will raise an error so we have to check
	const char* id = pSoundElement->Attribute("id");
	if (id == nullptr) return XML_ERROR_PARSING_ATTRIBUTE;
	const char* source = pSoundElement->Attribute("source");
	if (source == nullptr) return XML_ERROR_PARSING_ATTRIBUTE;
	// id and source are valid
	sound = make_pair(id, source);
	return XML_SUCCESS;
}

XMLError EditorParser::parseTilesets(XMLElement* pTilesetsElement, vector<Tileset> &tilesets)
{
	// check XML element
	if (pTilesetsElement == nullptr) return XML_ERROR_PARSING_ELEMENT;
	// Parse each tileset
	for (XMLElement * pTileset = pTilesetsElement->FirstChildElement(); pTileset != NULL; pTileset = pTileset->NextSiblingElement())
	{
		if (!strcmp(pTileset->Value(), "tileset"))
		{
			Tileset tileset;
			XMLCheckResult(parseTileset(pTileset, tileset));
			// If tileset was successfully parsed, add it to the vector
			tilesets.push_back(tileset);
		}
		else
		{
			return XML_ERROR_ELEMENT_MISMATCH;
		}
	}
	return XML_SUCCESS;
}

XMLError EditorParser::parseTileset(XMLElement* pTilesetElement, Tileset &tileset)
{
	const char* checkName = pTilesetElement->Attribute("name");
	if (checkName == nullptr) return XML_ERROR_PARSING_ATTRIBUTE;
	tileset.name = checkName;
	XMLError eResult = pTilesetElement->QueryIntAttribute("firstgid", &tileset.firstGridID);
	XMLCheckResult(eResult);
	eResult = pTilesetElement->QueryIntAttribute("tilewidth", &tileset.tileWidth);
	XMLCheckResult(eResult);
	eResult = pTilesetElement->QueryIntAttribute("tileheight", &tileset.tileHeight);
	XMLCheckResult(eResult);
	eResult = pTilesetElement->QueryIntAttribute("spacing", &tileset.spacing);
	XMLCheckResult(eResult);
	eResult = pTilesetElement->QueryIntAttribute("margin", &tileset.margin);
	XMLCheckResult(eResult);

	// Parse image attributes
	eResult = pTilesetElement->QueryIntAttribute("width", &tileset.width);
	XMLCheckResult(eResult);
	eResult = pTilesetElement->QueryIntAttribute("height", &tileset.height);
	XMLCheckResult(eResult);
	const char* checkTextureID = pTilesetElement->Attribute("textureID");
	if (checkTextureID == nullptr) return XML_ERROR_PARSING_ATTRIBUTE;
	tileset.textureID = checkTextureID;

	return XML_SUCCESS;
}

XMLError EditorParser::parseScreens(XMLElement *pScreensElem, string &sStart, string &sPause, string &sGameover, string &sEnd)
{
	if (pScreensElem == nullptr) return XML_ERROR_PARSING_ELEMENT;

	const char *attributeText = nullptr;
	attributeText = pScreensElem->Attribute("start");
	if (attributeText == nullptr) return XML_ERROR_PARSING_ATTRIBUTE;
	sStart = attributeText;

	attributeText = pScreensElem->Attribute("pause");
	if (attributeText == nullptr) return XML_ERROR_PARSING_ATTRIBUTE;
	sPause = attributeText;

	attributeText = pScreensElem->Attribute("gameover");
	if (attributeText == nullptr) return XML_ERROR_PARSING_ATTRIBUTE;
	sGameover = attributeText;

	attributeText = pScreensElem->Attribute("end");
	if (attributeText == nullptr) return XML_ERROR_PARSING_ATTRIBUTE;
	sEnd = attributeText;

	// If this point has been reached it means everything went fine
	return XML_SUCCESS;
}

XMLError EditorParser::parseHUD(XMLElement *pHUDElem, string &sHealth, string &sLives, string &sScore, string &sKeys)
{
	if (pHUDElem == nullptr) return XML_ERROR_PARSING_ELEMENT;

	const char *attributeText = nullptr;
	attributeText = pHUDElem->Attribute("health");
	if (attributeText == nullptr) return XML_ERROR_PARSING_ATTRIBUTE;
	sHealth = attributeText;

	attributeText = pHUDElem->Attribute("lives");
	if (attributeText == nullptr) return XML_ERROR_PARSING_ATTRIBUTE;
	sLives = attributeText;

	attributeText = pHUDElem->Attribute("score");
	if (attributeText == nullptr) return XML_ERROR_PARSING_ATTRIBUTE;
	sScore = attributeText;

	attributeText = pHUDElem->Attribute("keys");
	if (attributeText == nullptr) return XML_ERROR_PARSING_ATTRIBUTE;
	sKeys = attributeText;

	// If this point has been reached it means everything went fine
	return XML_SUCCESS;
}

XMLError EditorParser::parseValues(XMLElement* pValuesElem, int &health, int &lives, int &score, int &keys)
{
	// Check XML element
	if (pValuesElem == nullptr)  return XML_ERROR_PARSING_ELEMENT;

	XMLError eResult = pValuesElem->QueryIntAttribute("health", &health);
	XMLCheckResult(eResult);
	eResult = pValuesElem->QueryIntAttribute("lives", &lives);
	XMLCheckResult(eResult);
	eResult = pValuesElem->QueryIntAttribute("score", &score);
	XMLCheckResult(eResult);
	eResult = pValuesElem->QueryIntAttribute("keys", &keys);
	XMLCheckResult(eResult);

	return XML_SUCCESS;
}

XMLError EditorParser::parseWindowSize(XMLElement* pWindowElement, int &width, int &height)
{
	if (pWindowElement == nullptr) return XML_ERROR_PARSING_ELEMENT;
	// Parse window width and height
	XMLError eResult = pWindowElement->QueryIntAttribute("width", &width);
	XMLCheckResult(eResult);
	eResult = pWindowElement->QueryIntAttribute("height", &height);
	XMLCheckResult(eResult);

	return XML_SUCCESS;
}

bool EditorParser::writeProjectFile(const string fileName, const map<std::string, GameObjCfg> &objConfigs, 
	const map<string, string> &projectTextures,
	const std::vector<Tileset> &tilesets,
	const std::vector<std::pair<std::string, std::string>> &levels,
	const std::map<std::string, std::string> &sfxs,
	const std::map<std::string, std::string> &music)
{
	XMLDocument tmxFile;

	// Insert root element and its attributes
	XMLNode *pRoot = tmxFile.NewElement("editorFile");
	tmxFile.InsertFirstChild(pRoot);

	// write window resolution
	XMLElement *pElement = tmxFile.NewElement("window");
	pElement->SetAttribute("width", TheGame::Instance().getWindowWidth());
	pElement->SetAttribute("height", TheGame::Instance().getWindowHeight());
	pRoot->InsertEndChild(pElement);

	// write initial values
	pElement = tmxFile.NewElement("initvalues");
	int health, lives, score, keys;
	TheGame::Instance().getInitValues(health, lives, score, keys);
	writeValues(pElement, health, lives, score, keys);
	pRoot->InsertEndChild(pElement);

	// write maximum values
	pElement = tmxFile.NewElement("maxvalues");
	TheGame::Instance().getMaxValues(health, lives, score, keys);
	writeValues(pElement, health, lives, score, keys);
	pRoot->InsertEndChild(pElement);
	
	// write project levels
	pElement = tmxFile.NewElement("levels");
	writeLevels(pElement, levels);
	pRoot->InsertEndChild(pElement);

	// write game levels
	pElement = tmxFile.NewElement("gamelevels");
	// We can't write TheGame levels directly because we could be exporting a project,
	// and thus game levels path would be wrong (with current project's name instead of exported's)
	vector<pair<string, string>> gameLevels;
	// get game levels
	for (auto gameLevel : TheGame::Instance().getLevelFiles())
	{
		auto levelID = gameLevel.first;
		// search for levelID in project levels
		for (auto projectLevel : levels)
		{
			if (projectLevel.first == levelID)
			{
				// add level to game levels
				gameLevels.push_back(projectLevel);
			}
		}
	}
	// write game levels
	writeLevels(pElement, gameLevels);
	pRoot->InsertEndChild(pElement);

	// write project textures
	pElement = tmxFile.NewElement("textures");
	for (auto texture : projectTextures)
	{
		XMLElement *pTexture = tmxFile.NewElement("texture");
		pTexture->SetAttribute("id", texture.first.c_str());
		pTexture->SetAttribute("source", texture.second.c_str());
		pElement->InsertEndChild(pTexture);
	}
	// insert textures node
	pRoot->InsertEndChild(pElement);

	// write project sfxs
	pElement = tmxFile.NewElement("sounds");
	for (auto sfx : sfxs)
	{
		XMLElement *pSfx = tmxFile.NewElement("sound");
		pSfx->SetAttribute("id", sfx.first.c_str());
		pSfx->SetAttribute("source", sfx.second.c_str());
		pElement->InsertEndChild(pSfx);
	}
	pRoot->InsertEndChild(pElement);
	
	// write project music
	pElement = tmxFile.NewElement("music");
	for (auto msc : music)
	{
		XMLElement *pMsc = tmxFile.NewElement("msc");
		pMsc->SetAttribute("id", msc.first.c_str());
		pMsc->SetAttribute("source", msc.second.c_str());
		pElement->InsertEndChild(pMsc);
	}
	pRoot->InsertEndChild(pElement);

	// write hud
	pElement = tmxFile.NewElement("hud");
	string sHealth, sLives, sScore, sKeys;
	// get hud icons
	TheGame::Instance().getHUDIcons(sHealth, sLives, sScore, sKeys);
	// write hud icon sources
	writeHUD(pElement, sHealth, sLives, sScore, sKeys);
	pRoot->InsertEndChild(pElement);

	// write screens
	pElement = tmxFile.NewElement("screens");
	string sStart, sPause, sGameover, sEnd;
	// get screen ids
	TheGame::Instance().getScreenTextureIDs(sStart, sPause, sGameover, sEnd);
	// write screen image sources
	writeScreens(pElement, sStart, sPause, sGameover, sEnd);
	pRoot->InsertEndChild(pElement);

	// write project tilesets
	pElement = tmxFile.NewElement("tilesets");
	for (auto tileset : tilesets)
	{
		XMLElement *pTileset = tmxFile.NewElement("tileset");
		pTileset->SetAttribute("name", tileset.name.c_str());
		pTileset->SetAttribute("firstgid", tileset.firstGridID);
		pTileset->SetAttribute("tilewidth", tileset.tileWidth);
		pTileset->SetAttribute("tileheight", tileset.tileHeight);
		pTileset->SetAttribute("spacing", tileset.spacing);
		pTileset->SetAttribute("margin", tileset.margin);
		pTileset->SetAttribute("textureID", tileset.textureID.c_str());
		pTileset->SetAttribute("width", tileset.width);
		pTileset->SetAttribute("height", tileset.height);
		pElement->InsertEndChild(pTileset);
	}
	pRoot->InsertEndChild(pElement);

	// write editor objects
	pElement = tmxFile.NewElement("editorobjects");
	for (auto objCfg : objConfigs)
	{
		XMLElement *pObject = tmxFile.NewElement("editorobject");
		
		GameObjCfg object = objCfg.second;

		pObject->SetAttribute("name", objCfg.first.c_str());
		pObject->SetAttribute("textureID", object.textureID.c_str());
		pObject->SetAttribute("type", object.type.c_str());
		pObject->SetAttribute("frameWidth", object.frameWidth);
		pObject->SetAttribute("frameHeight", object.frameHeight);
		pObject->SetAttribute("xBB", object.collider.x);
		pObject->SetAttribute("yBB", object.collider.y);
		pObject->SetAttribute("widthBB", object.collider.w);
		pObject->SetAttribute("heightBB", object.collider.h);
		pObject->SetAttribute("xSpeed", object.xSpeed);
		pObject->SetAttribute("ySpeed", object.ySpeed);
		pObject->SetAttribute("value", object.value);
		pObject->SetAttribute("value2", object.value2);
		pObject->SetAttribute("value3", object.value3);
		pObject->SetAttribute("soundID", object.soundID.c_str());
		pObject->SetAttribute("sound2ID", object.sound2ID.c_str());

		// write animations node
		XMLElement *pAnimations = pObject->GetDocument()->NewElement("animations");
		for (auto anim : object.animations)
		{
			XMLElement *pAnimation = pAnimations->GetDocument()->NewElement("animation");
			// Write the name of the animation
			pAnimation->SetAttribute("name", anim.first.c_str());
			// Write the remaining attributes of the animation
			writeAnimation(pAnimation, anim.second);
			// Insert animation node
			pAnimations->InsertEndChild(pAnimation);
		}

		// Insert animations node
		pObject->InsertEndChild(pAnimations);

		// Insert editor object node
		pElement->InsertEndChild(pObject);
	}
	// Insert object configs node
	pRoot->InsertEndChild(pElement);
	
	// Save editor file
	if (tmxFile.SaveFile(fileName.c_str()) == XML_NO_ERROR)
	{
		return true;
	}
	else
	{
		std::cout << "Editor parser error writing file " << fileName << ". TinyXML error: " << tmxFile.ErrorName() << std::endl;
		return false;
	}
}

void EditorParser::writeAnimation(tinyxml2::XMLElement* pAnimElem, QAnimStruct animation)
{
	pAnimElem->SetAttribute("row", animation.row);				// Sprite sheet row
	pAnimElem->SetAttribute("nFrames", animation.nFrames);		// Total frames
	pAnimElem->SetAttribute("frameTime", animation.frameTime);	// Interval between frames
}

XMLError EditorParser::writeGameFile(const string settingsFile, 
	const map<string, string> &textures, 
	const vector<Tileset> &tilesets,
	const vector<pair<string, string>> &levels,
	const map<string, string> &sfxs,
	const map<string, string> &music)
{
	XMLDocument xmlDoc;

	// Insert root element and its attributes
	XMLNode *pRoot = xmlDoc.NewElement("game");
	xmlDoc.InsertFirstChild(pRoot);

	// write window resolution
	XMLElement *pElement = xmlDoc.NewElement("window");
	pElement->SetAttribute("width", TheGame::Instance().getWindowWidth());
	pElement->SetAttribute("height", TheGame::Instance().getWindowHeight());
	pRoot->InsertFirstChild(pElement);

	// write initial values
	pElement = xmlDoc.NewElement("initvalues");
	int health, lives, score, keys;
	TheGame::Instance().getInitValues(health, lives, score, keys);
	writeValues(pElement, health, lives, score, keys);
	pRoot->InsertEndChild(pElement);

	// write maximum values
	pElement = xmlDoc.NewElement("maxvalues");
	TheGame::Instance().getMaxValues(health, lives, score, keys);
	writeValues(pElement, health, lives, score, keys);
	pRoot->InsertEndChild(pElement);

	// write game levels
	pElement = xmlDoc.NewElement("levels");
	writeLevels(pElement, levels);
	pRoot->InsertEndChild(pElement);

	// write project textures
	pElement = xmlDoc.NewElement("textures");
	for (auto texture : textures)
	{
		XMLElement *pTexture = xmlDoc.NewElement("texture");
		pTexture->SetAttribute("id", texture.first.c_str());
		pTexture->SetAttribute("source", texture.second.c_str());
		pElement->InsertEndChild(pTexture);
	}
	// insert textures node
	pRoot->InsertEndChild(pElement);

	// write project sfxs
	pElement = xmlDoc.NewElement("sounds");
	for (auto sfx : sfxs)
	{
		XMLElement *pSound = xmlDoc.NewElement("sound");
		pSound->SetAttribute("id", sfx.first.c_str());
		pSound->SetAttribute("source", sfx.second.c_str());
		pElement->InsertEndChild(pSound);
	}
	pRoot->InsertEndChild(pElement);

	//write project music
	pElement = xmlDoc.NewElement("music");
	for (auto msc : music)
	{
		XMLElement *pMusic = xmlDoc.NewElement("msc");
		pMusic->SetAttribute("id", msc.first.c_str());
		pMusic->SetAttribute("source", msc.second.c_str());
		pElement->InsertEndChild(pMusic);
	}
	pRoot->InsertEndChild(pElement);

	// write hud
	pElement = xmlDoc.NewElement("hud");
	string sHealth, sLives, sScore, sKeys;
	// get hud icon sources
	TheGame::Instance().getHUDIcons(sHealth, sLives, sScore, sKeys);
	// write hud icon sources
	writeHUD(pElement, sHealth, sLives, sScore, sKeys);
	pRoot->InsertEndChild(pElement);

	// write screens
	pElement = xmlDoc.NewElement("screens");
	string sStart, sPause, sGameOver, sEnd;
	// get screen texture ids
	TheGame::Instance().getScreenTextureIDs(sStart, sPause, sGameOver, sEnd);
	// write screen image sources
	writeScreens(pElement, sStart, sPause, sGameOver, sEnd);
	pRoot->InsertEndChild(pElement);

	// write project tilesets
	pElement = xmlDoc.NewElement("tilesets");
	for (auto tileset : tilesets)
	{
		XMLElement *pTileset = xmlDoc.NewElement("tileset");
		pTileset->SetAttribute("name", tileset.name.c_str());
		pTileset->SetAttribute("firstgid", tileset.firstGridID);
		pTileset->SetAttribute("tilewidth", tileset.tileWidth);
		pTileset->SetAttribute("tileheight", tileset.tileHeight);
		pTileset->SetAttribute("spacing", tileset.spacing);
		pTileset->SetAttribute("margin", tileset.margin);
		pTileset->SetAttribute("textureID", tileset.textureID.c_str());
		pTileset->SetAttribute("width", tileset.width);
		pTileset->SetAttribute("height", tileset.height);
		pElement->InsertEndChild(pTileset);
	}
	pRoot->InsertEndChild(pElement);

	XMLError eResult = xmlDoc.SaveFile(settingsFile.c_str());
	XMLCheckResult(eResult);
	return XML_SUCCESS;
}

void EditorParser::writeLevels(XMLElement* pElem, const vector<pair<string, string>> &levels)
{
	for (auto level : levels)
	{
		XMLElement *pLevel = pElem->GetDocument()->NewElement("level");
		pLevel->SetAttribute("name", level.first.c_str());
		pLevel->SetAttribute("file", level.second.c_str());
		// Insert level node
		pElem->InsertEndChild(pLevel);
	}	
}

void EditorParser::writeValues(XMLElement* pElem, int health, int lives, int score, int keys)
{
	pElem->SetAttribute("health", health);
	pElem->SetAttribute("lives", lives);
	pElem->SetAttribute("score", score);
	pElem->SetAttribute("keys", keys);
}

void EditorParser::writeScreens(XMLElement* pElem, string start, string pause, string gameover, string end)
{
	pElem->SetAttribute("start", start.c_str());
	pElem->SetAttribute("pause", pause.c_str());
	pElem->SetAttribute("gameover", gameover.c_str());
	pElem->SetAttribute("end", end.c_str());	
}

void EditorParser::writeHUD(XMLElement* pElem, string health, string lives, string score, string keys)
{
	pElem->SetAttribute("health", health.c_str());
	pElem->SetAttribute("lives", lives.c_str());
	pElem->SetAttribute("score", score.c_str());
	pElem->SetAttribute("keys", keys.c_str());
}

XMLError EditorParser::parseLastProject(string file, string &lastProject)
{
	XMLDocument xmlDoc;
	XMLError eResult = xmlDoc.LoadFile(file.c_str());
	XMLCheckPrintResult(eResult);

	XMLNode * pRoot = xmlDoc.FirstChild();
	if (pRoot == nullptr) XMLCheckPrintResult(XML_ERROR_FILE_READ_ERROR);

	// Parse level files
	XMLElement *pElement = pRoot->FirstChildElement("project");
	if (pElement == nullptr) XMLCheckPrintResult(XML_ERROR_PARSING_ELEMENT);
	const char* checkSource = pElement->Attribute("source");
	if (checkSource != nullptr)
	{
		lastProject = checkSource;
		return eResult;
	}
	else XMLCheckPrintResult(XML_ERROR_PARSING_ATTRIBUTE);
}

XMLError EditorParser::parseLastLevel(string file, string &lastLevel)
{
	XMLDocument xmlDoc;
	XMLError eResult = xmlDoc.LoadFile(file.c_str());
	XMLCheckPrintResult(eResult);

	XMLNode * pRoot = xmlDoc.FirstChild();
	if (pRoot == nullptr) return XML_ERROR_FILE_READ_ERROR;

	// Parse level files
	XMLElement *pElement = pRoot->FirstChildElement("level");
	if (pElement == nullptr) return XML_ERROR_PARSING_ELEMENT;
	const char* checkSource = pElement->Attribute("source");
	if (checkSource != nullptr)
	{
		lastLevel = checkSource;
		return eResult;
	}
	else XMLCheckPrintResult(XML_ERROR_PARSING_ATTRIBUTE);
}

XMLError EditorParser::writeLastEdited(string file, string lastProject, string lastLevel)
{
	XMLDocument xmlDoc;

	// Insert root element and its attributes
	XMLNode *pRoot = xmlDoc.NewElement("last");
	xmlDoc.InsertFirstChild(pRoot);

	// write last edited project
	XMLElement *pElement = xmlDoc.NewElement("project");
	pElement->SetAttribute("source", lastProject.c_str());
	pRoot->InsertFirstChild(pElement);

	// write last edited level
	pElement = xmlDoc.NewElement("level");
	pElement->SetAttribute("source", lastLevel.c_str());
	pRoot->InsertEndChild(pElement);

	XMLError eResult = xmlDoc.SaveFile(file.c_str());
	XMLCheckResult(eResult);
	return XML_SUCCESS;
}

XMLError EditorParser::parseLevelSize(const string levelName, int &width, int &height, int &tileSize)
{
	// Open level file
	XMLDocument xmlDoc;
	XMLError eResult = xmlDoc.LoadFile(levelName.c_str());
	XMLCheckResult(eResult);

	// Go to root element
	XMLElement *pElement = xmlDoc.RootElement();
	if (pElement == nullptr) XMLCheckResult(XML_ERROR_PARSING_ELEMENT);

	// Get width, height and tileSize
	eResult = pElement->QueryIntAttribute("width", &width);
	XMLCheckResult(eResult);
	eResult = pElement->QueryIntAttribute("height", &height);
	XMLCheckResult(eResult);
	eResult = pElement->QueryIntAttribute("tilewidth", &tileSize);
	XMLCheckResult(eResult);

	return XML_SUCCESS;
}

XMLError EditorParser::parseEditorLevels(std::string file, std::vector<std::pair<std::string, std::string>> &levels)
{
	// Open level file
	XMLDocument xmlDoc;
	XMLError eResult = xmlDoc.LoadFile(file.c_str());
	XMLCheckPrintResult(eResult);

	// Levels element
	XMLElement * pElement = xmlDoc.FirstChild()->FirstChildElement("levels");
	eResult = parseLevels(pElement, levels);
	XMLCheckPrintResult(eResult);
	return eResult;
}

XMLError EditorParser::parseWindowSize(const string settingsFile, int &width, int &height)
{
	XMLDocument xmlDoc;
	XMLError eResult = xmlDoc.LoadFile(settingsFile.c_str());
	XMLCheckResult(eResult);

	// Parse window width and height
	XMLElement *pElement = xmlDoc.FirstChild()->FirstChildElement("window");
	if (pElement == nullptr) return XML_ERROR_PARSING_ELEMENT;
	eResult = pElement->QueryIntAttribute("width", &width);
	XMLCheckResult(eResult);
	eResult = pElement->QueryIntAttribute("height", &height);
	XMLCheckResult(eResult);

	// If this point has been reached it means everything went fine
	return XML_SUCCESS;
}