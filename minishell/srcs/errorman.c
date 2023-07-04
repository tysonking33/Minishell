/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorman.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phunguye <phunguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:42:20 by phunguye          #+#    #+#             */
/*   Updated: 2023/07/04 16:47:00 by phunguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

/* Function: error
 * ----------------------------
 * Prints an error message to stderr and exits the 
 * program with the value of errno.
 * str: The error message to be printed.
 */
void	error(char *str)
{
	fprintf(stderr, "%s\n", str);
	exit(errno);
}

/* Function: checkline
 * ----------------------------
 * Checks a command line string for invalid arguments, 
 * such as consecutive spaces or
 * consecutive single or double quotes.
 *
 * line: The command line string to be checked.
 */
void	checkline(char *line)
{
	int	i;

	i = 1;
	while (line[i])
	{
		if (line[i] == ' ' && line[i - 1] == ' ')
			error("Error: Invalid argument");
		if (line[i] == '\'' && line[i - 1] == '\'')
			error("Error: Invalid argument");
		if (line[i] == '\"' && line[i - 1] == '\"')
			error("Error: Invalid argument");
		i++;
	}
	checkclose(line);
}

/* Function: checkclose
 * ----------------------------
 * Checks if quotes (' or ") in the command line 
 * string are properly closed.
 *
 * line: The command line string to be checked.
 */
void	checkclose(char *line)
{
	int		i;
	char	cmp;

	i = 1;
	while (line[i])
	{
		while (line[i] != '\'' && line[i] != '\"' && line[i])
			i++;
		if (!line[i])
			return ;
		cmp = line[i];
		i++;
		while (line[i] != cmp && line[i])
			i++;
		if (!line[i])
			error("Error: No end quote");
		i++;
	}
}

/* Function: checkdollar
 * ----------------------------
 * Processes the command line string for variable 
 * substitution using the '$' symbol.
 *
 * line: The command line string to be processed.
 *
 * returns: The processed command line string.
 */
char	*checkdollar(char *line)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	line = checkquest(line);
	while (line[i])
	{
		while ((line[i] != '\'' && line[i] != '\0') || line[i] == '$')
		{
			if (x % 2 == 0)
				if (line[i] == '$' && line[i])
					line = replacedol(line, i);
			i++;
		}
		x++;
		if (line[i])
			i++;
	}
	return (line);
}
