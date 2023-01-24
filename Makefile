SRCS =	main.c \

OBJS = $(SRCS:c=o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
HEADER = minishell.h
INCLUDES = -I./includes

NAME = minishell

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean