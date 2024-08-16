##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## funcion which
##

NAME	=	my_hunter

LIB	=	-lcsfml-audio -lcsfml-system -lcsfml-window -lcsfml-graphics

INCLUDE	=	-I ./include/

SRC	= 	src/main.c	\
		src/display.c	\
		src/eventos.c	\
		src/int_to_str.c	\
		src/my_putchar.c	\
		src/my_putstr.c	\
		src/my_strlen.c	\
		src/my_revstr.c	\
		src/person.c	\
		src/struct.c	\

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): 	$(OBJ)
		gcc -g $(OBJ) -o $(NAME) $(INCLUDE) $(LIB)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f ./src/*.o

re: fclean all

exec:	re
	./$(NAME)
