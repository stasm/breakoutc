#pragma once
#include "../game.h"

ControlBall* mix_control_ball(Game*, int);
void mix_control_paddle(Game*, int);
Draw2D* mix_draw2d(Game*, int);
Move* mix_move(Game*, int);
Transform2D* mix_transform2d(Game*, int);
