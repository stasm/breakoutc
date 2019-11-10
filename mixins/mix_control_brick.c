#include <stdbool.h>
#include "../game.h"

void mix_control_brick(Game* game, int entity) {
	game->world[entity] |= HAS_CONTROL_BRICK;
}
