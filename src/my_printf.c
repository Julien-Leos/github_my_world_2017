/*
** EPITECH PROJECT, 2017
** epitech
** File description:
** my_printf
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void my_putchar(char c, int *i)
{
	(*i)++;
	write(1, &c, 1);
}

int my_putstr(char const *str, int *i)
{
	int e = 0;

	while (str[e] != '\0') {
		my_putchar(str[e], i);
		e = e + 1;
	}
	return (0);
}

int my_put_nbr(int nb, int *i)
{
	int mod;

	if (nb == -2147483648)
		return (84);
	if (nb < 0) {
		my_putchar('-', i);
		nb = nb * (-1);
	}
	if (nb >= 0) {
		if (nb >= 10) {
			mod = (nb % 10);
			nb = (nb - mod) / 10;
			my_put_nbr(nb, i);
			my_putchar((48 + mod), i);
		}
		else
			my_putchar((48 + nb % 10), i);
	}
	return (0);
}

void difcase(va_list list, char character, int *i)
{
	switch (character) {
	case 's':
	       	my_putstr(va_arg(list, char *), i);
		break;
	case 'c':
		my_putchar(va_arg(list, int), i);
		break;
	case 'i':
	case 'd':
		my_put_nbr((va_arg(list, int)), i);
	}
}

int my_printf(char *s, ...)
{
	va_list list;
	int i = 0;

	va_start(list, s);
	for (int a = 0; s[a] != '\0'; a++) {
		if (s[a] == '%') {
			a++;
			difcase(list, s[a], &i);
		}
		else
			my_putchar(s[a], &i);
	}
	va_end(list);
	return (i);
}
