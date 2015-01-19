#ifndef GAME_H_
#define GAME_H_

#include "gamestate.h"
#include "AudioMusic.h"
#include "texturebank.h"
#include "Player.h"
#include "state.h"
#include "gamestate.h"
#include "menustate.h"
#include "gameobject.h"
#include "enemy.h"
#include "Bullet.h"


//! Game class
/*!
 * Handles input from the user, sends it to the game world, and prints the result.
 */
class Game
{

public:
	//! Constructor
	/*!
	 * Sets the ingame music.
	 */
	Game();

	//! Run method
	/*!
	 * Handles everything related input and output
	 */
	void run();

	//! Get screen width
	/*!
	 * Gets the width of the screen.
	 * \return Width
	 */
	int getScreenWidth() const;

	//! Get screen height
	/*!
	 * Gets the height of the screen.
	 * \return Height
	 */
	int getScreenHeight() const;


private:
	//! Input handling method
	/*!
	 * Handles input from the player.
	 * \param running Reference to a bool variable that is true if the game is running
	 * \param myGame The current state that is used
	 */
	void handleInput(bool & running, State* myGame);

	static const int SCREEN_WIDTH = 1300;
	static const int SCREEN_HEIGHT = 800;

	AudioMusic bgMusic;

};

#endif
