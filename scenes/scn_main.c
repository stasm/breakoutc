#include "../game.h"
#include "../mixins/mix.h"

void scene_main(Game* game)
{
	srand(time(NULL));
	(void)rand();

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
		Move* move = mix_move(game, entity);
		move->speed = 500;
	}

	for (int i = 0; i < 10; i++) {
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
		ControlBall* control = mix_control_ball(game, entity);
		float angle = -(float)rand() / RAND_MAX * M_PI;
		control->direction[0] = cos(angle);
		control->direction[1] = sin(angle);
		Move* move = mix_move(game, entity);
		move->speed = 250;
	}
}