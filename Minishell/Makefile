NAME = minishell
CC = gcc
FLAGS = -Wall -Wextra -Werror -g
RM = rm -f

SRCS_DIR = sources/

FILES = ft_split_string \
		main \
		split_quotes \


SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS_DIR = sources/

OBJS = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

LIBFTPRINTF = libftprintf/libftprintf.a

all: $(NAME)

$(OBJS): %.o: %.c
	$(CC) $(FLAGS) -c -o $@ $< -lreadline

$(LIBFTPRINTF):
	$(MAKE) -C ./libftprintf

$(NAME): $(OBJS) $(LIBFTPRINTF)
	$(CC) $(FLAGS) $(OBJS) $(LIBFTPRINTF) -o $(NAME) -lreadline

clean:
	rm -f $(OBJS)
	$(RM) $(OBJS)
	$(MAKE) clean -C ./libftprintf

fclean: clean
	rm -f $(NAME)
	$(RM) $(NAME)
	$(MAKE) fclean -C ./libftprintf

re: clean all

.PHONY: all clean fclean re
