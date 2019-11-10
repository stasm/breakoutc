#include "../game.h"
#include "../mixins/mix.h"

void scene_main(Game* game)
{
	{
		// Paddle
		int entity = create_entity(game);
		Transform2D* transform = mix_transform2d(game, entity);
		transform->translation[0] = 100;
		transform->translation[1] = 100;
		Draw2D* draw = mix_draw2d(game, entity);
		draw->width = 100;
		draw->height = 20;
		draw->color[0] = 0xFF;
		draw->color[1] = 0x00;
		draw->color[2] = 0x00;
		mix_control_paddle(game, entity);
	}

	{
		// Ball
		int entity = create_entity(game);
		Transform2D* transform = mix_transform2d(game, entity);
		transform->translation[0] = 300;
		transform->translation[1] = 300;
		Draw2D* draw = mix_draw2d(game, entity);
		draw->width = 20;
		draw->height = 20;
		draw->color[0] = 0xFF;
		draw->color[1] = 0xFF;
		draw->color[2] = 0x00;
		mix_control_ball(game, entity);
	}
}