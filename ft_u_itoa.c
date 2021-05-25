/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:28:27 by jbota             #+#    #+#             */
/*   Updated: 2021/05/21 15:43:35 by jbota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	manelu(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_u_itoa(unsigned int n)
{
	char	*dest;
	int		i;
	long	j;

	j = n;
	i = manelu(j);
	if (j == 0)
		return (ft_strdup("0"));
	dest = malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	dest[i--] = '\0';
	if (j < 0)
		j = j * -1;
	while (j > 0)
	{
		dest[i] = j % 10 + '0';
		j = j / 10;
		i--;
	}
	return (dest);
}
