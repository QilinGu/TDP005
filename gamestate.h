#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
#include "enemy.h"
#include "shootingenemy.h"
#include "Player.h"
#include "Bullet.h"
#include "pickupscore.h"
#include "highScoreHandler.h"

//!\cond
#include <SDL2/SDL_ttf.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <iostream>
//!\endcond

//! Game state class
/*!
 * class that handles the game state
 */
class GameState : public State
{
public:
	//! Constructor
	/*!
	 * Initializes values, and sets what texture bank to use, which renderer to use, width and height of the board.
	 * \param bank Texture bank to use
	 * \param renderer Renderer to use
	 * \param width Board width
	 * \param height Board height
	 */
	GameState(TextureBank* bank, SDL_Renderer* renderer, int width, int height);

	//! Destructor
	/*!
	 * Doesn't do anything
	 */
	~GameState();

	//! Update method
	/*!
	 * Updates the game and its objects, and spawns new waves of enemies.
	 * \param timeModifier Elapsed time
	 * \return Status code deciding whether the current state should be switched or not.
	 */
	int update(float timeModifier);

	//! Draw method
	/*!
	 * Draws the objects to the screen, and the score.
	 */
	void draw();

	//! Reset method
	/*!
	 * Resets the game state to its original values.
	 */
	void reset();

private:
	//! Spawn new wave method
	/*!
	 * Creates a new wave of enemies and kebabs, based on elapsed time.
	 */
	void spawnNewWave();

	//! Check score method
	/*!
	 * Sets new high score (if score is a new record) with high score handler and prints a new record message.
	 */
	void checkScore();

	//! Get score method
	/*!
	 * Returns score of current game.
	 */
	int getScore();

	//! Player died method
	/*!
	 * Determines what should happen when the player dies, and still has lives left.
	 */
	void playerDied();

	//! Random integer generator
	/*!
	 * Generates a random integer.
	 * \param min Minimum value
	 * \param max Maximum value
	 * \return Random value between min and max
	 */
	int randInt(int min, int max);

	float currentTime;
	float waveTime;
	int currentWave;
	int spawnModifier;

	std::stringstream converter;

	bool record;

};

#endif
