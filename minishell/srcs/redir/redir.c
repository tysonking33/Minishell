/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phunguye <phunguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:42:03 by phunguye          #+#    #+#             */
/*   Updated: 2023/07/04 16:49:27 by phunguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini.h"

//finds and stores where > and < occurs in the array of commands
//stores the indexes in the integer array re
void	findredir(t_commands *in)
{
	int	i;

	i = 0;
	in->i = 0;
	in->s_ind = 1;
	while (in->cmds[in->s_ind] != 0)
	{
		if (in->cmds[in->s_ind][0] == '>')
			in->re[i++] = in->s_ind;
		if (in->cmds[in->s_ind][0] == '<')
			in->re[i++] = in->s_ind;
		in->s_ind++;
	}
	in->re[i++] = 0;
}

// Check and handle input/output redirection based on the stored indices
void	checkredir(t_commands *in)
{
	int	i;

	i = 0;
	while (in->re[i] != 0)
	{
		if (in->cmds[in->re[i]][0] == '>' && in->cmds[in->re[i]][1] == '>')
			reoutapp(in, i);
		else if (in->cmds[in->re[i]][0] == '<' && in->cmds[in->re[i]][1] == '<')
			delinpt(in, i);
		else if (in->cmds[in->re[i]][0] == '>')
			reout(in, i);
		else if (in->cmds[in->re[i]][0] == '<')
			rein(in, i);
		i++;
	}
}
