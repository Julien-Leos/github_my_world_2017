/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** Main file.
*/

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
#include "main.h"

int draw_2d_map(sfRenderWindow *window, sfVector2f **map_2d)
{

	for (int i = 0; i < MAP_X; i++) {
		for (int j = 0; j < MAP_Y - 1 ; j++)
			RDVA(window,
			create_line(&map_2d[i][j], &map_2d[i][j + 1]), NULL);
	}
	for (int i = 0; i < MAP_X; i++) {
		for (int j = 0; j < MAP_Y - 1; j++)
			RDVA(window,
			create_line(&map_2d[j][i], &map_2d[j + 1][i]), NULL);
	}
	return (0);
}
