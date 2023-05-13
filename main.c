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

# include "includes/minishell.h"

/*int execute(t_msh *minishell) {
	
}*/

int	main(int argc, char **argv, char **env)
{
	t_msh	minishell;
	int status;

	status = 1;
	status = get_environment(&minishell, env);
	while(status)
	{
		status = get_commands(&minishell, stdin);
		//print_env(&minishell);
		print_cmd(&minishell);
		//status = execute(&minishell);

	}
	(void)argc;
	(void)argv;
	(void)status;
}
