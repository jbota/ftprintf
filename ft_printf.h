/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:36:06 by jbota             #+#    #+#             */
/*   Updated: 2021/05/03 20:00:10 by jbota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

# define FLAGS cspdiuxX%#-+.* 0123456789hl

typedef struct  s_struct
{
	char	*format;
	int	nprinted;
	int	i;
	int	len;
	int	minus; //-i
	int	plus; //+
	int	space; // ' '
	int	zero; // 0
	int	dot; // . precisionf
	int	asterix; //*
	int	width; //0-9
	int	hash; //#
	int	precision; //.#
	int	length; // LL HH H L
		t_struck;
}
#endif
