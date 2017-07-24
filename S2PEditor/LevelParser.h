#pragma once

#include <vector>
#include <string>
#include "Animation.h"
#include "Level.h"
#include "tinyxml2.h"

class ObjectLayer;
class GameObject;

class LevelParser
{
public:
	// Create a level from file. Should be freed by the caller
	Level* parseLevel(const char* levelFile);
	bool writeLevel(const Level &level, std::string name);

private:
	// Add tile layer in pTileElement XMElement to level
	void parseTileLayer(tinyxml2::XMLElement* pTileElement, Level* pLevel);
	void parseObjLayer(tinyxml2::XMLElement* pObjectElement, Level* pLevel);
	void parseBckLayer(tinyxml2::XMLElement* pObjectElement, Level* pLevel);
	GameObject* parseObject(tinyxml2::XMLElement* pObject);
	void parseAnimations(tinyxml2::XMLElement* pAnimationsElement, std::map<std::string, Animation> &animations);
	void writeTileLayer(tinyxml2::XMLElement* pTileElement, TileLayer* layer, std::string layerName = "Tile Layer");
	void writeObjectLayer(tinyxml2::XMLElement* pGroupElement, ObjectLayer* layer, std::string layerName = "Object Layer");
	void writeAnimation(tinyxml2::XMLElement* pAnimElem, Animation animation);

	int m_tileSize{ 0 };
	int m_width{ 0 };
	int m_height{ 0 };
};