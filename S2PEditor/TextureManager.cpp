#include "TextureManager.h"
#include "Game.h"
#include <SDL_image.h>

using namespace std;

TextureManager::TextureManager():
//m_textColor({ 0, 0, 0})
m_textColor({ 255, 255, 255 })
{
}

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{
	// Auxiliar surface
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());

	if (pTempSurface == nullptr)
	{
		printf("IMG Error: %s\n", IMG_GetError());
		return false;
	}

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);	// Get rid of old loaded surface

	// everything went ok, add the texture to our list
	if (pTexture != nullptr)
	{
		if (m_textureMap.find(id) != m_textureMap.end())
		{
			// Destroy previous texture with the given id
			SDL_DestroyTexture(m_textureMap[id]);
		}
		m_textureMap[id] = pTexture;
		return true;
	}

	// reaching here means something went wrong
	cout << "Unable to load '" << id << "'. IMG Error: " << IMG_GetError() << endl;
	return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::draw(std::string id, int x, int y, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = getWidth(id);
	srcRect.h = destRect.h = getHeight(id);
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, SDL_Rect currentFrame,
	SDL_Renderer* pRenderer, SDL_RendererFlip flip, double angle, int alpha)
{
	SDL_Rect dstRect = { x, y, width, height};

	// set the alpha of the texture
	SDL_SetTextureAlphaMod(m_textureMap[id], alpha);
	if (SDL_RenderCopyEx(pRenderer, m_textureMap[id], &currentFrame, &dstRect, angle, 0, flip) < 0)
	{
		printf("Couldn't draw frame of texture '%s'. SDL_Error: %s\n", id.c_str(), SDL_GetError());
	}
	// set the alpha of the texture back to normal
	SDL_SetTextureAlphaMod(m_textureMap[id], SDL_ALPHA_OPAQUE);
}

int TextureManager::getWidth(std::string id)
{
	int w, h;
	if (SDL_QueryTexture(m_textureMap[id], NULL, NULL, &w, &h) != 0)
	{
		std::cout << "Couldn't get '" << id << "' width. SDL error: " << SDL_GetError() << "\n";
		return 0;
	}
	else
	{
		return w;
	}
}

int TextureManager::getHeight(std::string id)
{
	int w, h;
	if (SDL_QueryTexture(m_textureMap[id], NULL, NULL, &w, &h) != 0)
	{
		std::cout << "Couldn't get '" << id << "' height. SDL error: " << SDL_GetError() << "\n";
		return 0;
	}
	else
	{
		return h;
	}
}

void TextureManager::drawTile(std::string id, int margin, int spacing, int x, int y,
	int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer, int alpha)
{
	auto it = m_textureMap.find(id);
	if (it != m_textureMap.end())
	{
		SDL_Rect srcRect;
		SDL_Rect destRect;
		srcRect.x = margin + (spacing + width) * currentFrame;
		srcRect.y = margin + (spacing + height) * currentRow;
		srcRect.w = destRect.w = width;
		srcRect.h = destRect.h = height;
		destRect.x = x;
		destRect.y = y;

		// set the alpha of the texture
		SDL_SetTextureAlphaMod(m_textureMap[id], alpha);
		SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, SDL_FLIP_NONE);
	}
	else
	{
		std::cout << "Couldn't find " << id << " in Texture Manager\n";
	}
}

// Destroys the texture with the given ID 
void TextureManager::clearFromTextureMap(std::string id)
{
	SDL_DestroyTexture(m_textureMap[id]);
	m_textureMap.erase(id);
}

TextureManager::~TextureManager()
{
	// Clear font map
	for (auto font : m_fontMap)
	{
		TTF_CloseFont(font.second);
	}

	// Clear texture map
	clearTextureMap();
}

void TextureManager::clearTextureMap()
{
	for (auto texture : m_textureMap)
	{
		SDL_DestroyTexture(texture.second);
	}
	m_textureMap.clear();
}

bool TextureManager::loadFont(std::string fontPath, std::string id)
{
	TTF_Font* pTempFont = TTF_OpenFont(fontPath.c_str(), 15);

	if (pTempFont == nullptr)
	{
		std::cout << "Failed to load font " << fontPath << ". SDL_ttf Error: %s\n" << TTF_GetError();
		return false;
	}
	else
	{
		// Add font to the map
		m_fontMap[id] = pTempFont;
		return true;
	}
}

bool TextureManager::renderText(std::string text, std::string fontID, std::string textureID)
{
	// If fontID key is not in font map we cannot render text
	if (m_fontMap.find(fontID) == m_fontMap.end()) return false;

	bool success = true;

	//Render text surface
	SDL_Surface* pTextSurface = TTF_RenderText_Solid(m_fontMap[fontID], text.c_str(), m_textColor);
	if (pTextSurface == nullptr)
	{
		std::cout << "Unable to render text surface. SDL_ttf Error: %s\n" << TTF_GetError();
		success = false;
	}
	else
	{
		//Create texture from surface pixels
		SDL_Texture* pTextTexture = SDL_CreateTextureFromSurface(TheGame::Instance().getRenderer(), pTextSurface);

		if (pTextTexture == nullptr)
		{
			cout << "Unable to create texture '" << textureID << "'. SDL error: " << SDL_GetError() << endl;
			success = false;
		}
		else
		{
			// Get rid of previous texture. If textureID isn't in the map, a nullptr entry will be added
			if (m_textureMap[textureID] != nullptr)
			{
				SDL_DestroyTexture(m_textureMap[textureID]);
			}
			// Add texture to the texture map
			m_textureMap[textureID] = pTextTexture;
		}

		//Get rid of old surface
		SDL_FreeSurface(pTextSurface);
	}

	return success;
}

std::map<std::string, SDL_Texture*> TextureManager::getTextureMap() 
{
	return m_textureMap; 
}
