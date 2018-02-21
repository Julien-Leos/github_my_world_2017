/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** Main file.
*/

#include "main.h"

void	draw_vertex_array(sfRenderWindow *window, sfVector2f **map_2d, sfRenderStates state, int i, int j)
{
	sfVertexArray *tmp = NULL;

	if (i < MAP_X - 1 && j < MAP_Y - 1) {
		tmp = create_quads(&map_2d[i][j], &map_2d[i][j + 1], &map_2d[i + 1][j + 1], &map_2d[i + 1][j]);
		RW_DVA(window, tmp, &state);
		sfVertexArray_destroy(tmp);
	}
	if (j + 1 <= MAP_Y - 1) {
		tmp = create_line(&map_2d[i][j], &map_2d[i][j + 1]);
		RW_DVA(window, tmp, NULL);
		sfVertexArray_destroy(tmp);
	}
	if (i + 1 <= MAP_X - 1) {
		tmp = create_line(&map_2d[i][j], &map_2d[i + 1][j]);
		RW_DVA(window, tmp, NULL);
		sfVertexArray_destroy(tmp);
	}
}

void	draw_2d_map(sfRenderWindow *window, sfVector2f **map_2d, int rotation)
{
	sfTexture *grass= sfTexture_createFromFile("assets/grass1.png", NULL);
	sfRenderStates state;
	state.shader = NULL;
	state.texture = grass;
	state.transform = sfTransform_Identity;
	state.blendMode = sfBlendAlpha;

	if (rotation >= 0 && rotation < 90)
		for (int j = MAP_Y - 1; j >= 0; j--)
			for (int i = 0; i <= MAP_X - 1; i++)
				draw_vertex_array(window, map_2d, state, i, j);
	if (rotation >= 90 && rotation < 180)
		for (int i = MAP_X - 1; i >= 0; i--)
			for (int j = MAP_Y - 1; j >= 0; j--)
				draw_vertex_array(window, map_2d, state, i, j);
	if (rotation >= 180 && rotation < 270)
		for (int j = 0; j < MAP_Y - 1 ; j++)
			for (int i = MAP_X - 2; i >= 0; i--)
				draw_vertex_array(window, map_2d, state, i, j);
	if (rotation >= 270 && rotation <= 360)
		for (int i = 0; i < MAP_X - 1; i++)
			for (int j = 0; j < MAP_Y - 1 ; j++)
				draw_vertex_array(window, map_2d, state, i, j);
}
