#include "EditorState.h"
#include <SDL_ttf.h>
#include <fstream>
#include <algorithm>
#include "InputHandler.h"
#include "TextureManager.h"
#include "Game.h"
#include "PlayState.h"
#include "TextureManager.h"
#include "Camera.h"
#include "LevelParser.h"
#include "ObjectLayer.h"
#include "GameObject.h"
#include "LoaderParams.h"
#include "TileLayer.h"
#include "BckLayer.h"
#include "Background.h"
#include "ParallaxBck.h"

using namespace std;

const string EditorState::s_editorID = "EDITOR";

EditorState::EditorState(string levelFile) :
m_levelFile{ levelFile }
{
	// Previously onEnter
	loadLevel(m_levelFile);
	centerCamera();
}

EditorState::EditorState(string levelFile,int levelWidth, int levelHeight, int tileWidth, int tileHeight) :
m_level(new Level(levelWidth, levelHeight, tileWidth)),
m_levelWidth{ levelWidth },
m_levelHeight{ levelHeight },
m_tileSize{ tileWidth },
m_levelFile{ levelFile },
m_bckLayer{ new BckLayer() },
m_tileLayer{ new TileLayer(tileWidth, levelWidth, levelHeight, TheGame::Instance().getTilesets(), false) },
m_collisionLayer{ new TileLayer(tileWidth, levelWidth, levelHeight, TheGame::Instance().getTilesets(), true) },
m_objectLayer{ new ObjectLayer() }
{
	// Fill our tileID data with zeros, which means no tile
	vector<int> layerRow(levelWidth);
	for (int i = 0; i < levelHeight; i++)
	{
		m_tileIDs.push_back(layerRow);
		m_collisionIDs.push_back(layerRow);
	}
	m_tileLayer->setTileIDs(m_tileIDs);
	m_collisionLayer->setTileIDs(m_collisionIDs);
	// Add layers to the level layers
	m_level->m_layers.push_back(m_bckLayer);		// m_layers[0] = background
	m_level->m_layers.push_back(m_tileLayer);		// m_layers[1] = no collidable tile layer
	m_level->m_layers.push_back(m_collisionLayer);	// m_layers[2] = collidable tile layer
	m_level->m_layers.push_back(m_objectLayer);		// m_layers[3] = object layer

	// Inform Game about level size
	TheGame::Instance().setMapWidth(m_levelWidth * m_tileSize);
	TheGame::Instance().setMapHeight(m_levelHeight * m_tileSize);

	// Previously onEnter
	centerCamera();
}

bool EditorState::loadLevel(string levelFile)
{
	// Clean previous level
	if (m_level != nullptr)
	{
		delete m_level;
		m_bckLayer = nullptr;
		m_tileLayer = nullptr;
		m_collisionLayer = nullptr;
		m_objectLayer = nullptr;
		m_level = nullptr;
		m_levelFile.clear();
	}
	// Create new level parsing level file name
	LevelParser tempParser;
	m_level = tempParser.parseLevel(levelFile.c_str());
	if (m_level != nullptr)
	{
		m_levelFile = levelFile;
		// Get level layers
		m_bckLayer = dynamic_cast<BckLayer*>(m_level->m_layers[0]);			// Background layer
		m_tileLayer = dynamic_cast<TileLayer*>(m_level->m_layers[1]);		// Non-collision layer
		m_collisionLayer = dynamic_cast<TileLayer*>(m_level->m_layers[2]);	// Collision layer
		m_objectLayer = dynamic_cast<ObjectLayer*>(m_level->m_layers[3]);	// Game objects layer
		// Get level and tile size
		m_levelWidth = m_level->getWidth();
		m_levelHeight = m_level->getHeight();
		m_tileSize = m_level->getTileSize();
		// Inform Game about new level size
		TheGame::Instance().setMapWidth(m_levelWidth * m_tileSize);
		TheGame::Instance().setMapHeight(m_levelHeight * m_tileSize);
		// Clean m_tileIDs and m_collisionIDs
		for (auto i = 0; i < m_tileIDs.size(); i++)
		{
			m_tileIDs[i].clear();
			m_collisionIDs.clear();
		}
		m_tileIDs.clear();
		m_collisionIDs.clear();
		// Give m_tileIDs new level values
		for (auto row : m_tileLayer->getTileIDs())
		{
			m_tileIDs.push_back(row);
		}
		// Give m_collisionIDs new level values
		for (auto row : m_collisionLayer->getTileIDs())
		{
			m_collisionIDs.push_back(row);
		}
	}
	return m_level != nullptr;
} 
EditorState::~EditorState()
{
	delete m_level;
}

