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

void	which_select_square(window_t *win, map_t *map, settings_t *stg, brush_t *brs, int i, int j)
{
	sfVector2i m_pos = win->mouse_pos;

	if (calc_sqr(map->map_2d[i][j], map->map_2d[i][j + 1], m_pos) > 0 &&
	calc_sqr(map->map_2d[i][j], map->map_2d[i + 1][j], m_pos) < 0 &&
	calc_sqr(map->map_2d[i][j + 1], map->map_2d[i + 1][j + 1], m_pos) > 0 &&
	calc_sqr(map->map_2d[i + 1][j], map->map_2d[i + 1][j + 1], m_pos) < 0 &&
	is_mouse_on_toolbox(win->mouse_pos) == 0) {
		if (stg->rotation >= 0 && stg->rotation < 90) {
			brs->brush_max_x = (i > brs->brush_max_x) ? i : brs->brush_max_x;
			brs->brush_max_y = (j < brs->brush_max_y) ? j : brs->brush_max_y;
		} else if (stg->rotation >= 90 && stg->rotation < 180) {
			brs->brush_max_x = (i < brs->brush_max_x) ? i : brs->brush_max_x;
			brs->brush_max_y = (j < brs->brush_max_y) ? j : brs->brush_max_y;
		} else if (stg->rotation >= 180 && stg->rotation < 270) {
			brs->brush_max_x = (i < brs->brush_max_x) ? i : brs->brush_max_x;
			brs->brush_max_y = (j > brs->brush_max_y) ? j : brs->brush_max_y;
		} else if (stg->rotation >= 270 && stg->rotation <= 360) {
			brs->brush_max_x = (i > brs->brush_max_x) ? i : brs->brush_max_x;
			brs->brush_max_y = (j > brs->brush_max_y) ? j : brs->brush_max_y;
		}
	}
}
