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

sfVector2f project_iso_point(int x, int y, int z, map_t *map)
{
	sfVector2f vec = {0, 0};
	double rotation = (map->rotation / 180.0 * M_PI);
	double inclinaison = (map->inclinaison / 180.0 * M_PI);
	int x_origine = 0;
	int y_origine = 0;

	if (map->map_x % 2 == 0) {
		x_origine = ((SCALING_X * map->zoom * (map->map_x - 1)) / 2) + map->move_x;
		y_origine = ((SCALING_Y * map->zoom * (map->map_y - 1)) / 2) + map->move_y;
	} else {
		x_origine = ((SCALING_X * map->zoom * map->map_x) / 2) + map->move_x;
		y_origine = ((SCALING_Y * map->zoom * map->map_y) / 2) + map->move_y;
	}
	vec.x = (x - x_origine) * cos (rotation) + (y - y_origine) * sin (rotation) + x_origine;
	vec.y = - (x - x_origine) * sin (rotation) + (y - y_origine) * cos (rotation) + y_origine;
	vec.y = (vec.y - y_origine) * cos (inclinaison) - (z) * sin (inclinaison) + y_origine;
	vec.x += 1920 / 2 - x_origine;
	vec.y += 1080 / 2 - y_origine;
	return(vec);
}

// <<<<<<< HEAD
// float	**create_3d_map(int leveling)
// {
// 	float **map_3d = malloc(sizeof(float *) * MAP_X);
//
// 	for (int i = 0; i < MAP_X; i++) {
// 		map_3d[i] = malloc(sizeof(float) * MAP_Y);
// 		for (int j = 0; j < MAP_Y; j++) {
// 			// map_3d[i][j] = Get2DPerlinNoiseValue(i + 0.5, j + 0.5, SCALING_X, SCALING_Y) * leveling;
// 			// map_3d[i][j] = bruit_coherent2D(i, j, 0.5) * leveling;
// 			// printf("%f\n", bruit_coherent2D(i, j, 0.5) * leveling);
// 		}
// =======
float	**create_3d_map(map_t *map)
{
	float **map_3d = malloc(sizeof(int *) * map->map_x);
	int octave = 3;
	float persistance = 0.57;
	float lacunarity = 1.7;
	float amplitude = 0;
	float frequency = 0;
	float noise_height = 0;
	float perlin_value = 0;
	float sample_x = 0;
	float sample_y = 0;

	for (int i = 0; i < map->map_x; i++) {
		map_3d[i] = malloc(sizeof(int) * map->map_y);
		for (int j = 0; j < map->map_y; j++) {
			amplitude = 1;
			frequency = 1;
			noise_height = 0;
			for (int i = 0; i < octave; i++) {
				sample_x = i / SCALING_X * frequency;
				sample_y = j / SCALING_Y * frequency;

				perlin_value = Get2DPerlinNoiseValue(sample_x, sample_y);
				noise_height += perlin_value * amplitude;

				amplitude *= persistance;
				frequency *= lacunarity;
			}
			map_3d[i][j] = perlin_value;
			printf("%f\n", map_3d[i][j]);
		}
// >>>>>>> 8065cec15760d478cc1b10699b396a9ae08f53f0
	}
	return (map_3d);
}

sfVector2f **create_2d_map(float **map_3d, map_t *map)
{
	sfVector2f **map_2d = malloc(sizeof(sfVector2f *) * (map->map_x));

	for (int j = 0; j < map->map_x; j++) {
		map_2d[j] = malloc(sizeof(sfVector2f) * map->map_y);
		for (int i = 0; i < map->map_y; i++) {
			map_2d[j][i] = project_iso_point(i * SCALING_X * map->zoom,
				j * SCALING_Y * map->zoom, map_3d[j][i] * SCALING_Z *map->zoom, map);
		}
	}
	return (map_2d);
}
