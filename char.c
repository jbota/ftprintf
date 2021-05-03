/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:29:10 by jbota             #+#    #+#             */
/*   Updated: 2021/05/03 18:51:22 by jbota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	putzeros(int i)
{
	while (i > 0)
	{
		write(1, "0", 1);
		i--;
	}
}

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
	int	i;

	if (list->width != 0 && list->minus == 0)
	{
		i = list->minus - 1;
		if (list->zero != 0)
			putzeros(i);
		else
			putspaces(i);
		write(1, "%", 1);
		list->nprinted = list->nprinted + i + 1;
	}
	else if (list->width && list->minus == 1)
	{
		i = list->width - 1;
		write(1, "%", 1);
		putspaces(i);
		list->nprinted = list->nprinted + i + 1;
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
		if (list->zero != 0)
			putzeros(list->width - 1);
		if (list->zero == 0)
			putspaces(list->width - 1);
		write(1, &c, 1);
		list->nprinted = list->nprinted + (list->width - 1);
	}
	else if (list->width && list->minus == 1)
	{
		write(1, &c, 1);
		putspaces(list->width -1);
		list->nprinted = list->nprinted + (list->width - 1);
	}
	else
	{
		write(1, &c, 1);
		list->nprinted++;
	}
}
