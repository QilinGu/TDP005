#include "pickupscore.h"

PickupScore::PickupScore(float xPosition, float yPosition, State* currentState) : direction(0)
{
	setAlive(true);
	setPosition(xPosition, yPosition);
	setName("score");
	setMaxSpeed(100);
	direction = atan2((currentState->getHeight() / 2) - yPosition, (currentState->getWidth() / 2) - xPosition);
	setXSpeed(100 * cos(direction));
	setYSpeed(100 * sin(direction));
	if ((rand() % 100) > 75)
	{
		score = 200;
		setImage(currentState, "res/img/bigkebab.png");
	}
	else
	{
		score = 100;
		setImage(currentState, "res/img/kebab.png");
	}
}

void PickupScore::update(State* currentState, float timeModifier)
{
	updatePositions(timeModifier);
}

void PickupScore::collision(State* currentState, float timeModifier, GameObject& other)
{
	if (other.getName() == "player")
	{
		destroy();
		currentState->addVariable("score", score);
	}
	else if (other.getName() == "bullet")
	{
		destroy();
		currentState->subVariable("score", 50);
	}
}
