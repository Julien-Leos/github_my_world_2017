/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** check_save
*/

#include "main.h"

int check_map_size(char **argv)
{
	int nb = 0;
	int fd = open(argv[1], O_RDONLY);
	int mapx = my_getfloat(get_next_line(fd));
	int mapy = my_getfloat(get_next_line(fd));
	char *str = get_next_line(fd);
	int result = mapx * mapy;

	while (str != NULL) {
		str = get_next_line(fd);
		nb += 1;
	}
	if (nb != result)
		return (-1);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	return (fd);
}

int check_save_content(int *len, char *str)
{
	*len = my_strlen(str);
	if (str[*len - 3] != '.')
		return (-1);
	while (*len != 0) {
		if ((str[*len] < '0' && str[*len] != '.' &&
		str[*len] != '-' &&  str[*len] != '\n' && str[*len] != '\0') ||
		(str[*len] > '9' && str[*len] != '.' &&
		str[*len] != '-' && str[*len] != '\n' && str[*len] != '\0'))
			return (-1);
		(*len)--;
	}
	if ((str[0] < '0' && str[0] != '-' && str[0] != '.') ||
	(str[0] > '9' && str[0] != '-' && str[0] != '.'))
		return (-1);
	return (0);
}

int check_if_argv_is_save(char **argv)
{
	int len = 0;
	int fd = open(argv[1], O_RDONLY);
	char *str = NULL;

	if (fd == -1)
		return (-1);
	str = get_next_line(fd);
	if (str == NULL)
		return (-1);
	while (str != NULL) {
		if (check_save_content(&len, str) == -1)
			return (-1);
		str = get_next_line(fd);
	}
	close(fd);
	fd = check_map_size(argv);
	return (fd);
}
