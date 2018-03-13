/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** event_keys
*/

#include "main.h"

void	key_switch1(window_t *win, settings_t *stg)
{
	switch(win->event.key.code) {
		case sfKeyS:
		increase_inclinaison(stg);
		break;
		case sfKeyZ:
		decrease_inclinaison(stg);
		break;
		case sfKeyD:
		increase_rotation(stg);
		break;
		case sfKeyQ:
		decrease_rotation(stg);
		break;
		case sfKeyO:
		increase_zoom(stg);
		break;
		default:
		break;
	}
}

void key_switch2(window_t *win, settings_t *stg)
{
	switch(win->event.key.code) {
		case sfKeyL:
		decrease_zoom(stg);
		break;
		case sfKeyLeft:
		stg->offset_x += 20;
		break;
		case sfKeyRight:
		stg->offset_x -= 20;
		break;
		case sfKeyUp:
		stg->offset_y += 20;
		break;
		case sfKeyDown:
		stg->offset_y -= 20;
		break;
		default:
		break;
	}
}

void key_switch3(window_t *win, brush_t *brs)
{
	switch(win->event.key.code) {
		case sfKeyY:
		increase_strength(brs);
		break;
		case sfKeyH:
		decrease_strength(brs);
		break;
		case sfKeyG:
		increase_radius(brs);
		break;
		case sfKeyJ:
		decrease_radius(brs);
		break;
		default:
		break;
	}
}

void event_keys(window_t *win, settings_t *stg, brush_t *brs, int *box)
{
	if (win->event.type == sfEvtKeyPressed && *box == 0) {
		key_switch1(win, stg);
		key_switch2(win, stg);
		key_switch3(win, brs);
	}
}
