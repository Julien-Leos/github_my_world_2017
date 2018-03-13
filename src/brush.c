/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** brush2
*/

#include "main.h"

float	calc_sqr(sfVector2f A, sfVector2f B, sfVector2i P)
{
	sfVector2f vector_D = {B.x - A.x, B.y - A.y};
	sfVector2f vector_T = {P.x - A.x, P.y - A.y};

	return ((vector_D.x * vector_T.y) - (vector_D.y * vector_T.x));
}

void	init_coord_max(map_t *map, settings_t *stg, brush_t *brs)
{
	if (stg->rotation >= 0 && stg->rotation < 90) {
		brs->brush_max_x = -1;
		brs->brush_max_y = map->map_y + 1;
	} else if (stg->rotation >= 90 && stg->rotation < 180) {
		brs->brush_max_x = map->map_x + 1;
		brs->brush_max_y = map->map_y + 1;
	} else if (stg->rotation >= 180 && stg->rotation < 270) {
		brs->brush_max_x = map->map_x + 1;
		brs->brush_max_y = -1;
	} else if (stg->rotation >= 270 && stg->rotation <= 360) {
		brs->brush_max_x = -1;
		brs->brush_max_y = -1;
	}
}

void	select_brush(window_t *win, map_t *map, settings_t *stg, brush_t *brs)
{
	sfVector2f circle_pos = {0, 0};

	init_coord_max(map, stg, brs);
	for (int i = 0; i < map->map_x - 1; i++) {
		for (int j = 0; j < map->map_y - 1; j++) {
			which_select_square(win, map, stg, brs, i, j);
		}
	}
	if (brs->brush_max_x >= 0 && brs->brush_max_x < map->map_x && brs->brush_max_y >= 0 && brs->brush_max_y < map->map_y) {
		for (int i = 0; i < map->map_x; i++) {
			for (int j = 0; j < map->map_y; j++) {
				if (sqrt(pow(i - brs->brush_max_x, 2) + pow(j - brs->brush_max_y, 2)) <= brs->brush_radius) {
					circle_pos.x = map->map_2d[i][j].x - 5;
					circle_pos.y = map->map_2d[i][j].y - 5;
					draw_square(win->window, brs->brush_circle, circle_pos);
				}
			}
		}
	}
}

void	brush_nivelling(map_t *map, brush_t *brs)
{
	float res = 0;

	if (brs->brush_max_x >= 0 && brs->brush_max_x < map->map_x && brs->brush_max_y >= 0 && brs->brush_max_y < map->map_y) {
		if (brs->brush_altitude == -1)
			brs->brush_altitude = map->map_3d[brs->brush_max_x][brs->brush_max_y];
		for (int i = 0; i < map->map_x; i++) {
			for (int j = 0; j < map->map_y; j++) {
				if ((res = sqrt(pow(i - brs->brush_max_x, 2) + pow(j - brs->brush_max_y, 2))) <= brs->brush_radius) {
					if (map->map_3d[i][j] - brs->brush_altitude <= 0.5 && map->map_3d[i][j] - brs->brush_altitude >= -0.5)
						map->map_3d[i][j] = brs->brush_altitude;
					else if (map->map_3d[i][j] < brs->brush_altitude)
						map->map_3d[i][j] += brs->brush_strength * (((res / brs->brush_radius) - 1) * -1);
					else if (map->map_3d[i][j] > brs->brush_altitude)
						map->map_3d[i][j] -= brs->brush_strength * (((res / brs->brush_radius) - 1) * -1);
				}
			}
		}
	}
}

void	which_tool_brush(map_t *map, obj_t *obj, brush_t *brs)
{
	if (obj->num_tool == 0)
		up_brush(map, brs);
	else if (obj->num_tool == 1)
		down_brush(map, brs);
	else if (obj->num_tool == 2)
		brush_nivelling(map, brs);
}

void	up_brush(map_t *map, brush_t *brs)
{
	float res = 0;

	if (brs->brush_max_x >= 0 && brs->brush_max_x < map->map_x && brs->brush_max_y >= 0 && brs->brush_max_y < map->map_y) {
		for (int i = 0; i < map->map_x; i++) {
			for (int j = 0; j < map->map_y; j++) {
				if ((res = sqrt(pow(i - brs->brush_max_x, 2) + pow(j - brs->brush_max_y, 2))) <= brs->brush_radius) {
					map->map_3d[i][j] += brs->brush_strength * (((res / brs->brush_radius) - 1) * -1);
				}
			}
		}
	}
}

void	down_brush(map_t *map, brush_t *brs)
{
	float res = 0;

	if (brs->brush_max_x >= 0 && brs->brush_max_x < map->map_x && brs->brush_max_y >= 0 && brs->brush_max_y < map->map_y) {
		for (int i = 0; i < map->map_x; i++) {
			for (int j = 0; j < map->map_y; j++) {
				if ((res = sqrt(pow(i - brs->brush_max_x, 2) + pow(j - brs->brush_max_y, 2))) <= brs->brush_radius) {
					map->map_3d[i][j] -= brs->brush_strength * (((res / brs->brush_radius) - 1) * -1);
				}
			}
		}
	}
}
