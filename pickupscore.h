#ifndef PICKUPSCORE_H
#define PICKUPSCORE_H

#include "gameobject.h"

//!\cond
#include <cmath>
#include <cstdlib>
//!\endcond

//! Pickup score class
/*!
 * Class that handles the score object
 */
class PickupScore : public GameObject
{
public:
	//! Constructor
	/*!
	 * Sets default values, and chooses whether it should be a big or small kebab randomly.
	 * \param xPosition X position
	 * \param yPosition Y position
	 * \param currentState The state containing the object
	 */
	PickupScore(float xPosition, float yPosition, State* currentState);

	//! Update method
	/*!
	 * Updates the position of the score pickup.
	 * \param currentState The state containing the object
	 * \param timeModifier Elapsed time
	 */
	void update(State* currentState, float timeModifier);

	//! Collision method
	/*!
	 * Decides what should happen when this object collides with another object.
	 * \param currentState The state containing the object
	 * \param timeModifier Elapsed time
	 * \param other The collided object
	 */
	void collision(State* currentState, float timeModifier, GameObject& other);

private:
	float direction;
	float score;

};

#endif
