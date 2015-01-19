#include "enemy.h"

goEnemy::goEnemy(float xPosition, float yPosition, float initialSpeed, State* currentState)
	: currentMaxSpeed(initialSpeed),
	  direction(0),
	  aliveTime(0.0f),
	  player(nullptr),
	  converter()
{
	setAlive(true);
	setPosition(xPosition, yPosition);
	setName("enemy");
	setMaxSpeed(200);
	setImage(currentState, "res/img/enemy1.png");
}

void goEnemy::update(State* currentState, float timeModifier)
{
	player = currentState->requestObject("player");

	float xdiff = player->getPosition().x - getX();
	float ydiff = player->getPosition().y - getY();
	direction = atan2(ydiff, xdiff);

	currentMaxSpeed += 20 * timeModifier;

	setXSpeed(cos(direction) * currentMaxSpeed);
	setYSpeed(sin(direction) * currentMaxSpeed);

	aliveTime += timeModifier * 2;
	converter << "res/img/enemy" << (static_cast<int>(floor(aliveTime)) % 2) + 1 << ".png";
	setImage(currentState, converter.str());
	converter.str("");

	updatePositions(timeModifier);
}

void goEnemy::collision(State* currentState, float timeModifier, GameObject& other)
{
	if (other.getName() == "bullet")
	{
		destroy();
	}
}
