/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** decrease_event
*/

#include "main.h"

void	decrease_inclinaison(settings_t *stg)
{
	stg->inclinaison -= 1;
	if (stg->inclinaison < 20)
		stg->inclinaison = 20;
}

void	decrease_rotation(settings_t *stg)
{
	stg->rotation -= 2;
	if (stg->rotation < 0)
		stg->rotation = 359;
}

void	decrease_zoom(settings_t *stg)
{
	stg->zoom -= 0.03;
	if (stg->zoom < 0.2)
		stg->zoom = 0.2;
}

void	decrease_strength(brush_t *brs)
{
	brs->brush_strength -= 0.1;
	if (brs->brush_strength < 0.3)
		brs->brush_strength = 0.3;
}

void	decrease_radius(brush_t *brs)
{
	brs->brush_radius -= 1;
	if (brs->brush_radius < 2)
		brs->brush_radius = 2;
}
