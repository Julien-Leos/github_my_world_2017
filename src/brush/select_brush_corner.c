/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** select_corner.c
*/

#include "main.h"

void	init_coord_max(map_t *map, settings_t *stg, brush_t *brs)
{
	if (stg->rotation >= 0 && stg->rotation < 90) {
		brs->brush_max_x = -1;
		brs->brush_max_y = map->map_y + 1;
	}
	if (stg->rotation >= 90 && stg->rotation < 180) {
		brs->brush_max_x = map->map_x + 1;
		brs->brush_max_y = map->map_y + 1;
	}
	if (stg->rotation >= 180 && stg->rotation < 270) {
		brs->brush_max_x = map->map_x + 1;
		brs->brush_max_y = -1;
	}
	if (stg->rotation >= 270 && stg->rotation <= 360) {
		brs->brush_max_x = -1;
		brs->brush_max_y = -1;
	}
}

float	calc_sqr(V2F A, V2F B, V2I P)
{
	V2F vector_D = {B.x - A.x, B.y - A.y};
	V2F vector_T = {P.x - A.x, P.y - A.y};

	return ((vector_D.x * vector_T.y) - (vector_D.y * vector_T.x));
}

void	update_brush_max(settings_t *stg, brush_t *brs, int i, int j)
{
	int max_x = brs->brush_max_x;
	int max_y = brs->brush_max_y;

	if (stg->rotation >= 0 && stg->rotation < 90) {
		max_x = (i > max_x) ? i : max_x;
		max_y = (j < max_y) ? j : max_y;
	} else if (stg->rotation >= 90 && stg->rotation < 180) {
		max_x = (i < max_x) ? i : max_x;
		max_y = (j < max_y) ? j : max_y;
	} else if (stg->rotation >= 180 && stg->rotation < 270) {
		max_x = (i < max_x) ? i : max_x;
		max_y = (j > max_y) ? j : max_y;
	} else if (stg->rotation >= 270 && stg->rotation <= 360) {
		max_x = (i > max_x) ? i : max_x;
		max_y = (j > max_y) ? j : max_y;
	}
	brs->brush_max_x = max_x;
	brs->brush_max_y = max_y;
}

void	select_brush_corner(all_t *all, int i, int j)
{
	V2I m_pos = all->win->mouse_pos;
	V2F map_2d_0_0 = all->map->map_2d[i][j];
	V2F map_2d_0_1 = all->map->map_2d[i][j + 1];
	V2F map_2d_1_0 = all->map->map_2d[i + 1][j];
	V2F map_2d_1_1 = all->map->map_2d[i + 1][j + 1];

	if (calc_sqr(map_2d_0_0, map_2d_0_1, m_pos) > 0 &&
	calc_sqr(map_2d_0_0, map_2d_1_0, m_pos) < 0 &&
	calc_sqr(map_2d_0_1, map_2d_1_1, m_pos) > 0 &&
	calc_sqr(map_2d_1_0, map_2d_1_1, m_pos) < 0 &&
	is_mouse_on_toolbox(all->win->mouse_pos) == 0)
		update_brush_max(all->stg, all->brs, i, j);
}
