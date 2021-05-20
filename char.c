/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:29:10 by jbota             #+#    #+#             */
/*   Updated: 2021/05/14 20:24:48 by jbota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*void	putzeros(int i)
{
	while (i > 0)
	{
		write(1, "0", 1);
		i--;
	}
}
*/
void	putspaces(int i)
{
	while (i > 0)
	{
		write(1, " ", 1);
		i--;
	}
}

void	ispercent(t_struct *list)
{
	if (list->width != 0 && list->minus == 0)
	{
		putspaces(list->width - 1);
		write(1, "%", 1);
		list->nprinted = list->nprinted + list->width;
	}
	else if (list->width && list->minus == 1)
	{
		write(1, "%", 1);
		putspaces(list->width - 1);
		list->nprinted = list->nprinted + list->width;
	}
	else
	{
		write(1, "%", 1);
		list->nprinted++;
	}
}

void	ischar(t_struct *list, va_list args)
{
	unsigned char	c;

	c = (unsigned char)va_arg(args, int);
	if (list->width && list->minus == 0)
	{
		putspaces(list->width -1);
		write(1, &c, 1);
		list->nprinted = list->nprinted + list->width;
	}
	else if (list->width && list->minus == 1)
	{
		write(1, &c, 1);
		putspaces(list->width - 1);
		list->nprinted = list->nprinted + list->width;
	}
	else
	{
		write(1, &c, 1);
		list->nprinted++;
	}
}
