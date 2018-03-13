/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** switch_tools
*/

#include "main.h"

void switch_tools(all_t *all)
{
	switch (all->obj->num_button) {
		case 0:
		save(all);
		break;
		case 1:
		load(all);
		break;
		case 2:
		all->obj->num_tool = 0;
		break;
		case 3:
		all->obj->num_tool = 1;
		break;
	}
	switch_tools2(all);
}

void switch_tools2(all_t *all)
{
	switch (all->obj->num_button) {
		case 4:
		all->obj->num_tool = 2;
		break;
		case 5:
		reset(all->map, all->stg);
		break;
		case 6:
		all->map->display_lines *= -1;
		break;
		case 7:
		all->map->map_3d = create_perlin_map(all->map);
		break;
	}
}
