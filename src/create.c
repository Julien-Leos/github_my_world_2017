/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** create
*/

#include "main.h"

V2F project_iso_point(sfVector3f crd, settings_t *stg, map_t *map)
{
	V2F vec = {0, 0};
	double rt = (stg->rotation / 180.0 * M_PI);
	double ic = (stg->inclinaison / 180.0 * M_PI);
	int x0 = 0;
	int y0 = 0;

	if (map->map_x % 2 == 0) {
		x0 = ((SCALING_X * stg->zoom * (map->map_x - 1)) / 2);
		y0 = ((SCALING_Y * stg->zoom * (map->map_y - 1)) / 2);
	} else {
		x0 = ((SCALING_X * stg->zoom * map->map_x) / 2);
		y0 = ((SCALING_Y * stg->zoom * map->map_y) / 2);
	}
	vec.x = (crd.x - x0) * cos (rt) + (crd.y - y0) * sin (rt) + x0;
	vec.y = - (crd.x - x0) * sin (rt) + (crd.y - y0) * cos (rt) + y0;
	vec.y = (vec.y - y0) * cos (ic) - (crd.z) * sin (ic) + y0;
	vec.x += (1920 / 2) - x0 + stg->offset_x;
	vec.y += (1080 / 2) - y0 + stg->offset_y;
	return(vec);
}

void	create_perlin_map_sub(float *value, unsigned int *rdm, int i, int j)
{
	value[2] = 1;
	value[3] = 1;
	value[4] = 0;
	value[8] = 4;
	for (int e = 0; e < value[8]; e++) {
		value[6] = (i + 0.5) / SCALING_X;
		value[7] = (j + 0.5) / SCALING_Y;
		value[5] = get_perlin_noise_value(value[6], value[7], rdm);
		value[4] += value[5] * value[2];
		value[2] *= value[0];
		value[3] *= value[1];
	}
}

float	**create_perlin_map(map_t *map)
{
	float **map_3d = malloc(sizeof(int*) * map->map_x);
	unsigned int *rdm = generate_randomised_tab();
	float *value = malloc(sizeof(float) * 9);

	value[0] = 0.57;
	value[1] = 1.72;
	value[2] = 0;
	value[3] = 0;
	value[4] = 0;
	value[5] = 0;
	value[6] = 0;
	value[7] = 0;
	for (int i = 0; i < map->map_x; i++) {
		map_3d[i] = malloc(sizeof(int) * map->map_y);
		for (int j = 0; j < map->map_y; j++) {
			create_perlin_map_sub(value, rdm, i, j);
			map_3d[i][j] = value[4] * 30;
		}
	}
	return (map_3d);
}
