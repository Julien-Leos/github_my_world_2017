/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** init2
*/

#include "main.h"

void	init_color_tab(map_t *map)
{
	int r = 0;

	for (int i = 0; i < map->map_x; i++) {
		for (int j = 0; j < map->map_y; j++) {
			r = rand() % 20;
			map->color_tab[0][i][j] = RG(58 + r, 157 + r, 35 + r);
			map->color_tab[1][i][j] = RG(143 + r, 89 + r, 34 + r);
			map->color_tab[2][i][j] = RG(153 + r, 153 + r, 153 + r);
		}
	}
}

void	init_obj(obj_t *obj)
{
	obj->num_button = 0;
	obj->num_tool = 0;
}
