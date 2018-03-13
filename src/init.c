/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** init
*/

#include "main.h"

void	init_map(map_t *map, settings_t *stg)
{
	map->map_x = 40;
	map->map_y = 40;
	map->map_3d = create_3d_map(map);
	map->map_2d = create_2d_map(map->map_3d, map, stg);
	map->display_lines = -1;
	map->texture_tab = malloc(sizeof(sfTexture*) * 3);
	map->texture_tab[0] = sfTexture_createFromFile("images/gras.jpg", NULL);
	map->texture_tab[1] = sfTexture_createFromFile("images/dirt.jpg", NULL);
	map->texture_tab[2] = sfTexture_createFromFile("images/ston.jpg", NULL);
	map->color_tab = malloc(sizeof(COL**) * 3);
	for (int i = 0; i < 3; i++) {
		map->color_tab[i] = malloc(sizeof(COL*) * map->map_x);
		for (int e = 0; e < map->map_x; e++) {
			map->color_tab[i][e] = malloc(sizeof(COL) * map->map_y);
		}
	}
	init_color_tab(map);
}

void	init_window(window_t *win)
{
	win->input = malloc(sizeof(char) * 100);
	win->textbox = sfText_create();
	win->textbox_ex = sfText_create();
	win->font = sfFont_createFromFile("./images/ok2.ttf");
	win->window = my_window_create();
	win->mouse_pos = sfMouse_getPositionRenderWindow(win->window);
}

void	init_setting(settings_t *stg)
{
	stg->inclinaison = 35;
	stg->rotation = 46;
	stg->offset_x = 0;
	stg->offset_y = 0;
	stg->zoom = 0.7;
}

void	init_brush(brush_t *brs)
{
	brs->brush_radius = 6;
	brs->brush_strength = 1;
	brs->brush_altitude = -1;
	brs->brush_circle = sfCircleShape_create();
	sfCircleShape_setFillColor(brs->brush_circle, sfRed);
	sfCircleShape_setRadius(brs->brush_circle, 5);
}

void	init_all(all_t *all)
{
	all->stg = malloc(sizeof(*all->stg));
	all->brs = malloc(sizeof(*all->brs));
	all->map = malloc(sizeof(*all->map));
	all->button = malloc(sizeof(*all->button));
	all->win = malloc(sizeof(*all->win));
	all->obj = malloc(sizeof(*all->obj) * 8);
	init_window(all->win);
	init_setting(all->stg);
	init_brush(all->brs);
	init_map(all->map, all->stg);
	init_toolbox(all);
	init_obj(all->obj);
}
