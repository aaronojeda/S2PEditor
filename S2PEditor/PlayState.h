#ifndef __PlayState__
#define __PlayState__

#include <vector>
#include <string>
#include "GameState.h"
#include "Level.h"
#include "CollisionManager.h"

class GameObject;
class Level;

class PlayState : public GameState
{
public:
	PlayState(int level = 0);
	PlayState(std::string levelFile);
	virtual ~PlayState();

	virtual void update();
	virtual void render();

	virtual std::string getStateID() const { return s_playID; }

protected:
	Level *m_pLevel{ nullptr };
	std::string m_levelFile;
	bool loadLevel(std::string levelFile);
	bool loadLevel(int levelIndex);

private:
	int m_prevLives, m_prevScore, m_prevKeys;
	bool m_bPausePressed{ true };
	std::string m_sLives{ "livesText" };
	std::string m_sScore{ "scoreText" };
	std::string m_sKeys{ "keysText" };
	// HUD icons id, width and height
	std::string m_sLivesIcon;
	int m_livesWidth{ 0 }, m_livesHeight{ 0 };
	std::string m_sHealthIcon;
	int m_healthWidth{ 0 }, m_healthHeight{ 0 };
	std::string m_sScoreIcon;
	int m_scoreWidth{ 0 }, m_scoreHeight{ 0 };
	std::string m_sKeysIcon;
	int m_keysWidth{ 0 }, m_keysHeight{ 0 };
	// Game renderer
	SDL_Renderer *m_pRenderer{ nullptr };
	// HUD numbers/letters font
	std::string m_sHUDFont;

	static const std::string s_playID;
	void drawHUD();
	void loadHUDResources();
};

#endif