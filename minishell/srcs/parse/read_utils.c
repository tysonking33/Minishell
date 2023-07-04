/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phunguye <phunguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:41:48 by phunguye          #+#    #+#             */
/*   Updated: 2023/07/04 16:45:42 by phunguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini.h"

// Find and handle input/output redirection, then execute the command
void	search(t_commands *in)
{
	findredir(in);
	if (other(in))
		return ;
	findexe(in);
	execute(in);
}

// Find the executable path for the command
void	findexe(t_commands *in)
{
	char	*buff;
	int		i;

	i = 0;
	buff = in->cmds[0];
	in->cmds[0] = findpath(buff, in->envp);
}

// Check if the command is a built-in command (cd, unset, export, exit)
// If it is, execute the corresponding function and return the result
int	other(t_commands *in)
{
	int	i;

	i = 0;
	if (ft_strnstr(in->cmds[0], "cd", 2))
		i = changedir(in);
	if (ft_strnstr(in->cmds[0], "unset", 5))
		i = unset(in);
	if (ft_strnstr(in->cmds[0], "export", 6))
		i = exporter(in);
	if (ft_strnstr(in->cmds[0], "exit", 4))
	{
		kill(0, SIGKILL);
		exit(0);
		i = 1;
	}
	return (i);
}

// Signal handler function to handle specific signals
/*    ctrl-c : sends SIGINT to interrupt them,
    ctrl-\ : sends SIGQUIT to kill them,
    ctrl-z : sends SIGTSTP to suspend them.*/
void	cont1(int sig)
{
	if (sig == SIGINT)
		return ;
	if (sig == SIGQUIT)
		return ;
	if (sig == SIGTSTP)
		exit(0);
	(void)sig;
}
