#include "../game.h"

static int QUERY = HAS_TRANSFORM2D | HAS_CONTROL_PADDLE;

void sys_control_paddle_update(Game* game, int entity, float delta)
{
	float direction[2] = { 1, 1 };
	float speed = 300.0;

	Transform2D* transform = game->transform2d[entity];
	transform->translation[0] += direction[0] * speed * delta;
	transform->translation[1] += direction[1] * speed * delta;
	transform->dirty = true;
}

void sys_control_paddle(Game* game, float delta)
{
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if ((game->world[i] & QUERY) == QUERY) {
			sys_control_paddle_update(game, i, delta);
		}
	}
}
