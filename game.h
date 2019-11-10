#pragma once 

#include <SDL2/SDL.h>
#include <time.h>

#include "components/com_index.h"
#include "components/com_control_ball.h"
#include "components/com_draw2d.h"
#include "components/com_move.h"
#include "components/com_transform2d.h"

#define MAX_ENTITIES 100

typedef struct Game {
	int world[MAX_ENTITIES];
	ControlBall* control_ball[MAX_ENTITIES];
	Draw2D* draw2d[MAX_ENTITIES];
	Move* move[MAX_ENTITIES];
	Transform2D* transform2d[MAX_ENTITIES];

	int input_state[SDL_NUM_SCANCODES];
	int clear_color[4];

	clock_t last_time;
	SDL_Window* window;
	SDL_Renderer* renderer;

} Game;

int create_entity(Game*);
void destroy_entity(Game*, int);
void game_start(Game*, void (*)(Game*, float));
