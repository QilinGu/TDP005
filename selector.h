#ifndef SELECTOR_H
#define SELECTOR_H

#include "gameobject.h"

//! Selector class
/*!
 * Class that handles the menu selector object.
 */
class Selector : public GameObject
{
public:
	//! Constructor
	/*!
	 * Sets default values.
	 * \param currentState The state containing the object
	 */
	Selector(State* currentState);

	//! Update method
	/*!
	 * Checks for user input and changes position accordingly.
	 * \param currentState The state containing the object
	 * \param timeModifier Elapsed time
	 */
	void update(State* currentState, float timeModifier);

	//! Collision method
	/*!
	 * Checks for collisions (does nothing for this object).
	 * \param currentState The state containing the object
	 * \param timeModifier Elapsed time
	 * \param other The collided object
	 */
	void collision(State* currentState, float timeModifier, GameObject& other);

private:
	int currentSelection;
};

#endif
