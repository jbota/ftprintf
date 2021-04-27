/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:56:13 by jbota             #+#    #+#             */
/*   Updated: 2021/04/27 19:44:02 by jbota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printf(const char *bota, ...)
{
	const char	*joao;
	va_list		args;
	int			print;

	joao = ft_strdup(bota);
	if (!joao)
		return (0);
	va_start(args, bota);
	while (*bota)
	{
		va_arg(args, char);
	}
	va_end(args);
	free (joao);
	return (print);
}
