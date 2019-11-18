#pragma once
#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include <GL/glew.h>
#endif

int link_shaders(GLuint program, const char* vertex_source, const char* fragment_source);
