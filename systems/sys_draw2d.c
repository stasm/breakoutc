#include <SDL2/SDL.h>

#include "../game.h"
#include "../components/com_index.h"
#include "sys_draw2d.h"

static int QUERY = HAS_TRANSFORM2D | HAS_DRAW2D;

void draw_rect(Game* game, int entity) {
	Transform2D* transform = game->transform2d[entity];
	Draw2D* draw = game->draw2d[entity];
	SDL_Rect rect = {
		.x = transform->translation[0] - draw->size / 2,
		.y = transform->translation[1] - draw->size / 2,
		.w = draw->size,
		.h = draw->size,
	};
	SDL_SetRenderDrawColor(game->renderer, 0xFF, 0xFF, 0x55, 0xFF);
	SDL_RenderFillRect(game->renderer, &rect);
}

void sys_draw2d(Game* game, float delta)
{
	SDL_SetRenderDrawColor(game->renderer, 255, 85, 85, 255);
	SDL_RenderClear(game->renderer);

	for (int i = 0; i < MAX_ENTITIES; i++) {
		if ((game->world[i] & QUERY) == QUERY) {
			draw_rect(game, i);
		}
	}

	SDL_RenderPresent(game->renderer);
}
