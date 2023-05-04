NAME = minishell

SRCS =	main.c \
		environment.c \

OBJS = $(SRCS:c=o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
HEADER = minishell.h
INCLUDES = -I./includes
LIBFTPRINTF = libftprintf/libftprintf.a

all:	$(NAME)

$(LIBFTPRINTF):
	$(MAKE) -C ./libftprintf

$(NAME): $(OBJS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTPRINTF) -o $(NAME) -lreadline

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C ./libftprintf

fclean: 
	$(RM) $(OBJS)
	$(RM) $(NAME)
	$(MAKE) fclean -C ./libftprintf

re:	fclean all

.PHONY: all clean fclean