#ifndef __GameObject__
#define __GameObject__

#include <memory>
#include <vector>
#include <map>
#include <SDL.h>
#include "Vector2D.h"
#include "Animation.h"

class LoaderParams;
class TileLayer;
class Player;

// Game object abstract class with common functionallity to (almost) all objects
class GameObject
{
public:
	// base class needs virtual destructor
	virtual ~GameObject();

	// load object parameters
	virtual void load(std::unique_ptr<LoaderParams> const &pParams) = 0;

	// draw the object
	virtual void draw() = 0;	
	// do update stuff
	virtual void update() = 0;
		
	// object has collided, handle accordingly
	virtual void collision(Player *pPlayer);
	
	// get the type of the object
	virtual std::string type() = 0;
	
	// getters for common variables
	Vector2D& getPosition();
	Vector2D& getVelocity();
	int getXSpeed();
	int getYSpeed();
	int getValue();
	int getValue2();
	int getValue3();
	std::string getSoundID();
	std::string getSound2ID();
	
	std::string getTextureID();
	
	// is the object currently being updated?
	bool updating();
	
	bool collidable();
	void setCollidable(bool coll);

	// is the object dead?
	bool dead();
	
	// is the object doing a death animation?
	bool dying();
	
	// is the object deadly for the player?
	bool deadly();

	// set whether to update the object or not
	void setUpdating(bool updating);

	void setCollisionLayers(std::vector<TileLayer*>* layers);
	void setCollisionObjects(std::vector<GameObject*>* objects);

	// Animation getters
	SDL_Rect getCollider();
	int getWidth();
	int getHeight();
	std::map<std::string, Animation> getAnimations();

protected:
	
	GameObject();
	GameObject(const GameObject &obj) = delete;
	GameObject& operator=(const GameObject& obj) = delete;

	// movement
	Vector2D m_position{ 0, 0 };
	Vector2D m_velocity{ 0, 0 };
	int m_xSpeed{ 0 };
	int m_ySpeed{ 0 };

	// common boolean variables
	bool m_bUpdating{ false };
	bool m_bDead{ false };
	bool m_bDying{ false };
	bool m_deadly{ false };
	//bool m_pickable{ false };
	bool m_collidable{ false };

	// Special values which can act as score/health/lives added, damage taken by touching an enemy, etc.
	int m_value{ 0 }, m_value2{ 0 }, m_value3{ 0 };
	// Two strings to store sound IDs that the object may use
	std::string m_sndID;
	std::string m_snd2ID;

	SDL_RendererFlip m_sdlFlip;

	bool m_bMoveLeft;
	bool m_bMoveRight;
	bool m_bRunning;

	bool m_bJumping;
	bool m_bCanJump;

	// For collision checking
	std::vector<TileLayer*>* m_pCollisionLayers{ nullptr };		// layers with collidable tiles
	std::vector<GameObject*>* m_pCollisionObjects{ nullptr };	// collidable objects as doors

	// check collisions with collidable tiles & objects
	bool checkCollideTile(Vector2D newpos);
	bool checkCollideObject(Vector2D newpos);

	// object animations
	std::map<std::string, Animation> m_animations;
	// current object animation
	Animation m_currentAnim;
};

#endif /* defined(__GameObject__) */