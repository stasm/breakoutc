#pragma once

typedef float Vec2[2];
typedef float Mat2D[6];

void mat2d_create(float* matrix);
void mat2d_from_translation(float* out, float* v);
void mat2d_get_translation(float* out, float* a);
void mat2d_rotate(float* out, float* a, float rad);
void mat2d_scale(float* out, float* a, float* s);
void mat2d_multiply(float* out, float* a, float* b);
void mat2d_invert(float* out, float* a);

#define sign(x) ((x > 0) - (x < 0))
#define abs(x) (x * sign(x))
