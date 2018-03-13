/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** level_brush.c
*/

#include "main.h"

void	set_new_reference_altitude(map_t *map, brush_t *brs)
{
	brs->brush_altitude = map->map_3d[brs->brush_max_x][brs->brush_max_y];
}

void	level_map(map_t *map, brush_t *brs, int i, int j)
{
	float res = 0;
	float power_const = 0;
	float diff_altitude = 0;

	if ((res = is_brush_equation_valid(brs, i, j)) != -1) {
		power_const = (((res / brs->brush_radius) - 1) * -1);
		diff_altitude = map->map_3d[i][j] - brs->brush_altitude;
		if (diff_altitude >= -0.5 && diff_altitude <= 0.5)
			map->map_3d[i][j] = brs->brush_altitude;
		else if (map->map_3d[i][j] < brs->brush_altitude)
			map->map_3d[i][j] += brs->brush_strength * power_const;
		else if (map->map_3d[i][j] > brs->brush_altitude)
			map->map_3d[i][j] -= brs->brush_strength * power_const;
	}
}

void	browse_map_level_brush(map_t *map, brush_t *brs)
{
	for (int i = 0; i < map->map_x; i++)
		for (int j = 0; j < map->map_y; j++)
			level_map(map, brs, i, j);
}

void	level_brush(map_t *map, brush_t *brs)
{
	if (is_brush_max_valid(brs, map) == 1) {
		if (brs->brush_altitude == -1)
			set_new_reference_altitude(map, brs);
		browse_map_level_brush(map, brs);
	}
}
