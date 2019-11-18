#include "../game.h"

void mix_camera(Game* game, int entity) {
	Camera* camera = xmalloc(sizeof(Camera));
	*camera = (Camera){
		.projection = {0},
		.view = {0},
		.pv = {0},
	};

	mat4_perspective(camera->projection,
		(float)game->viewport_width / (float)game->viewport_height, 1.0f, 0.1f, 100.0f);
	mat4_create(camera->view);
	// This should happen in sys_camera.
	mat4_multiply(camera->pv, camera->projection, camera->view);

	game->world[entity] |= HAS_CAMERA;
	game->camera[entity] = camera;
}