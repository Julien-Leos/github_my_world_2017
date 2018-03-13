/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** Main file.
*/

#include "main.h"

int	verif_tab(unsigned int *tab, unsigned int random)
{
	for (int i = 0; i < 256; i++)
		if (tab[i] == random)
			return (1);
	return (0);
}

unsigned int	*generate_randomised_tab(void)
{
	unsigned int *tab = malloc(sizeof(unsigned int) * 256);
	unsigned int random = 0;

	for (int i = 0; i < 256; i++) {
		random = rand() % 257;
		while (verif_tab(tab, random) != 0)
			random = rand() % 257;
		tab[i] = random;
	}
	return (tab);
}

void	get_perlin_noise_sub(float *flt, int *inte, float grd[][2], V2F crd)
{
	flt[0] = grd[inte[0]][0] * flt[9] + grd[inte[0]][1] * flt[10];
	flt[9] = crd.x - (inte[4] + 1);
	flt[10] = crd.y - inte[5];
	flt[1] = grd[inte[1]][0] * flt[9] + grd[inte[1]][1] * flt[10];
	flt[9] = crd.x - inte[4];
	flt[10] = crd.y - (inte[5] + 1);
	flt[2] = grd[inte[2]][0] * flt[9] + grd[inte[2]][1] * flt[10];
	flt[9] = crd.x - (inte[4] + 1);
	flt[10] = crd.y - (inte[5] + 1);
	flt[3] = grd[inte[3]][0] * flt[9] + grd[inte[3]][1] * flt[10];
	flt[4] = crd.x - inte[4];
	flt[5] = 3 * flt[4] * flt[4] - 2 * flt[4] * flt[4] * flt[4];
	flt[7] = flt[0] + flt[5] * (flt[1] - flt[0]);
	flt[8] = flt[2] + flt[5] * (flt[3] - flt[2]);
	flt[4] = crd.y - inte[5];
	flt[6] = 3 * flt[4] * flt[4] - 2 * flt[4] * flt[4] * flt[4];
}

float	get_perlin_noise_value(float x, float y, unsigned int *perm)
{
	int *inte = malloc(sizeof(int) * 8);
	float *flt = malloc(sizeof(float) * 11);
	float unit = 1.0f/sqrt(2);
	float grd[][2] = {{unit,unit}, {-unit,unit}, {unit,-unit},
	{-unit,-unit}, {1,0}, {-1,0}, {0,1}, {0,-1}};

	inte[4] = (int)(x);
	inte[5] = (int)(y);
	inte[6] = inte[4] & 255;
	inte[7] = inte[5] & 255;
	inte[0] = perm[inte[6] + perm[inte[7]]] % 8;
	inte[1] = perm[inte[6] + 1 + perm[inte[7]]] % 8;
	inte[2] = perm[inte[6] + perm[inte[7] + 1]] % 8;
	inte[3] = perm[inte[6] + 1 + perm[inte[7] + 1]] % 8;
	flt[9] = x - inte[4];
	flt[10] = y - inte[5];
	get_perlin_noise_sub(flt, inte, grd, (V2F){x, y});
	return flt[7] + flt[6] * (flt[8] - flt[7]);
}
