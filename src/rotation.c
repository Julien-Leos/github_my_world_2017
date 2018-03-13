/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** rotation
*/

#include "main.h"

void	rotation_0_to_90(map_t *map, sfRenderWindow *win, sfRenderStates *st)
{
	for (int j = map->map_y - 1; j >= 0; j--)
		for (int i = 0; i <= map->map_x - 1; i++)
			draw_quads(map, win, st, (V2I){i, j});
}

void	rotation_90_to_180(map_t *map, sfRenderWindow *win, sfRenderStates *st)
{
	for (int i = map->map_x - 1; i >= 0; i--)
		for (int j = map->map_y - 1; j >= 0; j--)
			draw_quads(map, win, st, (V2I){i, j});
}

void	rotation_180_to_270(map_t *map, sfRenderWindow *win, sfRenderStates *st)
{
	for (int j = 0; j < map->map_y - 1 ; j++)
		for (int i = map->map_x - 1; i >= 0; i--)
			draw_quads(map, win, st, (V2I){i, j});
}

void	rotation_270_to_360(map_t *map, sfRenderWindow *win, sfRenderStates *st)
{
	for (int i = 0; i < map->map_x - 1; i++)
		for (int j = 0; j < map->map_y - 1 ; j++)
			draw_quads(map, win, st, (V2I){i, j});
}
