#include "AudioSoundEffect.h"

#include <iostream>

AudioSoundEffect::AudioSoundEffect(std::string filename) : Audio(filename)
{
	Mix_AllocateChannels(64);

	//Load sound effects
	soundEffect = Mix_LoadWAV(_filename.c_str());

	// Not nullptr because Mix_LoadWAV() returns NULL on error
	if (soundEffect == NULL)
	{
		std::cout << "Failed to load scratch sound effect! SDL_mixer Error: " << Mix_GetError() << std::endl;
		throw;
	}
}

AudioSoundEffect::~AudioSoundEffect()
{
	// Sound wants to be free

	Mix_FreeChunk (soundEffect);
	soundEffect = nullptr;
}

void AudioSoundEffect::play()
{
	Mix_PlayChannel( -1, soundEffect, 0);
}

