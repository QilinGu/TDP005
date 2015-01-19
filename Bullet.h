#ifndef BULLET_H
#define BULLET_H

//!\cond
#include <cmath>
//!\endcond

#include "AudioSoundEffect.h"
#include "gameobject.h"

//! Bullet class
/*!
 * A class that represents a bullet on the screen, which the player has shot.
 */
class Bullet : public GameObject
{

public:
	//! Constructor
	/*!
	 * The constructor sets the position to match the one of the player, and sets the direction which the bullet should go in.
	 * \param newDirection The direction of the bullet
	 * \param currentState The state that should contain the bullet
	 */
	Bullet(float newDirection, std::string name, float nx, float ny, State* currentState);

	//! Destructor
	/*!
	 * The destructor doesn't do anything.
	 */
	~Bullet();

	//! Update method
	/*!
	 * Updates the position of the bullet, and destroys the bullet if it has been alive for too long.
	 * \param currentState The state that contains the bullet
	 * \param timeModifier Elapsed time
	 */
	void update(State* currentState, float timeModifier);

	//! Collision method
	/*!
	 * Handles what should happen if the bullet collides with any object in currentState
	 * \param currentState The state that contains the bullet
	 * \param timeModifier Elapsed time
	 * \param other The object that the bullet collided with
	 */
	void collision(State* currentState, float timeModifier, GameObject& other);

private:
	float maxLifeSpan;
	float aliveTime;

	AudioSoundEffect soundEffect;
};

#endif
