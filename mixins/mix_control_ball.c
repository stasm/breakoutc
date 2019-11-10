#include <stdbool.h>
#include "../game.h"

void mix_control_ball(Game* game, int entity) {
	game->world[entity] |= HAS_CONTROL_BALL;
}
