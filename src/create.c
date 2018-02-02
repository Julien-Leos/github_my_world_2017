/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** Main file.
*/

#include "main.h"

sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2)
{
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex vertex1 = {.position = *point1, .color = sfWhite};
	sfVertex vertex2 = {.position = *point2, .color = sfWhite};

	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
	return (vertex_array);
}

sfVector2f project_iso_point(int x, int y, int z, map_t *map)
{
	sfVector2f vec = {0, 0};
	double rotation = (map->rotation / 180.0 * M_PI);
	double inclinaison = (map->inclinaison / 180.0 * M_PI);
	int x_origine = 0;
	int y_origine = 0;
	if (MAP_X % 2 == 0) {
		x_origine = (SCALING_X * (MAP_X - 1)) / 2;
		y_origine = (SCALING_Y * (MAP_Y - 1)) / 2;
	} else {
		x_origine = (SCALING_X * MAP_X) / 2;
		y_origine = (SCALING_Y * MAP_Y) / 2;
	}

	vec.x = (x - x_origine) * cos (rotation) + (y - y_origine) * sin (rotation) + x_origine;
	vec.y = - (x - x_origine) * sin (rotation) + (y - y_origine) * cos (rotation) + y_origine;

	vec.y = (vec.y - y_origine) * cos (inclinaison) - (z) * sin (inclinaison) + y_origine;

	vec.x += 1920 / 2 - x_origine;
	vec.y += 1080 / 2 - y_origine;
	return(vec);
}

int	**create_3d_map()
{
	int **map_3d = malloc(sizeof(int *) * MAP_X);

	for (int i = 0; i < MAP_X; i++) {
		map_3d[i] = malloc(sizeof(int) * MAP_Y);
		for (int j = 0; j < MAP_Y; j++)
			map_3d[i][j] = 0;
	}
	return (map_3d);
}

sfVector2f **create_2d_map(int **map_3d, map_t *map)
{
	sfVector2f **map_2d = malloc(sizeof(sfVector2f *) * (MAP_X));

	for (int j = 0; j < MAP_X; j++) {
		map_2d[j] = malloc(sizeof(sfVector2f) * MAP_Y);
		for (int i = 0; i < MAP_Y; i++) {
			map_2d[j][i] = project_iso_point(i * SCALING_X,
				j * SCALING_Y, map_3d[j][i] * SCALING_Z, map);
		}
	}
	return (map_2d);
}
