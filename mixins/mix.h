#pragma once
#include "../game.h"

void mix_camera(Game* game, int entity);
Collide* mix_collide(Game* game, int entity);
ControlBall* mix_control_ball(Game* game, int entity);
void mix_control_brick(Game* game, int entity);
void mix_control_paddle(Game* game, int entity);
Draw2D* mix_draw2d(Game* game, int entity);
Move* mix_move(Game* game, int entity);
Render* mix_render_basic(Game* game, int entity, Mesh* mesh);
Transform2D* mix_transform2d(Game* game, int entity);
