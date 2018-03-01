/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** Main file.
*/

#include "main.h"

sfColor select_color(map_t *map, int i, int j)
{
	float max = 0;
	float min = 10000;

	max = (max > map->map_3d[i][j]) ? max : map->map_3d[i][j];
	max = (max > map->map_3d[i][j + 1]) ? max : map->map_3d[i][j + 1];
	max = (max > map->map_3d[i + 1][j]) ? max : map->map_3d[i + 1][j];
	max = (max > map->map_3d[i + 1][j + 1]) ? max : map->map_3d[i + 1][j + 1];
	min = (min < map->map_3d[i][j]) ? min : map->map_3d[i][j];
	min = (min < map->map_3d[i][j + 1]) ? min : map->map_3d[i][j + 1];
	min = (min < map->map_3d[i + 1][j]) ? min : map->map_3d[i + 1][j];
	min = (min < map->map_3d[i + 1][j + 1]) ? min : map->map_3d[i + 1][j + 1];

	if (max - min >= 0 && max - min < 1) {
		return (map->color_tab_grass[i][j]);
	} else if (max - min >= 1 && max - min <= 3) {
		return (map->color_tab_dirt[i][j]);
	} else {
		return (map->color_tab_stone[i][j]);
	}
}

void	draw_vertex_array(sfRenderWindow *window, sfVector2f **map_2d, int i, int j, map_t *map)
{
	sfVertexArray *tmp = NULL;

	if (i < map->map_x - 1 && j < map->map_y - 1) {
		tmp = create_quads(&map_2d[i][j], &map_2d[i][j + 1], &map_2d[i + 1][j + 1], &map_2d[i + 1][j], select_color(map, i, j));
		RW_DVA(window, tmp, NULL);
		sfVertexArray_destroy(tmp);
	}
	//DECOMMENT TO DISPLAY LINES
	if (lol == 1) {
		if (j + 1 <= map->map_y - 1) {
			tmp = create_line(&map_2d[i][j], &map_2d[i][j + 1]);
			RW_DVA(window, tmp, NULL);
			sfVertexArray_destroy(tmp);
		}
		if (i + 1 <= map->map_x - 1) {
			tmp = create_line(&map_2d[i][j], &map_2d[i + 1][j]);
			RW_DVA(window, tmp, NULL);
			sfVertexArray_destroy(tmp);
		}
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

	// printf("%f\n", map->rotation);
	if (map->rotation >= 0 && map->rotation < 90)
		for (int j = map->map_y - 1; j >= 0; j--)
			for (int i = 0; i <= map->map_x - 1; i++)
				draw_vertex_array(window, map->map_2d, i, j, map);
	if (map->rotation >= 90 && map->rotation < 180)
		for (int i = map->map_x - 1; i >= 0; i--)
			for (int j = map->map_y - 1; j >= 0; j--)
				draw_vertex_array(window, map->map_2d, i, j, map);
	if (map->rotation >= 180 && map->rotation < 270)
		for (int j = 0; j < map->map_y - 1 ; j++)
			for (int i = map->map_x - 1; i >= 0; i--)
				draw_vertex_array(window, map->map_2d, i, j, map);
	if (map->rotation >= 270 && map->rotation <= 360)
		for (int i = 0; i < map->map_x - 1; i++)
			for (int j = 0; j < map->map_y - 1 ; j++)
				draw_vertex_array(window, map->map_2d, i, j, map);
}
