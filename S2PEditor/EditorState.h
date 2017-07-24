#ifndef __EditorState__
#define __EditorState__

#include "GameState.h"
#include <string>
#include <vector>
#include <map>
#include "Vector2D.h"
#include "Animation.h"
#include "Level.h"
#include "EditorParser.h"

class BckLayer;
class ObjectLayer;
class TileLayer;

enum insertionMode
{
	INSERT_TILE,
	INSERT_OBJECT,
	INSERT_NONE
};

class EditorState : public GameState
{
public:
	// Creates new level from existing level file
	EditorState(std::string levelFile);
	// Creates new level with name 'levelFile' from specified parameter
	EditorState(std::string levelFile, int levelWidth, int levelHeight, int tileWidth, int tileHeight);
	~EditorState();

	virtual void update();
	virtual void render();
	virtual std::string getStateID() const { return s_editorID; }

	// GUI and Qt messages management

	// "Qt slots"
	bool saveLevel(std::string levelFile);
	bool loadLevel(std::string levelFile);

	// Set selected tile
	void setTile(int row, int column);
	// Tileset selected in the editor
	void setCurrentTileset(Tileset tileset);
	Tileset getCurrentTileset();
	
	// Tileset tab closed
	void removeTileset(Tileset rmTileset);

	// Set object attributes for future creation
	void setObject(const GameObjCfg &obj, const std::map<std::string, Animation> &animations);

	// Change insertion mode: objects or tiles
	void setInsertMode(insertionMode mode);
	insertionMode getInsertMode() { return m_insertMode; }

	// Collision tiles box checked
	void setCollisionTiles(bool collidable) { m_collisionTiles = collidable; }
	//void setCamPos(float x, float y);
	void centerCamera();
	// Update camera position when scroll bars are moved
	void hScroll(int value);
	void vScroll(int value);

	int getLevelWidth();
	int getLevelHeight();
	int getTileSize();

	// Bck
	void clearBck();
	// Add background with given ID to the background layer
	void addBck(std::string type, std::string textureID, int xSpeed, int ySpeed);
	BckLayer* getBckLayer();
	void updateBckScroll();

	std::string getLevelFile(){ return m_levelFile; }

	void setMusic(std::string musicID);
	std::string getMusic();

private:
	static const std::string s_editorID;

	// Level from which the tmx file will be created
	Level* m_level{ nullptr };
	// Level basic info
	int m_levelWidth{ 0 };
	int m_levelHeight{ 0 };
	int m_tileSize{ 0 };
	std::string m_levelFile;

	// Level background layer, points to m_level->m_layers[0]
	BckLayer* m_bckLayer{ nullptr };
	// Level non-collision tile layer, points to m_level->m_layers[1]
	TileLayer* m_tileLayer{ nullptr };
	std::vector<std::vector<int>> m_tileIDs;
	// Level collision layer, points to m_level->m_layers[2]
	TileLayer* m_collisionLayer{ nullptr };
	std::vector<std::vector<int>> m_collisionIDs;
	// Level object layer, points to m_level->m_layers[3]
	ObjectLayer* m_objectLayer{ nullptr };

	// Tileset & Tiles
	int m_tileRow{ 0 };
	int m_tileColumn{ 0 };
	Tileset m_currentTileset;
	
	// Struct with current object attributes except animations
	GameObjCfg m_curObject;
	std::map<std::string, Animation> m_objAnimations;

	// Camera position
	Vector2D m_camera{ 0, 0 };

	// Flags
	insertionMode m_insertMode{ INSERT_NONE };
	bool m_objectRepeated{ false };
	bool m_collisionTiles{ true };

	// Places the selected item in the specified position
	void handlePlacement(int x, int y);
	// Draws a grid according to level dimensions
	void drawGrid();
	// Draws a rectangle pointing where will the items be placed
	void showSelected();
	// Shows the selected tile before it is placed
	void showSelectedTile(int x, int y);
	// Shows the selected object before it is placed
	void showSelectedObject(int x, int y);
	// Delete objects and tiles under position
	void deleteUnderPosition(int x, int y);
	// Add current object to position (x, y)
	void addObject(int x, int y);
	// Add current tile to position (x, y)
	void addTile(int x, int y);
};

#endif