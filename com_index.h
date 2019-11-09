#pragma once

enum ComponentIndex {
	GetDraw2D,
	GetTransform2D,
};

enum ComponentMask {
	HasDraw2D = 1 << GetDraw2D,
	HasTransform2D = 1 << GetTransform2D,
};
