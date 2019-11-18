#include "../game.h"
#include "mat_common.h"

static const char* vertex = 
	"#version 300 es\n"
	"uniform mat4 pv;"
	"uniform mat4 world;"

	"layout(location = 1) in vec3 position;"

	"void main() {"
		"gl_Position = pv * world * vec4(position, 1.0);"
	"}"
;

static const char *fragment =
	"#version 300 es\n"
	"precision mediump float;"
	"uniform vec4 color;"

	"out vec4 frag_color;"

	"void main() {"
		"frag_color = color;"
	"}"
;

void mat_basic(BasicMaterial* material) {
	material->mode = GL_TRIANGLES;
	material->program = glCreateProgram();
	link_shaders(material->program, vertex, fragment);
	material->pv = glGetUniformLocation(material->program, "pv");
	material->world = glGetUniformLocation(material->program, "world");
	material->color = glGetUniformLocation(material->program, "color");
}