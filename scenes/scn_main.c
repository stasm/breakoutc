#include "../game.h"
#include "../mixins/mix.h"

void scene_main(Game* game)
{
	int paddle = create_entity(game);
	Transform2D* transform = mix_transform2d(game, paddle);
	transform->translation[0] = 100;
	transform->translation[1] = 100;
	Draw2D* draw = mix_draw2d(game, paddle);
	draw->width = 100;
	draw->height = 20;
	draw->color[0] = 0xFF;
	draw->color[1] = 0xFF;
	draw->color[2] = 0x55;
	mix_control_paddle(game, paddle);
}