/*
 * This class plays music
 * For sound effects use AudioSoundEffect class
 */

#ifndef AUDIOMUSIC_H
#define AUDIOMUSIC_H

#include "Audio.h"

class AudioMusic : public Audio
{
public:

	//! Constructor
	/*!
	 * The constructor initialize the player and loads the media.
	 * \param filename The filename of the music to load.
	 */
	AudioMusic(std::string filename);

	//! Destructor
	/*!
	 * The destructor frees the memory of the allocated file.
	 */
	~AudioMusic();

	//! play method
	/*!
	 * Starts playing the music.
	 */
	void play();

	//! alternate method
	/*!
	 * If music is playing then pauses music
	 * else if music is paused then resumes playing music.
	 */
	void alternate();

private:
	Mix_Music* music {nullptr};
};

#endif /* AUDIOMUSIC_H_ */
