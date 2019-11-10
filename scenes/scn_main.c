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
		transform->translation[0] = game->viewport_width / 2;
		transform->translation[1] = game->viewport_height - 20;

		Draw2D* draw = mix_draw2d(game, entity);
		draw->width = 100;
		draw->height = 20;
		draw->color[0] = 0xFF;
		draw->color[1] = 0x00;
		draw->color[2] = 0x00;

		mix_control_paddle(game, entity);

		Move* move = mix_move(game, entity);
		move->speed = 500;

		Collide* collide = mix_collide(game, entity);
		collide->size[0] = 100;
		collide->size[1] = 20;
	}

	{
		// Ball
		int entity = create_entity(game);

		Transform2D* transform = mix_transform2d(game, entity);
		transform->translation[0] = game->viewport_width / 2;
		transform->translation[1] = game->viewport_height - 100;

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
		move->speed = 300;

		Collide* collide = mix_collide(game, entity);
		collide->size[0] = 20;
		collide->size[1] = 20;
	}

	int col_count = 5;
	int row_count = 5;
	int brick_width = 100;
	int brick_height = 20;
	int padding = 10;

	int brick_grid_width = brick_width * col_count + padding * (col_count - 1);
	int top_left_x = (game->viewport_width - brick_grid_width) / 2;
	int top_left_y = 50;

	for (int row = 0; row < row_count; row++) {
		int y = top_left_y + row * (brick_height + padding) + brick_height / 2;
		for (int col = 0; col < col_count; col++) {
			int x = top_left_x + col * (brick_width + padding) + brick_width / 2;

			// Brick
			int entity = create_entity(game);

			Transform2D* transform = mix_transform2d(game, entity);
			transform->translation[0] = x;
			transform->translation[1] = y;

			Draw2D* draw = mix_draw2d(game, entity);
			draw->width = 100;
			draw->height = 20;
			draw->color[0] = 0x00;
			draw->color[1] = 0xFF;
			draw->color[2] = 0x55;

			Collide* collide = mix_collide(game, entity);
			collide->size[0] = 100;
			collide->size[1] = 20;
		}
	}
}