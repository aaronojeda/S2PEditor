#include "Animation.h"

Animation::Animation()
{
}

Animation::Animation(std::string textureID, int row, std::vector<SDL_Rect> frames, float frameTime, SDL_Rect collider) :
m_textureID{ textureID },
m_spriteSheetRow{ row },
m_frames{ frames },	
m_frameTime{ frameTime },
m_collider{ collider }
{
}

Animation::~Animation()
{
}

const std::string Animation::getTextureID()
{
	return m_textureID;
}

const std::vector<SDL_Rect> Animation::getFrames()
{
	return m_frames;
}

const int Animation::getFrameIndex()
{
	return m_currentFrame;
}

const float Animation::getFrameTime()
{
	return m_frameTime;
}

const SDL_Rect Animation::getCollider()
{
	return m_collider;
}

void Animation::setFrame(const int frameIndex)
{
	m_currentFrame = frameIndex;
}

const int Animation::getWidth()
{
	if (m_frames.size())
	{
		return m_frames[m_currentFrame].w;
	}
	else return 0;
}

const int Animation::getHeight()
{
	if (m_frames.size())
	{
		return m_frames[m_currentFrame].h;
	}
	else return 0;
}

const SDL_Rect Animation::getCurrentFrame()
{
	if (m_frames.size())
	{
		return m_frames[m_currentFrame];
	}
	else return{ 0, 0, 0, 0 };
}

const int Animation::getNFrames()
{
	return m_frames.size();
}

const int Animation::getRow()
{
	return m_spriteSheetRow;
}