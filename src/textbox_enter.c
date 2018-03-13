/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** textbox_enter
*/

#include "main.h"

void text_enter(int *new_x, int *new_y, window_t *win)
{
	int save_val = 0;
	int power = 0;
	int j = 0;
	int a = 0;

	for (; win->input[j] != 'x'; j++);
	save_val = j + 1;
	for (int a = 0; win->input[a] != 'x'; a++) {
		*new_x += (win->input[a] - 48) * my_power(10, j - 1);
		j--;
	}
	a = save_val;
	for (; win->input[a] != '\0'; a++, power++);
	for (; win->input[save_val] != '\0'; save_val++) {
		*new_y += (win->input[save_val] - 48) * my_power(10, power - 1);
		power--;
	}
}
void enter_input(all_t *all, settings_t *stg, int *i, int *box)
{
	int new_x = 0;
	int new_y = 0;
	int old_x = 0;
	int old_y = 0;

	text_enter(&new_x, &new_y, all->win);
	old_x = all->map->map_x;
	old_y = all->map->map_y;
	save(all);
	all->map->map_x = new_x;
	all->map->map_y = new_y;
	reset(all->map, stg);
	load_resize((sfVector2i){old_x, old_y}, all->map);
	save(all);
	for (int j = 0; j != *i; ++j)
		all->win->input[j] = '\0';
	*box = 0;
	*i = 0;
}
