/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** init
*/

#include "main.h"

void	init_color_tab(map_t *map)
{
	int rand_value = 0;

	for (int i = 0; i < map->map_x; i++) {
		for (int j = 0; j < map->map_y; j++) {
			rand_value = rand() % 20;
			map->color_tab[0][i][j] = sfColor_fromRGB(58 + rand_value, 157 + rand_value, 35 + rand_value);
			map->color_tab[1][i][j] = sfColor_fromRGB(143 + rand_value, 89 + rand_value, 34 + rand_value);
			map->color_tab[2][i][j] = sfColor_fromRGB(153 + rand_value, 153 + rand_value, 153 + rand_value);
		}
	}
}

void	init_obj(obj_t *obj)
{
	obj->num_button = 0;
	obj->num_tool = 0;
}

void	init_map(map_t *map, settings_t *stg)
{
	map->map_x = 150;
	map->map_y = 150;
	map->map_3d = create_3d_map(map);
	map->map_2d = create_2d_map(map->map_3d, map, stg);
	map->color_tab = malloc(sizeof(sfColor**) * 3);
	for (int i = 0; i < 3; i++) {
		map->color_tab[i] = malloc(sizeof(sfColor*) * map->map_x);
		for (int e = 0; e < map->map_x; e++) {
			map->color_tab[i][e] = malloc(sizeof(sfColor) * map->map_y);
		}
	}
	init_color_tab(map);
}

void	init_window(window_t *win)
{
	win->input = malloc(sizeof(char) * 100);
	win->textbox = sfText_create();
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
	stg->zoom = 1;
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
	lol = 1;
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
