/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** Main file.
*/

#include "main.h"

sfRenderWindow *my_window_create(void)
{
	sfRenderWindow *window;
	sfVideoMode mode;

	mode.width = 1920;
	mode.height = 1080;
	mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(mode, "My World", sfDefaultStyle, NULL);
	sfRenderWindow_setFramerateLimit(window, 30);
	return (window);
}

void	which_corner_sub(map_t *map, int i, int j)
{
	if (map->map_2d[i][j].x > map->mouse_pos.x - SCALING_X / 3 &&
	map->map_2d[i][j].x < map->mouse_pos.x + SCALING_X / 3 &&
	map->map_2d[i][j].y > map->mouse_pos.y - SCALING_Y / 3 &&
	map->map_2d[i][j].y < map->mouse_pos.y + SCALING_Y / 3) {
		map->x_max = (i > map->x_max) ? i : map->x_max;
		map->y_max = (j > map->y_max) ? j : map->y_max;
	}
}

void	which_corner(window_t *win, map_t *map)
{
	sfCircleShape *circle = sfCircleShape_create();

	sfCircleShape_setFillColor(circle, sfRed);
	sfCircleShape_setRadius(circle, 5);
	for (int i = 0; i < MAP_X; i++)
		for (int j = 0; j < MAP_Y; j++)
			which_corner_sub(map, i, j);
	sfCircleShape_setPosition(circle, (sfVector2f){map->map_2d[map->x_max][map->y_max].x - 5, map->map_2d[map->x_max][map->y_max].y - 5});
	sfRenderWindow_drawCircleShape(win->window, circle, NULL);
}

void	init_map(map_t *map)
{
	map->x_max = -1;
	map->y_max = -1;
	map->sin = 35;
	map->map_3d = create_3d_map();
}

void	events(window_t *win, map_t *map)
{
	if (win->event.type == sfEvtClosed)
		sfRenderWindow_close(win->window);
	if (win->event.type == sfEvtMouseButtonPressed &&
	win->event.mouseButton.button == sfMouseLeft && map->x_max != -1)
		map->map_3d[map->x_max][map->y_max] += 1;
	if (win->event.type == sfEvtKeyPressed) {
		switch(win->event.key.code) {
			case sfKeyUp:
			map->sin -= 1;
			break;
			case sfKeyDown:
			map->sin += 1;
			break;
			default:
			break;
		}
	}
}

int	main()
{
	map_t *map = malloc(sizeof(*map));
	window_t *win = malloc(sizeof(*win));

	win->window = my_window_create();
	init_map(map);
	while (sfRenderWindow_isOpen(win->window)) {
		sfRenderWindow_clear(win->window, sfBlack);
		while (sfRenderWindow_pollEvent(win->window, &(win->event)))
			events(win, map);
		map->mouse_pos = sfMouse_getPositionRenderWindow(win->window);
		map->map_2d =  create_2d_map(map->map_3d, map);
		draw_2d_map(win->window, map->map_2d);
		which_corner(win, map);
		sfRenderWindow_display(win->window);
	}
	sfRenderWindow_destroy(win->window);
}
