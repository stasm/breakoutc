#include <SDL2/SDL.h>
#include "../game.h"

static int QUERY = HAS_TRANSFORM2D | HAS_DRAW2D;

void draw_rect(Game* game, int entity) {
	Transform2D* transform = game->transform2d[entity];
	Draw2D* draw = game->draw2d[entity];
	SDL_Rect rect = {
		.x = transform->translation[0] - draw->width / 2,
		.y = transform->translation[1] - draw->height / 2,
		.w = draw->width,
		.h = draw->height,
	};
	SDL_SetRenderDrawColor(game->renderer,
		draw->color[0],
		draw->color[1],
		draw->color[2],
		draw->color[3]);
	SDL_RenderFillRect(game->renderer, &rect);
}

void sys_draw2d(Game* game, float delta)
{
	SDL_SetRenderDrawColor(game->renderer,
		game->clear_color[0],
		game->clear_color[1],
		game->clear_color[2],
		game->clear_color[3]);
	SDL_RenderClear(game->renderer);

	for (int i = 0; i < MAX_ENTITIES; i++) {
		if ((game->world[i] & QUERY) == QUERY) {
			draw_rect(game, i);
		}
	}

	SDL_RenderPresent(game->renderer);
}
