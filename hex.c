/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:35:03 by jbota             #+#    #+#             */
/*   Updated: 2021/05/14 20:10:48 by jbota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexlen(long n)
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
		n = n / 16;
	}
	return (i);
}

void	right_hex(t_struct *list, int len, char *s, char c)
{
	char	h;

	h = find(list);
	if (c == '0' && list->hash == 2)
	{
		zeros(list, len, s, c);
		return ;
	}
	while (list->width > 0)
	{
		list->nprinted += write(1, &h, 1);
		list->width--;
	}
	while (list->precision > 0)
	{
		list->nprinted += write(1, "0", 1);
		list->precision--;
	}
	list->nprinted += write(1, s, len);
	free(s);
}

void	left_hex(t_struct *list, int len, char *s, char c)
{
	if (list->hash == 2 && c == 'x')
		list->nprinted += write(1, "0x", 2);
	else if (list->hash == 2 && c == 'X')
		list->nprinted += write(1, "0X", 2);
	while (list->precision > 0)
	{
		list->nprinted += write(1, "0", 1);
		list->precision--;
	}
	list->nprinted += write(1, s, len);
	while (list->width > 0)
	{
		list->nprinted += write(1, " ", 1);
		list->width--;
	}
	free(s);
}

void	formathex(unsigned int n, t_struct *list, char c, int len)
{
	char	*s;

	if (c == 'x')
		s = ft_itoa_base(n, 16);
	else if (c == 'X')
		s = ft_itoa_base(n, 16);
	if (n == 0)
	{
		len = 1;
		if (list->dot && list->precision == 0)
			len = 0;
	}
	if (list->dot && list->precision > len)
		list->precision = list->precision - len;
	else
		list->precision = 0;
	list->width = list->width - (list->precision + len);
	if (list->minus == 0)
		right_hex(list, len, s, c);
	else if (list->minus == 1)
		left_hex(list, len, s, c);
}

void	ishex(t_struct *list, va_list args, char c)
{
	unsigned int		n;
	int			len;

	n = 0;
	if (list->len == 0)
		n = (unsigned int)va_arg(args, unsigned int);
	len = hexlen(n);
	formathex(n, list, c, len);
}
