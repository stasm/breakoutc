#pragma once

typedef struct Transform2D {
	Mat2D world;
	Mat2D self;
	Vec2 translation;
	float rotation;
	Vec2 scale;
	bool dirty;
} Transform2D;
