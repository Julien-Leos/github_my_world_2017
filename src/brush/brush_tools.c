/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** brush_tools.c
*/

#include "main.h"

int	is_brush_max_valid(brush_t *brs, map_t *map)
{
	if (brs->brush_max_x >= 0 && brs->brush_max_x < map->map_x &&
	brs->brush_max_y >= 0 && brs->brush_max_y < map->map_y)
		return (1);
	return (0);
}

float	is_brush_equation_valid(brush_t *brs, int i, int j)
{
	float res = 0;
	int power_x = pow(i - brs->brush_max_x, 2);
	int power_y = pow(j - brs->brush_max_y, 2);

	if ((res = sqrt(power_x + power_y)) <= brs->brush_radius)
		return (res);
	return (-1);
}

void	which_brush(map_t *map, obj_t *obj, brush_t *brs)
{
	if (obj->num_tool == 0)
		up_brush(map, brs);
	else if (obj->num_tool == 1)
		down_brush(map, brs);
	else if (obj->num_tool == 2)
		level_brush(map, brs);
}
