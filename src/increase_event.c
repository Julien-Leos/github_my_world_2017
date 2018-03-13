/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** increase_event
*/

#include "main.h"

void	increase_inclinaison(settings_t *stg)
{
	stg->inclinaison += 1;
	if (stg->inclinaison > 80)
		stg->inclinaison = 80;
}

void	increase_rotation(settings_t *stg)
{
	stg->rotation += 2;
	if (stg->rotation > 359)
		stg->rotation = 0;
}

void	increase_zoom(settings_t *stg)
{
	stg->zoom += 0.03;
	if (stg->zoom > 1.5)
		stg->zoom = 1.5;
}

void	increase_strength(brush_t *brs)
{
	brs->brush_strength += 0.1;
	if (brs->brush_strength > 2)
		brs->brush_strength = 2;
}

void	increase_radius(brush_t *brs)
{
	brs->brush_radius += 1;
	if (brs->brush_radius > 20)
		brs->brush_radius = 20;
}
