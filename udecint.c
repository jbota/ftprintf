/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   udecint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:14:48 by jbota             #+#    #+#             */
/*   Updated: 2021/05/14 20:16:02 by jbota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	right_u(t_struct *list, int len, char *s)
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

static void	left_u(t_struct *list, int len, char *s)
{
	while (list->precision > 0)
	{
		list->nprinted += write(1, "0", 1);
		list->precision--;
	}
	write(1, s, len);
	list->nprinted += len;
	while (list->width > 0)
	{
		list->nprinted += write(1, " ", 1);
		list->width--;
	}
}

static void	formatvalue(unsigned int n, t_struct *list)
{
	char	*s;
	int	len;

	s = ft_u_itoa(n);
	len = manel(n);
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
		right_u(list, len, s);
	if (list->minus == 1)
		left_u(list, len, s);
	free(s);
}

void	isudecint(t_struct *list, va_list args)
{
	unsigned long	n;
	
	n = 0;
	n = va_arg(args, unsigned int);
	formatvalue(n, list);
}
