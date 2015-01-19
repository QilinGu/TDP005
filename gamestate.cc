#include "gamestate.h"


GameState::GameState(TextureBank* bank, SDL_Renderer* renderer, int width, int height)
	: State(bank, renderer, "game", width, height),
	  currentTime(0),
	  waveTime(5),
	  currentWave(0),
	  spawnModifier(0),
	  converter(),
	  record(false)
{
	srand(clock());
	addObject(new Player(500, 400, this));
	spawnObjects();
	setVariable("score", 0);
	setVariable("lives", 3);
}

GameState::~GameState()
{
	deleteObjects();
}

int GameState::update(float timeModifier)
{
	currentTime += timeModifier;
	if (currentTime >= waveTime)
	{
		spawnNewWave();
	}

	updateObjects(this, timeModifier);

	if (getStatus() == 2)
	{
		playerDied();
		setStatus(0);
	}

	return getStatus();
}

int GameState::getScore()
{
	std::stringstream converter;
	converter << getVariable("score");
	int score {stoi(converter.str())};

	return score;
}

void GameState::playerDied()
{
	resetEverything();
	addObject(new Player(500, 400, this));
	spawnObjects();
	subVariable("lives", 1);
	currentTime = 0;
	currentWave = 0;
	spawnModifier = 0;
}

void GameState::draw()
{
	if (getStatus() == -1)
	{
		checkScore();
		drawObjects();
		drawText("Game Over", 350, 20, 500, 200);
		std::string scoreText = "Score: ";
		if(record)
		{
			scoreText = "New Record: ";
			record = false;
		}
		std::string text = scoreText + std::to_string(int(getVariable("score")));
		drawText(text, 350, 300, 500, 250);
	}
	else
	{
		drawText("Score:", 0, 0, 100, 50);
		converter << getVariable("score");
		drawText(converter.str(), 100, 0, 80, 50);
		converter.str("");

		drawText("Lives:", 0, 60, 100, 50);
		converter << getVariable("lives");
		drawText(converter.str(), 100, 60, 40, 50);
		converter.str("");

		drawObjects();
	}
}

void GameState::reset()
{
	resetEverything();
	addObject(new Player(500, 400, this));
	spawnObjects();
	setVariable("lives", 3);
	setVariable("score", 0);
	currentTime = 0;
	currentWave = 0;
	spawnModifier = 0;
}

void GameState::checkScore()
{
	highScoreHandler highScore;
	int score {getScore()};
	if (highScore.isRecord(score))
	{
		highScore.setNewRecord(score);

		record = true;
	}
}

void GameState::spawnNewWave()
{
	currentTime = 0;
	++currentWave;
	if (spawnModifier < 10)
	{
		++spawnModifier;
	}
	for (int i = 0; i < spawnModifier; ++i)
	{
		addObject(new goEnemy((randInt(0,1) * 1500) - 100, randInt(100, 700), (currentWave * 10) + 50, this));
		addObject(new goEnemy(randInt(200, 1100), (randInt(0,1) * 1000) - 100, (currentWave * 10) + 50, this));
	}
	if (currentWave % 2 == 0)
	{
		for (int j = 0; j < currentWave / 2; ++j)
		{
			addObject(new ShootingEnemy(randInt(200, 1100), (randInt(0,1) * 1000) - 100, (currentWave * 10) + 70, this));
		}
	}
	addObject(new PickupScore((randInt(0,1) * 1600) - 200, randInt(100, 700), this));
}

int GameState::randInt(int min, int max)
{
	return (rand() % ((max + 1) - min)) + min;
}
