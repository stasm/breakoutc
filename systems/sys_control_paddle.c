#include "../game.h"

static int QUERY = HAS_MOVE | HAS_CONTROL_PADDLE;

void sys_control_paddle_update(Game* game, int entity)
{
	float speed = 300.0;
	float x = 0;
	float y = 0;

	if (game->input_state[SDL_SCANCODE_LEFT])
		x += -1;

	if (game->input_state[SDL_SCANCODE_RIGHT])
		x += 1;

	if (game->input_state[SDL_SCANCODE_UP])
		y += -1;

	if (game->input_state[SDL_SCANCODE_DOWN])
		y += 1;

	Move* move = game->move[entity];
	move->direction[0] = x;
	move->direction[1] = y;
}

void sys_control_paddle(Game* game, float delta)
{
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if ((game->world[i] & QUERY) == QUERY) {
			sys_control_paddle_update(game, i);
		}
	}
}
