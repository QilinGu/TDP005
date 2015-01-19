/*
 * AudioMusic.cc
 *
 *  Created on: Dec 1, 2014
 *      Author: warna720
 */

#include "AudioMusic.h"
#include <iostream>

AudioMusic::AudioMusic(std::string filename) : Audio(filename)
{
    //Load music
    music = Mix_LoadMUS (_filename.c_str());

	// Not nullptr because Mix_LoadMUS() returns NULL on error
    if( music == NULL )
    {
    	std::cout << "Failed to load beat music! SDL_mixer Error: " << Mix_GetError() << std::endl;
    	throw;
    }
}

AudioMusic::~AudioMusic()
{
	// Music wants to be free

	Mix_FreeMusic( music );
	music = nullptr;
}

void AudioMusic::play()
{
	// Start music
    Mix_PlayMusic( music, -1 );
}

void AudioMusic::alternate()
{
	if( Mix_PausedMusic() == 1 )
	{
		//Resume the music
		Mix_ResumeMusic();
	}
	//If the music is playing
	else
	{
		//Pause the music
		Mix_PauseMusic();
	}
}
