/*
 * This class plays sound effects
 * For music use AudioMusic class
 */

#ifndef AUDIOSOUNDEFFECT_H
#define AUDIOSOUNDEFFECT_H

#include "Audio.h"

//! AudioSoundEffect class
/*!
 * A class that plays sound effects.
 */
class AudioSoundEffect : public Audio
{
public:
	//! Constructor
	/*!
	 * The constructor initialize the player, loads the media and allocates channels.
	 * \param filename The filename of the sound effect to load.
	 */
	AudioSoundEffect(std::string filename);

	//! Destructor
	/*!
	 * The destructor frees the memory of the allocated file.
	 */
	~AudioSoundEffect();

	//! play method
	/*!
	 * Starts playing the sound effect.
	 */
	void play();


private:
	Mix_Chunk* soundEffect {nullptr};
};

#endif
