/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** down_brush.c
*/

#include "main.h"

void	down_map(map_t *map, brush_t *brs, int i, int j)
{
	float res = 0;
	float power_const = 0;

	if ((res = is_brush_equation_valid(brs, i, j)) != -1) {
		power_const = (((res / brs->brush_radius) - 1) * -1);
		map->map_3d[i][j] -= brs->brush_strength * power_const;
	}
}

void	browse_map_down_brush(map_t *map, brush_t *brs)
{
	for (int i = 0; i < map->map_x; i++)
		for (int j = 0; j < map->map_y; j++)
			down_map(map, brs, i, j);
}

void	down_brush(map_t *map, brush_t *brs)
{
	if (is_brush_max_valid(brs, map) == 1)
		browse_map_down_brush(map, brs);
}
