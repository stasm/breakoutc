#include <SDL2/SDL.h>
#include <stdio.h>
#include "../game.h"

void sys_framerate(Game* game, float delta)
{
	char fps[20];
	snprintf(fps, 20, "Frame: %4.3fs", delta);
	SDL_SetWindowTitle(game->window, fps);
}
