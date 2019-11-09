#pragma once

enum ComponentIndex {
	DRAW2D,
	TRANSFORM2D,
};

enum ComponentMask {
	HAS_DRAW2D = 1 << DRAW2D,
	HAS_TRANSFORM2D = 1 << TRANSFORM2D,
};
