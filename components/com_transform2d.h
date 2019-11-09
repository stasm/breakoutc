#pragma once
#include <stdbool.h>

typedef struct Transform2D {
	float world[6];
	float self[6];
	float translation[2];
	float rotation;
	float scale[2];
	bool dirty;
} Transform2D;
