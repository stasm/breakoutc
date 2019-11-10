#include "../game.h"

static int QUERY = HAS_TRANSFORM2D | HAS_MOVE | HAS_CONTROL_BALL | HAS_COLLIDE;

void sys_control_ball_update(Game* game, int entity)
{
	Transform2D* transform = game->transform2d[entity];
	ControlBall* control = game->control_ball[entity];

	if (transform->translation[0] < 0) {
		transform->translation[0] = 0;
		control->direction[0] *= -1;
	}

	if (transform->translation[0] > game->viewport_width) {
		transform->translation[0] = game->viewport_width;
		control->direction[0] *= -1;
	}

	if (transform->translation[1] < 0) {
		transform->translation[1] = 0;
		control->direction[1] *= -1;
	}

	if (transform->translation[1] > game->viewport_height) {
		transform->translation[1] = game->viewport_height;
		control->direction[1] *= -1;
	}

	Collide* collide = game->collide[entity];
	if (collide->collision != NULL) {
		if (collide->collision->hit[0]) {
			transform->translation[0] += collide->collision->hit[0];
			control->direction[0] *= -1;
		}
		if (collide->collision->hit[1]) {
			transform->translation[1] += collide->collision->hit[1];
			control->direction[1] *= -1;
		}
	}

	Move* move = game->move[entity];
	move->direction[0] = control->direction[0];
	move->direction[1] = control->direction[1];
}

void sys_control_ball(Game* game, float delta)
{
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if ((game->world[i] & QUERY) == QUERY) {
			sys_control_ball_update(game, i);
		}
	}
}
