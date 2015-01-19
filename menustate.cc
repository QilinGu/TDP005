#include "menustate.h"

MenuState::MenuState(TextureBank* bank, SDL_Renderer* renderer, int width, int height) : State(bank, renderer, "menu", width, height)
{
	addObject(new Selector(this));
	spawnObjects();
}

MenuState::~MenuState() {}

int MenuState::update(float timeModifier)
{
	updateObjects(this, timeModifier);
	return getStatus();
}

void MenuState::draw()
{
	highScoreHandler highScore;
	std::string highScoreText = std::to_string(highScore.getHighScore());
	drawText("Current highscore:", 0, 0, 240, 50);
	drawText(highScoreText, 240, 0, 40, 50);
	drawObjects();
}

void MenuState::reset()
{
	resetEverything();
}
