/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:13:10 by jbota             #+#    #+#             */
/*   Updated: 2021/05/14 20:13:33 by jbota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zeros(t_struct *list, int hexlen, char *s, char c)
{
	char	h;

	h = find(list);
	if ( h == '0' && list->hash == 2)
	{
		if (list->hash == 2 && c == 'X')
			list->nprinted += write(1, "0x", 2);
		else if (list->hash == 2 && c == 'X')
			list->nprinted += write(1, "0X", 2);
		while (list->width--> 0)
			list->nprinted += write(1, &c, 1);
		while (list->precision--> 0)
			list->nprinted += write(1, "0", 1);
		list->nprinted += write(1, s, hexlen);
		return ;
	}
}

char	find(t_struct *list)
{
	char	c;

	if (list->zero && !list->dot)
		c = '0';
	else
		c = ' ';
	return (c);
}

int	manel(long n)
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

char	*ft_itoa_base(unsigned int n, unsigned int base)
{
	char	*dest;
	int	i;
	long	j;


	j = n;
	i = 1;
	while ((j /= base) >= 1)
		i++;
	dest = malloc(sizeof(char) * i + 1);
	dest[i] = '\0';
	j = n;
	while (j > 0)
	{
		dest[i] = j % base + '0';
		j = j / base;
		i--;
	}
	return (dest);
}
