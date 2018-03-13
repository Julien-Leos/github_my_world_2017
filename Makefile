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
			src/square.c \
			src/brush.c \
			src/draw.c \
			src/textbox.c \
			src/utilities.c \

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
