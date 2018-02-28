/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** brush
*/

#include "main.h"

void	up_corner_brush(map_t *map)
{
	if (map->x_max != -1 && map->y_max != -1)
		map->map_3d[map->x_max][map->y_max] += 0.3;
}

void	down_square_brush(map_t *map)
{
	if (map->x_max != -1 && map->y_max != -1) {
		map->map_3d[map->x_max][map->y_max] -= 0.5;
		map->map_3d[map->x_max][map->y_max + 1] -= 0.5;
		map->map_3d[map->x_max + 1][map->y_max] -= 0.5;
		map->map_3d[map->x_max + 1][map->y_max + 1] -= 0.5;
	}
}

void	down_corner_brush(map_t *map)
{
	if (map->x_max != -1 && map->y_max != -1)
		map->map_3d[map->x_max][map->y_max] += 0.3;
}

void	up_tool_brush(map_t *map, obj_t *obj)
{
	if (obj->num_tool == 0)
		up_corner_brush(map);
	else if (obj->num_tool == 1)
		up_square_brush(map);
	else if (obj->num_tool == 2)
		up_brush(map);
}

void	down_tool_brush(map_t *map, obj_t *obj)
{
	if (obj->num_tool == 0)
		down_corner_brush(map);
	else if (obj->num_tool == 1)
		down_square_brush(map);
}
