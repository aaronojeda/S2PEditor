#ifndef __SDL_Game_Programming_Book__CollisionManager__
#define __SDL_Game_Programming_Book__CollisionManager__

#include <iostream>
#include <vector>

class Player;
class GameObject;

class CollisionManager
{
public:
	void checkCollision(Player* pPlayer, const std::vector<GameObject*> &objects);
};

#endif /* defined(__SDL_Game_Programming_Book__CollisionManager__) */