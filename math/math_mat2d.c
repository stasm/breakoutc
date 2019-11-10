#include <stdlib.h>
#include <math.h>
#include "math.h"

void mat2d_create(Mat2D out)
{
	out[0] = 1;
	out[1] = 0;
	out[2] = 0;
	out[3] = 1;
	out[4] = 0;
	out[5] = 0;
}

void mat2d_from_translation(Mat2D out, Vec2 v)
{
	out[0] = 1;
	out[1] = 0;
	out[2] = 0;
	out[3] = 1;
	out[4] = v[0];
	out[5] = v[1];
}

void mat2d_get_translation(Mat2D out, Vec2 a)
{
	out[0] = a[4];
	out[1] = a[5];
}

void mat2d_rotate(Mat2D out, Mat2D a, float rad)
{
	float s = (float)sin(rad);
	float c = (float)cos(rad);
	out[0] = a[0] * c + a[2] * s;
	out[1] = a[1] * c + a[3] * s;
	out[2] = a[0] * -s + a[2] * c;
	out[3] = a[1] * -s + a[3] * c;
	out[4] = a[4];
	out[5] = a[5];
}

void mat2d_scale(Mat2D out, Mat2D a, Vec2 v)
{
	out[0] = a[0] * v[0];
	out[1] = a[1] * v[0];
	out[2] = a[2] * v[1];
	out[3] = a[3] * v[1];
	out[4] = a[4];
	out[5] = a[5];
}

void mat2d_invert(Mat2D out, Mat2D a)
{
	float aa = a[0];
	float ab = a[1];
	float ac = a[2];
	float ad = a[3];
	float atx = a[4];
	float aty = a[5];

	float det = aa * ad - ab * ac;
	if (!det) {
		abort();
	}
	det = 1.0 / det;

	out[0] = ad * det;
	out[1] = -ab * det;
	out[2] = -ac * det;
	out[3] = aa * det;
	out[4] = (ac * aty - ad * atx) * det;
	out[5] = (ab * atx - aa * aty) * det;
}

void mat2d_multiply(Mat2D out, Mat2D a, Mat2D b)
{
	out[0] = a[0] * b[0] + a[2] * b[1];
	out[1] = a[1] * b[0] + a[3] * b[1];
	out[2] = a[0] * b[2] + a[2] * b[3];
	out[3] = a[1] * b[2] + a[3] * b[3];
	out[4] = a[0] * b[4] + a[2] * b[5] + a[4];
	out[5] = a[1] * b[4] + a[3] * b[5] + a[5];
}
