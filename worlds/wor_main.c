#include "../game.h"
#include "../mixins/mix_transform2d.h"
#include "../mixins/mix_draw2d.h"

void world_main(Game* game)
{
	int paddle = create_entity(game);
	Transform2D* transform = with_transform2d(game, paddle);
	transform->translation[0] = 100;
	transform->translation[1] = 100;
	Draw2D* draw = with_draw2d(game, paddle);
}