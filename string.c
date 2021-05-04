/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:51:38 by jbota             #+#    #+#             */
/*   Updated: 2021/05/03 20:00:07 by jbota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	left(t_struct *list, char c, char *str, int i)
{
	if (list->minus == 0)
	{
		if (list->dot && i > list->precision)
			i = list->precison;
		if (list->width > i)
		{
			while (list->width > i)
			{	
				list->len = list->len + write(1, &c, 1);
				list->nprinted++;
				list->width--;
			}
		}
		list->len = list->len + write(1, str, 1);
		list->nprinted = list->nprinted + i;
	}
}

void	right(t_struct *list, char c, char *str, int i)
{
	if (list->minus != 0)
	{
		c = ' ';
		if (list->dot && i > list->precision)
			i = list->precition;
		list->len = list->len + write(1, str, i);
		list->nprinted = list->nprinted + i;
		while (list->width > i)
		{
			list->len = list->len + write(1, &c, 1);
			list->nprinted++;
			list->width--;
		}
	}
}

void	isstring(t_struct *list, va_list args)
{
	char	*str;
	int		i;
	char	c;

	if (list->zero == 1)
		c = '0';
	else
		c = ' ';
	str = (char *)va_arg(args, char *);
	if (str == NULL)
		str = "(NULL)";
	i = ft_strlen(str);
	if( list->minus == 0)
		left(list, c, str, i);
	else if (lits->minus == 1)
		righ(list, c, str, i);
}
