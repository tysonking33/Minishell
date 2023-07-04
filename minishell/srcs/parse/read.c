/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phunguye <phunguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:41:56 by phunguye          #+#    #+#             */
/*   Updated: 2023/07/04 16:45:42 by phunguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini.h"

void	cont(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		exit(0);
	}
	if (sig == SIGQUIT)
		return ;
	if (sig == SIGTSTP || !rl_line_buffer)
		exit(0);
	(void)sig;
}

void	checknull(char *line)
{
	if (line == NULL)
	{
		printf("\n");
		kill(0, SIGKILL);
	}
}

void	prntproc(void)
{
	signal(SIGINT, &cont);
	signal(SIGTSTP, &cont);
}

void	chldproc(pid_t pid, int *status)
{
	signal(SIGINT, &cont1);
	signal(SIGQUIT, &cont1);
	signal(SIGTSTP, &cont1);
	while (wait(status) != pid)
		;
	g_exstat = *status;
}

char	*input(void)
{
	char			*line;
	pid_t			pid;
	static pid_t	kid;
	int				status;

	line = (char *) NULL;
	pid = fork();
	if (pid == kid)
		exit(0);
	else if (pid == 0)
	{
		prntproc();
		line = readline("T-P_wrld~: ");
		checknull(line);
	}
	else if (pid > 0)
	{
		kid = pid;
		chldproc(pid, &status);
	}
	if (line && *line)
		add_history(line);
	return (line);
}
