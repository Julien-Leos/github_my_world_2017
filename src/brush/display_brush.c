/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** display_brush.c
*/

#include "main.h"

void	draw_circle(sfRenderWindow *win, sfCircleShape *circle, V2F pos)
{
	sfCircleShape_setPosition(circle, pos);
	sfRenderWindow_drawCircleShape(win, circle, NULL);
}

void	display_brush_corner(window_t *win, map_t *map, brush_t *brs, V2I coord)
{
	V2F circle_pos = {0, 0};

	if (is_brush_equation_valid(brs, coord.x, coord.y) != -1) {
		circle_pos.x = map->map_2d[coord.x][coord.y].x - 5;
		circle_pos.y = map->map_2d[coord.x][coord.y].y - 5;
		draw_circle(win->window, brs->brush_circle, circle_pos);
	}
}

void	browse_map_display_brush(window_t *win, map_t *map, brush_t *brs)
{
	for (int i = 0; i < map->map_x; i++)
		for (int j = 0; j < map->map_y; j++)
			display_brush_corner(win, map, brs, (V2I){i, j});
}

void	display_brush(all_t *all)
{
	init_coord_max(all->map, all->stg, all->brs);
	for (int i = 0; i < all->map->map_x - 1; i++)
		for (int j = 0; j < all->map->map_y - 1; j++)
			select_brush_corner(all, i, j);
	if (is_brush_max_valid(all->brs, all->map) == 1)
		browse_map_display_brush(all->win, all->map, all->brs);
}
