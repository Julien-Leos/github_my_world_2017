/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** event_keys
*/

#include "main.h"

void	increase_inclinaison(settings_t *stg)
{
	stg->inclinaison += 1;
	if (stg->inclinaison > 80)
		stg->inclinaison = 80;
}

void	decrease_inclinaison(settings_t *stg)
{
	stg->inclinaison -= 1;
	if (stg->inclinaison < 20)
		stg->inclinaison = 20;
}

void	increase_rotation(settings_t *stg)
{
	stg->rotation += 2;
	if (stg->rotation > 359)
		stg->rotation = 0;
}

void	decrease_rotation(settings_t *stg)
{
	stg->rotation -= 2;
	if (stg->rotation < 0)
		stg->rotation = 359;
}

void	increase_zoom(settings_t *stg)
{
	stg->zoom += 0.03;
	if (stg->zoom > 1.5)
		stg->zoom = 1.5;
}

void	decrease_zoom(settings_t *stg)
{
	stg->zoom -= 0.03;
	if (stg->zoom < 0.2)
		stg->zoom = 0.2;
}

void	increase_strength(brush_t *brs)
{
	brs->brush_strength += 0.1;
	if (brs->brush_strength > 2)
		brs->brush_strength = 2;
}

void	decrease_strength(brush_t *brs)
{
	brs->brush_strength -= 0.1;
	if (brs->brush_strength < 0.3)
		brs->brush_strength = 0.3;
}

void	increase_radius(brush_t *brs)
{
	brs->brush_radius += 1;
	if (brs->brush_radius > 20)
		brs->brush_radius = 20;
}

void	decrease_radius(brush_t *brs)
{
	brs->brush_radius -= 1;
	if (brs->brush_radius < 2)
		brs->brush_radius = 2;
}

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
		case sfKeyV:
		lol *= -1;
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
