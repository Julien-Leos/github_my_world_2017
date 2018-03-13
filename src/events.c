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
		which_brush(map, all->obj, all->brs);
	else
		all->brs->brush_altitude = -1;
}

void event_button(all_t *all, window_t *win, int *box)
{
	sfVector2i m_p = win->mouse_pos;

	if (win->event.type == sfEvtMouseButtonPressed) {
		if (m_p.x > 1400 && m_p.x < 1850 && m_p.y > 10 && m_p.y < 80)
			*box = 1;
		switch_tools(all);
	}
}

void event(all_t *all, window_t *win, map_t *map, settings_t *stg)
{
	static int box = 0;

	if (win->event.type == sfEvtClosed)
		sfRenderWindow_close(win->window);
	if (win->event.type == sfEvtTextEntered && box == 1)
		textbox(all, win, stg, &box);
	event_button(all, win, &box);
	event_brush(all, map);
	event_scrolled(win, stg);
	event_keys(win, stg, all->brs, &box);
}
