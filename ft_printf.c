/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:56:13 by jbota             #+#    #+#             */
/*   Updated: 2021/05/14 20:14:28 by jbota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *bota, ...)
{
	va_list		args;
	int			print;
	t_struct	*list;
	int			length;

	length = ft_strlen(bota);
	list = (t_struct*)malloc(sizeof(t_struct));
	if (!list)
		return (0);
	zerostruct(list);
	list->bota = (char *)bota;
	va_start(args, bota);
	if (!bota[0])
	{
		write(1, "", 0);
		return (0);
	}
	if (length == 1 && bota[0] == '%')
		return (0);
	else
		print = parse(bota, list, args, 0);
	va_end(args);
	free (list);
	return (print);
}
