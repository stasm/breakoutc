#include "../game.h"

static int QUERY = HAS_MOVE | HAS_CONTROL_PADDLE;

static void update(Game* game, int entity)
{
	Move* move = game->move[entity];
	move->direction[0] = 0;

	if (game->input_state[SDL_SCANCODE_LEFT])
		move->direction[0] -= 1;

	if (game->input_state[SDL_SCANCODE_RIGHT])
		move->direction[0] += 1;
}

void sys_control_paddle(Game* game, float delta)
{
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if ((game->world[i] & QUERY) == QUERY) {
			update(game, i);
		}
	}
}
