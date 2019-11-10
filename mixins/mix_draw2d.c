#include <stdbool.h>
#include "../game.h"

Draw2D* mix_draw2d(Game* game, int entity) {
	Draw2D* draw = (Draw2D*)malloc(sizeof(Draw2D));
	*draw = (Draw2D){
		.width = 100,
		.height = 100,
		.color = {0, 0, 0, 0xFF},
	};

	game->world[entity] |= HAS_DRAW2D;
	return game->draw2d[entity] = draw;
}
