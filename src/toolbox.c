/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** toolbox
*/

#include "main.h"

int    buttonIsClicked(obj_t *obj, sfVector2i clickPosition, int i)
{
	return (clickPosition.x < sfSprite_getPosition(obj[i].sprite).x + 80 &&
	clickPosition.x > sfSprite_getPosition(obj[i].sprite).x &&
	clickPosition.y < sfSprite_getPosition(obj[i].sprite).y + 80 &&
	clickPosition.y > sfSprite_getPosition(obj[i].sprite).y);
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
void set_rectangle_for_box(all_t *all)
{
	sfRectangleShape_setSize(all->button->rect, (sfVector2f){3, 1080});
	RS_SETPOS(all->button->rect, (sfVector2f){125, 0});
	sfRectangleShape_setFillColor(all->button->rect, sfWhite);
	sfRectangleShape_setSize(all->button->text_one, (sfVector2f){3, 70});
	RS_SETPOS(all->button->text_one,(sfVector2f){1400, 10});
	sfRectangleShape_setFillColor(all->button->text_one, sfWhite);
	sfRectangleShape_setSize(all->button->text_two, (sfVector2f){3, 70});
	RS_SETPOS(all->button->text_two, (sfVector2f){1800, 10});
	sfRectangleShape_setFillColor(all->button->text_two, sfWhite);
	sfRectangleShape_setSize(all->button->text_three, (sfVector2f){400, 3});
	RS_SETPOS(all->button->text_three, (sfVector2f){1400, 10});
	sfRectangleShape_setFillColor(all->button->text_three, sfWhite);
	sfRectangleShape_setSize(all->button->text_four, (sfVector2f){403, 3});
	RS_SETPOS(all->button->text_four, (sfVector2f){1400, 80});
	sfRectangleShape_setFillColor(all->button->text_four, sfWhite);
}

void init_button_shape(all_t *all)
{
	all->button->rect = sfRectangleShape_create();
	all->button->text_one = sfRectangleShape_create();
	all->button->text_two = sfRectangleShape_create();
	all->button->text_three = sfRectangleShape_create();
	all->button->text_four = sfRectangleShape_create();
}

void init_toolbox(all_t *all)
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

	init_button_shape(all);
	all->obj[0] = create_object(scale, "./images/save.png", pos);
	all->obj[1] = create_object(scale, "./images/load.png", pos2);
	all->obj[2] = create_object(scale, "./images/up.png", pos3);
	all->obj[3] = create_object(scale, "./images/down.png", pos4);
	all->obj[4] = create_object(scale, "./images/level.png", pos5);
	all->obj[5] = create_object(scale, "./images/reset.png", pos6);
	all->obj[6] = create_object(scale, "./images/layout.png", pos7);
	all->obj[7] = create_object(scale, "./images/random.png", pos8);
	set_rectangle_for_box(all);
}
