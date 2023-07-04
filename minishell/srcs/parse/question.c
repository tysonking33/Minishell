/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   question.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phunguye <phunguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:41:38 by phunguye          #+#    #+#             */
/*   Updated: 2023/07/04 16:48:00 by phunguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini.h"

/* Function: replacedol2
 * ----------------------------
 * Replaces the variable in the command line string with the 
 * corresponding value
 * in the "new" string, starting at index "i".
 *
 * line: The original command line string.
 * new: The string containing the substituted variable.
 * temp: The value of the variable.
 * i: The index at which the variable starts in the original 
 * command line string.
 *
 * returns: The updated command line string with the variable replaced.
 */
char	*replacedol2(char *line, char *new, char *temp, int i)
{
	int	j;
	int	c;

	j = 0;
	c = jstrlen(new);
	while (temp[j])
	{
		new[c] = temp[j];
		c++;
		j++;
	}
	while (line[i])
	{
		new[c] = line[i];
		c++;
		i++;
	}
	new[c] = '\0';
	return (new);
}

/* Function: replacedol
 * ----------------------------
 * Processes the command line string for variable substitution 
 * using the '$' symbol.
 * Replaces the variable in the command line string with its 
 * corresponding value.
 *
 * line: The command line string to be processed.
 * i: The index at which the variable starts in the command line string.
 *
 * returns: The updated command line string with the variable replaced.
 */
char	*replacedol(char *line, int i)
{
	int		c;
	int		j;
	char	*env;
	char	*new;

	c = 0;
	j = 0;
	new = malloc(sizeof(*new) * 1000);
	env = malloc(sizeof(*new) * 100);
	while (c < i)
	{
		new[c] = line[c];
		c++;
	}
	i++;
	while ((line[i] != ' ' && line[i] != '\"' ) && line[i])
	{
		env[j] = line[i];
		j++;
		i++;
	}
	env = getenv(env);
	line = replacedol2(line, new, env, i);
	return (line);
}

/* Function: checkquest
 * ----------------------------
 * Checks if the command line string contains the "$?" sequence.
 * Replaces "$?" with the exit status value in the command line string.
 *
 * line: The command line string to be checked and processed.
 *
 * returns: The updated command line string with the "$?" sequence replaced.
 */
char	*checkquest(char *line)
{
	int	i;

	i = 0;
	while (line[i++])
		if (line[i] == '?' && line[i - 1] == '$')
			line = exitstat(line, i - 1);
	return (line);
}

/* Function: exitstat
 * ----------------------------
 * Replaces the "$?" sequence in the command line 
 * string with the exit status value.
 *
 * line: The command line string to be processed.
 * i: The index at which the "$?" sequence starts in the command line string.
 *
 * returns: The updated command line string with the "$?" sequence replaced.
 */
char	*exitstat(char *line, int i)
{
	int		j;
	int		q;
	char	*c;
	char	*new;

	j = -1;
	q = 0;
	new = malloc(sizeof(char) * 1000);
	c = ft_itoa(g_exstat);
	while (line[i])
	{
		while (j++ < i - 1)
			new[j] = line[j];
		while (c[q])
			new[j++] = c[q++];
		i = i + 2;
		while (line[i])
			new[j++] = line[i++];
	}
	new[j] = '\0';
	return (new);
}
