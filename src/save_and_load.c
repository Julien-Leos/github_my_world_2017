/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** save_and_load
*/

#include "main.h"

int load(all_t *all)
{
	int fd = open("save.txt", O_RDONLY);

	if (fd == -1)
		return (-1);
	get_next_line(fd);
	get_next_line(fd);
	for (int i = 0; i < all->map->map_x; i++) {
		for (int j = 0; j < all->map->map_y; j++)
			all->map->map_3d[i][j] = my_getfloat(get_next_line(fd));
	}
	return (0);
}

int save(all_t *all)
{
	int fd = open("save.txt", O_CREAT | O_TRUNC, S_IRWXU);
	if (fd == -1)
		return (-1);
	close(fd);
	fd = open("save.txt", O_WRONLY);
	my_putstrfd(fd, my_itoa(all->map->map_x));
	write(fd, "\n", 1);
	my_putstrfd(fd, my_itoa(all->map->map_y));
	write(fd, "\n", 1);
	for (int i = 0; i < all->map->map_x; i++) {
		for (int j = 0; j < all->map->map_y; j++) {
			my_putstrfd(fd, my_itoa(all->map->map_3d[i][j]));
			write(fd, "\n", 1);
		}
	}
	return (0);
}
