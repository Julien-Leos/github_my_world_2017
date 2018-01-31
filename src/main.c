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

void	which_corner(sfRenderWindow *window, map_t *map)
{
	sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
	sfCircleShape *circle = sfCircleShape_create();
	int x_max = -1;
	int y_max = -1;

	sfCircleShape_setFillColor(circle, sfRed);
	for (int i = 0; i < MAP_X; i++) {
		for (int j = 0; j < MAP_Y; j++) {
			if (map->map_2d[i][j].x >= mouse_pos.x - 20 && map->map_2d[i][j].x <= mouse_pos.x + 20 &&
			map->map_2d[i][j].y >= mouse_pos.y - 20 && map->map_2d[i][j].y <= mouse_pos.y + 20) {
				x_max = (i > x_max) ? i : x_max;
				y_max = (j > y_max) ? j : y_max;
			}
		}
	}
	if (x_max != -1 && y_max != -1)
		map->map_3d[x_max][y_max] += 1;
}

void	events(sfRenderWindow *window, sfEvent event, map_t *map)
{
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(window);
	if (event.type == sfEvtMouseButtonPressed) {
		if (event.mouseButton.button == sfMouseLeft)
			which_corner(window, map);
	}
	if (event.type == sfEvtKeyPressed) {
		switch(event.key.code) {
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
	sfRenderWindow *window = my_window_create();
	sfEvent event;

	map->map_3d = create_3d_map();
	while (sfRenderWindow_isOpen(window)) {
		sfRenderWindow_clear(window, sfBlack);
		map->map_2d = create_2d_map(map->map_3d, map);
		draw_2d_map(window, map->map_2d);
		while (sfRenderWindow_pollEvent(window, &event))
			events(window, event, map);
		sfRenderWindow_display(window);
	}
	sfRenderWindow_destroy(window);
}
