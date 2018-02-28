/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** square
*/

#include "main.h"

void	draw_square(sfRenderWindow *win, sfCircleShape *circle, sfVector2f pos)
{
	sfCircleShape_setPosition(circle, pos);
	sfRenderWindow_drawCircleShape(win, circle, NULL);
}

void	which_select_square(window_t *win, map_t *map, int i, int j)
{
	sfVector2i m_pos = win->mouse_pos;

	if (calc_sqr(map->map_2d[i][j], map->map_2d[i][j + 1], m_pos) > 0 &&
	calc_sqr(map->map_2d[i][j], map->map_2d[i + 1][j], m_pos) < 0 &&
	calc_sqr(map->map_2d[i][j + 1], map->map_2d[i + 1][j + 1], m_pos) > 0 &&
	calc_sqr(map->map_2d[i + 1][j], map->map_2d[i + 1][j + 1], m_pos) < 0 &&
	is_mouse_on_toolbox(win->mouse_pos) == 0) {
		map->x_max = (i > map->x_max) ? i : map->x_max;
		map->y_max = (j > map->y_max) ? j : map->y_max;
	}
}

void	select_square(window_t *win, map_t *map)
{
	sfVector2f circle_pos = {0, 0};

	map->x_max = -1;
	map->y_max = -1;
	for (int i = 0; i < map->map_x - 1; i++)
		for (int j = 0; j < map->map_y - 1; j++)
			which_select_square(win, map, i, j);
	if (map->x_max != -1 && map->y_max != -1) {
		circle_pos.x = map->map_2d[map->x_max][map->y_max].x - 5;
		circle_pos.y = map->map_2d[map->x_max][map->y_max].y - 5;
		draw_square(win->window, map->mouse_circle, circle_pos);
		circle_pos.x = map->map_2d[map->x_max][map->y_max + 1].x - 5;
		circle_pos.y = map->map_2d[map->x_max][map->y_max + 1].y - 5;
		draw_square(win->window, map->mouse_circle, circle_pos);
		circle_pos.x = map->map_2d[map->x_max + 1][map->y_max].x - 5;
		circle_pos.y = map->map_2d[map->x_max + 1][map->y_max].y - 5;
		draw_square(win->window, map->mouse_circle, circle_pos);
		circle_pos.x = map->map_2d[map->x_max + 1][map->y_max + 1].x - 5;
		circle_pos.y = map->map_2d[map->x_max + 1][map->y_max + 1].y - 5;
		draw_square(win->window, map->mouse_circle, circle_pos);
	}
}
