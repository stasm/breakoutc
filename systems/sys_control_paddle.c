#include "../game.h"

static int QUERY = HAS_TRANSFORM2D | HAS_CONTROL_PADDLE;

void sys_control_paddle_update(Game* game, int entity, float delta)
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

	Transform2D* transform = game->transform2d[entity];
	transform->translation[0] += x * speed * delta;
	transform->translation[1] += y * speed * delta;
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
