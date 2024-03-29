/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:35:03 by jbota             #+#    #+#             */
/*   Updated: 2021/05/20 23:43:52 by jbota            ###   ########.fr       */
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

static void	right_p(t_struct *list, int pwidth, int hexlen, char *s)
{
	while (pwidth-- > 0)
		list->nprinted += write(1, " ", 1);
	list->nprinted += write(1, "0x", 2);
	while (list->precision-- > 0)
		list->nprinted += write(1, "0", 1);
	write(1, s, hexlen);
	list->nprinted += hexlen;
}

static void	left_p(t_struct *list, int pwidth, int hexlen, char *s)
{
	list->nprinted += write(1, "0x", 2);
	while (list->precision-- > 0)
		list->nprinted += write(1, "0", 1);
	write(1, s, hexlen);
	list->nprinted += hexlen;
	while (pwidth-- > 0)
		list->nprinted += write(1, " ", 1);
}

void	ispointer(t_struct *list, va_list args, int n)
{
	int					hexlen;
	char				*s;
	int					pwidth;
	unsigned long long	pointer;

	pointer = (unsigned long long)va_arg(args, void *);
	n = 2;
	s = ft_base_itoa(pointer, 16);
	s = ft_lower_str(s);
	hexlen = ft_strlen(s);
	list->precision = list->precision - hexlen;
	pwidth = list->width - hexlen - n;
	if (list->dot && list->precision == 0)
		hexlen = 0;
	if (list->minus)
		left_p(list, pwidth, hexlen, s);
	else
		right_p(list, pwidth, hexlen, s);
	free(s);
}