void EditorState::update()
{
	// Check if left button has been clicked
	if (TheInputHandler::Instance().getMouseButtonState(LEFT))
	{
		// Insert element in clicked position
		handlePlacement(TheInputHandler::Instance().getMousePosition()->x() + m_camera.x(),
			TheInputHandler::Instance().getMousePosition()->y() + m_camera.y());
	}
	else
	{
		// Left button has been released, so we allow object insertion again
		m_objectRepeated = false;
	}
	
	// Check if right button has been clicked
	if (TheInputHandler::Instance().getMouseButtonState(RIGHT))
	{
		// Delete element under current position
		deleteUnderPosition(TheInputHandler::Instance().getMousePosition()->x() + m_camera.x(),
			TheInputHandler::Instance().getMousePosition()->y() + m_camera.y());
	}
}

void EditorState::handlePlacement(int x, int y)
{
	switch (m_insertMode)
	{
	case INSERT_TILE:
		if (m_currentTileset.firstGridID > 0)
		{
			addTile(x, y);
		}
		break;
	case INSERT_OBJECT:
		// Check if object have been already added and type is defined
		if (!m_objectRepeated && !m_curObject.type.empty())
		{
			addObject(x, y);
			m_objectRepeated = true;
		}
		break;
	}
}

void EditorState::addTile(int x, int y)
{
	// Insert tile in collision or non-collision tile layer
	if (y < m_levelHeight * m_tileSize && x < m_levelWidth * m_tileSize)
	{
		if (m_collisionTiles)
		{
			m_collisionIDs[y / m_tileSize][x / m_tileSize] = m_currentTileset.firstGridID +
				m_currentTileset.width * m_tileRow + m_tileColumn;
			m_collisionLayer->setTileIDs(m_collisionIDs);
		}
		else
		{
			m_tileIDs[y / m_tileSize][x / m_tileSize] = m_currentTileset.firstGridID +
				m_currentTileset.width * m_tileRow + m_tileColumn;
			m_tileLayer->setTileIDs(m_tileIDs);
		}
	}
}

void EditorState::addObject(int x, int y)
{
	if (m_curObject.type == "Player" && m_level->getPlayer() != nullptr)
	{
		cout << "There is already a player placed in this level\n";
	}
	else
	{
		// Create new object
		GameObject* pGameObject = TheGameObjectFactory::Instance().create(m_curObject.type);
		if (pGameObject != nullptr)
		{
			pGameObject->load(unique_ptr<LoaderParams>(new LoaderParams(
				x, y, m_curObject.xSpeed, m_curObject.ySpeed, m_objAnimations,
				m_curObject.value, m_curObject.soundID, m_curObject.sound2ID,
				m_curObject.value2, m_curObject.value3)));
			m_objectLayer->getGameObjects()->push_back(pGameObject);
			if (pGameObject->type() == "Player")
			{
				m_level->setPlayer(static_cast<Player*>(pGameObject));
			}
		}
		else
		{
			cout << "Object of type " << m_curObject.type << " couldn't be created,\n";
		}
	}
}

