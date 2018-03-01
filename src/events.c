/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** events
*/

#include "main.h"

void event_scrolled(window_t *win, settings_t *stg)
{
	if (win->event.type ==  sfEvtMouseWheelScrolled) {
		if (win->event.mouseWheelScroll.delta == 1 && stg->zoom < 3)
			stg->zoom += 0.01;
		if (win->event.mouseWheelScroll.delta == -1 && stg->zoom > 0.1)
			stg->zoom -= 0.01;
	}
}

void event_brush(all_t *all, map_t *map)
{
	if (sfMouse_isButtonPressed(sfMouseLeft))
		which_tool_brush(map, all->obj, all->brs);
	else
		all->brs->brush_altitude = -1;
}

void event_button(all_t *all, window_t *win, int *box)
{
	sfVector2i mouse = {0, 0};

	if (win->event.type == sfEvtMouseButtonPressed) {
		mouse = sfMouse_getPositionRenderWindow(win->window);
		if (mouse.x > 1400 && mouse.x < 1850 && mouse.y > 10 && mouse.y < 80)
			*box = 1;
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
			case 4:
			all->obj->num_tool = 2;
			break;
		}
	}
}

void events(all_t *all, window_t *win, map_t *map, settings_t *stg, brush_t *brs)
{
	static int box = 0;

	if (win->event.type == sfEvtClosed)
		sfRenderWindow_close(win->window);
	if (win->event.type == sfEvtTextEntered && box == 1)
		textbox(win, map, stg, &box);
	event_button(all, win, &box);
	event_brush(all, map);
	event_scrolled(win, stg);
	event_keys(win, stg, brs, &box);
}
