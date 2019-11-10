#pragma once
#include <stdbool.h>

typedef struct Collision {
	int entity;
	float hit[2];
} Collision ;

typedef struct Collide {
	int entity;
	float size[2];
	float min[2];
	float max[2];
	float center[2];
	Collision* collision;
} Collide;
