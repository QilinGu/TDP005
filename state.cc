#include "state.h"
#include "Bullet.h"

State::State(TextureBank* bank, SDL_Renderer* renderer, std::string newName, int width, int height)
		: textureBank(bank),
		  currentRenderer(renderer),
		  killQueue(),
		  spawnQueue(),
		  worldVariables(),
		  name(newName),
		  stateWidth(width),
		  stateHeight(height),
		  statusCode(0),
		  font(TTF_OpenFont("res/font.ttf", 24)),
		  textSurface(nullptr),
		  textColor()
{
	textColor.r = 255;
	textColor.g = 255;
	textColor.b = 255;
	textColor.a = 255;
}

State::~State()
{
	for (GameObject* obj : objectList)
	{
		delete obj;
	}
	SDL_FreeSurface(textSurface);
	TTF_CloseFont(font);
}

TextureBank* State::getTextureBank()
{
	return textureBank;
}

SDL_Renderer* State::getRenderer()
{
	return currentRenderer;
}

std::string State::getName()
{
	return name;
}

int State::getWidth()
{
	return stateWidth;
}

int State::getHeight()
{
	return stateHeight;
}

int State::getStatus()
{
	return statusCode;
}

void State::addObject(GameObject* newObject)
{
	spawnQueue.push_back(newObject);
}

void State::setStatus(int newStatus)
{
	statusCode = newStatus;
}

void State::setVariable(std::string varName, float newValue)
{
	worldVariables[varName] = newValue;
}

void State::addVariable(std::string varName, float addValue)
{
	worldVariables[varName] += addValue;
}

void State::subVariable(std::string varName, float subValue)
{
	worldVariables[varName] -= subValue;
}

float State::getVariable(std::string varName)
{
	return worldVariables[varName];
}

int State::countObjects(std::string objName)
{
	unsigned int count{ 0 };
	for (GameObject* obj : objectList)
	{
		if (obj->getName() == objName)
		{
			++count;
		}
	}
	return count;
}

GameObject* State::requestObject(std::string name)
{
	for (GameObject* obj : objectList)
	{
		if (obj->getName() == name)
		{
			return obj;
		}
	}
	return nullptr;
}

void State::deleteObjects()
{
	for (GameObject* obj : objectList)
	{
		delete obj;
	}
	objectList.clear();
}

void State::updateObjects(State* currentState, float timeModifier)
{
	spawnObjects();

	for (GameObject* obj : objectList)
	{
		obj->update(currentState, timeModifier);
		checkCollisions(obj, currentState, timeModifier);
	}

	cleanUpDeadObjects();
}

void State::drawObjects()
{
	for (GameObject* obj : objectList)
	{
		SDL_RenderCopy(currentRenderer, obj->getTextureInfo().getTexture(), nullptr, obj->getDrawPosition());
	}
}

void State::spawnObjects()
{
	for (GameObject* obj : spawnQueue)
	{
		objectList.push_back(obj);
	}
	spawnQueue.clear();
}

void State::resetEverything()
{
	for (GameObject* obj : objectList)
	{
		delete obj;
	}
	objectList.clear();
	killQueue.clear();
	spawnQueue.clear();
	statusCode = 0;
}

void State::drawText(std::string message, float x, float y, float w, float h)
{
	textSurface = TTF_RenderText_Blended(font, message.c_str(), textColor);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(currentRenderer, textSurface);
	SDL_Rect position;
	position.x = x;
	position.y = y;
	position.w = w;
	position.h = h;
	SDL_RenderCopy(currentRenderer, tex, nullptr, &position);
	SDL_FreeSurface(textSurface);
	textSurface = nullptr;
	SDL_DestroyTexture(tex);
}

void State::checkCollisions(GameObject* obj, State* currentState, float timeModifier)
{
	for (GameObject* possibleCollision : objectList)
	{
		if (!obj->isDestroyed() && !possibleCollision->isDestroyed() && checkIntersection(obj, possibleCollision))
		{
			obj->collision(currentState, timeModifier, *possibleCollision);
			possibleCollision->collision(currentState, timeModifier, *obj);
		}
	}
}

bool State::checkIntersection(GameObject* obj1, GameObject* obj2)
{
	SDL_Rect obj1rect = obj1->getPosition();
	SDL_Rect obj2rect = obj2->getPosition();

	if (obj1 != obj2 && obj1rect.x <= obj2rect.x + obj2rect.w &&
						obj1rect.x + obj1rect.w >= obj2rect.x &&
						obj1rect.y <= obj2rect.y + obj2rect.h &&
						obj1rect.y + obj1rect.h >= obj2rect.y)
	{
		return true;
	}
	return false;
}

void State::cleanUpDeadObjects()
{
	int objCounter{ 0 };
	for (GameObject* obj : objectList)
	{
		if (obj->isDestroyed())
		{
			killQueue[objCounter] = obj;
		}
		++objCounter;
	}

	for (std::pair<int, GameObject*> obj : killQueue)
	{
		delete obj.second;
		objectList.erase(objectList.begin() + obj.first);
	}
	killQueue.clear();
}
