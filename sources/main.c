/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phunguye <phunguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:39:14 by phunguye          #+#    #+#             */
/*   Updated: 2023/01/23 15:13:59 by phunguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int ft_attach_node(t_env *end_node, char *source)
{
	t_env *new_node;

	new_node = malloc(sizeof(t_env));
	if(strcpy(new_node->env_variable, source))
		return(-1);
	end_node->next_pointer = new_node;
	return(0);
}

int	get_environment(t_msh *minishell, char **env)
{
	int	status;
	t_env *current_variable;
	int i;

	status = 1;
	i = 0;
	/*while(status)
	{
		status = check_valid(minishell, env);
		if(!status)
			return(-1);
		i++;
	}*/
	i = 0;
	
	current_variable = malloc(sizeof(t_env));
	strcpy(current_variable->env_variable, env[i]);
	minishell->environment_list = current_variable;
	while(status)
	{
		status = ft_attach_node(current_variable, env[++i]);
		if(status == -1)
			return(-1);
		current_variable = current_variable->next_pointer;
	}
	return(1);
}

int	main(int argc, char **argv, char **env)
{
	t_msh	minishell;
	int status;

	status = 1;
	status = get_environment(&minishell, env);
	/*while(status)
	{
		printf("$ ");
		get_commands(minishell, stdin);

		status = execute(minishell);

	}*/
	(void)argc;
	(void)argv;
	(void)status;
}
