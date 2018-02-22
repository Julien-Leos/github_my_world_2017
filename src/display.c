/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** Main file.
*/

#include "main.h"

sfColor select_color(float **map_3d, int i, int j)
{
	int max = 0;
	int min = 10000;
	int rand_value = rand() % 8;

	max = (max > map_3d[i][j]) ? max : map_3d[i][j];
	max = (max > map_3d[i][j + 1]) ? max : map_3d[i][j + 1];
	max = (max > map_3d[i + 1][j]) ? max : map_3d[i + 1][j];
	max = (max > map_3d[i + 1][j + 1]) ? max : map_3d[i + 1][j + 1];
	min = (min < map_3d[i][j]) ? min : map_3d[i][j];
	min = (min < map_3d[i][j + 1]) ? min : map_3d[i][j + 1];
	min = (min < map_3d[i + 1][j]) ? min : map_3d[i + 1][j];
	min = (min < map_3d[i + 1][j + 1]) ? min : map_3d[i + 1][j + 1];

	if (max - min >= 0 && max - min < 1) {
		return (sfColor_fromRGB(58, 157, 35));
	} else if (max - min >= 1 && max - min <= 3) {
		return (sfColor_fromRGB(143, 89, 34));
	} else {
		return (sfColor_fromRGB(153 + rand_value, 153+ rand_value, 153+ rand_value));
	}
}

void	draw_vertex_array(sfRenderWindow *window, sfVector2f **map_2d, int i, int j, float **map_3d)
{
	sfVertexArray *tmp = NULL;

	if (i < MAP_X - 1 && j < MAP_Y - 1) {
		tmp = create_quads(&map_2d[i][j], &map_2d[i][j + 1], &map_2d[i + 1][j + 1], &map_2d[i + 1][j], select_color(map_3d, i, j));
		RW_DVA(window, tmp, NULL);
		sfVertexArray_destroy(tmp);
	}
	//DECOMMENT TO DISPLAY LINES
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

void	draw_2d_map(sfRenderWindow *window, map_t *map)
{
	// sfTexture *grass= sfTexture_createFromFile("assets/grass1.png", NULL);
	// sfRenderStates state;
	// state.shader = NULL;
	// state.texture = grass;
	// state.transform = sfTransform_Identity;
	// state.blendMode = sfBlendAlpha;

	if (map->rotation >= 0 && map->rotation < 90)
		for (int j = MAP_Y - 1; j >= 0; j--)
			for (int i = 0; i <= MAP_X - 1; i++)
				draw_vertex_array(window, map->map_2d, i, j, map->map_3d);
	if (map->rotation >= 90 && map->rotation < 180)
		for (int i = MAP_X - 1; i >= 0; i--)
			for (int j = MAP_Y - 1; j >= 0; j--)
				draw_vertex_array(window, map->map_2d, i, j, map->map_3d);
	if (map->rotation >= 180 && map->rotation < 270)
		for (int j = 0; j < MAP_Y - 1 ; j++)
			for (int i = MAP_X - 2; i >= 0; i--)
				draw_vertex_array(window, map->map_2d, i, j, map->map_3d);
	if (map->rotation >= 270 && map->rotation <= 360)
		for (int i = 0; i < MAP_X - 1; i++)
			for (int j = 0; j < MAP_Y - 1 ; j++)
				draw_vertex_array(window, map->map_2d, i, j, map->map_3d);
}
