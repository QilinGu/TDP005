#ifndef ENEMY_H
#define ENEMY_H

//!\cond
#include <cmath>
#include <sstream>
//!\endcond

#include "gameobject.h"

//! Enemy class
/*!
 * A class that represents the enemies in the game.
 */
class goEnemy : public GameObject
{
public:
	//! Constructor
	/*!
	 * Creates an enemy at any position in the current state, with an initial speed.
	 * \param xPosition The X position where the enemy should be created
	 * \param yPosition The Y position where the enemy should be created
	 * \param initialSpeed The initial speed in pixels/second
	 * \param currentState The state that should contain the enemy
	 */
	goEnemy(float xPosition, float yPosition, float initialSpeed, State* currentState);

	//! Update method
	/*!
	 * Updates the position of the enemy.
	 * \param currentState The state that contains the enemy
	 * \param timeModifier Elapsed time
	 */
	void update(State* currentState, float timeModifier);

	//! Collision method
	/*!
	 * Handles what should happen if the enemy collides with any object in currentState.
	 * \param currentState The state that contains the enemy
	 * \param timeModifier Elapsed time
	 * \param other The object that the enemy collided with
	 */
	void collision(State* currentState, float timeModifier, GameObject& other);

private:
	float currentMaxSpeed;
	float direction;
	float aliveTime;
	GameObject* player;
	std::stringstream converter;
};

#endif
