#include "LevelParser.h"
#include <map>
#include "Game.h"
#include "TextureManager.h"
#include "GameObjectFactory.h"
#include "TileLayer.h"
#include "ObjectLayer.h"
#include "base64.h"
#include "zlib.h"
#include "GameObject.h"
#include "LoaderParams.h"
#include "ScoreItem.h"
#include "HealthItem.h"
#include "ParallaxBck.h"
#include "BckLayer.h"

using namespace std;
using namespace tinyxml2;

Level* LevelParser::parseLevel(const char* levelFile)
{
	// create a TinyXML document and load the XML level
	XMLDocument xmlDoc;
	if (xmlDoc.LoadFile(levelFile) != XML_SUCCESS)
	{
		std::cout << "Error: unable to load " << levelFile << std::endl;
		return nullptr;
	}

	// create the level object
	Level* pLevel = new Level();

	// get the root node
	XMLNode* pRoot = xmlDoc.RootElement();

	pRoot->ToElement()->QueryAttribute("tilewidth", &m_tileSize);
	pRoot->ToElement()->QueryAttribute("width", &m_width);
	pRoot->ToElement()->QueryAttribute("height", &m_height);
	pLevel->m_width = m_width;
	pLevel->m_height = m_height;
	pLevel->m_tileSize = m_tileSize;
	// Attribute() returns null if not found and std::string cannot be initialized with nullptr.
	const char* musicID = nullptr;
	musicID = pRoot->ToElement()->Attribute("musicID");
	if (musicID == nullptr) musicID = "";
	pLevel->setMusic(musicID);

	// parse object and tile layers
	for (XMLElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("objectgroup"))
		{
			parseObjLayer(e, pLevel);
		}
		else if (e->Value() == std::string("layer"))
		{
			parseTileLayer(e, pLevel);
		}
		else if (e->Value() == std::string("background"))
		{
			parseBckLayer(e, pLevel);
		}
	}

	return pLevel;
}

void LevelParser::parseTileLayer(XMLElement* pTileElement, Level *pLevel)
{
	// New TileLayer instance 
	TileLayer* pTileLayer = new TileLayer(m_tileSize, m_width, m_height, TheGame::Instance().getTilesets());

	// local temporary variable
	bool collidable = false;

	// A multidimensional array of int values to hold our final decoded and uncompressed tile data
	std::vector<std::vector<int>> data;

	// xml data node
	XMLElement* pDataNode = nullptr;
	// to store base64 decoded information
	std::string decodedIDs;	

	// We search for the node we need
	for (XMLElement* e = pTileElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		// check if layer has properties
		if (e->Value() == std::string("properties"))
		{
			for (XMLElement* property = e->FirstChildElement(); property != NULL; property = property->NextSiblingElement())
			{
				if (property->Value() == std::string("property"))
				{
					// Check if it is a collision layer
					if (property->Attribute("name") == std::string("collidable"))
					{
						collidable = true;
					}
				}
			}
		}

		if (e->Value() == std::string("data"))
		{
			pDataNode = e;
		}
	}

	// Tile information not encoded nor compressed
	if (pDataNode->Attribute("encoding") == nullptr)
	{
		std::vector<int> layerRow(m_width);
		for (int rows = 0; rows < m_height; rows++)
		{
			data.push_back(layerRow);
		}

		XMLElement* tile = pDataNode->FirstChildElement();
		int id;
		for (int rows = 0; rows < m_height; rows++)
		{
			for (int cols = 0; cols < m_width ; cols++)
			{
				tile->QueryAttribute("gid", &data[rows][cols]);
				tile = tile->NextSiblingElement();
			}
		}
	}
	else
	{
		// We get the text (our encoded/compressed data) from the data node and use the base64 decoder to decode it
		for (XMLNode* e = pDataNode->FirstChild(); e != NULL; e = e->NextSibling())
		{
			XMLText* text = e->ToText();
			std::string t = text->Value();
			decodedIDs = base64_decode(t);
		}

		// We use the zlib library to decompress our data once again
		uLongf sizeofids = m_width * m_height * sizeof(int);
		std::vector<unsigned> gids(sizeofids);
		uncompress((Bytef*)&gids[0], &sizeofids, (const Bytef*)decodedIDs.c_str(), decodedIDs.size());

		// gids now contains all of our tile IDs, so we fill our data array with the correct values

		std::vector<int> layerRow(m_width);

		for (int j = 0; j < m_height; j++)
		{
			data.push_back(layerRow);
		}

		for (int rows = 0; rows < m_height; rows++)
		{
			for (int cols = 0; cols < m_width; cols++)
			{
				data[rows][cols] = gids[rows * m_width + cols];
			}
		}
	}

	pTileLayer->setTileIDs(data);
	pTileLayer->setMapWidth(m_width);

	// push into collision array and mark the layer as collidable if necessary
	if (collidable)
	{
		pTileLayer->setCollidable(true);
		pLevel->getCollisionLayers()->push_back(pTileLayer);
	}

	pLevel->getLayers()->push_back(pTileLayer);
}

