#include "../game.h"

void mix_control_paddle(Game* game, int entity) {
	game->world[entity] |= HAS_CONTROL_PADDLE;
}
