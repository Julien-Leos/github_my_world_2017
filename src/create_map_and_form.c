/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** create_map_and_form
*/

#include "main.h"

sfVertexArray *create_line(V2F *point1, V2F *point2)
{
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex vertex1 = {.position = *point1, .color = sfWhite};
	sfVertex vertex2 = {.position = *point2, .color = sfWhite};

	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
	return (vertex_array);
}

sfVertexArray *create_quads(sfVector2f **vector_tab, sfColor color)
{
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex vertex1 = {.position = *vector_tab[0], .color = color,
		.texCoords = (V2F){0, 0}};
	sfVertex vertex2 = {.position = *vector_tab[1], .color = color,
		.texCoords = (V2F){0, SCALING_Y}};
	sfVertex vertex3 = {.position = *vector_tab[2], .color = color,
		.texCoords = (V2F){SCALING_X, SCALING_Y}};
	sfVertex vertex4 = {.position = *vector_tab[3], .color = color,
		.texCoords = (V2F){SCALING_X, 0}};

	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_append(vertex_array, vertex3);
	sfVertexArray_append(vertex_array, vertex4);
	sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
	return (vertex_array);
}

float	**create_3d_map(map_t *map)
{
	float **map_3d = malloc(sizeof(int*) * map->map_x);

	for (int i = 0; i < map->map_x; i++) {
		map_3d[i] = malloc(sizeof(int) * map->map_y);
		for (int j = 0; j < map->map_y; j++)
			map_3d[i][j] = 0;
	}
	return (map_3d);
}

V2F **create_2d_map(float **map_3d, map_t *map, settings_t *stg)
{
	V2F **map_2d = malloc(sizeof(V2F*) * (map->map_x + 1000));
	sfVector3f param;

	for (int j = 0; j < map->map_x; j++) {
		map_2d[j] = malloc(sizeof(V2F) * (map->map_y + 1000));
		for (int i = 0; i < map->map_y; i++) {
			param.x = i * SCALING_X * stg->zoom;
			param.y = j * SCALING_Y * stg->zoom;
			param.z = map_3d[j][i] * SCALING_Z *stg->zoom;
			map_2d[j][i] = project_iso_point(param, stg, map);
		}
	}
	return (map_2d);
}
