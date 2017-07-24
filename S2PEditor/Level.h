#pragma once

#include <string>
#include <vector>
#include "Layer.h"
#include "Player.h"

class TileLayer;

// Struct that holds the information we need to know about our tilesets.
struct Tileset
{
	int firstGridID;
	int tileWidth;
	int tileHeight;
	int spacing;
	int margin;
	int width;
	int height;
	std::string name;
	std::string textureID;
};

// Basic Level class whose purpose is to store, draw, and update our layers.
class Level
{
public:
	Level();
	Level(int width, int height, int tileSize);
	~Level();

	void update();
	void render();

	//const std::vector<Tileset>& getTilesets() { return m_tilesets; }
	std::vector<Layer*>* getLayers() { return &m_layers; }
	std::vector<TileLayer*>* getCollisionLayers() { return &m_collisionLayers; }
	std::vector<GameObject*>* getCollisionObjects() { return &m_collisionObjects; }

	// Player getter and setter
	Player* getPlayer() { return m_pPlayer; }
	void setPlayer(Player* pPlayer) { m_pPlayer = pPlayer; }

	// Return level width in tiles
	int getWidth() const { return m_width; }
	// Return level height in tiles
	int getHeight() const { return m_height; }
	// Return tile size in pixels
	int getTileSize() const { return m_tileSize; }

	// Remove all tiles of a given tileset
	void removeTiles(const int firstGridID);
	
	const std::string &getMusic() const { return m_music; }
	void setMusic(const std::string &music);
private:

	/* Whenever we want to create a level we must call the LevelParser->parseLevel function
	To ensure that this we will make the Level class' constructor private and make it a friend class of LevelParser: */

	friend class LevelParser;
	friend class EditorState;

	std::vector<Layer*> m_layers;
	std::vector<TileLayer*> m_collisionLayers;
	std::vector<GameObject*> m_collisionObjects;
	
	// Size in tiles
	int m_width;
	int m_height;
	// Standard tile size
	int m_tileSize;

	// A pointer to Player is needed because it will not handle ints own collisions
	Player* m_pPlayer;

	// background music
	std::string m_music;
};