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
	#include <SFML/Graphics.h>
	#include <SFML/Graphics/Color.h>
	#include <SFML/Window.h>
	#include <SFML/Audio.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <math.h>
	#include <fcntl.h>
	#include <unistd.h>
	#include <math.h>

	#define RDVA	sfRenderWindow_drawVertexArray
	#define MAP_X	6
	#define MAP_Y	6
	#define SCALING_X 90
	#define SCALING_Y 90
	#define SCALING_Z 20
	
	typedef struct angle_s {
		double angle_y;
		double angle_x;
		double yolo_y;
}angle_t;

	int draw_2d_map(sfRenderWindow *, sfVector2f **);
	sfVertexArray *create_line(sfVector2f *, sfVector2f *);
	sfVector2f project_iso_point(int, int, int, angle_t *);
	sfVector2f **create_2d_map(int **, angle_t *);

#endif
