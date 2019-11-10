#include <SDL2/SDL.h>
#include <stdio.h>

#include "game.h"
#include "systems/sys.h"

int create_entity(Game* game)
{
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if (game->world[i] == 0) {
			return i;
		}
	}

	return -1;
}

void destroy_entity(Game* game, int entity)
{
	game->world[entity] = 0;
}

void update(Game* game, float delta)
{
	sys_control_paddle(game, delta);
	sys_control_ball(game, delta);
	sys_transform2d(game, delta);
	sys_draw2d(game, delta);
	sys_framerate(game, delta);
}

void game_start(Game* game)
{
	game->last_time = clock() - 1;

	for (;;) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				exit(0);
				break;
			case SDL_KEYDOWN:
				if (event.key.repeat == 0)
					game->input_state[event.key.keysym.scancode] = 1;
				break;
			case SDL_KEYUP:
				if (event.key.repeat == 0)
					game->input_state[event.key.keysym.scancode] = 0;
				break;
			default:
				break;
			}
		}

		clock_t current_time = clock();
		clock_t delta = current_time - game->last_time;
		update(game, (float)delta / CLOCKS_PER_SEC);
		game->last_time = current_time;
	}
}

