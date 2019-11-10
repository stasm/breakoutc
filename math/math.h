#pragma once
#include <stdbool.h>

typedef float Vec2[2];
typedef float Mat2D[6];

void vec2_normalize(Vec2 out, Vec2 a);

void mat2d_create(Mat2D out);
void mat2d_from_translation(Mat2D out, Vec2 v);
void mat2d_get_translation(Mat2D out, Vec2 a);
void mat2d_rotate(Mat2D out, Mat2D a, float rad);
void mat2d_scale(Mat2D out, Mat2D a, Vec2 s);
void mat2d_multiply(Mat2D out, Mat2D a, Mat2D b);
void mat2d_invert(Mat2D out, Mat2D a);

#define sign(x) ((x > 0) - (x < 0))
#define abs(x) (x * sign(x))
