/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** event_keys
*/

#include "main.h"

void key_switch1(window_t *win, map_t *map)
{
	switch(win->event.key.code) {
		case sfKeyZ:
		map->inclinaison -= 1;
		break;
		case sfKeyS:
		map->inclinaison += 1;
		break;
		case sfKeyQ:
		map->rotation -= 2;
		if (map->rotation <= 0)
			map->rotation = 360;
		break;
		case sfKeyD:
		map->rotation += 2;
		if (map->rotation >= 360)
			map->rotation = 0;
		break;
		default:
		break;
	}
}

void key_switch2(window_t *win, map_t *map)
{
	switch(win->event.key.code) {
		case sfKeyLeft:
		map->move_x += 20;
		break;
		case sfKeyRight:
		map->move_x -= 20;
		break;
		case sfKeyUp:
		map->move_y += 20;
		break;
		case sfKeyDown:
		map->move_y -= 20;
		break;
		case sfKeyO:
		map->zoom += 0.03;
		break;
		default:
		break;
	}
}

void key_switch3(window_t *win, map_t *map)
{
	switch(win->event.key.code) {
		case sfKeyL:
		map->zoom -= 0.03;
		break;
		case sfKeyY:
		map->power += 0.1;
		break;
		case sfKeyH:
		map->power -= 0.1;
		break;
		case sfKeyG:
		map->radius += 1;
		break;
		case sfKeyJ:
		map->radius -= 1;
		break;
		case sfKeyV:
		lol *= -1;
		break;
		default:
		break;
	}
}

void event_keys(window_t *win, map_t *map, int *box)
{
	if (win->event.type == sfEvtKeyPressed && *box == 0) {
		key_switch1(win, map);
		key_switch2(win, map);
		key_switch3(win, map);
	}
}
