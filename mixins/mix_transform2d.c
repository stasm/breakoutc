#include "../game.h"

Transform2D* mix_transform2d(Game* game, int entity) {
	Transform2D* transform = xmalloc(sizeof(Transform2D));
	*transform = (Transform2D){
		.world = {0},
		.self = {0},
		.translation = {0},
		.rotation = 0,
		.scale = {1, 1},
		.dirty = true,
	};

	mat2d_create(transform->world);
	mat2d_create(transform->self);

	game->world[entity] |= HAS_TRANSFORM2D;
	return game->transform2d[entity] = transform;
}
