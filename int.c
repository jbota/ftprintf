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
		if (list->space)
		{
			list->nprinted += write(1, " ", 1);
			list->space = 0;
		}
		if (sinal != '\0')
			list->nprinted += write(1, &sinal, 1);
		sign -= sign;	
	}
	return (sign);
}

void	rigth_align(t_struct *list, int len, char *s, int sign)
{
	char	sinal;
	char	c;

	if (list->zero && !list->dot)
		c = '0';
	else
		c = ' ';
	sinal = '\0';
	if (sign == POSITIVE)
		sinal = '+';
	else if (sign == NEGATIVE)
		sinal = '-';
	sign = signzerowidth(list, c, sinal, sign);
	while (list->width-- > 0)
		list->nprinted += write(1, &c, 1);
	if (list->space != 0)
		list->nprinted += write(1, " ", 1);
	if (sign != 0 && sinal != '\0')
		list->nprinted += write(1, &sinal, 1);
	list->nprinted += write(1, s, len);
}

void	left_align(t_struct *list, int len, char *s, int sign)
{
	if (list->space)
		list->nprinted += write(1, " ", 1);
	if (sign == POSITIVE)
		list->nprinted += write(1, "+", 1);
	else if (sign == NEGATIVE)
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

void	formatint(intmax_t n, t_struct *list, int sign)
{
	int	len;
	char	*s;

	if (list->space && sign != 0)
		list->space = 0;
	s = ft_itoa(n);
	len = manel(n);
	if (n == 0)
		len = 1;
	if (list->dot == 1 && list->precision == 0 && n == 0)
		len = 0;
	if (list->dot && list->precision > len)
		list-precision = list->precision - len;
	else
		list->precision = 0;
	if (sign != 0)
		list->width = list->width - (list->precision + len + 1 + list->space);
	else
		list->width = list->width - (list->precision + len + list->space);
	if (list->minus == 0)
		right_align(list, len, s, sign);
	if (list->minus == 1)
		left_align(list, len, s, sign);
	free(s);
}

void	isint(t_struct *list, va_arg args, int sign, intmax_t i)
{
	if (list->length == 0)
		i = (int)va_arg(ap, int);
	if (list->plus && i >= 0)
		sign = POS;
	else if (i < 0)
	{
		sign = NEG;
		i = i * -1;
	}
	formatint(i, list, sign);
}
