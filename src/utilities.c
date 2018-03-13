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
	else if (mouse_pos.x >= 1400 && mouse_pos.x <= 1800 &&
	mouse_pos.y >= 10 && mouse_pos.y <= 80)
		return (1);
	return (0);
}

int	my_power(int nb, int power)
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

int	my_strlen(char *str)
{
	int a = 0;

	while (str != NULL && str[a] != '\0')
		a++;
	return (a);
}

int	my_putstrfd(int fd, char *str)
{
	int i = 0;
	while (str[i] != '\0') {
		write(fd, &str[i], 1);
		i++;
	}
	return (0);
}

char	*my_revstr (char *str)
{
	int i = 0;
	int len = my_strlen(str);
	int mid = len / 2;
	char x;

	while (i < mid) {
		x = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = x;
		i++;
	}
	return (str);
}
