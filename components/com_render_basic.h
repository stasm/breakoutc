#pragma once

typedef struct {
	GLenum mode;
	GLuint program;
	GLint pv;
	GLint world;
	GLint color;

} BasicMaterial;

enum BasicAttribute {
	BASIC_ATTR_POSITION = 1
};

typedef struct {
	BasicMaterial* material;
	Mesh* mesh;
	GLuint vao;
	Vec4 color;
} RenderBasic;
