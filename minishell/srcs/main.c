/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phunguye <phunguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:42:26 by phunguye          #+#    #+#             */
/*   Updated: 2023/07/04 16:45:42 by phunguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

/*what the shell does:
gets input
 - splits into two processes
 - one process waits for the input line from user
 - other process 
parses input

executes
*/
int	main(int ac, char **av, char **envp)
{
	char		*line;
	t_commands	*inpt;
	char		**new_env;

	if (!g_exstat)
		g_exstat = 0;
	line = input();
	if (!line || line == NULL || (line[0] == '\0' && line[0] != '$'))
	{
		free(line);
		main(50, av, envp);
	}
	inpt = parseline(line, envp);
	free(line);
	if (line[0] == '\t')
		return (1);
	search(inpt);
	new_env = inpt->envp;
	freeall(inpt);
	main(50, av, new_env);
	ac = 10;
	return (1);
}