void EditorState::addBck(string type, string textureID, int xSpeed, int ySpeed)
{
	// Create new background
	GameObject* pBck= TheGameObjectFactory::Instance().create(type);
	if (pBck != nullptr)
	{
		// Bck only have one animation (idle) with one frame 
		map<string, Animation> animations;
		auto frameWidth = TheTextureManager::Instance().getWidth(textureID);
		auto frameHeight = TheTextureManager::Instance().getHeight(textureID);
		SDL_Rect frame = { 0, 0, frameWidth, frameHeight };
		vector<SDL_Rect> frames;
		frames.push_back(frame);
		Animation idle(textureID, 0, frames, 0, { 0, 0, 0, 0 });
		animations["idle"] = idle;
		// Load background params
		pBck->load(unique_ptr<LoaderParams>(new LoaderParams(0, 0, xSpeed, ySpeed, animations)));
		// Add bck to bck layer
		m_bckLayer->getGameObjects()->push_back(pBck);
	}
	else
	{
		cout << "Background of type " << type << " couldn't be created,\n";
	}
}

bool EditorState::saveLevel(string levelFile)
{
	// Write level with the given name
	LevelParser lParser;
	return lParser.writeLevel(*m_level, levelFile);
}

void EditorState::removeTileset(Tileset rmTileset)
{
	// Remove tiles of the removed tileset
	for (int i = 0; i < m_levelHeight; i++)
	{
		for (int j = 0; j < m_levelWidth; j++)
		{
			// Collidable layer
			int id = m_collisionIDs[i][j];
			if (id != 0)
			{
				// Checks if current tile belongs to the removed tileset
				Tileset tileset = m_collisionLayer->getTilesetByID(id);
				if (tileset.firstGridID == rmTileset.firstGridID)
				{
					m_collisionIDs[i][j] = 0;
				}
			}

			// Non-collidable layer
			id = m_tileIDs[i][j];
			if (id != 0)
			{
				Tileset tileset = m_collisionLayer->getTilesetByID(id);
				if (tileset.firstGridID == rmTileset.firstGridID)
				{
					m_tileIDs[i][j] = 0;
				}
			}
		}
	}
	m_collisionLayer->setTileIDs(m_collisionIDs);
	m_tileLayer->setTileIDs(m_tileIDs);
}

void EditorState::deleteUnderPosition(int x, int y)
{
	switch (m_insertMode)
	{
	case INSERT_OBJECT:
		{
			// Delete object under cursor
			vector<GameObject*>* gObjects = static_cast<ObjectLayer*>(m_objectLayer)->getGameObjects();
			for (auto it = gObjects->begin(); it != gObjects->end();)
			{
				if (x < (*it)->getPosition().x() + (*it)->getWidth()
					&& x >(*it)->getPosition().x()
					&& y < (*it)->getPosition().y() + (*it)->getHeight()
					&& y >(*it)->getPosition().y())
				{
					if ((*it)->type() == "Player")
					{
						m_level->setPlayer(nullptr);
					}
					delete *it;
					it = gObjects->erase(it);
				}
				else
				{
					++it;
				}
			}
		}
		break;
	case INSERT_TILE:
		{
			// Delete tile under cursor
			if (m_tileSize > 0)
			{
				if (m_collisionTiles)
				{
					// delete from collision layer
					m_collisionIDs[y / m_tileSize][x / m_tileSize] = 0;
					m_collisionLayer->setTileIDs(m_collisionIDs);
				}
				else
				{
					// delete from non-collision layer
					m_tileIDs[y / m_tileSize][x / m_tileSize] = 0;
					m_tileLayer->setTileIDs(m_tileIDs);
				}
			}
		}
	}
}

void EditorState::centerCamera()
{
	TheCamera::Instance().setTarget(&m_camera, mode::LEFT);
}

void EditorState::hScroll(int value)
{
	m_camera.x(value);
}

void EditorState::vScroll(int value)
{
	m_camera.y(value);
}

/////////////////////
////// Getters //////
/////////////////////

int EditorState::getLevelWidth()
{
	if (m_level != nullptr)
	{
		return m_level->getWidth();
	}
	return -1;
}

int EditorState::getLevelHeight()
{
	if (m_level != nullptr)
	{
		return m_level->getHeight();
	}
	return -1;
}

