#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "state.h"
#include "selector.h"
#include "highScoreHandler.h"

#include <string>

//! Menu state class
/*!
 * Class that handles the menu state
 */
class MenuState : public State
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
	MenuState(TextureBank* bank, SDL_Renderer* renderer, int width, int height);

	//! Destructor
	/*!
	 * Doesn't do anything
	 */
	~MenuState();

	//! Update method
	/*!
	 * Updates the game and its objects.
	 * \param timeModifier Elapsed time
	 * \return Status code deciding whether the current state should be switched or not.
	 */
	int update(float timeModifier);

	//! Draw method
	/*!
	 * Draws the objects to the screen.
	 */
	void draw();

	//! Reset method
	/*!
	 * Resets the game state to its original values.
	 */
	void reset();
};

#endif
