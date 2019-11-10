#include "../game.h"
#include "../math/math.h"

static int QUERY = HAS_TRANSFORM2D | HAS_COLLIDE;

void compute_aabb(Transform2D* transform, Collide* collide)
{
	mat2d_get_translation(collide->center, transform->world);
	collide->min[0] = collide->center[0] - collide->size[0] / 2;
	collide->min[1] = collide->center[1] - collide->size[1] / 2;
	collide->max[0] = collide->center[0] + collide->size[0] / 2;
	collide->max[1] = collide->center[1] + collide->size[1] / 2;
}

void penetrate_aabb(float* hit, Collide* a, Collide* b) {
	float distance_x = a->center[0] - b->center[0];
	float penetration_x = a->size[0] / 2 + b->size[0] / 2 - abs(distance_x);

	float distance_y = a->center[1] - b->center[1];
	float penetration_y = a->size[1] / 2 + b->size[1] / 2 - abs(distance_y);

	if (penetration_x < penetration_y) {
		hit[0] = penetration_x * sign(distance_x);
		hit[1] = 0;
	}
	else {
		hit[0] = 0;
		hit[1] = penetration_y * sign(distance_y);
	}
}

bool intersect_aabb(Collide* a, Collide* b) {
	return a->min[0] < b->max[0]
		&& a->max[0] > b->min[0]
		&& a->min[1] < b->max[1]
		&& a->max[1] > b->min[1];
}

void sys_collide(Game* game, float delta)
{
	int all_colliders_count = 0;
	Collide* all_colliders[MAX_ENTITIES];
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if ((game->world[i] & QUERY) == QUERY) {
			Transform2D* transform = game->transform2d[i];
			Collide* collide = game->collide[i];

			if (collide->collision != NULL) {
				free(collide->collision);
				collide->collision = NULL;
			}
			compute_aabb(transform, collide);
			all_colliders[all_colliders_count] = collide;
			all_colliders_count++;
		}
	}

	for (int i = 0; i < all_colliders_count; i++) {
		Collide* collider = all_colliders[i];
		for (int j = 0; j < all_colliders_count; j++) {
			Collide* other = all_colliders[j];
			if (collider->entity != other->entity && intersect_aabb(collider, other)) {
				collider->collision = (Collision*)malloc(sizeof(Collision));
				collider->collision->entity = other->entity;
				penetrate_aabb(collider->collision->hit, collider, other);
			}
		}
	}
}
