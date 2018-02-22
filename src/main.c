/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** Main file.
*/

#include "main.h"

void	init_obj(obj_t *obj)
{
	obj->num_button = 0;
	obj->num_tool = 2;
	obj->num_brush = 0;
}

void	init_map(map_t *map)
{
	map->inclinaison = 35;
	map->rotation = 45;
	map->map_3d = create_3d_map();
	map->map_2d = create_2d_map(map->map_3d, map);
	map->move_x = 0;
	map->move_y = 0;
	map->zoom = 1;
	map->mouse_circle = sfCircleShape_create();
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

void	draw_square(sfRenderWindow *win, sfCircleShape *circle, sfVector2f pos)
{
	sfCircleShape_setPosition(circle, pos);
	sfRenderWindow_drawCircleShape(win, circle, NULL);
}

int	is_mouse_on_toolbox(sfVector2i mouse_pos)
{
	if (mouse_pos.x >= 0 && mouse_pos.x <= 128)
		return (1);
	return (0);
}

float	calc_sqr(sfVector2f A, sfVector2f B, sfVector2i P)
{
	sfVector2f vector_D = {B.x - A.x, B.y - A.y};
	sfVector2f vector_T = {P.x - A.x, P.y - A.y};

	return ((vector_D.x * vector_T.y) - (vector_D.y * vector_T.x));
}

void	which_select_square(window_t *win, map_t *map, int i, int j)
{
	sfVector2i m_pos = win->mouse_pos;

	if (calc_sqr(map->map_2d[i][j], map->map_2d[i][j + 1], m_pos) > 0 &&
	calc_sqr(map->map_2d[i][j], map->map_2d[i + 1][j], m_pos) < 0 &&
	calc_sqr(map->map_2d[i][j + 1], map->map_2d[i + 1][j + 1], m_pos) > 0 &&
	calc_sqr(map->map_2d[i + 1][j], map->map_2d[i + 1][j + 1], m_pos) < 0 &&
	is_mouse_on_toolbox(win->mouse_pos) == 0) {
		map->x_max = (i > map->x_max) ? i : map->x_max;
		map->y_max = (j > map->y_max) ? j : map->y_max;
	}
}

void	which_select_corner(window_t *win, map_t *map, int i, int j)
{
	if (map->map_2d[i][j].x > win->mouse_pos.x - (SCALING_X * map->zoom / 3) &&
	map->map_2d[i][j].x < win->mouse_pos.x + (SCALING_X * map->zoom / 3) &&
	map->map_2d[i][j].y > win->mouse_pos.y - (SCALING_Y * map->zoom / 3) &&
	map->map_2d[i][j].y < win->mouse_pos.y + (SCALING_Y * map->zoom / 3) &&
	is_mouse_on_toolbox(win->mouse_pos) == 0) {
		map->x_max = (i > map->x_max) ? i : map->x_max;
		map->y_max = (j > map->y_max) ? j : map->y_max;
	}
}

void	select_brush(window_t *win, map_t *map)
{

	sfVector2f circle_pos = {0, 0};
	int radius = 5;

	map->x_max = -1;
	map->y_max = -1;
	for (int i = 0; i < MAP_X - 1; i++)
		for (int j = 0; j < MAP_Y - 1; j++)
			which_select_square(win, map, i, j);
	if (map->x_max != -1 && map->y_max != -1) {
		for (int i = 0; i < MAP_X; i++) {
			for (int j = 0; j < MAP_Y; j++) {
				if (sqrt(pow(i - map->x_max, 2) + pow(j - map->y_max, 2)) <= radius) {
					circle_pos.x = map->map_2d[i][j].x - 5;
					circle_pos.y = map->map_2d[i][j].y - 5;
					draw_square(win->window, map->mouse_circle, circle_pos);
				}
			}
		}
	}
}

void	select_corner(window_t *win, map_t *map)
{
	sfVector2f circle_pos = {0, 0};

	map->x_max = -1;
	map->y_max = -1;
	for (int i = 0; i < MAP_X; i++)
		for (int j = 0; j < MAP_Y; j++)
			which_select_corner(win, map, i, j);
	if (map->x_max != -1 && map->y_max != -1) {
		circle_pos.x = map->map_2d[map->x_max][map->y_max].x - 5;
		circle_pos.y = map->map_2d[map->x_max][map->y_max].y - 5;
		draw_square(win->window, map->mouse_circle, circle_pos);
	}
}

void	select_square(window_t *win, map_t *map)
{
	sfVector2f circle_pos = {0, 0};

	map->x_max = -1;
	map->y_max = -1;
	for (int i = 0; i < MAP_X - 1; i++)
		for (int j = 0; j < MAP_Y - 1; j++)
			which_select_square(win, map, i, j);
	if (map->x_max != -1 && map->y_max != -1) {
		circle_pos.x = map->map_2d[map->x_max][map->y_max].x - 5;
		circle_pos.y = map->map_2d[map->x_max][map->y_max].y - 5;
		draw_square(win->window, map->mouse_circle, circle_pos);
		circle_pos.x = map->map_2d[map->x_max][map->y_max + 1].x - 5;
		circle_pos.y = map->map_2d[map->x_max][map->y_max + 1].y - 5;
		draw_square(win->window, map->mouse_circle, circle_pos);
		circle_pos.x = map->map_2d[map->x_max + 1][map->y_max].x - 5;
		circle_pos.y = map->map_2d[map->x_max + 1][map->y_max].y - 5;
		draw_square(win->window, map->mouse_circle, circle_pos);
		circle_pos.x = map->map_2d[map->x_max + 1][map->y_max + 1].x - 5;
		circle_pos.y = map->map_2d[map->x_max + 1][map->y_max + 1].y - 5;
		draw_square(win->window, map->mouse_circle, circle_pos);
	}
}

// void	up_square(map_t *map)
// {
// 	if (map->x_max != -1 && map->y_max != -1) {
// 		map->map_3d[map->x_max][map->y_max] += 1;
// 		map->map_3d[map->x_max][map->y_max + 1] += 1;
// 		map->map_3d[map->x_max + 1][map->y_max] += 1;
// 		map->map_3d[map->x_max + 1][map->y_max + 1] += 1;
// 	}
// }

void	up_square_brush(map_t *map)
{
	if (map->x_max != -1 && map->y_max != -1) {
		map->map_3d[map->x_max][map->y_max] += 0.3;
		map->map_3d[map->x_max][map->y_max + 1] += 0.3;
		map->map_3d[map->x_max + 1][map->y_max] += 0.3;
		map->map_3d[map->x_max + 1][map->y_max + 1] += 0.3;
	}
}

void	up_brush(map_t *map)
{
	int radius = 5;
	float res = 0;

	if (map->x_max != -1 && map->y_max != -1) {
		for (int i = 0; i < MAP_X; i++) {
			for (int j = 0; j < MAP_Y; j++) {
				if ((res = sqrt(pow(i - map->x_max, 2) + pow(j - map->y_max, 2))) <= radius) {
					map->map_3d[i][j] += 1 * (((res / radius) - 1) * -1);
				}
			}
		}
	}
}

// void	up_corner(map_t *map)
// {
// 	if (map->x_max != -1 && map->y_max != -1)
// 		map->map_3d[map->x_max][map->y_max] += 0.5;
// }

void	up_corner_brush(map_t *map)
{
	if (map->x_max != -1 && map->y_max != -1)
		map->map_3d[map->x_max][map->y_max] += 0.3;
}

// void	down_square(map_t *map)
// {
// 	if (map->x_max != -1 && map->y_max != -1) {
// 		map->map_3d[map->x_max][map->y_max] -= 0.5;
// 		map->map_3d[map->x_max][map->y_max + 1] -= 0.5;
// 		map->map_3d[map->x_max + 1][map->y_max] -= 0.5;
// 		map->map_3d[map->x_max + 1][map->y_max + 1] -= 0.5;
// 	}
// }

void	down_square_brush(map_t *map)
{
	if (map->x_max != -1 && map->y_max != -1) {
		map->map_3d[map->x_max][map->y_max] -= 0.5;
		map->map_3d[map->x_max][map->y_max + 1] -= 0.5;
		map->map_3d[map->x_max + 1][map->y_max] -= 0.5;
		map->map_3d[map->x_max + 1][map->y_max + 1] -= 0.5;
	}
}

// void	down_corner(map_t *map)
// {
// 	if (map->x_max != -1)
// 		map->map_3d[map->x_max][map->y_max] -= 0.5;
// }

void	down_corner_brush(map_t *map)
{
	if (map->x_max != -1 && map->y_max != -1)
		map->map_3d[map->x_max][map->y_max] += 0.3;
}

void	up_tool_brush(map_t *map, obj_t *obj)
{
	if (obj->num_tool == 0)
		up_corner_brush(map);
	else if (obj->num_tool == 1)
		up_square_brush(map);
	else if (obj->num_tool == 2)
		up_brush(map);
}

// void	up_tool(map_t *map, obj_t *obj)
// {
// 	if (obj->num_tool == 0)
// 		up_corner(map);
// 	else if (obj->num_tool == 1)
// 		up_square(map);
// }
//
// void	down_tool(map_t *map, obj_t *obj)
// {
// 	if (obj->num_tool == 0)
// 		down_corner(map);
// 	else if (obj->num_tool == 1)
// 		down_square(map);
// }

void	down_tool_brush(map_t *map, obj_t *obj)
{
	if (obj->num_tool == 0)
		down_corner_brush(map);
	else if (obj->num_tool == 1)
		down_square_brush(map);
}

void	change_tool(obj_t *obj)
{
	obj->num_tool += 1;
	if (obj->num_tool > 2)
		obj->num_tool = 0;
}

void	change_brush(obj_t *obj)
{
	obj->num_brush += 1;
	if (obj->num_brush > 1)
		obj->num_brush = 0;
}

void	events(all_t *all, window_t *win, map_t *map)
{
	if (win->event.type == sfEvtClosed)
		sfRenderWindow_close(win->window);
	if (win->event.type == sfEvtMouseButtonPressed) {
		// switch (win->event.mouseButton.button) {
		// 	case sfMouseLeft:
		// 	up_tool(map, all->obj);
		// 	break;
		// 	case sfMouseRight:
		// 	down_tool(map, all->obj);
		// 	break;
		// 	default:
		// 	break;
		// }
		switch (all->obj->num_button) {
			case 0:
			save(all);
			break;
			case 1:
			load(all);
			break;
			case 2:
			change_tool(all->obj);
			break;
			case 3:
			change_brush(all->obj);
			break;
		}
	}
	if (sfMouse_isButtonPressed(sfMouseLeft) && all->obj->num_brush == 1) {
		up_tool_brush(map, all->obj);
	} else if (sfMouse_isButtonPressed(sfMouseRight) && all->obj->num_brush == 1) {
		down_tool_brush(map, all->obj);
	}
	if (win->event.type ==  sfEvtMouseWheelScrolled) {
		if (win->event.mouseWheelScroll.delta == 1 && map->zoom < 3)
			map->zoom += 0.01;
		if (win->event.mouseWheelScroll.delta == -1 && map->zoom > 0.1)
			map->zoom -= 0.01;
	}
	if (win->event.type == sfEvtKeyPressed) {
		switch(win->event.key.code) {
			case sfKeyZ:
			map->inclinaison -= 1;
			break;
			case sfKeyS:
			map->inclinaison += 1;
			break;
			case sfKeyQ:
			map->rotation -= 1;
			if (map->rotation <= 0)
				map->rotation = 360;
			break;
			case sfKeyD:
			map->rotation += 1;
			if (map->rotation >= 360)
				map->rotation = 0;
			break;
			case sfKeyLeft:
			map->move_x += 10;
			break;
			case sfKeyRight:
			map->move_x -= 10;
			break;
			case sfKeyUp:
			map->move_y += 10;
			break;
			case sfKeyDown:
			map->move_y -= 10;
			break;
			case sfKeyO:
			map->zoom += 0.01;
			break;
			case sfKeyL:
			map->zoom -= 0.01;
			break;
			default:
			break;
		}
	}
}

void	my_free(all_t *all)
{
	for (int i = 0; i < MAP_X; i++) {
		free (all->map->map_2d[i]);
		free (all->map->map_3d[i]);
	}
	free (all->map->map_2d);
	free (all->map->map_3d);
	sfCircleShape_destroy(all->map->mouse_circle);
	free (all->map);
	for (int i = 0; i < 8; i++) {
		sfSprite_destroy(all->obj[i].sprite);
		sfTexture_destroy(all->obj[i].text);
	}
	free (all->obj);
	sfRectangleShape_destroy(all->button->rect);
	free (all->button);
	sfRenderWindow_destroy(all->win->window);
	free (all->win);
	free (all);
}

void	which_button(window_t *win, obj_t *obj)
{
	for (int i = 0; i != 8; i++) {
		if (buttonIsClicked(obj, win->mouse_pos, i) == 1) {
			obj->num_button = i;
			break;
		} else
			obj->num_button = -1;
	}
}

void	draw_toolbox(window_t *win, obj_t *obj, button_t *button)
{
	for (int i = 0; i != 8; i++)
		sfRenderWindow_drawSprite(win->window, obj[i].sprite, NULL);
	sfRenderWindow_drawRectangleShape(win->window, button->rect, NULL);
}

void	terraforming(window_t *win, map_t *map, obj_t *obj)
{
	for (int i = 0; i < MAP_X; i++)
		free (map->map_2d[i]);
	free (map->map_2d);
	map->map_2d =  create_2d_map(map->map_3d, map);
	draw_2d_map(win->window, map);
	if (obj->num_tool == 0)
		select_corner(win, map);
	else if (obj->num_tool == 1)
		select_square(win, map);
	else if (obj->num_tool == 2)
		select_brush(win, map);
}

void	init_window(window_t *win)
{
	win->window = my_window_create();
	win->mouse_pos = sfMouse_getPositionRenderWindow(win->window);
}

void	init_all(all_t *all)
{
	all->map = malloc(sizeof(*all->map));
	all->button = malloc(sizeof(*all->button));
	all->win = malloc(sizeof(*all->win));
	all->obj = malloc(sizeof(*all->obj) * 8);
	init_window(all->win);
	init_map(all->map);
	init_toolbox(all);
	init_obj(all->obj);
}

void	draw_window(window_t *win)
{
	sfRenderWindow_display(win->window);
	sfRenderWindow_clear(win->window, sfBlack);
	win->mouse_pos = sfMouse_getPositionRenderWindow(win->window);
}

int	main()
{
	all_t *all = malloc(sizeof(*all));
	init_all(all);
	while (sfRenderWindow_isOpen(all->win->window)) {
		which_button(all->win, all->obj);
		while (RW_PE(all->win->window, &(all->win->event)))
			events(all, all->win, all->map);
		terraforming(all->win, all->map, all->obj);
		draw_toolbox(all->win, all->obj, all->button);
		draw_window(all->win);
	}
	my_free(all);
	return (0);
}
