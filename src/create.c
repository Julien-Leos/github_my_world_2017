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

sfVector2f project_iso_point(int x, int y, int z, angle_t *angle)
{
	sfVector2f vec = {0, 0};

	angle->angle_x = cos(45.0 / 180.0 * M_PI);
	angle->angle_y = sin((35 + angle->yolo_y) / 180.0 * M_PI);


	vec.x = angle->angle_x * x - angle->angle_x * y + 960;
	vec.y = angle->angle_y * y + angle->angle_y * x - z + 470;

	return(vec);
}
sfVector2f **create_2d_map(int **map_3d,angle_t *angle)
{
	sfVector2f **map_2d = malloc(sizeof(sfVector2f *) * (MAP_X));

	for (int j = 0; j < MAP_X; j++) {
		map_2d[j] = malloc(sizeof(sfVector2f) * MAP_Y);
		for (int i = 0; i < MAP_Y; i++) {
			map_2d[j][i] = project_iso_point(i * SCALING_X,
				j * SCALING_Y, map_3d[j][i] * SCALING_Z, angle);
		}
	}
	return (map_2d);
}
