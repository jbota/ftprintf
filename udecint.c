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

void	right_u(t_struct *list, int len, char *s, int sinal)
{
	char	sin;
	char	c;

	if (list->zero && !list->dot)
		c = '0';
	else
		c = ' ';
	sin = '\0';
	if (sinal == '+')
		sin = '+';
	else if (sinal == '-')
		sinal = '-';
	sinal = signzerowidth(list, c, sin, sinal);
	while (list->width-- > 0)
		list->nprinted += write(1, &c, 1);
	if (list->space != 0)
		list->nprinted += write(1, " ", 1);
	if (sinal != 0 && sin != '\0')
		list->nprinted += write(1, &sin, 1);
	list->nprinted += write(1, s, len);	
}

void	left_u(t_struct *list, int len, char *s, int sinal)
{
	sinal = 0;
	if (list->space)
		list->nprinted += write(1, " ", 1);
	if (sinal == '+')
		list->nprinted += write(1, "+", 1);
	else if (sinal == '-')
		list->nprinted += write(1, "-", 1);
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
}

void	formatvalue(unsigned int n, t_struct *list, int sinal)
{
	char	*s;
	int	len;

	if (list->space && sinal != 0)
		list->space = 0;
	s = ft_itoa(n);
	len = manel(n);
	if (n == 0)
		len = 1;
	if (list->dot && list->precision == 0)
		len = 0;
	if (list->dot && list->precision > len)
		list->precision = list->precision - len;
	else
		list->precision = 0;
	if (sinal != 0)
		list->width = list->width - (list->precision + len + 1 + list->space);
	else
		list->width = list->width - (list->precision + len + list->space);
	if (list->minus == 0)
		right_u(list, len, s, sinal);
	if (list->minus == 1)
		left_u(list, len, s, sinal);
	free(s);
}

void	isudecint(t_struct *list, va_list args)
{
	unsigned int	n;
	int		sinal;

	sinal = 0;
	n = 0;
	if (list->space)
		list->space = 0;
	n = (unsigned int)va_arg(args, unsigned int);
	if (list->plus)
		sinal = '+';
	formatvalue(n, list, sinal);
}
