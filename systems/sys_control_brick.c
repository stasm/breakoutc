#include "../game.h"

static int QUERY = HAS_CONTROL_BRICK | HAS_COLLIDE;

static void update(Game* game, int entity)
{
	Collide* collide = game->collide[entity];
	if (collide->collision != NULL) {
		destroy_entity(game, entity);
	}
}

void sys_control_brick(Game* game, float delta)
{
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if ((game->world[i] & QUERY) == QUERY) {
			update(game, i);
		}
	}
}
