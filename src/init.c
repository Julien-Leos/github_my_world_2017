/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** init
*/

#include "main.h"


void	init_obj(obj_t *obj)
{
	obj->num_button = 0;
	obj->num_tool = 2;
	obj->num_brush = 0;
}

void	init_map(map_t *map)
{
	map->map_x = MAP_X;
	map->map_y = MAP_Y;
	map->inclinaison = 35;
	map->rotation = 45;
	map->map_3d = create_3d_map(map);
	map->map_2d = create_2d_map(map->map_3d, map);
	map->move_x = 0;
	map->move_y = 0;
	map->zoom = 1;
	map->radius = 6;
	map->power = 1;
	map->mouse_circle = sfCircleShape_create();
	sfCircleShape_setFillColor(map->mouse_circle, sfRed);
	sfCircleShape_setRadius(map->mouse_circle, 5);
}

void	init_window(window_t *win)
{
	win->input = malloc(sizeof(char) * 100);
	win->textbox = sfText_create();
	win->font = sfFont_createFromFile("./images/ok2.ttf");
	win->window = my_window_create();
	win->mouse_pos = sfMouse_getPositionRenderWindow(win->window);
}

void	init_all(all_t *all)
{
	all->map = malloc(sizeof(*all->map));
	all->button = malloc(sizeof(*all->button));
	all->win = malloc(sizeof(*all->win));
	all->obj = malloc(sizeof(*all->obj) * 8);
	init_window(all->win);
	init_map(all->map);
	init_toolbox(all);
	init_obj(all->obj);
}
