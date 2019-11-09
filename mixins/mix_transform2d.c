#include <stdbool.h>
#include "../components/com_index.h"
#include "../components/com_transform2d.h"
#include "../math/math_mat2d.h"
#include "../game.h"

void create_transform2d(Game* game, int entity) {
	Transform2D* transform = (Transform2D*)malloc(sizeof(Transform2D));
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

	game->world[entity] |= HasTransform2D;
	game->AllTransform2D[entity] = transform;
}
