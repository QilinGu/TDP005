#ifndef STATE_H
#define STATE_H

//!\cond
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
#include <map>


#include "forwarddeclarations.h"
//!\endcond

#include "gameobject.h"
#include "texturebank.h"


struct reversecompare
{
  bool operator()(const char& lhs, const char& rhs) const
  {
	  return lhs > rhs;
  }
};

//! State class
/*!
 * Abstract class that handles states.
 */
class State
{
public:
	//! Constructor
	/*!
	 * Sets info about the state.
	 * \param bank Which texture bank the state should use
	 * \param renderer Which renderer the state should use
	 * \param newName The name of the state
	 * \param width The width off the screen
	 * \param height The height off the screen
	 */
	State(TextureBank* bank, SDL_Renderer* renderer, std::string newName, int width, int height);

	//! Abstract destructor
	/*!
	 * Makes sure that the destructors of the derived classes are called alongside this one.
	 */
	virtual ~State();

	//! Abstract update method
	/*!
	 * Determines what should happen when the screen updates.
	 * \param timeModifier Elapsed time
	 */
	virtual int update(float timeModifier) = 0;

	//! Abstract draw method
	/*!
	 * Determines what should be drawn to the screen on update.
	 */
	virtual void draw() = 0;

	//! Abstract reset method
	/*!
	 * Determines what should happen when the state is reset.
	 */
	virtual void reset() = 0;

	//! Get texture bank
	/*!
	 * Gets the texture bank the state uses.
	 * \return Texture bank
	 */
	TextureBank* getTextureBank();

	//! Get renderer
	/*!
	 * Gets the renderer the state uses.
	 * \return Renderer
	 */
	SDL_Renderer* getRenderer();

	//! Get name
	/*!
	 * Gets the name of the state.
	 * \return String
	 */
	std::string getName();

	//! Get state width
	/*!
	 * Gets the width of the state.
	 * \return Width
	 */
	int getWidth();

	//! Get state height
	/*!
	 * Gets the height of the state.
	 * \return Height
	 */
	int getHeight();

	//! Get state status
	/*!
	 * Gets the status of the state.
	 * \return Status code
	 */
	int getStatus();

	//! Add object method
	/*!
	 * Adds an object to the state.
	 * \param newObject The new object
	 */
	void addObject(GameObject* newObject);

	//! Set status method
	/*!
	 * Sets the current status code.
	 * \param newStatus The new status
	 */
	void setStatus(int newStatus);

	//! Set variable
	/*!
	 * Creates, if not already created, and sets a variable in the world.
	 * \param varName The name of the variable
	 * \param newValue The value for the variable
	 */
	void setVariable(std::string varName, float newValue);

	//! Add value to variable
	/*!
	 * Adds a value to an variable.
	 * \param varName The name of the variable
	 * \param addValue The value to be added
	 */
	void addVariable(std::string varName, float addValue);

	//! Subtract value from variable
	/*!
	 * Subtracts a value from a variable
	 * \param varName The name of the variable
	 * \param subValue The value to be subtracted
	 */
	void subVariable(std::string varName, float subValue);

	//! Get value from variable
	/*!
	 * Gets the value from a variable.
	 * \param varName The name of the variable
	 */
	float getVariable(std::string varName);

	//! Get object count
	/*!
	 * Gets the amount of a chosen object.
	 * \param objName The name of the object
	 * \return The amount of that object
	 */
	int countObjects(std::string objName);

	//! Request an object
	/*!
	 * Finds and returns an object in the state.
	 * \param name The name of the object
	 * \return A pointer to the requested object
	 */
	GameObject* requestObject(std::string name);

	//! Delete objects
	/*!
	 * Deletes all the objects in the world.
	 */
	void deleteObjects();

protected:
	//! Update objects
	/*!
	 * Calls the update function for every object in the world.
	 * \param currentState The state which objects should be updated
	 * \param timeModifier Elapsed time
	 */
	void updateObjects(State* currentState, float timeModifier);

	//! Update objects
	/*!
	 * Draws every object in the state to the screen.
	 */
	void drawObjects();

	//! Spawn objects
	/*!
	 * Creates objects listed in the spawnqueue.
	 */
	void spawnObjects();

	//! Reset everything
	/*!
	 * Resets the state, deleting all objects, and clears all queues.
	 */
	void resetEverything();

	//! Draw text
	/*!
	 * Draws text onto the screen.
	 * \param message The string to be drawn
	 * \param x X position of the message
	 * \param y Y position of the message
	 * \param w Width of the message
	 * \param h Height of the message
	 */
	void drawText(std::string message, float x, float y, float w, float h);

private:
	std::vector<GameObject*> objectList;
	TextureBank* textureBank;
	SDL_Renderer* currentRenderer;
	std::map<int, GameObject*, reversecompare> killQueue;
	std::vector<GameObject*> spawnQueue;
	std::map<std::string, float> worldVariables;
	std::string name;

	int stateWidth;
	int stateHeight;
	int statusCode;

	TTF_Font* font;
	SDL_Surface* textSurface;
	SDL_Color textColor;

	//! Check collisions
	/*!
	 * Checks for collisions in the world, and handles them.
	 * \param obj The object that should check for collisions
	 * \param currentState The state containing obj
	 * \param timeModifier Elapsed time
	 */
	void checkCollisions(GameObject* obj, State* currentState, float timeModifier);

	//! Check intersection
	/*!
	 * Checks for an intersection between two objects.
	 * \param obj1 The first object
	 * \param obj2 The second object
	 * \return True if intersection has occured, false if not
	 */
	bool checkIntersection(GameObject* obj1, GameObject* obj2);

	//! Clean up dead objects
	/*!
	 * Deletes all the objects added to the killqueue.
	 */
	void cleanUpDeadObjects();

};

#endif
