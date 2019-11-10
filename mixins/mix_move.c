#include <stdbool.h>
#include "../game.h"

Move* mix_move(Game* game, int entity) {
	Move* move = (Move*)malloc(sizeof(Move));
	*move = (Move){
		.direction = {0, 0},
	};

	game->world[entity] |= HAS_MOVE;
	return game->move[entity] = move;
}
