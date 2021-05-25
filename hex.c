/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:35:03 by jbota             #+#    #+#             */
/*   Updated: 2021/05/20 23:31:57 by jbota            ###   ########.fr       */
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

static void	right_hex(t_struct *list, int len, char *s)
{
	char	c;

	if (list->zero && !list->dot)
		c = '0';
	else
		c = ' ';
	while (list->width-- > 0)
		list->nprinted += write(1, &c, 1);
	while (list->precision-- > 0)
		list->nprinted += write(1, "0", 1);
	write(1, s, len);
	list->nprinted += len;
}

static void	left_hex(t_struct *list, int len, char *s)
{
	while (list->precision-- > 0)
		list->nprinted += write(1, "0", 1);
	write(1, s, len);
	list->nprinted += len;
	while (list->width-- > 0)
		list->nprinted += write(1, " ", 1);
}

static void	formathex(unsigned long n, t_struct *list, char c)
{
	char	*s;
	int		len;

	s = ft_base_itoa(n, 16);
	if (c == 'x')
		s = ft_lower_str(s);
	len = ft_strlen(s);
	if (n == 0)
		len = 1;
	if (list->dot && list->precision == 0 && n == 0)
		len = 0;
	if (list->dot && list->precision > len)
		list->precision = list->precision - len;
	else
		list->precision = 0;
	list->width = list->width - (list->precision + len);
	if (list->width < 0)
		list->width = 0;
	if (list->minus == 0)
		right_hex(list, len, s);
	if (list->minus == 1)
		left_hex(list, len, s);
	free(s);
}

void	ishex(t_struct *list, va_list args, char c)
{
	unsigned long	n;

	n = 0;
	n = va_arg(args, unsigned int);
	formathex(n, list, c);
}
