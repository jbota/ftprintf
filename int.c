/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:14:48 by jbota             #+#    #+#             */
/*   Updated: 2021/05/14 20:14:56 by jbota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	signzerowidth(t_struct *list, char c, char sinal, int sign)
{
	if (list->width > 0 && c == '0')
	{
		if (sinal != '\0')
			list->nprinted += write(1, &sinal, 1);
		sign = -sign;
	}
	return (sign);
}

void	right_align(t_struct *list, int len, char *s, int sign)
{
	char	sinal;
	char	c;

//	sign = signzerowidth(list, c, sinal, sign);
	if (list->zero && !list->dot)
		c = '0';
	else
		c = ' ';
	sinal = '\0';
	if (sign == '-')
		sinal = '-';
	sign = signzerowidth(list, c, sinal, sign);
	while (list->width-- > 0)
	{
		list->nprinted += write(1, &c, 1);
	}
	if (sign != 0 && sinal != '\0')
		list->nprinted += write(1, &sign, 1);
	while (list->precision-- > 0)
		list->nprinted += write(1, "0", 1);
	write(1, s, len);
	list->nprinted += len;
}

void	left_align(t_struct *list, int len, char *s, int sign)
{
	if (sign == '-')
		list->nprinted += write(1, "-", 1);
	while (list->precision-- > 0)
	{
		list->nprinted += write(1, "0", 1);
	}
	write(1, s, len);
	list->nprinted += len;
	while (list->width-- > 0)
	{
		list->nprinted += write(1, " ", 1);
	}
}

void	formatint(int n, t_struct *list, int sign)
{
	int	len;
	char	*s;

	s = ft_itoa(n);
	len = manel(n);
	if (n == 0)
		len = 1;
	if (list->dot == 1 && list->precision == 0 && n == 0)
		len = 0;
	if (list->dot && list->precision > len)
		list->precision = list->precision - len;
	else
		list->precision = 0;
	if (sign != 0)
		list->width = list->width - (list->precision + len + 1);
	else
		list->width = list->width - (list->precision + len);
	if (list->width < 0)
		list->width = 0;
	if (list->minus == 0)
		right_align(list, len, s, sign);
	if (list->minus == 1)
		left_align(list, len, s, sign);
	free(s);
}

void	isint(t_struct *list, va_list args, int sign, int i)
{
	i = (int)va_arg(args, int);
	if (i < 0)
	{
		sign = '-';
		i = i * -1;
	}
	formatint(i, list, sign);
}
