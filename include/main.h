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
	#include <SFML/Window.h>
	#include <SFML/Audio.h>
	#include <SFML/System.h>
	#include <math.h>

	#define RDVA	sfRenderWindow_drawVertexArray
	#define MAP_X	10
	#define MAP_Y	10
	#define SCALING_X 90
	#define SCALING_Y 90
	#define SCALING_Z 20

	typedef struct map_s {
		sfVector2f **map_2d;
		int **map_3d;
		double sin;
	}map_t;

	int draw_2d_map(sfRenderWindow *, sfVector2f **);
	sfVertexArray *create_line(sfVector2f *, sfVector2f *);
	sfVector2f project_iso_point(int, int, int, map_t *);
	sfVector2f **create_2d_map(int **, map_t *);
	int **create_3d_map();

#endif
