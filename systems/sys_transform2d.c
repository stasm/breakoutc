#include "../game.h"

static int QUERY = HAS_TRANSFORM2D;

static void update(Game* game, int entity)
{
	Transform2D* transform = game->transform2d[entity];
	if (transform->dirty)
	{
		transform->dirty = false;
		mat2d_from_translation(transform->world, transform->translation);
		mat2d_rotate(transform->world, transform->world, transform->rotation);
		mat2d_scale(transform->world, transform->world, transform->scale);

		mat2d_invert(transform->self, transform->world);
	}
}

void sys_transform2d(Game* game, float delta)
{
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if ((game->world[i] & QUERY) == QUERY) {
			update(game, i);
		}
	}
}
