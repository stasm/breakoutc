#include <stdio.h>
#include "game.h"
#include "materials/mat.h"
#include "systems/sys.h"
#include "scenes/scn.h"

void update(Game* game, float delta)
{
	sys_control_paddle(game, delta);
	sys_control_ball(game, delta);
	sys_control_brick(game, delta);
	sys_move(game, delta);
	sys_transform2d(game, delta);
	sys_collide(game, delta);
	//sys_draw2d(game, delta);
	sys_render(game, delta);
	sys_framerate(game, delta);
}

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Failed to initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	Game game = (Game){
		.world = {0},
		.input_state = {0},
		.clear_color = {0, 0, 0, 0xFF},
		.window = NULL,
		.renderer = NULL,
		.context = NULL,
		.viewport_width = 854,
		.viewport_height = 480,
		.material_basic = {0},
	};

	game.window = SDL_CreateWindow("breakoutc",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		game.viewport_width, game.viewport_height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if (game.window == NULL) {
		printf("Failed to create window: %s\n", SDL_GetError());
		exit(1);
	}

	/*
	game.renderer = SDL_CreateRenderer(game.window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (game.renderer == NULL) {
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}
	*/

	game.context = SDL_GL_CreateContext(game.window);
	if (game.context == NULL) {
		printf("Failed to create context: %s\n", SDL_GetError());
		exit(1);
	}

#ifndef __APPLE__
	glewExperimental = GL_TRUE;
	GLenum glew_error = glewInit();
	if (glew_error != GLEW_OK) {
		printf("Failed to init GLEW: %s\n", glewGetErrorString(glew_error));
		exit(1);
	}
#endif

	SDL_GL_SetSwapInterval(1);

	glEnable(GL_PROGRAM_POINT_SIZE);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glFrontFace(GL_CW);

	mat_basic(&game.material_basic);

	scene_main(&game);
	game_start(&game, &update);

	SDL_GL_DeleteContext(game.context);
	//SDL_DestroyRenderer(game.renderer);
	SDL_DestroyWindow(game.window);
	SDL_Quit();

	return 0;
}
