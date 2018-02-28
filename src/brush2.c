/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** brush2
*/

#include "main.h"

void	select_brush(window_t *win, map_t *map)
{

	sfVector2f circle_pos = {0, 0};

	map->x_max = -1;
	map->y_max = -1;
	for (int i = 0; i < map->map_x - 1; i++)
		for (int j = 0; j < map->map_y - 1; j++)
			which_select_square(win, map, i, j);
	if (map->x_max != -1 && map->y_max != -1) {
		for (int i = 0; i < map->map_x; i++) {
			for (int j = 0; j < map->map_y; j++) {
				if (sqrt(pow(i - map->x_max, 2) + pow(j - map->y_max, 2)) <= map->radius) {
					circle_pos.x = map->map_2d[i][j].x - 5;
					circle_pos.y = map->map_2d[i][j].y - 5;
					draw_square(win->window, map->mouse_circle, circle_pos);
				}
			}
		}
	}
}

void	up_square_brush(map_t *map)
{
	if (map->x_max != -1 && map->y_max != -1) {
		map->map_3d[map->x_max][map->y_max] += 0.3;
		map->map_3d[map->x_max][map->y_max + 1] += 0.3;
		map->map_3d[map->x_max + 1][map->y_max] += 0.3;
		map->map_3d[map->x_max + 1][map->y_max + 1] += 0.3;
	}
}

void	up_brush(map_t *map)
{
	float res = 0;

	if (map->x_max != -1 && map->y_max != -1) {
		for (int i = 0; i < map->map_x; i++) {
			for (int j = 0; j < map->map_y; j++) {
				if ((res = sqrt(pow(i - map->x_max, 2) + pow(j - map->y_max, 2))) <= map->radius) {
					map->map_3d[i][j] += map->power * (((res / map->radius) - 1) * -1);
				}
			}
		}
	}
}
