#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <math.h>
#include <iostream>

#include "game.h"


using namespace std;


Game::Game() : bgMusic("res/audio/bg-music.wav") {}

void Game::run()
{
	// initialize SDLd
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		cerr << "Error initializing SDL" << endl;
		exit(1);
	}
	TTF_Init();

	// create the window
	SDL_Window* window = SDL_CreateWindow("SUPER SMASH KEBAB", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	// make the scaled rendering look smoother
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	// render at a virtual resolution then stretch to actual resolution
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);


	TextureInfo bg;
	TextureInfo bgMenu;

	bool running{true};

	TextureBank bank;

	if (!bank.requestTexture(bg, "res/img/bg.png", renderer))
	{
		running = false;
	}
	if (!bank.requestTexture(bgMenu, "res/img/bgmenu.png", renderer))
	{
		running = false;
	}

	GameState Game(&bank, renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
	MenuState Menu(&bank, renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
	State* currentState = &Menu;
	int stateStatus = 0;

	Uint32 beginTime{ SDL_GetTicks() };
	int endTime{ 0 };
	float deltaTime{ 0.0f };

	// Start background music
	bgMusic.play();

	// main loop
	while (running)
	{
		endTime = SDL_GetTicks();
		deltaTime = 0.001 * (endTime - beginTime);
		beginTime = endTime;

		// Handle exit, mute and shooting
		handleInput(running, currentState);

		if (stateStatus == 1 && currentState == &Menu)
		{
			currentState = &Game;
			stateStatus = 0;
			currentState->setStatus(0);
		}
		else if (stateStatus == -1 && currentState == &Menu)
		{
			running = false;
		}
		else if (stateStatus == -1 && currentState == &Game)
		{
			SDL_Delay(2000);
			currentState->reset();
			currentState = &Menu;
			stateStatus = 0;
			currentState->setStatus(0);
		}
		/*else if (stateStatus == 1 && currentState == &Game)
		{
			currentState->draw();
			currentState->setStatus(-1);
		}*/


		// clear screen
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_Rect bgP = bg.getRect();
		if (currentState == &Menu)
		{
			SDL_RenderCopy(renderer, bgMenu.getTexture(), &bgP, nullptr);
		}
		else
		{
			SDL_RenderCopy(renderer, bg.getTexture(), &bgP, nullptr);
		}


		// Update screen
		stateStatus = currentState->update(deltaTime);

		// draw things
		currentState->draw();

		// show the newly drawn things
		SDL_RenderPresent(renderer);

		// wait before drawing the next frame
		SDL_Delay(10);

	}

	// free memory
	bank.destroyTextures();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
}


void Game::handleInput(bool & running, State* myGame)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			running = false;
		}
		else if (event.type == SDL_KEYDOWN) {

			// If user quits
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				running = false;
			}
			else if (event.key.keysym.sym == SDLK_q)
			{
				running = false;
			}

			// If user mutes/unmutes music
			if (event.key.keysym.sym == SDLK_m)
			{
				bgMusic.alternate();
			}
		}

		if(event.type == SDL_MOUSEBUTTONDOWN && myGame->getName() == "game")
		{
			int relativeMouseX;
			int relativeMouseY;
			SDL_GetMouseState(&relativeMouseX, &relativeMouseY);
			relativeMouseX -= myGame->requestObject("player")->getX();
			relativeMouseY -= myGame->requestObject("player")->getY();
			myGame->addObject(new Bullet(atan2(relativeMouseY, relativeMouseX), "bullet", myGame->requestObject("player")->getX(), myGame->requestObject("player")->getY(), myGame));
		}
	}
}

int Game::getScreenHeight() const
{
	return SCREEN_HEIGHT;
}

int Game::getScreenWidth() const
{
	return SCREEN_WIDTH;
}
