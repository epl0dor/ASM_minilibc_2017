##
## EPITECH PROJECT, 2018
## ASM
## File description:
## Makefile tests
##

CC	=	gcc

RM 	=	rm -f

NAME 	=	tests_asm

SRCS	=	tests-strlen.c \
		tests-strchr.c \
		tests-memset.c \
		tests-memcpy.c \
		tests-strcmp.c \
		tests-memmove.c \
		tests-strncmp.c \
		tests-strcasecmp.c \
		tests-rindex.c \
		tests-strstr.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)
		./run_tests

$(NAME):	$(OBJS)
		$(CC) $(SRCS) -o $(NAME) --coverage -lcriterion

clean:
		@$(RM) $(OBJS)
		@$(RM) *.gcno
		@$(RM) *.gcda
		@$(RM) *.gcov

fclean:         clean
		@$(RM) $(NAME)

re:             fclean all
