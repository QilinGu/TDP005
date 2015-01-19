#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

//!\cond
#include <SDL2/SDL.h>
#include <string>


#include "forwarddeclarations.h"
//!\endcond

#include "texturebank.h"
#include "state.h"

//! Game object class
/*!
 * Abstract class that handles any object on the screen
 */
class GameObject
{
public:
	//! Abstract destructor
	/*!
	 * Makes sure that the destructors of the derived classes are called along with this one.
	 */
	virtual ~GameObject() {};

	//! Abstract update method
	/*!
	 * Defines what should happen to the object in the window loop.
	 * \param currentState The state that contains the object
	 * \param timeModifier Elapsed time
	 */
	virtual void update(State* currentState, float timeModifier) = 0;

	//! Abstract collision method
	/*!
	 * Defines what should happen when the object collides with another object.
	 * \param currentState The state that contains the object
	 * \param timeModifier Elapsed time
	 * \param other Collided object
	 */
	virtual void collision(State* currentState, float timeModifier, GameObject& other) = 0;

	//! Get texture info
	/*!
	 * Fetches info about the object texture
	 * \return TextureInfo object containing info about the texture used on this object
	 */
	TextureInfo getTextureInfo();

	//! Get position
	/*!
	 * Fetches the objects position on the screen.
	 * \return SDL_Rect representing the position of the object on the screen
	 */
	SDL_Rect getPosition();

	//! Get position as pointer
	/*!
	 * Fetches the objects position on the screen as a pointer.
	 * \return Pointer to SDL_Rect representing the position of the object on the screen
	 */
	SDL_Rect* getDrawPosition();

	//! Get object name
	/*!
	 * Fetches the name of the object.
	 * \return A string containing the name
	 */
	std::string getName() const;

	//! Check if object is destroyed
	/*!
	 * Checks if the object is alive or dead.
	 * \return true if the object is dead, false if not
	 */
	bool isDestroyed();

	//! Destroy object
	/*!
	 * Destroys the object.
	 */
	void destroy();

	//! Get X position
	/*!
	 * Fetches the X position of the object on the screen
	 * \return X position
	 */
	float getX(){return x;};

	//! Get Y position
	/*!
	 * Fetches the Y position of the object on the screen
	 * \return Y position
	 */
	float getY(){return y;};

protected:
	//! Set acceleration
	/*!
	 * Sets the X and Y acceleration of the object.
	 * \param xAccel The X acceleration
	 * \param yAccel The Y acceleration
	 */
	void setAcceleration(float xAccel, float yAccel);

	//! Set position
	/*!
	 * Sets the X and Y position of the object.
	 * \param xPosition The X position
	 * \param yPosition The Y position
	 */
	void setPosition(float xPosition, float yPosition);

	//! Set name
	/*!
	 * Sets the name of the object.
	 * \param newName The new name
	 */
	void setName(std::string const& newName);

	//! Set max speed
	/*!
	 * Sets the max speed in both the X and Y direction of the object.
	 * \param nSpeed The new max speed
	 */
	void setMaxSpeed(float nSpeed);

	//! Set image
	/*!
	 * Sets the texture used on the object.
	 * \param currentState The state containing the object
	 * \param textureName String representing the name of the image file
	 */
	void setImage(State* currentState, std::string textureName);

	//! Update position
	/*!
	 * Updates the position on the object, based on current speed, acceleration and elapsed time.
	 * \param timeModifier Elapsed time
	 */
	void updatePositions(float timeModifier);

	//! Set X position
	/*!
	 * Sets the X position of the object.
	 * \param _x The new X position
	 */
	void setX(float _x);

	//! Set Y position
	/*!
	 * Sets the Y position of the object.
	 * \param _y The new Y position
	 */
	void setY(float _y);

	//! Set X speed
	/*!
	 * Sets the X speed of the object.
	 * \param speed The new X speed
	 */
	void setXSpeed(float speed);

	//! Set Y speed
	/*!
	 * Sets the Y speed of the object.
	 * \param speed The new Y speed
	 */
	void setYSpeed(float speed);

	//! Set X acceleration
	/*!
	 * Sets the X acceleration of the object.
	 * \param accel The new X acceleration
	 */
	void setXAcceleration(float accel);

	//! Set Y acceleration
	/*!
	 * Sets the Y acceleration of the object.
	 * \param accel The new Y acceleration
	 */
	void setYAcceleration(float accel);

	//! Set alive
	/*!
	 * Sets whether the object should live or not.
	 * \param alive true or false whether alive or not
	 */
	void setAlive(bool alive);

	//! Get X speed
	/*!
	 * Fetches the X speed.
	 * \return X speed
	 */
	float getXSpeed(){return xSpeed;};

	//! Get Y speed
	/*!
	 * Fetches the Y speed.
	 * \return Y speed
	 */
	float getYSpeed(){return ySpeed;};

	//! Get X acceleration
	/*!
	 * Fetches the X acceleration.
	 * \return X acceleration
	 */
	float getXAcceleration(){return xAcceleration;};

	//! Get Y acceleration
	/*!
	 * Fetches the Y acceleration.
	 * \return Y acceleration
	 */
	float getYAcceleration(){return yAcceleration;};

	//! Get max speed
	/*!
	 * Fetches the max speed in both the X and Y direction.
	 * \return Max speed
	 */
	float getMaxSpeed(){return maxSpeed;};

private:
	TextureInfo texture;
	float x;
	float y;
	float xSpeed;
	float ySpeed;
	float xAcceleration;
	float yAcceleration;
	float maxSpeed;
	std::string name;
	SDL_Rect drawPosition;
	bool kill{ false };
};

#endif
