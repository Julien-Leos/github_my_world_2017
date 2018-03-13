/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** Utilities2
*/

#include "main.h"

char	*my_itoa_str(float *nb, int *len, int *i, char *str)
{
	str = malloc(sizeof(char) * ((*len) + 5));
	*nb *= my_power(10, 2);
	for (int e = 0; e < 2; e++, (*i)++) {
		str[*i] = (int)(*nb) % 10 + '0';
		*nb /= 10;
	}
	str[*i] = '.';
	(*i)++;
	for (; *i < *len + 3; (*i)++) {
		str[*i] = (int)(*nb) % 10 + '0';
		*nb /= 10;
	}
	return (str);
}
void	check_nb(float *nb, int *is_negative, int *len, int *tmp)
{
	if (*nb < 0) {
		*is_negative = 1;
		*nb *= -1;
	}
	if (*nb == 0)
		*len = 1;
	*tmp = (int)(*nb);
	while (*tmp > 0) {
		*tmp /= 10;
		(*len)++;
	}
}

char	*my_itoa(float nb)
{
	int len = 0;
	char *str = NULL;
	int tmp = 0;
	int i = 0;
	int is_negative = 0;

	check_nb(&nb, &is_negative, &len, &tmp);
	str = my_itoa_str(&nb, &len, &i, str);
	if (is_negative == 1) {
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
	return (my_revstr(str));
}
