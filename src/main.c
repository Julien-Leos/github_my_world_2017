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

int events (sfRenderWindow *window, sfEvent event, angle_t *angle, int **map_3d)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		if (event.type == sfEvtKeyPressed)
			switch(event.key.code) {
				case sfKeyUp:
				angle->yolo_y -= 1;
				break;
				case sfKeyDown:
				angle->yolo_y += 1;
				break;
				case sfKeyE:
				map_3d[0][0] += 1;
				break;
				case sfKeyR:
				map_3d[0][0] -= 1;
				break;
				default:
				break;
			}
	}
	return (0);
}

void alloc(int **map_3d)
{
	for (int i = 0; i < MAP_X; i++) {
		map_3d[i] = calloc(sizeof(int), MAP_Y);
		for (int j = 0; j < MAP_Y; j++) {
			map_3d[i][j] = 10;
		}
	}
	map_3d[2][3] = 15;
	map_3d[2][4] = 13;
}

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	sfRenderWindow *window = my_window_create();
	sfEvent event;
	int **map_3d = malloc(sizeof(int *) * MAP_X);
	angle_t *angle = malloc(sizeof(*angle));
	sfVector2f **map_2d;

	alloc(map_3d);
	while (sfRenderWindow_isOpen(window)) {
		sfRenderWindow_clear(window, sfBlack);
		map_2d = create_2d_map(map_3d, angle);
		draw_2d_map(window, map_2d);
		events(window, event, angle, map_3d);
		sfRenderWindow_display(window);
	}
	sfRenderWindow_destroy(window);
}
