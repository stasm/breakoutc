#pragma once
#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include <GL/glew.h>
#endif

typedef struct Mesh {
	const GLfloat* vertices;
	const GLfloat* normals;
	const GLushort* indices;
	GLsizei vertex_count;
	GLsizei index_count;
} Mesh;

Mesh Cube;