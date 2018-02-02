/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** Main file.
*/

#include "main.h"

char *my_itoa(int nb)
{
	int len = 0;
	char *str;
	int tmp = nb;

	while (tmp > 0) {
		tmp /= 10;
		len++;
	}
	str = malloc(sizeof(*str) * (len + 1));
	str[len] = '\0';
	while (len--) {
		str[len] = nb % 10  + '0';
		nb /= 10;
	}
	return (str);
}
int load(all_t *all)
{
	int fd = open("save.txt", O_RDONLY);
	if (fd == -1)
		return -1;
	for (int i = 0; i < MAP_X; i++) {
		for (int j = 0; j < MAP_Y - 1 ; j++)
			all->map->map_3d[i][j] = my_getnbr(get_next_line(fd));
	}
	return (0);
}

int save(all_t *all)
{
	int fd = open("save.txt", O_CREAT, S_IRWXU);
	if (fd == -1)
		return -1;
	close(fd);
	fd = open("save.txt", O_WRONLY);
	printf("%d\n", all->map->map_3d[0][0]);
	for (int i = 0; i < MAP_X; i++) {
		for (int j = 0; j < MAP_Y - 1 ; j++) {
			write(fd, my_itoa(all->map->map_3d[i][j]), 2);
			write(fd, "\n", 1);
		}
	}
	return (0);
}

int    buttonIsClicked(obj_t *obj, sfVector2i clickPosition, int *i)
{
	return (clickPosition.x < sfSprite_getPosition(obj[*i].sprite).x + 80 &&
	clickPosition.x > sfSprite_getPosition(obj[*i].sprite).x &&
	clickPosition.y < sfSprite_getPosition(obj[*i].sprite).y + 80 &&
	clickPosition.y > sfSprite_getPosition(obj[*i].sprite).y);
}

obj_t	create_object(sfVector2f scale, char *path, sfVector2f pos)
{
	obj_t obj;
	obj.pos = pos;
	obj.text = sfTexture_createFromFile(path, NULL);
	obj.sprite = sfSprite_create();
	sfSprite_setScale(obj.sprite, scale);
	sfSprite_setTexture(obj.sprite, obj.text, sfTrue);
	sfSprite_setPosition(obj.sprite, obj.pos);
	return (obj);
}

int	create_toolbox(all_t *all)
{
	sfVector2f pos = {20, 30};
	sfVector2f pos2 = {20, 160};
	sfVector2f pos3 = {20, 290};
	sfVector2f pos4 = {20, 420};
	sfVector2f pos5 = {20, 550};
	sfVector2f pos6 = {20, 680};
	sfVector2f pos7 = {20, 810};
	sfVector2f pos8 = {20, 940};
	sfVector2f scale = {0.3, 0.3};
	sfVector2f position = {125, 0};
	sfVector2f size = {3, 1080};
	all->button->rect = sfRectangleShape_create();
	all->obj[0] = create_object(scale, "./square.png", pos);
	all->obj[1] = create_object(scale, "./square.png", pos2);
	all->obj[2] = create_object(scale, "./square.png", pos3);
	all->obj[3] = create_object(scale, "./square.png", pos4);
	all->obj[4] = create_object(scale, "./square.png", pos5);
	all->obj[5] = create_object(scale, "./square.png", pos6);
	all->obj[6] = create_object(scale, "./square.png", pos7);
	all->obj[7] = create_object(scale, "./square.png", pos8);

	sfRectangleShape_setSize(all->button->rect, size);
	sfRectangleShape_setPosition(all->button->rect, position);
	sfRectangleShape_setFillColor(all->button->rect, sfWhite);
	return (0);
}
