/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** textbox
*/

#include "main.h"

void change_next_line(map_t *map, int *i, int *j, int fd)
{
	if (*i < map->map_x && *j < map->map_y) {
		map->map_3d[*i][*j] = my_getfloat(get_next_line(fd));
	} else
		get_next_line(fd);
}

int load_resize(sfVector2i old_map, map_t *map)
{
	int fd = open("save.txt", O_RDONLY);

	if (fd == -1)
		return (-1);
	get_next_line(fd);
	get_next_line(fd);
	for (int i = 0; i < old_map.x; i++)
		for (int j = 0; j < old_map.y; j++)
			change_next_line(map, &i, &j, fd);
	return (0);
}

void reset(map_t *map, settings_t *stg)
{
	free(map->map_3d);
	free(map->map_2d);
	free(map->color_tab);
	map->map_3d = create_3d_map(map);
	map->map_2d = create_2d_map(map->map_3d, map, stg);
	map->color_tab = malloc(sizeof(sfColor**) * 3);
	for (int i = 0; i < 3; i++) {
		map->color_tab[i] = malloc(sizeof(COL*) * map->map_x);
		for (int e = 0; e < map->map_x; e++) {
			map->color_tab[i][e] = malloc(sizeof(COL) * map->map_y);
		}
	}
	init_color_tab(map);
}

void set_text(window_t *win)
{
	sfText_setString(win->textbox, win->input);
	sfText_setFont(win->textbox, win->font);
	sfText_setCharacterSize(win->textbox, 50);
	sfText_setPosition(win->textbox, (sfVector2f){1410, 15});
}

int textbox(all_t *all, window_t *win, settings_t *stg, int *box)
{
	static int i = 0;

	if (i == 16)
		i--;
	if (win->event.text.unicode == 13 || win->event.text.unicode == 10) {
		if (check_input(win, &i, box) == 84)
			return (84);
		enter_input(all, stg, &i, box);
	} else if (win->event.text.unicode == 8) {
		win->input[i - 1] = '\0';
		if (i > 0)
			--i;
	} else if ((win->event.text.unicode >= 48 &&
	win->event.text.unicode <= 57) || win->event.text.unicode == 120) {
		win->input[i] = win->event.text.unicode;
		i++;
	}
	set_text(win);
	return (0);
}
