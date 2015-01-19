#ifndef PLAYER_H
#define PLAYER_H

#include "gameobject.h"

class Player : public GameObject
{
public:

	//! Constructor
	/*!
	 * The constructor sets the properties of the player, coordinates, image, speed, max speed, acceleration.
	 * \param xPosition The X coordinate that player will spawn on.
	 * \param yPosition The Y coordinate that player will spawn on.
	 * \param currentState The state that should contain the player.
	 */
	Player(float xPosition, float yPosition, State* currentState);

	//! update method
	/*!
	 * Updates the position of the player by invoking the methods handleKeyboardStates(), drainSpeed() and move().
	 * \param currentState The state that contains the player.
	 * \param timeModifier Elapsed time.
	 */
	void update(State* currentState, float timeModifier);

	//! collision method
	/*!
	 * Handles what should happen if the player collides with any object in currentState.
	 * \param currentState The state that contains the player.
	 * \param timeModifier Elapsed time.
	 * \param other The object that the player collided with.
	 */
	void collision(State* currentState, float timeModifier, GameObject& other);


private:

	//! handleKeyboardStates method
	/*!
	 * Handles key pressed for player keys. Increments speed based on key and direction.
	 */
	void handleKeyboardStates();

	//! drainSpeed method
	/*!
	 * Drains the speed, making the player walking smooth.
	 */
	void drainSpeed();

	//! handleKeyboardStates method
	/*!
	 * Firstly, corrects if player speed exceeds max speed.
	 * Secondly updates the coordinates of the player.
	 * Thirdly correcting player position if player is out of bounds.
	 * \param currenState The state that contains the player.
	 */
	void move(State* currentState);
};

#endif
