#pragma once

#include "Layer.h"
#include <vector>
#include "Level.h"
#include "Vector2D.h"

// This type of layer is made up entirely of tiles and does not contain anything else
class TileLayer : public Layer
{
public:

	TileLayer(int tileSize, int mapWidth, int mapHeight, const std::vector<Tileset>& tilesets, bool collidable = false);

	virtual ~TileLayer() {}

	virtual void update(Level* pLevel){};
	virtual void render();

	virtual std::string getLayerID() const { return s_tileLayerID; }

	void setTileIDs(const std::vector<std::vector<int>>& data) { m_tileIDs = data; }
	void setTileSize(int tileSize) { m_tileSize = tileSize; }
	void setMapWidth(int mapWidth) { m_numColumns = mapWidth; }

	int getMapWidth() { return m_numColumns; }
	int getMapHeight() { return m_numRows; }

	int getTileSize() { return m_tileSize; }

	const std::vector<std::vector<int>> & getTileIDs() { return m_tileIDs; }

	Tileset getTilesetByID(int tileID);

	const Vector2D getPosition() { return m_position; }

	bool isCollidable() { return m_collidable; };
	void setCollidable(bool coll) { m_collidable = coll; }

private:

	int m_numColumns;
	int m_numRows;
	int m_tileSize;

	bool m_collidable;

	// These Vector2D variables are used when we scroll our maps.
	Vector2D m_position;
	Vector2D m_velocity;

	const std::vector<Tileset> & m_tilesets;

	std::vector<std::vector<int>> m_tileIDs;

	static const std::string s_tileLayerID;
};