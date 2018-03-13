##
## EPITECH PROJECT, 2018
## Project My_world
## File description:
## Build My_world binary.
##

MAIN_SRC	=	src/main.c

SRC	=		src/create.c \
			src/display.c \
			src/toolbox.c \
			src/get_next_line.c \
			src/noise_test.c	\
			src/my_getnbr.c \
			src/events.c \
			src/events_keys.c \
			src/init.c \
			src/init2.c \
			src/brush/brush_tools.c \
			src/brush/display_brush.c	\
			src/brush/select_brush_corner.c	\
			src/brush/level_brush.c	\
			src/brush/up_brush.c	\
			src/brush/down_brush.c	\
			src/draw.c \
			src/textbox.c \
			src/utilities.c \
			src/increase_event.c \
			src/decrease_event.c \
			src/save_and_load.c \
			src/textbox_enter.c \
			src/my_printf.c \
			src/arguments.c \
			src/textbox_error.c \
			src/utilities2.c \
			src/check_save.c \
			src/create_map_and_form.c \
			src/rotation.c \
			src/switch_tools.c

UT_SRC	=	tests/main_test.c

OBJ	=	$(MAIN_SRC:.c=.o) $(SRC:.c=.o)

UT_OBJ	=	$(SRC:.c=.o) $(UT_SRC:.c=.o)

CFLAGS	=	-Wextra -W -Wall -I ./include/ -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -g3 -lm

MLFLAGS	=	-Wextra -W -Wall -I ./include/ -lc_graph_prog -g3 -lm

NAME	=	my_world

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(MLFLAGS)

dev:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(UT_OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f units
	rm -f *.html
	find . -name "*.gcda" -type f -delete
	find . -name "*.gcno" -type f -delete

re: fclean all

test_run:	CFLAGS += --coverage

test_run:	$(UT_OBJ)
		$(CC) -o units $(UT_OBJ) $(LDFLAGS) -lcriterion --coverage
		./units

cov:	test_run
	gcovr -r . --html -o coverage.html --html-details -e ".*tests/.*"
