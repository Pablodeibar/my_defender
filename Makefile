##
## EPITECH PROJECT, 2022
## make
## File description:
## make
##

SRC		=	src/main.c										\
			src/basic_functions/my_get_nbr.c				\
			src/basic_functions/my_put.c					\
			src/grouped_functions/ini_struct.c				\
			src/game.c										\
			src/window/close_window.c						\
			src/grouped_functions/draw.c					\
			src/grouped_functions/destroy.c					\
			src/window/menu.c								\
			src/grouped_functions/ini_sprite.c				\
			src/clock/clock.c								\
			src/music_sound/music.c							\
			src/window/menu2.c								\
			src/window/close_window2.c						\
			src/gameplay/coins.c							\
			src/gameplay/buy_alli.c							\
			src/gameplay/pause.c							\
			src/linked_list/add_list.c						\
			src/linked_list/linked_list.c					\
			src/linked_list/linked_loop.c					\
			src/linked_list/ennemi_loop.c					\
			src/linked_list/linked_loop_2.c					\
			src/linked_list/linked_loop_3.c					\
			src/gameplay/life.c								\
			src/gameplay/buy_alli_2.c						\
			src/linked_list/collision.c						\
			src/grouped_functions/draw_2.c					\
			src/gameplay/ini_shop_3.c						\
			src/linked_list/suppr_elem.c					\

SRC_TESTS	=	src/basic_functions/my_get_nbr.c			\
				src/basic_functions/my_put.c				\
				test/basic_test.c							\

OBJ		=	$(SRC:%.c=%.o)

NAME	=	my_defender

NAME_TEST	=	unit_test

CC		=	gcc

CFLAGS	=	-I./include

LDFLAGS	=	-lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio -lm

TEST_FLAGS	=	--coverage -lcriterion

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

tests_run:
			$(CC) -o $(NAME_TEST) $(SRC_TESTS) $(TEST_FLAGS)
			./$(NAME_TEST)
			gcovr

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

debug:	CFLAGS += -g
debug:	re

.PHONY	=	all clean fclean re
