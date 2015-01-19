#ifndef AUDIO_H
#define AUDIO_H

//!\cond
#include <string>
#include <SDL2/SDL_mixer.h>
//!\endcond


//! Audio class
/*!
 * A class that represents a player which AudioMusic and AudioSoundEffect inherits.
 * See this class as the player and the classes that inherits this class is loading and starting the sound.
 */
class Audio
{

public:
	//! Constructor
	/*!
	 * The constructor initialize the mixed and the filename variable.
	 * \param filename The filename of the audio to load.
	 */
	Audio(std::string filename);

	//! Destructor
	/*!
	 * The destructor frees the memory of the allocated player.
	 */
	virtual ~Audio();

protected:
	std::string _filename;
};


#endif
