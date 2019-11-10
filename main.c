#include <SDL2/SDL.h>
#include <stdio.h>
#include <time.h>
#include "game.h"
#include "systems/sys.h"
#include "scenes/scn.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

void update(Game* game, float delta)
{
	sys_control_paddle(game, delta);
	sys_control_ball(game, delta);
	sys_transform2d(game, delta);
	sys_draw2d(game, delta);
	sys_framerate(game, delta);
}

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Failed to initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	Game game = (Game){
		.world = {0},
		.input_state = {0},
		.clear_color = {0, 0, 0, 0xFF},
		.window = NULL,
		.renderer = NULL
	};

	game.window = SDL_CreateWindow("breakoutc",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (game.window == NULL) {
		printf("Failed to create window: %s\n", SDL_GetError());
		exit(1);
	}

	game.renderer = SDL_CreateRenderer(game.window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (game.renderer == NULL) {
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}

	scene_main(&game);
	game_start(&game, &update);

	SDL_DestroyRenderer(game.renderer);
	SDL_DestroyWindow(game.window);
	SDL_Quit();

	return 0;
}
