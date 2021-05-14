/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:44:30 by jbota             #+#    #+#             */
/*   Updated: 2021/05/14 15:56:00 by jbota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision(const char *bota, t_struct *list)
{
	if (bota[list->i] == '#')
	{
	}
}

void	dot(const char *bota, t_struct *list, va_list args, int j)
{
	int	i;

	i = list->i;
	if (bota[i] == '.')
	{
		list->dot = 1;
		i++;
		if (bota[i] >= '0' && bota[i] <= '9')
		{
			list->precision = ft_atoi(&bota[i]);
			while (bota[i] >= '0' && bota[i] <= '9')
				i++;
		}
		else if (bota[list->i] == '*')
		{
			j = va_arg(args, int);
			if (j >= 0)
				list->precision = j;
			else if (j < 0)
				list->dot = 0;
			while (bota[list->i] == '*')
				i++;
		}
	}
	list->i = i;
}

void	flags(const char *bota, t_struct *list)
{
	while (ft_strchr("-+ #0", bota[list->i]))
	{
		if (bota[list->i] == '-')
			list->minus = 1;
		if (bota[list->i] == '+')
			list->plus = 1;
		if (bota[list->i] == ' ')
			list->space = 1;
		if (bota[list->i] == '#')
			list->hash = 1;
		if (bota[list->i] == '0')
			list->zero = 1;
		list->i++;
	}
	if (list->plus == '1')
		list->space = 0;
}

void	width(const char *bota, t_struct *list, va_list args)
{
	if (bota[list->i] >= 0 && bota[list->i] <= 9)
	{
		list->width = ft_atoi(&bota[list->i]);
		while (bota[list->i] >= 0 && bota[list->i] <= 9)
		{
			list->i++;
			if (list->i == '*')
			{
				if (list->width < 0)
				{
					list->minus = 1;
					list->width = -(list->width);
				}
				while (bota[list->i] == '*')
				{
					list->i++;
				}
			}
		}	
	}
}

void	modifiers(const char *bota, t_struct *list, va_list args)
{
	width(bota, list, args);
	flags(bota, list);
	dot(bota, list, args, 0);
	precision();
//	length();
}
