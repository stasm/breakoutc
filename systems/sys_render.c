#include <SDL2/SDL.h>
#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include <GL/glew.h>
#endif

#include "../game.h"

static int QUERY = HAS_TRANSFORM2D | HAS_RENDER;

void sys_render(Game* game, float delta)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Camera* camera = NULL;
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if (game->world[i] & HAS_CAMERA) {
			camera = game->camera[i];
			break;
		}
	}

	if (camera == NULL) {
		// Skip sys_render if there's no camera in the scene.
		return;
	}

	for (int i = 0; i < MAX_ENTITIES; i++) {
		if ((game->world[i] & QUERY) == QUERY) {
			Render* render = game->render[i];
			switch (render->kind) {
			case RENDER_BASIC:
				glUseProgram(render->layout.basic.material->program);
				glUniformMatrix4fv(render->layout.basic.material->pv, 1, GL_FALSE, camera->pv);
				glUniformMatrix4fv(render->layout.basic.material->world, 1, GL_FALSE, (GLfloat[]) {
					1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 2, -2, -7, 1
				});
				glUniform4fv(render->layout.basic.material->color, 1, render->layout.basic.color);

				glBindVertexArray(render->layout.basic.vao);
				glDrawElements(
					render->layout.basic.material->mode,
					render->layout.basic.mesh->index_count,
					GL_UNSIGNED_SHORT,
					NULL);
				glBindVertexArray(0);
			}
		}
	}

	SDL_GL_SwapWindow(game->window);
}
