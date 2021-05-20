/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:51:38 by jbota             #+#    #+#             */
/*   Updated: 2021/05/18 17:19:03 by jbota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	left(t_struct *list,  char *str, int i)
{
	if (list->dot && i > list->precision)
		i = list->precision;
	if (list->width > i)
	{
		while ((list->width - i) > 0)
		{	
			list->len = list->len + write(1, " ", 1);
			list->nprinted++;
			list->width--;
		}
	}
	list->len = list->len + write(1, str, i);
	list->nprinted += i;
}

void	right(t_struct *list, char *str, int i)
{
		if (list->dot && i > list->precision)
			i = list->precision;
		list->len = list->len + write(1, str, i);
		list->nprinted = list->nprinted + i;
		while (list->width > i)
		{
			list->len = list->len + write(1, " ", 1);
			list->nprinted++;
			list->width--;
		}
}

void	isstring(t_struct *list, va_list args)
{
	char	*str;
	int	i;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(NULL)";
	i = ft_strlen(str);
	if (list->minus == 0)
		left(list, str, i);
	else if (list->minus == 1)
		right(list, str, i);
}