void LevelParser::parseObjLayer(tinyxml2::XMLElement* pObjectElement, Level* pLevel)
{
	auto pObjLayer = new ObjectLayer();
	for (XMLElement* e = pObjectElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("object"))
		{
			GameObject* pGameObject = parseObject(e);
			if (pGameObject != nullptr)
			{
				// inform new object about level's collision layers and objects
				pGameObject->setCollisionLayers(pLevel->getCollisionLayers());
				pGameObject->setCollisionObjects(pLevel->getCollisionObjects());
				// Look for special object types
				if (pGameObject->type() == "Player")
				{
					// Inform level about current player
					pLevel->setPlayer(static_cast<Player*>(pGameObject));
				}
				else if (pGameObject->type() == "LockedDoor")
				{
					pGameObject->setCollidable(true);
					pLevel->m_collisionObjects.push_back(pGameObject);
				}
				pObjLayer->getGameObjects()->push_back(pGameObject);
			}
		}
	}
	// Add object layer to the level
	pLevel->getLayers()->push_back(pObjLayer);
}

void LevelParser::parseBckLayer(tinyxml2::XMLElement* pObjectElement, Level* pLevel)
{
	auto pBckLayer = new BckLayer();
	for (XMLElement* e = pObjectElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("object"))
		{
			// Parse object to fill loading attribtues
			auto pBck = parseObject(e);
			if (pBck != nullptr)
			{
				if (pBck->type() == "ParallaxBck")
				{
					ParallaxBck* pParallax = static_cast<ParallaxBck*>(pBck);
					// Scrolling ratio in horizontal axis
					int rlwidth = pLevel->getWidth() * pLevel->getTileSize() - TheGame::Instance().getGameWidth();
					int rbwidth = pParallax->getWidth() - TheGame::Instance().getGameWidth();
					if (rbwidth > 0)
					{
						float scrollX = float(rlwidth) / rbwidth;
						pParallax->setScrollRatioX(scrollX);
					}
					// Scrolling ratio in vertical axis
					int rlheight = pLevel->getHeight() * pLevel->getTileSize() - TheGame::Instance().getGameHeight();
					int rbheight = pParallax->getHeight() - TheGame::Instance().getGameHeight();
					if (rbheight > 0)
					{
						float scrollY = float(rlheight) / rbheight;
						pParallax->setScrollRatioY(scrollY);
					}
				}
				pBckLayer->getGameObjects()->push_back(pBck);
			}
		}
	}

	// Add background layer to the level
	pLevel->getLayers()->push_back(pBckLayer);
}

