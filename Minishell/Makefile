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

all: $(NAME)

$(OBJS): %.o: %.c
	$(CC) $(FLAGS) -c -o $@ $< -lreadline

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) -lreadline

clean:
	rm -f $(OBJS)
	$(RM) $(OBJS)

fclean: clean
	rm -f $(NAME)
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
