/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** Main file.
*/

#include "main.h"

sfColor select_color(map_t *map, int i, int j, sfRenderStates *state)
{
	float max = -10000;
	float min = 10000;
	max = max > map->map_3d[i][j] ? max : map->map_3d[i][j];
	max = max > map->map_3d[i][j + 1] ? max : map->map_3d[i][j + 1];
	max = max > map->map_3d[i + 1][j] ? max : map->map_3d[i + 1][j];
	max = max > map->map_3d[i + 1][j + 1] ? max : map->map_3d[i + 1][j + 1];
	min = min < map->map_3d[i][j] ? min : map->map_3d[i][j];
	min = min < map->map_3d[i][j + 1] ? min : map->map_3d[i][j + 1];
	min = min < map->map_3d[i + 1][j] ? min : map->map_3d[i + 1][j];
	min = min < map->map_3d[i + 1][j + 1] ? min : map->map_3d[i + 1][j + 1];
	if (fabs(max - min) >= 0 && fabs(max - min) < 1) {
		state->texture = map->texture_tab[0];
		return (map->color_tab[0][i][j]);
	} else if (fabs(max - min) >= 1 && fabs(max - min) <= 3) {
		state->texture = map->texture_tab[1];
		return (map->color_tab[1][i][j]);
	} else {
		state->texture = map->texture_tab[2];
		return (map->color_tab[2][i][j]);
	}
}

void	draw_lines(map_t *map, sfRenderWindow *win, V2I crd, sfVector2f **v_tab)
{
	sfVertexArray *tmp = NULL;

	if (map->display_lines == 1) {
		if (crd.y + 1 <= map->map_y - 1) {
			tmp = create_line(v_tab[0], v_tab[1]);
			RW_DVA(win, tmp, NULL);
			sfVertexArray_destroy(tmp);
		}
		if (crd.x + 1 <= map->map_x - 1) {
			tmp = create_line(v_tab[0], v_tab[3]);
			RW_DVA(win, tmp, NULL);
			sfVertexArray_destroy(tmp);
		}
	}
}

void	draw_quads(map_t *map, sfRenderWindow *win, sfRenderStates *st, V2I crd)
{
	sfVertexArray *tmp = NULL;
	sfVector2f **vector_tab = malloc(sizeof(sfVector2f*) * 4);

	vector_tab[0] = &map->map_2d[crd.x][crd.y];
	vector_tab[1] = &map->map_2d[crd.x][crd.y + 1];
	vector_tab[2] = &map->map_2d[crd.x + 1][crd.y + 1];
	vector_tab[3] = &map->map_2d[crd.x + 1][crd.y];
	if (crd.x < map->map_x - 1 && crd.y < map->map_y - 1) {
		tmp = create_quads(vector_tab,
			select_color(map, crd.x, crd.y, st));
		RW_DVA(win, tmp, st);
		sfVertexArray_destroy(tmp);
	}
	draw_lines(map, win, crd, vector_tab);
}

void	draw_2d_map(sfRenderWindow *win, map_t *map, settings_t *stg)
{
	sfRenderStates state;

	state.shader = NULL;
	state.texture = NULL;
	state.transform = sfTransform_Identity;
	state.blendMode = sfBlendAlpha;
	if (stg->rotation >= 0 && stg->rotation < 90)
		rotation_0_to_90(map, win, &state);
	if (stg->rotation >= 90 && stg->rotation < 180)
		rotation_90_to_180(map, win, &state);
	if (stg->rotation >= 180 && stg->rotation < 270)
		rotation_180_to_270(map, win, &state);
	if (stg->rotation >= 270 && stg->rotation <= 360)
		rotation_270_to_360(map, win, &state);
}
