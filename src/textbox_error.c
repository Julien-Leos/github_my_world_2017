/*
** EPITECH PROJECT, 2018
** Project My_world
** File description:
** textbox_error
*/

#include "main.h"

int check_end(window_t *win)
{
	int nb = 0;
	int perfect = 0;
	int i = 0;

	while (win->input[i] != '\0') {
		if (win->input[i] == 120)
			nb += 1;
		if (win->input[i] == 'x' && win->input[i - 1] != 'x' &&
		win->input[i + 1] != '\0')
			perfect += 1;
		i++;
	}
	if (nb == 1 && perfect >= 1)
		return (0);
	else
		return (84);
}

int check_input(window_t *win, int *i, int *box)
{
	if (check_end(win) == 84) {
		for (int j = 0; j != *i; ++j)
			win->input[j] = '\0';
		*i = 0;
		*box = 0;
		sfText_setString(win->textbox, win->input);
		sfText_setFont(win->textbox, win->font);
		sfText_setCharacterSize(win->textbox, 50);
		sfText_setPosition(win->textbox, (sfVector2f){1410, 15});
		return (84);
	}
	return (0);
}