int EditorState::getTileSize()
{
	if (m_level != nullptr)
	{
		return m_level->getTileSize();
	}
	return -1;
}

/////////////////////
////// Setters //////
/////////////////////

void EditorState::setObject(const GameObjCfg &obj, const map<string, Animation> &animations)
{
	m_curObject = obj;
	m_objAnimations = animations;
}

void EditorState::setTile(int row, int column)
{
	// Update member data for tile row and column
	m_tileRow = row;
	m_tileColumn = column;
}

void EditorState::setInsertMode(insertionMode mode)
{
	m_insertMode = mode;
}

///////////////////////////////
////// Drawing functions //////
///////////////////////////////

void EditorState::render()
{
	m_level->render();
	drawGrid();
	showSelected(); 
}

void EditorState::showSelected()
{
	// Set rendering color
	SDL_SetRenderDrawColor(TheGame::Instance().getRenderer(), 0xFF, 0x00, 0x00, SDL_ALPHA_OPAQUE);
	// Get mouse position in the window
	int mouseX = TheInputHandler::Instance().getMousePosition()->x();
	int mouseY = TheInputHandler::Instance().getMousePosition()->y();

	// Draw selected item if it's in te viewable area. Due to Qt issues, gamewidth/height - 2
	// seems to be the maximum value that x/y can have with the mouse outside Editor window.
	if (mouseX > 0 && mouseY > 0
		&& mouseX < TheGame::Instance().getGameWidth() - 2
		&& mouseY < TheGame::Instance().getGameHeight() - 2)
	{
		if (m_insertMode == INSERT_TILE)
		{
			if (m_currentTileset.firstGridID > 0)
			{
				showSelectedTile(mouseX + m_camera.x(), mouseY + m_camera.y());
			}
		}
		else if (m_insertMode == INSERT_OBJECT)
		{
			if (!m_objAnimations.empty())
			{
				showSelectedObject(mouseX, mouseY);
			}
		}
	}
}

void EditorState::showSelectedTile(int x, int y)
{
	// Adjust rectangle to tile size
	int rectX = x / m_tileSize * m_tileSize;
	int rectY = y / m_tileSize * m_tileSize;
	SDL_Rect placeRect = { rectX - m_camera.x(), rectY - m_camera.y(), m_tileSize, m_tileSize};
	SDL_RenderDrawRect(TheGame::Instance().getRenderer(), &placeRect);
	TheTextureManager::Instance().drawTile(m_currentTileset.textureID, m_currentTileset.margin, m_currentTileset.spacing,
		rectX - m_camera.x(), rectY - m_camera.y(), m_currentTileset.tileWidth, m_currentTileset.tileHeight, m_tileRow, m_tileColumn,
		TheGame::Instance().getRenderer(), 100);
}


