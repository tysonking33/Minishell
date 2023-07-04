/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phunguye <phunguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:41:30 by phunguye          #+#    #+#             */
/*   Updated: 2023/07/04 16:47:20 by phunguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini.h"

/* Function: parse
 * ----------------------------
 * Parses the command line string and separates it into individual commands
 * and arguments based on spaces and quotes.
 *
 * in: The t_commands struct to store the parsed commands and arguments.
 * line: The command line string to be parsed.
 */
void	parse(t_commands *in, char *line)
{
	int	c;

	c = 0;
	while (line[in->i])
	{
		while ((line[in->i] != ' ' && line[in->i] != '\''
				&& line[in->i] != '\"') && line[in->i])
			in->i++;
		if (line[in->i] != '\'' && line[in->i] != '\"')
			in->cmds[c++] = jstrcpy(line, in->s_ind, in->i);
		if (!line[in->i])
			break ;
		if (line[in->i] == '\'' || line[in->i] == '\"')
			in->cmds[c++] = parsequote(line, in);
		in->i++;
		in->s_ind = in->i;
	}
	in->cmds[c] = 0;
	in->args = c - 1;
}

/* Function: parseline
 * ----------------------------
 * Parses the command line string and creates a t_commands struct to store
 * the parsed commands and arguments.
 *
 * line: The command line string to be parsed.
 * envp: The environment variables.
 *
 * returns: A pointer to the t_commands struct containing 
 * the parsed commands and arguments.
 */
t_commands	*parseline(char *line, char **envp)
{
	t_commands	*in;

	checkline(line);
	line = checkdollar(line);
	in = malloc(sizeof(t_commands));
	malcomm(in, envp);
	in->cmds = malloc(sizeof(char *) * (countwords(line) + 1));
	parse(in, line);
	return (in);
}

/* Function: parsequote
 * ----------------------------
 * Parses a quoted section of the command line string.
 *
 * line: The command line string.
 * in: The t_commands struct containing parsing information.
 *
 * returns: The parsed quoted section.
 */
char	*parsequote(char *line, t_commands *in)
{
	char	comp;
	char	*ret;

	comp = line[in->i];
	in->s_ind++;
	in->i++;
	while (line[in->i] != comp && line[in->i] != '\0')
		in->i++;
	ret = jstrcpy(line, in->s_ind, in->i);
	in->i++;
	return (ret);
}

/* Function: malcomm
 * ----------------------------
 * Allocates memory for the members of the t_commands struct.
 *
 * in: The t_commands struct to allocate memory for.
 * envp: The environment variables.
 */
void	malcomm(t_commands *in, char **envp)
{
	in->i = (int)malloc(sizeof(int));
	in->s_ind = (int)malloc(sizeof(int));
	in->i = 0;
	in->s_ind = 0;
	in->args = (int)malloc(sizeof(int));
	in->envp = envp;
	in->re = malloc(sizeof(int) * 10);
}
