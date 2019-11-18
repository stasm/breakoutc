#pragma once
#include "com_render_basic.h"

enum RenderKind {
	RENDER_BASIC,
	RENDER_SHADED,
};

typedef struct {
	enum RenderKind kind;
	union {
		RenderBasic basic;
	} layout;
} Render;
