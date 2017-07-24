#pragma once

#include <string>
#include <map>
#include <SDL_mixer.h>

enum sound_type
{
	SOUND_MUSIC = 0,
	SOUND_SFX = 1
};

class SoundManager
{
public:

	static SoundManager& Instance()
	{
		static SoundManager s_pInstance;
		return s_pInstance;
	}

	bool load(std::string fileName, std::string id, sound_type type);

	// -1 for infinite loops, 0 for playing once
	void playSound(std::string id, int loops);
	// -1 for infinite loops, 1 for playing once
	void playMusic(std::string id, int loops);

	// Free music and sound effects
	void clear();
	// Free from sfxs map
	void clearSfx(std::string id);
	// Free from musics map
	void clearMusic(std::string id);

	void stopMusic();

private:

	SoundManager();
	~SoundManager();

	// Delete the methods we don't want (new in C++ 11)
	SoundManager(const SoundManager&) = delete;
	SoundManager& operator=(const SoundManager&) = delete;

	std::map<std::string, Mix_Chunk*> m_sfxs;
	std::map<std::string, Mix_Music*> m_music;
};

typedef SoundManager TheSoundManager;