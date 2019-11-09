#include <stdbool.h>
#include "../game.h"
#include "../math/math_mat2d.h"

Draw2D* mix_draw2d(Game* game, int entity) {
	Draw2D* draw = (Draw2D*)malloc(sizeof(Draw2D));
	*draw = (Draw2D){
		.size = 50,
	};

	game->world[entity] |= HAS_DRAW2D;
	return game->draw2d[entity] = draw;
}
