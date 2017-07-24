#ifndef __GameObjectFactory__
#define __GameObjectFactory__

#include <string>
#include <map>

class GameObject;

// This is the base class for all the Creator types.
class BaseCreator
{
public:

	virtual GameObject* createGameObject() const = 0;

	virtual ~BaseCreator();
};

class GameObjectFactory
{
public:

	//Adds a new object type to the map with the given ID and creator.
	bool registerType(std::string typeID, BaseCreator* pCreator);

	GameObject* create(std::string typeID);
	
	// Create the public instance function
	static GameObjectFactory& Instance();
	
private:
	GameObjectFactory();
	~GameObjectFactory();

	// Delete the methods we don't want (new in C++ 11)
	GameObjectFactory(const GameObjectFactory&) = delete;
	GameObjectFactory& operator=(const GameObjectFactory&) = delete;

	// This map holds the important elements of our factory. The functions of the class essentially either add or remove from this map
	std::map<std::string, BaseCreator*> m_creators;
};

typedef GameObjectFactory TheGameObjectFactory;

#endif /* defined(__GameObjectFactory__) */