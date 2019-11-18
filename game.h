#pragma once

#define _USE_MATH_DEFINES

#include <SDL2/SDL.h>
#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include <GL/glew.h>
#endif
#include <time.h>

#include "math/math.h"
#include "meshes/mesh.h"
#include "components/com_index.h"
#include "components/com_camera.h"
#include "components/com_collide.h"
#include "components/com_control_ball.h"
#include "components/com_draw2d.h"
#include "components/com_move.h"
#include "components/com_render.h"
#include "components/com_transform2d.h"

#define MAX_ENTITIES 100

typedef struct Game {
	int world[MAX_ENTITIES];
	Camera* camera[MAX_ENTITIES];
	Collide* collide[MAX_ENTITIES];
	ControlBall* control_ball[MAX_ENTITIES];
	Draw2D* draw2d[MAX_ENTITIES];
	Move* move[MAX_ENTITIES];
	Render* render[MAX_ENTITIES];
	Transform2D* transform2d[MAX_ENTITIES];

	int input_state[SDL_NUM_SCANCODES];
	int clear_color[4];

	clock_t last_time;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_GLContext context;

	BasicMaterial material_basic;

	int viewport_width;
	int viewport_height;

} Game;

void* xmalloc(size_t size);
int create_entity(Game* game);
void destroy_entity(Game* game, int entity);
void game_start(Game* game, void (*update)(Game*, float));
