/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** Main file.
*/

#include "main.h"

void	draw_2d_map(sfRenderWindow *window, sfVector2f **map_2d)
{
	sfVertexArray *tmp = NULL;
	sfRenderStates state;
	sfTexture *grass= sfTexture_createFromFile("assets/grass1.png", NULL);
	state.texture = grass;

	for (int i = 0; i < MAP_X - 1; i++) {
		for (int j = 0; j < MAP_Y - 1 ; j++) {
			tmp = create_quads(&map_2d[i][j], &map_2d[i][j + 1],
				&map_2d[i + 1][j + 1], &map_2d[i + 1][j]);
			RW_DVA(window, tmp, &state);
			printf("segfault\n");
			sfVertexArray_destroy(tmp);
		}
	}
	for (int i = 0; i < MAP_X; i++) {
		for (int j = 0; j < MAP_Y - 1 ; j++) {
			tmp = create_line(&map_2d[i][j], &map_2d[i][j + 1]);
			RW_DVA(window, tmp, NULL);
			tmp = create_line(&map_2d[j][i], &map_2d[j + 1][i]);
			RW_DVA(window, tmp, NULL);
			sfVertexArray_destroy(tmp);
		}
	}
}
