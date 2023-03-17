##
## EPITECH PROJECT, 2021
## delivery
## File description:
## Makefile
##

NAME	=	bsq

PTSRC = printlib/my_put_nbr.c	\
	printlib/my_put_nbr_unsigned.c	\
	printlib/my_putstr.c	\
	printlib/my_putchar.c	\
	printlib/my_strlen.c	\
	printlib/base_type.c \
	printlib/basic_flag.c	\
	printlib/my_printf.c	\

SRC	=	main.c	\
	src/find_square.c	\
	src/my_strlen_for_specase.c	\
	src/my_getnbr.c	\
	src/transform_to_int_array.c	\
	src/remove_and_free.c	\
	src/process_algo.c	\

OBJ	=	$(SRC:.c=.o)	\
	$(PTSRC:.c=.o)

CFLAGS = -Wall -Wextra

CPPFLAGS = -I includes

all:	$(NAME)	\

debug : CFLAGS += -g3
debug : re

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)	\
	rm -f *~	\
	rm -f *#
	rm -f include/*.gch
	rm -f printlib/*.o
	rm -f vgcore.*

fclean:	clean
	rm -f $(NAME)

re:	fclean all