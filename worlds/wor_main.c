#include "../game.h"
#include "../mixins/mix.h"

void world_main(Game* game)
{
	int paddle = create_entity(game);
	Transform2D* transform = mix_transform2d(game, paddle);
	transform->translation[0] = 100;
	transform->translation[1] = 100;
	Draw2D* draw = mix_draw2d(game, paddle);
	mix_control_paddle(game, paddle);
}