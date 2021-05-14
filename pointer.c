/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:15:17 by jbota             #+#    #+#             */
/*   Updated: 2021/05/14 20:15:36 by jbota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned long long n)
{
	int	i;

	i = 0;
	while (n / 16)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	right_align(int pwidth, int pprecision, int hexlen, char *s)
{
	int	i;

	i = 0;
	while (pwidth > 0)
	{
		i += write(1, " ", 1);
		pwidth--;
	}
	i += write(1, "0x", 2);
	while (pprecision > 0)
	{
		i += write(1, "0", 1);
		pprecision--;
	}
	i += write(1, s, hexlen);
	return (i);
}

int	left_align(int pwidth, int pprecision, int hexlen, char *s)
{
	int	i;

	i = 0;
	i += write(1, "0x", 2);
	while (pprecision > 0)
	{
		i += write(1, "0", 1);
		pprecision--;
	}
	i += write(1, s, hexlen);
	while (pwidth > 0)
	{
		i += write(1, " ", 1);
		pwidth--;
	}
	return (i);
}

void	ispointer(t_struct *list, va_list args, int n)
{
	int			hexlen;
	char			*s;
	int			pprecision;
	int			pwidth;
	unsigned long long	pointer;

	pointer = (unsigned long long)va_arg(args, void *);
	n = 2;
	hexlen = hex_len(pointer) + 1;
	s = ft_itoa_base(pointer, 16);
	pprecision = list->precision - hexlen;
	pwidth = list->width - hexlen - n;
	if (list->dot && list->precision == 0)
		hexlen = 0;
	if (list->minus)
		list->nprinted += left_align(pwidth, pprecison, hexlen, s);
	else
		list->nprinted += right_align(pwidth, pprecision, hexlen, s);
	free(s);
}
