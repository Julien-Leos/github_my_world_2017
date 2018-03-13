/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** arguments
*/

#include "main.h"

void	init_map_start(map_t *map, settings_t *stg, int fd)
{
	map->map_x = my_getfloat(get_next_line(fd));
	map->map_y = my_getfloat(get_next_line(fd));
	map->map_3d = create_3d_map(map);
	map->map_2d = create_2d_map(map->map_3d, map, stg);
	map->color_tab = malloc(sizeof(sfColor**) * 3);
	for (int i = 0; i < 3; i++) {
		map->color_tab[i] = malloc(sizeof(COL*) * map->map_x);
		for (int e = 0; e < map->map_x; e++) {
			map->color_tab[i][e] = malloc(sizeof(COL) * map->map_y);
		}
	}
	map->display_lines = -1;
	init_color_tab(map);
}

void show_options(void)
{
	my_printf("USAGE:\n ./my_world \
	\n\nOPTIONS:\n	HELP\n		./my_world -h \
	\n\n	LOAD MAP AT START\n		./my_world <map> \
	\n\nIN GAME USAGE:\n	KEYS\n		Z: tilt up \
	\n		Q: rotate left \n		S: tilt down \
	\n		D: rotate right\
	\n		Y: increase speed of brush \
	\n		H: decrease speed of brush \
	\n		G: increase size of brush \
	\n		J: decrease size of brush \
	\n		O: zoom in  \n		L: zoom out  \
	\n		V: display/hide vertex\
	\n\n	TOOLBOX(left on screen): \n		1: save \
	\n		2: load \n		3: TOOL: increase altitude \
	\n		4: TOOL: decrease altitude \
	\n		5: TOOL: put the altitude at the same point \
	\n		6: reset map \n		7: display grid layout \
	\n		8: generate randomized map \
	\n\n	TEXTBOX(up right corner on screen): \
	\n		Resize the map by writting 'Height X Width'\n\n\n");
}

int load_start(char **argv, all_t *all)
{
	int fd = check_if_argv_is_save(argv);

	if (fd == -1)
		return (84);
	init_map_start(all->map, all->stg, fd);
	for (int i = 0; i < all->map->map_x; i++) {
		for (int j = 0; j < all->map->map_y; j++)
			all->map->map_3d[i][j] = my_getfloat(get_next_line(fd));
		}
	return (0);
}

int check_argv(char **argv, all_t *all)
{
	if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
		show_options();
		return (1);
	} else
		if (load_start(argv, all) == 84)
			return (84);
	return (0);
}
