#include "texturebank.h"

TextureInfo::TextureInfo()
{
	texture = nullptr;
	rect.x = 0;
	rect.y = 0;
	rect.w = 0;
	rect.h = 0;
	filename = "";
}

TextureInfo::TextureInfo(SDL_Texture* newtex, int neww, int newh, std::string newfilename)
{
	filename = newfilename;
	rect.x = 0;
	rect.y = 0;
	rect.w = neww;
	rect.h = newh;
	texture = newtex;
}

SDL_Texture* TextureInfo::getTexture()
{
	return texture;
}

SDL_Rect TextureInfo::getRect()
{
	return rect;
}

std::string TextureInfo::getFilename()
{
	return filename;
}

bool TextureBank::requestTexture(TextureInfo& texture, std::string filename, SDL_Renderer* renderer)
{
	for (TextureInfo& tex : textureList)
	{
		if (tex.filename == filename)
		{
			texture = tex;
			return true;
		}
	}

	if (!loadTexture(filename, renderer))
	{
		return false;
	}

	texture = textureList.back();
	return true;
}

void TextureBank::destroyTextures()
{
	for (TextureInfo& tex : textureList)
	{
		SDL_DestroyTexture(tex.texture);
	}
}

bool TextureBank::loadTexture(std::string filename, SDL_Renderer* renderer)
{
	SDL_Surface* tempSurface = nullptr;
	tempSurface = IMG_Load(filename.c_str());
	if (tempSurface == nullptr)
	{
		return false;
	}

	TextureInfo newTexture (SDL_CreateTextureFromSurface(renderer, tempSurface), tempSurface->w, tempSurface->h, filename);

	textureList.push_back(newTexture);

	SDL_FreeSurface(tempSurface);
	return true;
}
