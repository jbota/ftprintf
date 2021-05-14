/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:36:06 by jbota             #+#    #+#             */
/*   Updated: 2021/05/14 15:50:01 by jbota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

# define FLAGS "cspdiuxX%#-+.* 0123456789hl"

typedef struct s_struct
{
	char	*bota;
	int		nprinted;
	int		i;
	int		len;
	int		minus; //-i
	int		plus; //+
	int		space; // ' '
	int		zero; // 0
	int		dot; // . precisionf
	int		asterix; //*
	int		width; //0-9
	int		hash; //#
	int		precision; //.#
	int		length; // LL HH H L
}			t_struct;

void	zerostruct(t_struct *list);
int		parse(const char *bota, t_struct *list, va_list args, int i);
int		parse2(t_struct *list, int position, const char *bota, va_list args);
void	conversions(char c, va_list args, t_struct *list);
void	putzeros(int i);
void	putspaces(int i);
//void	ispercent(t_struct *list);
void	ischar(t_struct *list, va_list args);
int		ft_printf(const char *bota, ...);
void	modifiers(const char *src, t_struct *list, va_list args);
void	flags(const char *bota, t_struct *list);
void	width(const char *bota, t_struct *list, va_list args);
void	dot(const char *bota, t_struct *list, va_list args, int j);
void	left(t_struct *list, char c, char *str, int i);
void	right(t_struct *list, char c, char *str, int i);
void	isstring(t_struct *list, va_list args);
void	left(t_struct *list, char c, char *str, int i);
void	right(t_struct *list, char c, char *str, int i);

#endif
