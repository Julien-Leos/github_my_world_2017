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
	#define MAP_X	10
	#define MAP_Y	10
	#define SCALING_X 90
	#define SCALING_Y 90
	#define SCALING_Z 20

	typedef struct map_s {
		sfVector2f **map_2d;
		int **map_3d;
		double inclinaison;
		double rotation;
		int x_max;
		int y_max;
		float zoom;
		int move_x;
		int move_y;
		sfCircleShape *mouse_circle;
	} map_t;

	typedef struct obj_s {
		sfSprite *sprite;
		sfTexture *text;
		sfVector2f pos;
		int num_button;
		int num_tool;
	} obj_t;

	typedef struct button_s {
		sfRectangleShape *rect;
	}button_t;

	typedef struct window_s {
		sfRenderWindow *window;
		sfEvent event;
		sfVector2i mouse_pos;
	} window_t;

	typedef struct all_s {
		button_t *button;
		map_t *map;
		obj_t *obj;
		window_t *win;
	} all_t;

	int draw_2d_map(sfRenderWindow *, sfVector2f **);
	sfVertexArray *create_line(sfVector2f *, sfVector2f *);
	sfVector2f project_iso_point(int, int, int, map_t *);
	sfVector2f **create_2d_map(int **, map_t *);
	int **create_3d_map();
	obj_t create_object(sfVector2f, char *, sfVector2f);
	int init_toolbox(all_t *);
	int buttonIsClicked(obj_t *, sfVector2i, int);
	char *my_itoa(int);
	int save(all_t *);
	char *get_next_line(int);
	int my_getnbr(char *);
	int load(all_t *);

#endif
