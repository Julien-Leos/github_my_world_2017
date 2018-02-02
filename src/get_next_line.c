/*
** EPITECH PROJECT, 2018
** Project nextline
** File description:
** Main file.
*/

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/get_next_line.h"

int my_strlen(char *str)
{
	int a = 0;

	while (str != NULL && str[a] != '\0')
		a++;
	return (a);
}

int test(char *total, int *stop)
{
	int i = 0;
	while (total[i] != '\0') {
		if (total[i] == '\n')
		*stop = 0;
		i++;
	}
	return (0);
}

char *my_strcat(char *str, char *tmp, int *stop)
{
	int i = 0;
	int j = 0;
	int a = my_strlen(str);
	int b = my_strlen(tmp);
	char *total = malloc(sizeof(char) * (a + b + 1));

	while (str != NULL && str[i] != '\0') {
		total[i] = str[i];
		i++;
	}
	free(str);
		total[i] = tmp[j];
		while (tmp[j] != '\0') {
		j++;
		i++;
	}
	total[i] = '\0';
	test(total, stop);
	return (total);
}
char *checkend(char *str)
{
	int i = my_strlen(str);
	while (str && str[i] != '\n')
		i--;
	if (str)
		str[i + 1] = '\0';
	return (str);
}
char *next(char *str)
{
	char *next;
	static int j = 0;
	int a = 0;

	next = malloc(sizeof(char) * (my_strlen(str) + 1));

	if (str != NULL && str[j] != '\0') {
		while (str[j] != '\n' && str[j] != '\0') {
			next[a] = str[j];
			j++;
			a++;
		}
		j++;
		next[a] = '\0';
		j = 0;
		return (next);
	}
	else
		return (NULL);
}

char *get_next_line(int fd)
{
	char *str = NULL;
	char *tmp;
	char *line;
	int a = 0;
	int stop = 1;

	if  (READ_SIZE <= 0)
		return (NULL);
	if ((tmp = malloc(sizeof(char) * READ_SIZE + 1)) == NULL)
		return (NULL);
	a = read(fd, tmp, READ_SIZE);
	tmp[a] = '\0';
	while (a != 0 && stop != 0) {
		str = my_strcat(str, tmp, &stop);
		if (stop != 0)
			a = read(fd, tmp, READ_SIZE);
	}
	str = checkend(str);
	line = next(str);
	return (line);
}
