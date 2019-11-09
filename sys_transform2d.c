#include "sys_transform2d.h"
#include "math_mat2d.h"
#include "com_index.h"

int SYS_TRANSFORM_QUERY = HasTransform2D;

void sys_transform_update(Game* game, int entity)
{
	Transform2D* transform = game->AllTransform2D[entity];
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
		if ((game->world[i] & SYS_TRANSFORM_QUERY) == SYS_TRANSFORM_QUERY) {
			sys_transform_update(game, i);
		}
	}
}
