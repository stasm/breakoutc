#include "../game.h"

static int QUERY = HAS_MOVE | HAS_CONTROL_BALL;

void sys_control_ball_update(Game* game, int entity)
{
	Move* move = game->move[entity];
	move->direction[0] = 1;
	move->direction[1] = 1;
}

void sys_control_ball(Game* game, float delta)
{
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if ((game->world[i] & QUERY) == QUERY) {
			sys_control_ball_update(game, i);
		}
	}
}
