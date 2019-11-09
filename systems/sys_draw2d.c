#include <SDL2/SDL.h>

#include "../game.h"
#include "../components/com_index.h"
#include "sys_draw2d.h"

int SYS_DRAW2D_QUERY = HAS_TRANSFORM2D;

void sys_draw2d(Game* game, float delta)
{
	SDL_SetRenderDrawColor(game->renderer, 255, 85, 85, 255);
	SDL_RenderClear(game->renderer);

	SDL_RenderPresent(game->renderer);
}
