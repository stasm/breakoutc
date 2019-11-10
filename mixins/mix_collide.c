#include <stdbool.h>
#include "../game.h"

Collide* mix_collide(Game* game, int entity) {
	Collide* collide = malloc(sizeof(Collide));
	*collide = (Collide){
		.entity = entity,
		.size = {0, 0},
		.min = {0, 0},
		.max = {0, 0},
		.center = {0, 0},
		.collision = NULL,
	};

	game->world[entity] |= HAS_COLLIDE;
	return game->collide[entity] = collide;
}
