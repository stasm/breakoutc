#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include <GL/glew.h>
#endif

void link_shaders(GLuint program, const char* vertex_source, const char* fragment_source)
{
	int source_length;
	GLint status;
	GLchar message[1024];

	GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	source_length = strlen(vertex_source);
	glShaderSource(vertex_shader, 1, (const GLchar**)&vertex_source, &source_length);
	glCompileShader(vertex_shader);
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE) {
		glGetShaderInfoLog(vertex_shader, 1024, NULL, message);
		fprintf(stderr, "Vertex shader compilation failed: %s\n", message);
		abort();
	}

	GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, (const GLchar**)&fragment_source, &source_length);
	glCompileShader(fragment_shader);
	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE) {
		glGetShaderInfoLog(fragment_shader, 1024, NULL, message);
		fprintf(stderr, "Fragment shader compilation failed: %s\n", message);
		abort();
	}

	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);
	glLinkProgram(program);

	glGetProgramiv(program, GL_LINK_STATUS, &status);
	if (status == GL_FALSE) {
		glGetProgramInfoLog(program, 1024, NULL, message);
		fprintf(stderr, "Shader linking failed: %s\n", message);
		abort();
	}
}