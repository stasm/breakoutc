#include <stdlib.h>
#include <math.h>
#include "math.h"

void vec2_normalize(Vec2 out, Vec2 a) {
	float len = a[0] * a[0] + a[1] * a[1];
	if (len > 0) {
		len = 1 / sqrt(len);
	}
	out[0] = a[0] * len;
	out[1] = a[1] * len;
}
