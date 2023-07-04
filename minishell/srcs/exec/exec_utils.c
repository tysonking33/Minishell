/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phunguye <phunguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:40:17 by phunguye          #+#    #+#             */
/*   Updated: 2023/07/04 16:45:42 by phunguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini.h"

int	len(long nb)
{
	int		len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static void	itoastr(long n, char *str, int *i)
{
	if (n > 9)
	{
		itoastr(n / 10, str, i);
		itoastr(n % 10, str, i);
	}
	else
		str[(*i)++] = n + '0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nbr;

	nbr = n;
	str = malloc(sizeof(char) * (len(nbr) + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (nbr < 0)
	{
		str[i++] = '-';
		nbr *= -1;
	}
	itoastr(nbr, str, &i);
	str[i] = '\0';
	return (str);
}
