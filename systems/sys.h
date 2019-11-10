#pragma once
#include "../game.h"

void sys_control_ball(Game* game, float delta);
void sys_control_paddle(Game* game, float delta);
void sys_draw2d(Game* game, float delta);
void sys_framerate(Game* game, float delta);
void sys_move(Game* game, float delta);
void sys_transform2d(Game* game, float delta);
