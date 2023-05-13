/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phunguye <phunguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:39:31 by phunguye          #+#    #+#             */
/*   Updated: 2023/01/23 15:13:59 by phunguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "../libftprintf/ft_printf.h"
# include "../libftprintf/libft/libft.h"

# define BUILT_IN 1
# define REDIR_INPUT 2
# define REDIR_TRUNCATE 3 //"Truncate" redirection is a type of output redirection used in shell programming that sends the output of a command to a file and overwrites any existing content in that file.
# define REDIR_APPEND 4
# define DELIMINATOR 5
# define PIPE 6
# define EMPTY 7
# define END_LINE 8
# define EXIT 9
# define UNKNOWN 999

/* for readline() */
#include <readline/readline.h>
#include <readline/history.h>

/*typedef struct s_history;
{
	char instructions[128];
	struct s_history *prev;
	struct s_history *next;
}	t_history */

typedef struct s_env
{
	char	*env_variable; 
	struct s_env *next_pointer;
}	t_env;

typedef struct s_token
{
	char	*token_string;
	int		type;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_msh
{
	t_env	*environment_list;
	t_token	*token_list;
} t_msh;

/* found in main.c */
int	main(int argc, char **argv, char **env);

/* found in get_environment.c */
int ft_attach_node(t_env *end_node, char *source);
void print_env(t_msh *minishell);
int	get_environment(t_msh *minishell, char **env);
char	**ft_split(char const *s, char c);

/* found in get_command.c */
int get_commands(t_msh *minishell, FILE* stdin);
void print_cmd(t_msh *minishell);
int ft_attach_command_token(t_token *end_node, char *str_command);
void assign_type(t_token *node);


#endif