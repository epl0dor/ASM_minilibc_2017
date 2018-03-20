##
## Makefile for Makefile in /home/collei_r/Rendu/asm_minilibc
##
## Made by Rodolphe Colleie
## Login   <collei_r@epitech.net>
##
## Started on  Fri Mar 24 15:44:22 2017 Rodolphe Colleie
## Last update Sun Mar 26 21:25:51 2017 Rodolphe Colleie
##

LD	= 	ld

CC	=	gcc

RM	= 	rm -f

NAME	= 	libasm.so

NAME2	= 	tests_asm

SRCS	= 	src/strlen.s \
		src/strchr.s \
		src/memset.s \
		src/memcpy.s \
		src/strcmp.s \
		src/memmove.s \
		src/strncmp.s \
		src/strcasecmp.s \
		src/rindex.s \
		src/strstr.s \
		src/strpbrk.s \
		src/strcspn.s

SRCS2	=	tests/tests-strlen.c \
		tests/tests-strchr.c \
		tests/tests-memset.c \
		tests/tests-memcpy.c \
		tests/tests-strcmp.c \
		tests/tests-memmove.c \
		tests/tests-strncmp.c \
		tests/tests-strcasecmp.c \
		tests/tests-rindex.c \
		tests/tests-strstr.c \
		tests/tests-strpbrk.c \
		tests/tests-strcspn.c

OBJS	= 	$(SRCS:.s=.o)

OBJS2	=	$(SRCS2:.c=.o)

CFLAGS 	= 	-shared -fPIC

AS	=	nasm -f elf64

all:		$(NAME)

$(NAME):	$(OBJS)
		$(LD) $(CFLAGS) -o $(NAME) $(OBJS)

tests_run:	$(OBJS2)
		@$(CC) $(SRCS2) -o $(NAME2) --coverage -lcriterion
		./run_tests

clean:
		@$(RM) $(OBJS)
		@$(RM) $(OBJS2)
		@$(RM) *.gcno
		@$(RM) *gcda
		@$(RM) *.gcov

fclean:		clean
		@$(RM) $(NAME)
		@$(RM) $(NAME2)

re:		fclean all
