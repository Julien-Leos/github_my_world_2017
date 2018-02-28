	/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** Header file
*/

#ifndef MAIN_H_
	#define MAIN_H_
	#include <stdlib.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <SFML/Graphics.h>
	#include <SFML/Window.h>
	#include <SFML/Audio.h>
	#include <SFML/System.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	#include <math.h>

	#define RW_DVA	sfRenderWindow_drawVertexArray
	#define RW_PE sfRenderWindow_pollEvent
	#define MAP_X	150
	#define MAP_Y	150
	#define SCALING_X 45
	#define SCALING_Y 45
	#define SCALING_Z 20

	typedef struct map_s {
		sfVector2f **map_2d;
		float **map_3d;
		double inclinaison;
		double rotation;
		int map_x;
		int map_y;
		int x_max;
		int y_max;
		int move_x;
		int move_y;
		float zoom;
		int radius;
		float power;
		sfCircleShape *mouse_circle;
	} map_t;

	typedef struct obj_s {
		sfSprite *sprite;
		sfTexture *text;
		sfVector2f pos;
		int num_button;
		int num_tool;
		int num_brush;
	} obj_t;

	typedef struct button_s {
		sfRectangleShape *rect;
		sfRectangleShape *text_one;
		sfRectangleShape *text_two;
		sfRectangleShape *text_three;
		sfRectangleShape *text_four;
	}button_t;

	typedef struct window_s {
		sfRenderWindow *window;
		sfEvent event;
		sfVector2i mouse_pos;
		char *input;
		sfText *textbox;
		sfFont *font;
	} window_t;

	typedef struct all_s {
		button_t *button;
		map_t *map;
		obj_t *obj;
		window_t *win;
	} all_t;

	void draw_2d_map(sfRenderWindow *, map_t*);
	sfVertexArray *create_line(sfVector2f *, sfVector2f *);
	sfVertexArray *create_quads(sfVector2f *, sfVector2f *, sfVector2f *, sfVector2f *, sfColor);
	sfVector2f project_iso_point(int, int, int, map_t *);
	sfVector2f **create_2d_map(float **, map_t *);
	float **create_3d_map();
	obj_t create_object(sfVector2f, char *, sfVector2f);
	int init_toolbox(all_t *);
	int buttonIsClicked(obj_t *, sfVector2i, int);
	char *my_itoa(float);
	int save(all_t *);
	char *get_next_line(int);
	int my_getnbr(char *);
	int load(all_t *);
	void draw_square(sfRenderWindow *win, sfCircleShape *circle, sfVector2f pos);
	void	which_select_square(window_t *win, map_t *map, int i, int j);
	void	select_square(window_t *win, map_t *map);
	void	init_obj(obj_t *obj);
	void	init_map(map_t *map);
	void	init_window(window_t *win);
	void	init_all(all_t *all);
	void events(all_t *all, window_t *win, map_t *map);
	void event_scrolled(window_t *win, map_t *map);
	void event_brush(all_t *all, map_t *map);
	void event_button(all_t *all, window_t *win, int *box);
	int	is_mouse_on_toolbox(sfVector2i mouse_pos);
	float	calc_sqr(sfVector2f A, sfVector2f B, sfVector2i P);
	void	which_select_corner(window_t *win, map_t *map, int i, int j);
	void	select_brush(window_t *win, map_t *map);
	void	select_corner(window_t *win, map_t *map);
	void	up_square_brush(map_t *map);
	void	up_brush(map_t *map);
	void	up_corner_brush(map_t *map);
	void	down_square_brush(map_t *map);
	void	down_corner_brush(map_t *map);
	void	up_tool_brush(map_t *map, obj_t *obj);
	void	down_tool_brush(map_t *map, obj_t *obj);
	void	change_tool(obj_t *obj);
	void	change_brush(obj_t *obj);
	int my_power(int nb, int power);
	void textbox(window_t *win, map_t *map, int *box);
	void	my_free(all_t *all);
	void	which_button(window_t *win, obj_t *obj);
	void	draw_toolbox(window_t *win, obj_t *obj, button_t *button);
	void	terraforming(window_t *win, map_t *map, obj_t *obj);
	void	draw_window(window_t *win);
	void event_keys(window_t *win, map_t *map, int *box);
	sfRenderWindow *my_window_create(void);
	int my_putstrfd(int fd, char *str);
#endif
