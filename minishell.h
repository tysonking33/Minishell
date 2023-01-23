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

/*typedef struct s_history;
{
	char instructions[128];
	struct s_history *prev;
	struct s_history *next;
}	t_history */

STDIN = stdin

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
}

#endif