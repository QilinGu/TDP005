#include "Audio.h"
#include <iostream>

Audio::Audio(std::string filename) : _filename(filename)
{
	if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
	{
		std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
		throw;
	}
}

Audio::~Audio()
{
	Mix_Quit();
}
