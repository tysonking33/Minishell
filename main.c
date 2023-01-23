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

#include "minishell.h"

int	get_environment(t_msh *minishell, char **env)
{
	int	status;
	int	number;
	t_env current_variable;

	status = 1;
	number = 0;
	while(status)
	{
		status = check_valid(minishell, *env)
		if(!status)
			return(-1);
		*(env++);
		number++;
	}
	while(status)
	{
		status = strcpy(current_variable.env_variable, *env);
		minishell.environment_list = current_variable 

		*(env++);
	}
	
	
	
	/*int ctr = 0;
	head = env[0];
	head.next_pointer = NULL;
	while (*env[ctr])
	{
		current_variable = head;
		temp_var = env[ctr + 1];
		current_variable->next_pointer = temp_var;
		ctr++;
	}
	minishell->environment_variables.env_variables = head;*/
	/*while(number)
	{
		minishell.environemt_list->next = current_variable;
		number--;
	}*/





	return(1);
}

int	main(int argc, char **argv, char **env)
{
	t_msh	*minishell;

	int status;

	status = 1;
	status = get_environment(minishell, env);
	while(status)
	{
		printf("$ ")
		get_commands(minishell, STDIN);

		status = execute(minishell);

	}
}
