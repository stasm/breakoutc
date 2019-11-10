#include <stdbool.h>
#include "../game.h"

ControlBall* mix_control_ball(Game* game, int entity) {
	ControlBall* control = malloc(sizeof(ControlBall));
	*control = (ControlBall){
		.direction = {0, 0},
	};

	game->world[entity] |= HAS_CONTROL_BALL;
	return game->control_ball[entity] = control;
}
