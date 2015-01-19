#include "Bullet.h"

#include <SDL2/SDL.h>

Bullet::Bullet(float newDirection, std::string name, float nx, float ny, State* currentState) : soundEffect("res/audio/bulletSound1.wav")
{

	setAlive(true);
	aliveTime = 0;
	maxLifeSpan = 2;


	float _x {nx};
	float y {ny};

	setPosition(_x, y);
	setName(name);

	if (name == "bullet")
	{
		setImage(currentState, "res/img/projectile.png");
		setMaxSpeed(1000);
	}
	else if (name == "enemybullet")
	{
		setImage(currentState, "res/img/enemyProjectile.png");
		setMaxSpeed(400);
	}

	setXSpeed(cos(newDirection) * 1000);
	setYSpeed(sin(newDirection) * 1000);

	setXAcceleration(cos(newDirection) * 1000);
	setYAcceleration(sin(newDirection) * 1000);

	soundEffect.play();

}

Bullet::~Bullet(){}

void Bullet::update(State* currentState, float timeModifier)
{
	aliveTime += timeModifier;
	if (aliveTime >= maxLifeSpan)
	{
		destroy();
	}
	updatePositions(timeModifier);
}

void Bullet::collision(State* currentState, float timeModifier, GameObject& other)
{
	if (other.getName() == "enemy" && getName() == "bullet")
	{
		destroy();
		currentState->addVariable("score", 10);
	}
	else if (other.getName() == "score")
	{
		destroy();
	}
}
