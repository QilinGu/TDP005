#include "gameobject.h"

TextureInfo GameObject::getTextureInfo()
{
	return texture;
}

SDL_Rect GameObject::getPosition()
{
	SDL_Rect returnRect = texture.getRect();
	returnRect.x = x;
	returnRect.y = y;
	return returnRect;
}

SDL_Rect* GameObject::getDrawPosition()
{
	drawPosition = texture.getRect();
	drawPosition.x = x;
	drawPosition.y = y;
	return &drawPosition;
}

std::string GameObject::getName() const
{
	return name;
}

bool GameObject::isDestroyed()
{
	return kill;
}

void GameObject::setAcceleration(float xAccel, float yAccel)
{
	xAcceleration = xAccel;
	yAcceleration = yAccel;
}

void GameObject::setPosition(float xPosition, float yPosition)
{
	x = xPosition;
	y = yPosition;
}

void GameObject::setName(std::string const& newName)
{
	name = newName;
}

void GameObject::setMaxSpeed(float nSpeed)
{
	maxSpeed = nSpeed;
}

void GameObject::setImage(State* currentState, std::string textureName)
{
	currentState->getTextureBank()->
	requestTexture(texture, textureName, currentState->getRenderer());
}

void GameObject::updatePositions(float timeModifier)
{
	//xSpeed += xAcceleration * timeModifier;
	if (xSpeed >= maxSpeed)
	{
		xSpeed = maxSpeed;
	}
	else if (xSpeed <= -maxSpeed)
	{
		xSpeed = -maxSpeed;
	}
	//ySpeed += yAcceleration * timeModifier;
	if (ySpeed >= maxSpeed)
	{
		ySpeed = maxSpeed;
	}
	else if (ySpeed <= -maxSpeed)
	{
		ySpeed = -maxSpeed;
	}

	x += xSpeed * timeModifier;
	y += ySpeed * timeModifier;
}

void GameObject::destroy()
{
	kill = true;
}

void GameObject::setX(float _x)
{
	x = _x;
}

void GameObject::setY(float _y)
{
	y = _y;
}

void GameObject::setXSpeed(float speed)
{
	xSpeed = speed;
}

void GameObject::setYSpeed(float speed)
{
	ySpeed = speed;
}

void GameObject::setXAcceleration(float accel)
{
	xAcceleration = accel;
}

void GameObject::setYAcceleration(float accel)
{
	yAcceleration = accel;
}

void GameObject::setAlive(bool alive)
{
	kill = !alive;
}
