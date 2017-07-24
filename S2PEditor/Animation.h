#pragma once

#include <vector>
#include <SDL.h>

class Animation
{
public:
	Animation();
	Animation(std::string textureID, int row, std::vector<SDL_Rect> frames, float frameTime, SDL_Rect collider);
	~Animation();

	// Getters
	const std::string getTextureID();
	const std::vector<SDL_Rect> getFrames();
	const int getFrameIndex();
	void setFrame(const int frameIndex);
	const float getFrameTime();
	const SDL_Rect getCollider();
	const int getWidth();
	const int getHeight();
	const SDL_Rect getCurrentFrame();
	const int getNFrames();
	const int getRow();
private:
	std::string m_textureID;
	int m_spriteSheetRow{ 0 };
	std::vector<SDL_Rect> m_frames;
	int m_currentFrame{ 0 };
	float m_frameTime{ 0. };
	SDL_Rect m_collider;
};

