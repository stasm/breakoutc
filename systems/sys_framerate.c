#include <SDL2/SDL.h>
#include <stdio.h>

#include "sys_framerate.h"

void sys_framerate(Game* game, float delta)
{
	char fps[20];
	sprintf(fps, "Frame: %4.3fs", delta);
	SDL_SetWindowTitle(game->window, fps);
}
