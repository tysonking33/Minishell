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

/* found in environment.c */
int ft_attach_node(t_env *end_node, char *source);
void print_env(t_msh *minishell);
int	get_environment(t_msh *minishell, char **env);
char	**ft_split(char const *s, char c);


#endif