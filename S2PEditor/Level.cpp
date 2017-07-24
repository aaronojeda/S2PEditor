#include "Level.h"
#include "TextureManager.h"
#include "TileLayer.h"

Level::Level():
m_width(0),
m_height(0),
m_tileSize(0),
m_pPlayer(nullptr)
{
}

Level::Level(int width, int height, int tileSize):
m_width{ width },
m_height{ height },
m_tileSize{ tileSize },
m_pPlayer{ nullptr }
{
}

Level::~Level()
{
	if (m_layers.size() > 0)
	{
		for (int i = 0; i < m_layers.size(); i++)
		{
			delete m_layers[i];
		}
	}
}

void Level::render()
{
	for (int i = 0; i < m_layers.size(); i++)
	{
		m_layers[i]->render();
	}
}

void Level::update()
{
	for (int i = 0; i < m_layers.size(); i++)
	{
		m_layers[i]->update(this);
	}
}

void Level::removeTiles(const int firstGridID)
{
	// Clear tiles of the tileset with given firstGridID from all tile layers
	for (auto layer : m_layers)
	{
		if (layer->getLayerID() != "TILE")
		{
			continue;
		}
		// We are sure it is a tile layer so we can make static cast
		auto tileLayer = static_cast<TileLayer*>(layer);
		// Get layer tile IDs
		auto tileIDs = tileLayer->getTileIDs();
		// Loop through all tiles and check if they belong to the removed tileset
		for (int i = 0; i < tileLayer->getMapHeight(); i++)
		{
			for (int j = 0; j < tileLayer->getMapWidth(); j++)
			{
				// Collidable layer
				int id = tileIDs[i][j];
				if (id != 0)
				{
					// Checks if current tile belongs to the removed tileset
					Tileset tileset = tileLayer->getTilesetByID(id);
					if (tileset.firstGridID == firstGridID)
					{
						tileIDs[i][j] = 0;
					}
				}
			}
		}
		tileLayer->setTileIDs(tileIDs);
	}
}

void Level::setMusic(const std::string &music)
{
	m_music = music;
}