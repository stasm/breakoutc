#include "../game.h"

GLuint buffer(Mesh* mesh)
{
	GLuint vao, vertices_buffer, indices_buffer;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vertices_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertices_buffer);
	glBufferData(GL_ARRAY_BUFFER, mesh->vertex_count * sizeof(GLfloat), mesh->vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(BASIC_ATTR_POSITION);
	glVertexAttribPointer(BASIC_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glGenBuffers(1, &indices_buffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indices_buffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->index_count * sizeof(GLuint), mesh->indices, GL_STATIC_DRAW);

	glBindVertexArray(0);
	return vao;
}

Render* mix_render_basic(Game* game, int entity, Mesh* mesh)
{
	Render* render = xmalloc(sizeof(Render));
	*render = (Render){
		.kind = RENDER_BASIC,
		.layout = {
			.basic = {
				.material = &game->material_basic,
				.mesh = mesh,
				.vao = buffer(mesh),
				.color = {0},
			}
		}
	};

	game->world[entity] |= HAS_RENDER;
	return game->render[entity] = render;
}

