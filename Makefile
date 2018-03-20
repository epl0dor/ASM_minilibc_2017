##
## Makefile for Makefile in /home/collei_r/Rendu/asm_minilibc
##
## Made by Rodolphe Colleie
## Login   <collei_r@epitech.net>
##
## Started on  Fri Mar 24 15:44:22 2017 Rodolphe Colleie
## Last update Sun Mar 26 21:25:51 2017 Rodolphe Colleie
##

CC	= 	ld

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

OBJS	= 	$(SRCS:.s=.o)

CFLAGS 	= 	-shared -fPIC

AS	=	nasm -f elf64

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

tests_run:
		@cd tests && $(MAKE)
		mv tests/*.gcno .

clean:
		@$(RM) $(OBJS)
		@$(RM) *.gcno

fclean:		clean
		@$(RM) $(NAME)

clean_all:	fclean
		@cd tests/ && $(MAKE) fclean

re:		fclean all
