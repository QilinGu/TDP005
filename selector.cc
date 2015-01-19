#include "selector.h"

#include <SDL2/SDL.h>

Selector::Selector(State* currentState) : currentSelection(0)
{
	setY(300);
	setX(400);
	setImage(currentState, "res/img/selection.png");
}

void Selector::update(State* currentState, float timeModifier)
{
	const Uint8* state = SDL_GetKeyboardState(NULL);

	if ( (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W]) )
	{
		currentSelection = 0;
	}

	if ( (state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_S]) )
	{
		currentSelection = 1;
	}

	if ( state[SDL_SCANCODE_RETURN] )
	{
		if (currentSelection == 0)
		{
			currentState->setStatus(1);
		}
		else
		{
			currentState->setStatus(-1);
		}
	}

	setY(300 + (currentSelection * 200));
}

void Selector::collision(State* currentState, float timeModifier, GameObject& other)
{

}
