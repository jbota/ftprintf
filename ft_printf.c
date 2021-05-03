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
	va_list		args;
	int			print;
	
	va_start(args, bota);
	while (*bota)
	{
		va_arg(args, char);
	}
	va_end(args);
	free (bota);
	return (print);
}