void EditorState::showSelectedObject(int x, int y)
{
	// Draw selected object with its frame size and collision box
	Animation anim;
	anim = m_objAnimations["idle"];
	// Theorically all objects have idle animation, but we check just in case
	if (!anim.getTextureID().empty())
	{
		// Rectangle containing the frame
		auto frameRect = anim.getCurrentFrame();
		frameRect.x = x;
		frameRect.y = y;
		// Rectangle containing the collision box
		auto collisionRect = anim.getCollider();
		collisionRect.x += x;
		collisionRect.y += y;
		// Draw the selected object looking at left or right, with transparency
		SDL_RendererFlip flip;
		(m_curObject.xSpeed >= 0) ? (flip = SDL_FLIP_NONE) : (flip = SDL_FLIP_HORIZONTAL);
		//(m_xSpeed >= 0) ? (flip = SDL_FLIP_NONE) : (flip = SDL_FLIP_HORIZONTAL);
		TheTextureManager::Instance().drawFrame(anim.getTextureID(),
			x, y, anim.getWidth(), anim.getHeight(), anim.getFrames()[0],
			TheGame::Instance().getRenderer(), flip, 0.0, 120);
		// Draw frame surrounding rectangle in black
		SDL_SetRenderDrawColor(TheGame::Instance().getRenderer(), 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawRect(TheGame::Instance().getRenderer(), &frameRect);
		// Highlight collision box in red		
		SDL_SetRenderDrawColor(TheGame::Instance().getRenderer(), 0xFF, 0x00, 0x00, 120);
		SDL_RenderDrawRect(TheGame::Instance().getRenderer(), &collisionRect);
	}
}

void EditorState::drawGrid()
{
	SDL_SetRenderDrawColor(TheGame::Instance().getRenderer(), 0, 0, 0, 0xFF);

	// Camera offset
	int xOffset = int(m_camera.x()) % m_tileSize;
	int yOffset = int(m_camera.y()) % m_tileSize;

	// Horizontal lines
	for (int i = 0; i <= m_levelHeight; i++)
	{
		for (int j = 0; j <= m_levelWidth*m_tileSize; j += 2)
		{
			// Draw a sequence of dots
			SDL_RenderDrawPoint(TheGame::Instance().getRenderer(), j, i*m_tileSize - yOffset);
		}
	}
	// Last horizontal line
	for (int i = 0; i <= m_levelWidth*m_tileSize; i += 2)
	{
		// Draw a sequence of dots
		SDL_RenderDrawPoint(TheGame::Instance().getRenderer(), i, m_levelHeight*m_tileSize - 1 - yOffset);
	}

	// Vertical lines
	for (int i = 0; i <= m_levelWidth; i++)
	{
		for (int j = 0; j <= m_levelHeight*m_tileSize; j += 2)
		{
			// Draw a sequence of dots
			SDL_RenderDrawPoint(TheGame::Instance().getRenderer(), i*m_tileSize - xOffset, j);
		}
	}
	// Last vertical line
	for (int i = 0; i <= m_levelHeight*m_tileSize; i += 2)
	{
		// Draw a sequence of dots
		SDL_RenderDrawPoint(TheGame::Instance().getRenderer(), m_tileSize*m_levelWidth - 1 - xOffset, i);
	}
}

void EditorState::setCurrentTileset(Tileset tileset)
{
	m_currentTileset = tileset;
}

Tileset EditorState::getCurrentTileset()
{
	return m_currentTileset;
}

void EditorState::clearBck()
{
	// Clean background layer
	for (auto bck : *m_bckLayer->getGameObjects())
	{
		delete bck;
	}
	m_bckLayer->getGameObjects()->clear();
}

BckLayer* EditorState::getBckLayer()
{
	return m_bckLayer;
}

void EditorState::updateBckScroll()
{
	if (m_bckLayer != nullptr)
	{
		for (auto pBck : *m_bckLayer->getGameObjects())
		{
			if (pBck->type() == "ParallaxBck")
			{
				ParallaxBck *pParBck = static_cast<ParallaxBck*>(pBck);
				// Scrolling in horizontal axis
				int rlwidth = m_levelWidth * m_tileSize - TheGame::Instance().getGameWidth();
				int rbwidth = pParBck->getWidth() - TheGame::Instance().getGameWidth();
				float scrollX = 1;
				if (rbwidth > 0)
				{
					scrollX = float(rlwidth) / rbwidth;
				}
				pParBck->setScrollRatioX(scrollX);
				// Scrolling in vertical axis
				int rlheight = m_levelHeight * m_tileSize - TheGame::Instance().getGameHeight();
				int rbheight = pParBck->getHeight() - TheGame::Instance().getGameHeight();
				float scrollY = 1;
				if (rbheight > 0)
				{
					scrollY = float(rlheight) / rbheight;
				}
				pParBck->setScrollRatioY(scrollY);
			}
		}
	}
}

void EditorState::setMusic(string musicID)
{
	if (m_level != nullptr)
	{
		m_level->setMusic(musicID);
	}
}

string EditorState::getMusic()
{
	if (m_level != nullptr)
	{
		return m_level->getMusic();
	}
	else return "";
}
