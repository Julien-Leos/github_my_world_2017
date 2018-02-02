/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** Main file.
*/

#include "main.h"

void	init_map(map_t *map)
{
	map->sin = 35;
	map->map_3d = create_3d_map();
	map->map_2d = create_2d_map(map->map_3d, map);
	map->mouse_circle =  sfCircleShape_create();
	sfCircleShape_setFillColor(map->mouse_circle, sfRed);
	sfCircleShape_setRadius(map->mouse_circle, 5);
}

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
	sfVector2f circle_pos = {0, 0};

	map->x_max = -1;
	map->y_max = -1;
	for (int i = 0; i < MAP_X; i++)
		for (int j = 0; j < MAP_Y; j++)
			which_corner_sub(map, i, j);
	if (map->x_max != -1 && map->y_max != -1) {
		circle_pos.x = map->map_2d[map->x_max][map->y_max].x - 5;
		circle_pos.y = map->map_2d[map->x_max][map->y_max].y - 5;
		sfCircleShape_setPosition(map->mouse_circle, circle_pos);
		sfRenderWindow_drawCircleShape(win->window, map->mouse_circle, NULL);
	}
}

void	events(all_t *all)
{
	sfVector2i mousepos = sfMouse_getPositionRenderWindow(all->win->window);

	if (all->win->event.type == sfEvtClosed)
		sfRenderWindow_close(all->win->window);
	if (all->win->event.type == sfEvtMouseButtonPressed &&
	all->win->event.mouseButton.button == sfMouseLeft && all->map->x_max != -1) {
		all->map->map_3d[all->map->x_max][all->map->y_max] += 1;
	} else if (all->win->event.type == sfEvtMouseButtonPressed &&
	all->win->event.mouseButton.button == sfMouseRight && all->map->x_max != -1) {
			all->map->map_3d[all->map->x_max][all->map->y_max] -= 1;
	}
	if (all->win->event.type == sfEvtKeyPressed) {
		switch(all->win->event.key.code) {
			case sfKeyUp:
			all->map->sin -= 1;
			break;
			case sfKeyDown:
			all->map->sin += 1;
			break;
			default:
			break;
		}
	}

	if (all->win->event.type == sfEvtMouseButtonPressed)
		for (int i = 0; i != 8; i++)
			if (buttonIsClicked(all->obj, mousepos, &i) == 1)
				switch (i) {
				case 0:
				save(all);
				break;
				case 1:
				load(all);
				break;
/*				case 2:
				altitude_down();
				break;
				case 3:
				zoom_up();
				break;
				case 4:
				zoom_down();
				break;
				case 5:
				egalise();
				break;
				case 6:
				home();
				break;
				case 7:
				altitude_up();
				*/
			}
}

void	my_free(window_t *win, map_t *map)
{
	for (int i = 0; i < MAP_X; i++) {
		free (map->map_2d[i]);
		free (map->map_3d[i]);
	}
	free (map->map_2d);
	free (map->map_3d);
	sfCircleShape_destroy(map->mouse_circle);
	free (map);
	sfRenderWindow_destroy(win->window);
	free (win);
}

int	main()
{
	all_t *all = malloc(sizeof(*all));
	all->map = malloc(sizeof(*all->map));
	all->button = malloc(sizeof(*all->button));
	all->win = malloc(sizeof(*all->win));
	all->obj = malloc(sizeof(obj_t) * 8);
	all->win->window = my_window_create();

	create_toolbox(all);
	init_map(all->map);
	while (sfRenderWindow_isOpen(all->win->window)) {
		sfRenderWindow_clear(all->win->window, sfBlack);
		while (sfRenderWindow_pollEvent(all->win->window, &(all->win->event)))
			events(all);
		all->map->mouse_pos = sfMouse_getPositionRenderWindow(all->win->window);
		all->map->map_2d = create_2d_map(all->map->map_3d, all->map);
		for (int i = 0; i < MAP_X; i++)
			free (all->map->map_2d[i]);
		free (all->map->map_2d);
		all->map->map_2d =  create_2d_map(all->map->map_3d, all->map);
		draw_2d_map(all->win->window, all->map->map_2d);
		which_corner(all->win, all->map);
		for (int i = 0; i != 8; i++)
			sfRenderWindow_drawSprite(all->win->window, all->obj[i].sprite, NULL);
		sfRenderWindow_drawRectangleShape(all->win->window, all->button->rect, NULL);
		sfRenderWindow_display(all->win->window);
	}
	my_free(all->win, all->map);
	return (0);
}
