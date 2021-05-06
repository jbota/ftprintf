/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:56:13 by jbota             #+#    #+#             */
/*   Updated: 2021/05/03 16:44:01 by jbota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printf(const char *bota, ...)
{
	va_list	args;
	int	print;
	t_stuct	*list;
	int	length;
	
	length = ft_strlen(bota);
	list = (t_struct)malloc(sizeof(t_struct));
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
	if (lenght == 1 && format[0] == '%')
		return (0)
	else
		print = parse(bota, list, args, 0)
	va_end(args);
	free (list);
	return (print);
}
