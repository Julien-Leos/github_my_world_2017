/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** draw
*/

#include "main.h"

sfRenderWindow *my_window_create(void)
{
	sfRenderWindow *window;
	sfVideoMode mode;

	mode.width = 1920;
	mode.height = 1080;
	mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(mode, "My World", sfDefaultStyle, NULL);
	sfRenderWindow_setFramerateLimit(window, 30);
	return (window);
}

void	draw_window(window_t *win)
{
	sfRenderWindow_display(win->window);
	sfRenderWindow_clear(win->window, sfBlack);
	win->mouse_pos = sfMouse_getPositionRenderWindow(win->window);
}

void	draw_toolbox(window_t *win, obj_t *obj, button_t *button)
{
	for (int i = 0; i != 8; i++)
		sfRenderWindow_drawSprite(win->window, obj[i].sprite, NULL);
	sfRenderWindow_drawRectangleShape(win->window, button->rect, NULL);
	sfRenderWindow_drawRectangleShape(win->window, button->text_one, NULL);
	sfRenderWindow_drawRectangleShape(win->window, button->text_two, NULL);
	sfRenderWindow_drawRectangleShape(win->window, button->text_three, NULL);
	sfRenderWindow_drawRectangleShape(win->window, button->text_four, NULL);
	sfRenderWindow_drawText(win->window, win->textbox, NULL);

}
