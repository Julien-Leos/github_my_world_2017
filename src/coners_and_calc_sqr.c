/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** corners
*/

#include "main.h"

float	calc_sqr(sfVector2f A, sfVector2f B, sfVector2i P)
{
	sfVector2f vector_D = {B.x - A.x, B.y - A.y};
	sfVector2f vector_T = {P.x - A.x, P.y - A.y};

	return ((vector_D.x * vector_T.y) - (vector_D.y * vector_T.x));
}

void	which_select_corner(window_t *win, map_t *map, int i, int j)
{
	if (map->map_2d[i][j].x > win->mouse_pos.x - (SCALING_X * map->zoom / 3) &&
	map->map_2d[i][j].x < win->mouse_pos.x + (SCALING_X * map->zoom / 3) &&
	map->map_2d[i][j].y > win->mouse_pos.y - (SCALING_Y * map->zoom / 3) &&
	map->map_2d[i][j].y < win->mouse_pos.y + (SCALING_Y * map->zoom / 3) &&
	is_mouse_on_toolbox(win->mouse_pos) == 0) {
		map->x_max = (i > map->x_max) ? i : map->x_max;
		map->y_max = (j > map->y_max) ? j : map->y_max;
	}
}

void	select_corner(window_t *win, map_t *map)
{
	sfVector2f circle_pos = {0, 0};

	map->x_max = -1;
	map->y_max = -1;
	for (int i = 0; i < map->map_x; i++)
		for (int j = 0; j < map->map_y; j++)
			which_select_corner(win, map, i, j);
	if (map->x_max != -1 && map->y_max != -1) {
		circle_pos.x = map->map_2d[map->x_max][map->y_max].x - 5;
		circle_pos.y = map->map_2d[map->x_max][map->y_max].y - 5;
		draw_square(win->window, map->mouse_circle, circle_pos);
	}
}
