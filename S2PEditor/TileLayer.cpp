#include "TileLayer.h"
#include "Game.h"
#include "TextureManager.h"
#include "Camera.h"

const std::string TileLayer::s_tileLayerID = "TILE";

TileLayer::TileLayer(int tileSize, int mapWidth, int mapHeight, const std::vector<Tileset>& tilesets, bool collidable) :
m_tileSize(tileSize),
m_tilesets(tilesets),
m_collidable(collidable),
m_position(0, 0),
m_velocity(0, 0)
{
	m_numColumns = mapWidth;
	m_numRows = mapHeight;
}

// The tile map moves according to the position of the camera and skips any tiles that are outside the viewable area
void TileLayer::render()
{
	// We loop through the number of rows and columns in the level
	for (int i = 0; i < m_numRows; i++)
	{
		for (int j = 0; j < m_numColumns; j++)
		{
			// Get the id of the corresponding tile
			int id = m_tileIDs[i][j];

			// If tile id is equal to 0 we don't want to draw anything
			if (id == 0)
			{
				continue;
			}

			// if outside the viewable area then skip the tile
			if (((j + 1) * m_tileSize <= TheCamera::Instance().getPosition().x()) ||
				(j * m_tileSize >= TheCamera::Instance().getPosition().x() + TheGame::Instance().getGameWidth()) ||
				((i + 1) * m_tileSize <= TheCamera::Instance().getPosition().y()) ||
				(i * m_tileSize >= TheCamera::Instance().getPosition().y() + TheGame::Instance().getGameHeight()))
			{
				continue;
			}

			// We select the correct tileset according with the tile global id
			Tileset tileset = getTilesetByID(id);
			// If id belongs to layer tilesets, draw it
			if (tileset.firstGridID)
			{
				// We decrement the ID so that we can draw the correct tile from the tileset (global ids start on 1)
				id--;

				// Draw the tile into position while offsetting its x and y position by subtracting the camera position
				TheTextureManager::Instance().drawTile(tileset.textureID, tileset.margin, tileset.spacing,
					j * m_tileSize - TheCamera::Instance().getPosition().x(),
					i * m_tileSize - TheCamera::Instance().getPosition().y(),
					tileset.tileWidth, tileset.tileHeight,
					(id - (tileset.firstGridID - 1)) / tileset.width,
					(id - (tileset.firstGridID - 1)) % tileset.width,
					TheGame::Instance().getRenderer());
			}
		}
	}
}

Tileset TileLayer::getTilesetByID(int tileID)
{
	for (auto tileset : m_tilesets)
	{
		// if tileset's range of tiles include tileID, return it
		if (tileID >= tileset.firstGridID && tileID < tileset.firstGridID + tileset.width * tileset.height)
		{
			return tileset;
		}
	}
	// Return invalid tileset
	Tileset t;
	t.firstGridID = 0;
	return t;
}