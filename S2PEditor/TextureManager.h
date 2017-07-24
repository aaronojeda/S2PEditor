#ifndef __TextureManager__
#define __TextureManager__

#include "SDL.h"
#include <SDL_ttf.h>
#include <iostream>
#include <map>

class TextureManager
{
public:

	static TextureManager& Instance()
	{
		static TextureManager s_pInstance;
		return s_pInstance;
	}
	
	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	// Simpler version of draw which will draw the whole size texture
	void draw(std::string id, int x, int y, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void drawFrame(std::string id, int x, int y, int width, int height, SDL_Rect currentFrame, SDL_Renderer* pRenderer,
		SDL_RendererFlip flip = SDL_FLIP_NONE, double angle = 0., int alpha = 255);

	void clearFromTextureMap(std::string id);

	// This function is specifically for drawing tiles and includes margin and spacing values
	void drawTile(std::string id, int margin, int spacing, int x, int y, int width, int height,
		int currentRow, int currentFrame, SDL_Renderer *pRenderer, int alpha = 255);

	std::map<std::string, SDL_Texture*> getTextureMap();
	
	// Get the width and height in pixels of the given texture by ID
	int getWidth(std::string id);
	int getHeight(std::string id);

	// To manage text
	bool loadFont(std::string fontPath, std::string id);
	// Create new texture from given text and load it into Texture Manager map
	bool renderText(std::string text, std::string fontID, std::string textureID = "textInput");
	
	// Clear texture map
	void clearTextureMap();

private:

	TextureManager();
	~TextureManager();

	// Delete the methods we don't want (new in C++ 11)
	TextureManager(const TextureManager&) = delete;
	TextureManager& operator=(const TextureManager&) = delete;

	static TextureManager* s_pInstance;

	std::map<std::string, SDL_Texture*> m_textureMap;
	std::map<std::string, TTF_Font*> m_fontMap;

	// Text rendering color
	SDL_Color m_textColor;
};

typedef TextureManager TheTextureManager;

#endif /* defined(__TextureManager__) */