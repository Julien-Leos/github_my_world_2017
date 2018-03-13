/*
** EPITECH PROJECT, 2017
** getnbr
** File description:
** getnbr
*/

#include "main.h"

int nbr_maker(char *str, int i)
{
	int nb = 0;

	while (str[i] >= '0' && str[i] <= '9') {
		nb = nb * 10;
		nb = nb + str[i] - '0';
		i++;
	}
	return (nb);
}

float	my_getfloat(char *str)
{
	int i = 0;
	int integer = 0;
	float decimal = 0;
	int is_negative = 1;

	if (str == NULL)
		return (-1);
	if (str[i] == '-') {
		is_negative = -1;
		i++;
	}
	for (; str[i] != '.'; i++)
		integer = (integer * 10) + str[i] - '0';
	i++;
	for (; str[i] != '\0'; i++)
		decimal = (decimal * 10) + str[i] - '0';
	return ((integer + (decimal / 100)) * is_negative);
}

int my_getnbr(char *str)
{
	int nb = 0;
	int j = 0;
	int i = 0;

	while (str && str[i] != '\0' && nb == 0) {
		if ((str[i] <= 47 && str[i] != 45) ||
		(str[i] >= 58 && str[i] != 45)) {
			return (-991);
			}
		if (str[i] == '-')
			j++;
		if (str[i] >= '0' && str[i] <= '9')
			nb = nbr_maker(str, i);
		i++;
	}
	if (j % 2 == 1)
		nb = - nb;
	return (nb);
}
