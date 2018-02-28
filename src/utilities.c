/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** Utilities
*/

#include "main.h"

int	is_mouse_on_toolbox(sfVector2i mouse_pos)
{
	if (mouse_pos.x >= 0 && mouse_pos.x <= 128)
		return (1);
	return (0);
}

int my_power(int nb, int power)
{
	int res = nb;

	if (power > 0) {
		nb = res * my_power(nb, power - 1);
		return (nb);
	}
	else if (power == 0)
		return (1);
	else
		return (0);
}

int my_putstrfd(int fd, char *str)
{
	int i = 0;
	while (str[i] != '\0') {
		write(fd, &str[i], 1);
		i++;
	}
	return (0);
}

char	*my_itoa(float nb)
{
	int len = 0;
	char *str;
	float tmp = nb;

	while (tmp > 0) {
		tmp /= 10;
		len++;
	}
	str = malloc(sizeof(*str) * (len + 1));
	str[len] = '\0';
	while (len--) {
		str[len] = (int)nb % 10  + '0';
		nb /= 10;
	}
	return (str);
}
