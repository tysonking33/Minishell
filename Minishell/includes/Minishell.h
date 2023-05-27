#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h> //readline
#include <readline/history.h>   //readline
#include <stdlib.h>             //malloc
#include <sys/wait.h>            //wait

# include "../libftprintf/ft_printf.h"
# include "../libftprintf/libft/libft.h"


/* found in main.c */
int main();
void execute_arguments(char **parsedCommands);
void change_to_preestablished_loc(char **parsedCommands);
int	ft_strcmp(char *s1, char *s2);
int takeInput(char *inputString);
void init_shell();

// found in parsing.c
int argCount(char *src);
char **parse_commands(char *src);

/* found in ft_split.c */
char		**ft_split_string(char *src);
int	stringlen(char *src);
int nextStart(char *src, int currentStart);
char *wordDup(char *src, int startidx);


/* found in split_quotes.c */
int find_quotes(char *src);

/*found in execute_cd.c*/
int execute_cd(char **parsed_commands);

#endif