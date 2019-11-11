#include <stdio.h>
#include "game.h"

void* xmalloc(size_t size)
{
	void* ptr = malloc(size);
	if (ptr == NULL) {
		printf("Out of memory, malloc failed.");
		abort();
	}
	return ptr;
}

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

void game_start(Game* game, void (*update)(Game*, float))
{
	game->last_time = clock() - 1;

	for (;;) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				return;
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
		(*update)(game, (float)delta / CLOCKS_PER_SEC);
		game->last_time = current_time;
	}
}

