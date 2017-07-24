#ifndef __GameState__
#define __GameState__

#include <string>
#include <vector>

class GameObject;

class GameState
{
public:

	virtual ~GameState(){}
	
	virtual void update() = 0;
	virtual void render() = 0;

	virtual std::string getStateID() const = 0;

	bool getIsValid() const { return m_isValid; }
	void setIsValid(bool isValid) { m_isValid = isValid; }

protected:
	GameState() : 
		m_isValid(true)
	{

	}

	// Objects associated with this state
	std::vector<GameObject*> m_gameObjects;

	// A list of texture IDs used by that state.
	std::vector<std::string> m_textureIDList;

private:

	bool m_isValid;	// Flag that indicates if the state is queued for deletion
};

#endif