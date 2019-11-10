#include "../game.h"

static int QUERY = HAS_TRANSFORM2D | HAS_MOVE;

static void update(Game* game, int entity, float delta)
{
	Transform2D* transform = game->transform2d[entity];
	Move* move = game->move[entity];
	if (move->direction[0] || move->direction[1]) {
		transform->translation[0] += move->direction[0] * move->speed * delta;
		transform->translation[1] += move->direction[1] * move->speed * delta;
		transform->dirty = true;
	}
}

void sys_move(Game* game, float delta)
{
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if ((game->world[i] & QUERY) == QUERY) {
			update(game, i, delta);
		}
	}
}
