#include "Player.h"

#include <SDL2/SDL.h>

Player::Player(float xPosition, float yPosition, State* currentState)
{
	setAlive(true);
	setPosition(xPosition, yPosition);
	setName("player");
	setMaxSpeed(5);
	setImage(currentState, "res/img/character.png");

	setXSpeed(0);
	setYSpeed(0);

	setXAcceleration(1);
	setYAcceleration(1);
}

void Player::update(State* currentState, float timeModifier)
{
	handleKeyboardStates();
	drainSpeed();
	move(currentState);
}

void Player::collision(State* currentState, float timeModifier, GameObject& other)
{
	if (other.getName() == "enemy" || other.getName() == "shootingenemy" || other.getName() == "enemybullet")
	{
		if (currentState->getVariable("lives") <= 1)
		{
			currentState->setStatus(-1);
		}
		else
		{
			currentState->setStatus(2);
		}
	}
}

void Player::move(State* currentState)
{
	float xSpeed {getXSpeed()};
	float ySpeed {getYSpeed()};

	float maxSpeed {getMaxSpeed()};

	if (xSpeed > maxSpeed)
	{
		xSpeed = maxSpeed;
	}
	else if (xSpeed < maxSpeed * -1)
	{
		xSpeed = maxSpeed * -1;
	}

	if (ySpeed > maxSpeed)
	{
		ySpeed = maxSpeed;
	}
	else if (ySpeed < maxSpeed * -1)
	{
		ySpeed = maxSpeed * -1;
	}

	setX(getX() + int(xSpeed));
	setY(getY() + int(ySpeed));

	if (getX() < 0)
	{
		setX(0);
		setXSpeed(0);
	}
	else if (getX() + getTextureInfo().getRect().w > currentState->getWidth())
	{
		setX(currentState->getWidth() - getTextureInfo().getRect().w);
		setXSpeed(0);
	}
	if (getY() < 0)
	{
		setY(0);
		setYSpeed(0);
	}
	else if (getY() + getTextureInfo().getRect().h > currentState->getHeight())
	{
		setY(currentState->getHeight() - getTextureInfo().getRect().h);
		setYSpeed(0);
	}
}

void Player::handleKeyboardStates()
{
	// Get move input and add to velocity if limit not reached
	// turnSpeed is when turning velocity to opposite

	const Uint8* state = SDL_GetKeyboardState(NULL);

	float vx {getXSpeed()};
	float vy {getYSpeed()};

	float maxSpeed {getMaxSpeed()};
	float accSpeed {getXAcceleration()};

	if ( (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A]) &&
			!(vx < maxSpeed*-1))
	{
		vx -= accSpeed;
	}

	if ( (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D]) &&
			!(vx > maxSpeed))
	{
		vx += accSpeed;
	}

	if ( (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W]) &&
			!(vy < maxSpeed*-1))
	{
		vy -= accSpeed;
	}

	if ( (state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_S]) &&
			!(vy > maxSpeed))
	{
		vy += accSpeed;
	}

	setXSpeed(vx);
	setYSpeed(vy);
}

void Player::drainSpeed()
{
	// Drain velocity

	float vx {getXSpeed()};
	float vy {getYSpeed()};

	float vDrain{0.97};

	if(int(vx)!= 0)
	{
		vx *= vDrain;
	}

	if(int(vy)!= 0)
	{
		vy *= vDrain;
	}

	setXSpeed(vx);
	setYSpeed(vy);
}
