/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:36:06 by jbota             #+#    #+#             */
/*   Updated: 2021/05/14 20:10:55 by jbota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

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
}			t_struct;

void	zerostruct(t_struct *list);
int		parse(const char *bota, t_struct *list, va_list args, int i);
int		parse2(t_struct *list, int position, const char *bota, va_list args);
void	conversions(char c, va_list args, t_struct *list);
void	putzeros(int i);
void	putspaces(int i);
void	ispercent(t_struct *list);
void	ischar(t_struct *list, va_list args);
int		ft_printf(const char *bota, ...);
void	modifiers(const char *src, t_struct *list, va_list args);
void	flags(const char *bota, t_struct *list);
void	width(const char *bota, t_struct *list, va_list args);
void	precision(const char *bota, t_struct *list, va_list args, int h);
void	left(t_struct *list, char c, char *str, int i);
void	right(t_struct *list, char c, char *str, int i);
void	isstring(t_struct *list, va_list args);
void	left(t_struct *list, char c, char *str, int i);
void	right(t_struct *list, char c, char *str, int i);
int		signzerowidth(t_struct *list, char c, char sinal, int sign);
void	right_align(t_struct *list, int len, char *s, int sign);
void	left_align(t_struct *list, int len, char *s, int sign);
void	formatint(int n, t_struct *list, int sign);
void	isint(t_struct *list, va_list args, int sign, int i);
int		hex_len(unsigned long long n);
int		right_palign(int pwidth, int pprecision, int hexlen, char *s);
int		left_palign(int pwidth, int pprecision, int hexlen, char *s);
void	ispointer(t_struct *list, va_list args, int n);
void	right_u(t_struct *list, int len, char *s, int sinal);
void	left_u(t_struct	*list, int len, char *s, int sinal);
void	formatvalue(unsigned int n, t_struct *list, int sinal);
void	isudecint(t_struct *list, va_list args);
int		manel(long n);
char	*ft_itoa_base(unsigned int n, unsigned int base);
void	ishex(t_struct *list, va_list args, char c);
void	formathex(unsigned int n, t_struct *list, char c, int len);
void	left_hex(t_struct *list, int len, char *s, char c);
void	right_hex(t_struct *list, int len, char *s, char c);
int		hexlen(long n);
void    asterix(const char *bota, t_struct *list, va_list args);
char	find(t_struct *list);
void    zeros(t_struct *list, int hexlen, char *s, char c);

#endif
