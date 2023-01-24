NAME = minishell
CC = gcc
FLAGS = -Wall -Wextra -Werror -g
RM = rm -f

SRCS_DIR = main /

FILES = main

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS_DIR = sources/

OBJS = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

all: $(NAME)

$(OBJS): %.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	@$(MAKE) re -C 
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) 

clean:
	rm -f $(OBJS)
	$(RM) $(OBJS)
	@$(MAKE) -C clean

fclean: clean
	rm -f $(NAME)
	$(RM) $(NAME)
	@$(MAKE) -C fclean


re: clean all

.PHONY: all clean fclean re