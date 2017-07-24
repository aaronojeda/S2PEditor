#include "SoundManager.h"
#include <iostream>

using namespace std;

SoundManager::SoundManager()
{
	// We call Mix_OpenAudio with values that will work well for most games.
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
	{
		std::cout << "Mix Error: " << Mix_GetError() << std::endl;
	}
}

bool SoundManager::load(string fileName, string id, sound_type type)
{
	if (type == SOUND_MUSIC)
	{
		Mix_Music* pMusic = Mix_LoadMUS(fileName.c_str());
		
		if (pMusic == 0)
		{
			std::cout << "Could not load music. Error: " << Mix_GetError() << std::endl;
			return false;
		}

		m_music[id] = pMusic;
		return true;
	}
	else if (type == SOUND_SFX)
	{
		Mix_Chunk* pChunk = Mix_LoadWAV(fileName.c_str());

		if (pChunk == 0)
		{
			std::cout << "Could not load SFX. Error: " << Mix_GetError() << std::endl;
			return false;
		}

		m_sfxs[id] = pChunk;
		return true;
	}
	return false;
}

void SoundManager::playMusic(string id, int loops)
{
	Mix_PlayMusic(m_music[id], loops);
}

void SoundManager::playSound(string id, int loops)
{
	// A value of -1 tells SDL_mixer to play the sound on any available channel.
	Mix_PlayChannel(-1, m_sfxs[id], loops);
}

SoundManager::~SoundManager()
{
	clear();	
	Mix_CloseAudio();
}

void SoundManager::clear()
{
	// Free music
	for (auto music : m_music)
	{
		Mix_FreeMusic(music.second);
	}
	m_music.clear();

	// Free sound effects
	for (auto sfx : m_sfxs)
	{
		Mix_FreeChunk(sfx.second);
	}
	m_sfxs.clear();
}

void SoundManager::clearSfx(string id)
{
	Mix_FreeChunk(m_sfxs[id]);
	m_sfxs.erase(id);
}

void SoundManager::clearMusic(string id)
{
	Mix_FreeMusic(m_music[id]);
	m_music.erase(id);
}

void SoundManager::stopMusic()
{
	Mix_HaltMusic();
}