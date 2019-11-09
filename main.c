#include <SDL2/SDL.h>
#include <stdio.h>
#include <time.h>
#include "game.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Failed to initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	Game game = (Game){
		.world = {0},
		.window = NULL,
		.renderer = NULL
	};

	game.window = SDL_CreateWindow("breakoutc",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (game.window == NULL) {
		printf("Failed to create window: %s\n", SDL_GetError());
		exit(1);
	}

	game.renderer = SDL_CreateRenderer(game.window, -1, SDL_RENDERER_ACCELERATED);
	if (game.renderer == NULL) {
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}

	game_start(&game);

	//Destroy window
	SDL_DestroyWindow(game.window);

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}
