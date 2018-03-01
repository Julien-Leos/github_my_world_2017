/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** textbox
*/

#include "main.h"

void textbox(window_t *win, map_t *map, settings_t *stg, int *box)
{
	static int i = 0;
	int j = 0;
	int a = 0;
	int save = 0;
	int num = 0;
	int num2 = 0;
	int power = 0;

	if (win->event.text.unicode == 13) {
		for (; win->input[j] != 'x'; j++);
		save = j + 1;
		for (int a = 0; win->input[a] != 'x'; a++) {
			num += (win->input[a] - 48) * my_power(10, j - 1);
			j--;
		}
		a = save;
		for (; win->input[a] != '\0'; a++, power++);
		for (; win->input[save] != '\0'; save++) {
			num2 += (win->input[save] - 48) * my_power(10, power - 1);
			power--;
		}
		map->map_x = num;
		map->map_y = num2;
		free(map->map_3d);
		free(map->map_2d);
		map->map_3d = create_3d_map(map);
		map->map_2d = create_2d_map(map->map_3d, map, stg);
		for (int j = 0; j != i; ++j)
			win->input[j] = '\0';
		*box = 0;
		i = 0;
	} else if (win->event.text.unicode == 8)
		win->input[i - 1] = '\0';
	else {
		win->input[i] = win->event.text.unicode;
		i++;
	}
	sfText_setString(win->textbox, win->input);
	sfText_setFont(win->textbox, win->font);
	sfText_setCharacterSize(win->textbox, 50);
	sfText_setPosition(win->textbox, (sfVector2f){1410, 15});
}