GameObject* LevelParser::parseObject(XMLElement* pObject)
{
	// variables to store object properties
	int x{ 0 }, y{ 0 }, value{ 0 }, value2{ 0 }, value3{ 0 }, frameWidth{ 0 }, 
		frameHeight{ 0 }, xSpeed{ 0 }, ySpeed{ 0 };
	std::string type, textureID, soundID, sound2ID;
	std::map<std::string, Animation> animations;
	SDL_Rect collider;
	// get object attributes
	pObject->QueryAttribute("x", &x);
	pObject->QueryAttribute("y", &y);
	pObject->QueryAttribute("frameWidth", &frameWidth);
	pObject->QueryAttribute("frameHeight", &frameHeight);
	pObject->QueryAttribute("xBB", &collider.x);
	pObject->QueryAttribute("yBB", &collider.y);
	pObject->QueryAttribute("widthBB", &collider.w);
	pObject->QueryAttribute("heightBB", &collider.h);
	pObject->QueryAttribute("xSpeed", &xSpeed);
	pObject->QueryAttribute("ySpeed", &ySpeed);
	pObject->QueryAttribute("value", &value);
	pObject->QueryAttribute("value2", &value2);
	pObject->QueryAttribute("value3", &value3);
	// Assigning nullptr to an std::string will raise an error so we have to check
	const char* check = pObject->Attribute("type");
	if (check == nullptr) check = "";
	type = check;
	check = pObject->Attribute("textureID");
	if (check == nullptr) check = "";
	textureID = check;
	check = pObject->Attribute("soundID");
	if (check == nullptr) check = "";
	soundID = check;
	check = pObject->Attribute("sound2ID");
	if (check == nullptr) check = "";
	sound2ID = check;

	// Parse animations
	XMLElement * pAnimations = pObject->FirstChildElement("animations");
	// For each animation XMLElement we create an Animation and add it to the object
	for (XMLElement * pAnim = pAnimations->FirstChildElement(); pAnim != NULL; pAnim = pAnim->NextSiblingElement())
	{
		std::vector<SDL_Rect> frames;
		int row{ 0 };
		int nFrames{ 1 };
		int frameTime{ 0 };

		// Parse animation nodes
		pAnim->QueryAttribute("row", &row);
		pAnim->QueryAttribute("nFrames", &nFrames);
		pAnim->QueryAttribute("frameTime", &frameTime);

		// Deduce frames from object and animation attributes
		for (int i = 0; i < nFrames; i++)
		{
			SDL_Rect frame;
			frame.x = i*frameWidth;
			frame.y = row*frameHeight;
			frame.w = frameWidth;
			frame.h = frameHeight;
			frames.push_back(frame);
		}

		const char* name = pAnim->Attribute("name");
		if (name != nullptr)
		{
			Animation animation(textureID, row, frames, frameTime, collider);
			animations[name] = animation;
		}
		// If the animation doesn't have a name we don't add it to the map
	}

	GameObject* pGameObject = TheGameObjectFactory::Instance().create(type);
	if (pGameObject != nullptr)
	{
		// Now that we have the values We can create the object and add it to this layer's game object array
		pGameObject->load(unique_ptr<LoaderParams>(new LoaderParams(x, y, xSpeed, ySpeed, animations,
			value, soundID, sound2ID, value2, value3)));
	}
	else
	{
		cout << "Warning: LevelParser couldn't create object of type " << type << endl;
	}
	return pGameObject;
}


bool LevelParser::writeLevel(const Level &level, std::string name)
{
	XMLDocument tmxFile;

	// Insert root element and its attributes
	XMLNode *pRoot = tmxFile.NewElement("map");
	tmxFile.InsertFirstChild(pRoot);

	XMLElement * pElement = tmxFile.RootElement();

	// Another option here would be taking the biggest width, height and tilewidth from level's tilelayers
	// width
	pElement->SetAttribute("width", level.getWidth());
	// height
	pElement->SetAttribute("height", level.getHeight());
	// tilewidth
	pElement->SetAttribute("tilewidth", level.getTileSize());
	// tileheight
	pElement->SetAttribute("tileheight", level.getTileSize());
	// musicID
	pElement->SetAttribute("musicID", level.getMusic().c_str());

	// write level layers
	int tileLayers = 1, objLayers = 1, bckLayers = 1;
	for (auto pLayer : level.m_layers)
	{
		std::string layerID = pLayer->getLayerID();
		if (layerID == "OBJECT")// && (dynamic_cast<ObjectLayer*>(pLayer)->getGameObjects()->size() != 0))
		{
			pElement = tmxFile.NewElement("objectgroup");
			writeObjectLayer(pElement, dynamic_cast<ObjectLayer*>(pLayer), "Object Layer " + to_string(objLayers));
			objLayers++;
			// Insert object layer node
			pRoot->InsertEndChild(pElement);
		}
		else if (layerID == "TILE")
		{
			pElement = tmxFile.NewElement("layer");
			writeTileLayer(pElement, dynamic_cast<TileLayer*>(pLayer), "Tile Layer " + to_string(tileLayers));
			tileLayers++;
			// Insert tile layer node
			pRoot->InsertEndChild(pElement);
		}
		else if (layerID == "BACKGROUND")
		{
			pElement = tmxFile.NewElement("background");
			writeObjectLayer(pElement, dynamic_cast<BckLayer*>(pLayer), "Background Layer " + to_string(bckLayers));
			bckLayers++;
			pRoot->InsertEndChild(pElement);
		}
	}

	if (tmxFile.SaveFile(name.c_str()) == XML_NO_ERROR)
	{
		return true;
	}
	else
	{
		std::cout << "An error has ocurred writing file " << name << ". TinyXML error: " << tmxFile.ErrorName() << std::endl;
		return false;
	}
}

