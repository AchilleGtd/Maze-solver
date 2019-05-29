##
## EPITECH PROJECT, 2018
## MAKEFILE
## File description:
## compile makefile
##

SRC	=	get_maze.c\
read_file.c\
utility.c\
a_star.c\
solver.c\
list_management.c\
str_to_wordtab.c

OBJ	=	$(SRC:.c=.o)

NAME	=	test

all:	$(NAME) clean

$(NAME):	$(OBJ)
	ar rc libmy.a $(OBJ)

clean :
	rm -f $(OBJ)
