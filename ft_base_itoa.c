/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:15:54 by jbota             #+#    #+#             */
/*   Updated: 2021/05/21 15:43:31 by jbota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*base_treat(unsigned long j, int base, char *dest, int i)
{
	while (j != 0)
	{
		if ((j % base < 10))
			dest[i - 1] = (j % base) + 48;
		else
			dest[i - 1] = (j % base) + 55;
		j /= base;
		i--;
	}
	return (dest);
}

char	*ft_base_itoa(unsigned long n, int base)
{
	char	*dest;
	int		i;
	long	j;

	i = 0;
	j = n;
	if (j == 0)
		return (ft_strdup("0"));
	while (n != 0)
	{
		n /= base;
		i++;
	}
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	dest[i] = '\0';
	dest = base_treat(j, base, dest, i);
	return (dest);
}
