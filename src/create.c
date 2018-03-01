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

sfVertexArray *create_quads(sfVector2f *point1, sfVector2f *point2,
	sfVector2f *point3, sfVector2f *point4, sfColor color)
{
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex vertex1 = {.position = *point1, .color = color, .texCoords = (sfVector2f){0, 0}};
	sfVertex vertex2 = {.position = *point2, .color = color, .texCoords = (sfVector2f){0, SCALING_Y}};
	sfVertex vertex3 = {.position = *point3, .color = color, .texCoords = (sfVector2f){SCALING_X, SCALING_Y}};
	sfVertex vertex4 = {.position = *point4, .color = color, .texCoords = (sfVector2f){SCALING_X, 0}};

	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_append(vertex_array, vertex3);
	sfVertexArray_append(vertex_array, vertex4);
	sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
	return (vertex_array);
}

sfVector2f project_iso_point(int x, int y, int z, settings_t *stg, map_t *map)
{
	sfVector2f vec = {0, 0};
	double rotation = (stg->rotation / 180.0 * M_PI);
	double inclinaison = (stg->inclinaison / 180.0 * M_PI);
	int x_origine = 0;
	int y_origine = 0;

	if (map->map_x % 2 == 0) {
		x_origine = ((SCALING_X * stg->zoom * (map->map_x - 1)) / 2);
		y_origine = ((SCALING_Y * stg->zoom * (map->map_y - 1)) / 2);
	} else {
		x_origine = ((SCALING_X * stg->zoom * map->map_x) / 2);
		y_origine = ((SCALING_Y * stg->zoom * map->map_y) / 2);
	}
	vec.x = (x - x_origine) * cos (rotation) + (y - y_origine) * sin (rotation) + x_origine;
	vec.y = - (x - x_origine) * sin (rotation) + (y - y_origine) * cos (rotation) + y_origine;
	vec.y = (vec.y - y_origine) * cos (inclinaison) - (z) * sin (inclinaison) + y_origine;
	vec.x += (1920 / 2) - x_origine + stg->offset_x;
	vec.y += (1080 / 2) - y_origine + stg->offset_y;
	return(vec);
}

float	**create_3d_map(map_t *map)
{
	float **map_3d = malloc(sizeof(int*) * map->map_x);
	// int octave = 4;
	// float persistance = 0.57;
	// float lacunarity = 1.72;
	// float amplitude = 0;
	// float frequency = 0;
	// float noise_height = 0;
	// float perlin_value = 0;
	// float sample_x = 0;
	// float sample_y = 0;

	for (int i = 0; i < map->map_x; i++) {
		map_3d[i] = malloc(sizeof(int) * map->map_y);
		for (int j = 0; j < map->map_y; j++) {
			map_3d[i][j] = 0;
			// amplitude = 1;
			// frequency = 1;
			// noise_height = 0;
			// for (int e = 0; e < octave; e++) {
			// 	sample_x = (i + 0.5) / SCALING_X;
			// 	sample_y = (j + 0.5) / SCALING_Y;
			//
			// 	perlin_value = Get2DPerlinNoiseValue(sample_x, sample_y);
			// 	noise_height += perlin_value * amplitude;
			//
			// 	amplitude *= persistance;
			// 	frequency *= lacunarity;
			// }
			// map_3d[i][j] = noise_height * 20;
		}
	}
	return (map_3d);
}

sfVector2f **create_2d_map(float **map_3d, map_t *map, settings_t *stg)
{
	sfVector2f **map_2d = malloc(sizeof(sfVector2f*) * map->map_x);

	for (int j = 0; j < map->map_x; j++) {
		map_2d[j] = malloc(sizeof(sfVector2f) * map->map_y);
		for (int i = 0; i < map->map_y; i++) {
			map_2d[j][i] = project_iso_point(i * SCALING_X * stg->zoom,
				j * SCALING_Y * stg->zoom, map_3d[j][i] * SCALING_Z *stg->zoom, stg, map);
		}
	}
	return (map_2d);
}