void LevelParser::writeTileLayer(XMLElement* pTileElement, TileLayer* layer, string layerName)
{
	// write tile layer attributes
	pTileElement->SetAttribute("name", layerName.c_str());	
	pTileElement->SetAttribute("width", layer->getMapWidth());
	pTileElement->SetAttribute("height", layer->getMapHeight());

	// write layer properties (if any)	
	XMLElement* pTileSubElement = pTileElement->GetDocument()->NewElement("properties");

	if (layer->isCollidable())
	{
		XMLElement* auxElement = pTileElement->GetDocument()->NewElement("property");
		auxElement->SetAttribute("name", "collidable");
		auxElement->SetAttribute("value", "true");
		pTileSubElement->InsertEndChild(auxElement);
		pTileElement->InsertEndChild(pTileSubElement);
	}

	// write tiles data
	pTileSubElement = pTileElement->GetDocument()->NewElement("data");

	XMLElement *pTileID;
	for (auto row : layer->getTileIDs())
	{
		for (auto id : row)
		{
			pTileID = pTileElement->GetDocument()->NewElement("tile");
			pTileID->SetAttribute("gid", id);

			pTileSubElement->InsertEndChild(pTileID);
		}
	}

	pTileElement->InsertEndChild(pTileSubElement);
}

void LevelParser::writeObjectLayer(XMLElement* pGroupElement, ObjectLayer* layer, string layerName)
{
	// write object group attributes
	pGroupElement->SetAttribute("name", layerName.c_str());

	// write objects
	XMLElement *pObjectElement;
	for (auto object : *layer->getGameObjects())
	{
		// object->writeXML(XMLElement);
		pObjectElement = pGroupElement->GetDocument()->NewElement("object");
		
		// write object attributes
		pObjectElement->SetAttribute("type", object->type().c_str());
		pObjectElement->SetAttribute("x", object->getPosition().x());
		pObjectElement->SetAttribute("y", object->getPosition().y());
		pObjectElement->SetAttribute("textureID", object->getTextureID().c_str());
		pObjectElement->SetAttribute("frameWidth", object->getWidth());
		pObjectElement->SetAttribute("frameHeight", object->getHeight());
		pObjectElement->SetAttribute("xBB", object->getCollider().x);
		pObjectElement->SetAttribute("yBB", object->getCollider().y);
		pObjectElement->SetAttribute("widthBB", object->getCollider().w);
		pObjectElement->SetAttribute("heightBB", object->getCollider().h);
		pObjectElement->SetAttribute("xSpeed", object->getXSpeed());
		pObjectElement->SetAttribute("ySpeed", object->getYSpeed());
		pObjectElement->SetAttribute("value", object->getValue());
		pObjectElement->SetAttribute("value2", object->getValue2());
		pObjectElement->SetAttribute("value3", object->getValue3());
		pObjectElement->SetAttribute("soundID", object->getSoundID().c_str());
		pObjectElement->SetAttribute("sound2ID", object->getSound2ID().c_str());

		// write animation nodes
		XMLElement *pAnimations= pGroupElement->GetDocument()->NewElement("animations");

		for (auto anim : object->getAnimations())
		{
			XMLElement *pAnimation = pGroupElement->GetDocument()->NewElement("animation");
			// Write the name of the animation
			pAnimation->SetAttribute("name", anim.first.c_str());
			// Write the remaining attributes of the animation
			writeAnimation(pAnimation, anim.second);
			// Insert animation node
			pAnimations->InsertEndChild(pAnimation);
		}		

		// Insert animations node
		pObjectElement->InsertEndChild(pAnimations);

		// Insert object node
		pGroupElement->InsertEndChild(pObjectElement);
	}
}

void LevelParser::writeAnimation(tinyxml2::XMLElement* pAnimElem, Animation animation)
{
	pAnimElem->SetAttribute("row", animation.getRow());				// Sprite sheet row
	pAnimElem->SetAttribute("nFrames", animation.getNFrames());		// Total frames
	pAnimElem->SetAttribute("frameTime", animation.getFrameTime());	// Interval between frames
}

