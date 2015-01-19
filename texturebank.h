#ifndef SPRITEBANK_H
#define SPRITEBANK_H

//!\cond
#include <list>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//!\endcond


//! Texture info class
/*!
 * Class that handles texture info.
 */
class TextureInfo
{
	friend class TextureBank;
public:
	//! Constructor
	/*!
	 * Sets default values.
	 */
	TextureInfo();

	//! Get texture
	/*!
	 * Gets the texture.
	 * \return Texture
	 */
	SDL_Texture* getTexture();

	//! Get texture rectangle
	/*!
	 * Gets a rectangle containing info about the width and height of the texture.
	 * \return Rectangle
	 */
	SDL_Rect getRect();

	//! Get filename
	/*!
	 * Gets the filename of the texture.
	 * \return String
	 */
	std::string getFilename();

private:
	//! Constructor
	/*!
	 * Sets custom values.
	 * \param newtex The texture
	 * \param neww Width of the texture
	 * \param newh Height of the texture
	 * \param newfilename The filename of the texture
	 */
	TextureInfo(SDL_Texture* newtex, int neww, int newh, std::string newfilename);

	SDL_Texture* texture;
	SDL_Rect rect;
	std::string filename;
};

//! Texture bank class
/*!
 * Class that handles texture loading.
 */
class TextureBank
{
public:
	//! Request texture
	/*!
	 * Fetches a texture from a file.
	 * \param texture The TextureInfo object that should store the new texture
	 * \param filename The filename of the object
	 * \param renderer The renderer that should contain the loaded texture
	 * \return True if loading was successful, false if not
	 */
	bool requestTexture(TextureInfo& texture, std::string filename, SDL_Renderer* renderer);

	//! Destroy textures
	/*!
	 * Frees all loaded textures.
	 */
	void destroyTextures();

private:
	//! Load texture
	/*!
	 * Loads a texture.
	 * \param filename The string representing the filename
	 * \param renderer The renderer that should contain the loaded texture
	 * \return True if loading was successful, false if not
	 */
	bool loadTexture(std::string filename, SDL_Renderer* renderer);

	std::list<TextureInfo> textureList;
};

#endif
