#include "../game.h"

static int QUERY = HAS_TRANSFORM2D | HAS_CONTROL_BALL;

void sys_control_ball_update(Game* game, int entity, float delta)
{
	float speed = 200.0;

	Transform2D* transform = game->transform2d[entity];
	transform->translation[0] += speed * delta;
	transform->translation[1] += speed * delta;
	transform->dirty = true;
}

void sys_control_ball(Game* game, float delta)
{
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if ((game->world[i] & QUERY) == QUERY) {
			sys_control_ball_update(game, i, delta);
		}
	}
}
