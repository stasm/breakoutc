#pragma once

typedef struct Collision {
	int entity;
	Vec2 hit;
} Collision ;

typedef struct Collide {
	int entity;
	Vec2 size;
	Vec2 min;
	Vec2 max;
	Vec2 center;
	Collision* collision;
} Collide;
