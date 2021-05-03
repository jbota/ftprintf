/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:35:21 by jbota             #+#    #+#             */
/*   Updated: 2021/04/27 19:42:55 by jbota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return(list->nprinted)
}

int	parse2(t_struct *list, int position, const char *bota, va_list args)
{
	list->i = position;
	if (!ft_strchr("cspdiuxX%", bota[position]))
		modifiers(bota, list, args);
	else if (ft_strchr("cspdiuxX%", bota[position]))
		conversions(bota[position], args, list); 
	return (f->i - 1);
}	

void	conversions(char c, va_list args, t_struct *s)
{
	if (c == 'c')
		ischar(s, args);
	else if (c == 's')
		isstring(s, args);
	else if (c == 'p')
		ispointer(s, args, 2);
	else if (c == 'd' || c == 'i')
		isint (s, args, 0, 0);
	else if (c == 'u')
		isdecint(s, args);
	else if (c == 'x' || c == 'X')
		ishex(s, args, c);
	else if (c == '%')
		ispercent(s);
}
