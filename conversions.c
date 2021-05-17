/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:35:21 by jbota             #+#    #+#             */
/*   Updated: 2021/05/14 20:24:36 by jbota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zerostruct(t_struct *list)
{
	list->i = 0;
	list->nprinted = 0;
	list->minus = 0;
	list->plus = 0;
	list->len = 0;
	list->space = 0;
	list->zero = 0;
	list->dot = 0;
	list->asterix = 0;
	list->width = 0;
	list->hash = 0;
	list->precision = 0;
}

int	parse(const char *bota, t_struct *list, va_list args, int i)
{
	while (bota[i] != '\0')
	{
		if (bota[i] != '%' && bota[i])
			list->nprinted += write(1, &bota[i], 1);
		else if (bota[i] == '%')
		{
			if (!ft_strchr(FLAGS, bota[i + 1]))
				break ;
			while (ft_strchr(FLAGS, bota[i + 1]))
			{
				i++;
				if (ft_strchr("cspdiuxX%", bota[i]))
				{
					i = parse2(list, i, bota, args) + 2;
					break ;
				}
				else
					i = parse2(list, i, bota, args);
			}
			continue;
		}
		i++;
	}
	return(list->nprinted);
}

int	parse2(t_struct *list, int position, const char *bota, va_list args)
{
	list->i = position;
	if (!ft_strchr("cspdiuxX%", bota[position]))
		modifiers(bota, list, args);
	else if (ft_strchr("cspdiuxX%", bota[position]))
	{
		conversions(bota[position], args, list);
		zerostruct(list);
	}
	return (list->i - 1);
}	

void	conversions(char c, va_list args, t_struct *list)
{
	if (c == 'c')
		ischar(list, args);
	else if (c == 's')
		isstring(list, args);
	else if (c == 'p')
		ispointer(list, args, 2);
	else if (c == 'd' || c == 'i')
		isint(list, args, 0, 0);
	else if (c == 'u')
		isudecint(list, args);
	else if (c == 'x' || c == 'X')
		ishex(list, args, c);
	else if (c == '%')
		ispercent(list);
}
