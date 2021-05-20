
#include "ft_printf.h"

int	hex_len(unsigned long long n)
{
	int	i;

	i = 0;
	while (n / 16)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static void	right_palign(t_struct *list, int pwidth, int pprecision, int hexlen, char *s)
{
//	int	i;

	while (pwidth-- > 0)
		list->nprinted += write(1, " ", 1);
	list->nprinted += write(1, "0x", 2);
	while (pprecision-- > 0)
		list->nprinted += write(1, "0", 1);
	write(1, s, hexlen);
	list->nprinted += hexlen;
}

static void	left_palign(t_struct *list, int pwidth, int pprecision, int hexlen, char *s)
{
//	int	i;

//	i = 0;
	list->nprinted += write(1, "0x", 2);
	while (pprecision-- > 0)
		list->nprinted += write(1, "0", 1);
	write(1, s, hexlen);
	list->nprinted += hexlen;
	while (pwidth-- > 0)
		list->nprinted += write(1, " ", 1);
}

void	ispointer(t_struct *list, va_list args, int n)
{
	int			hexlen;
	char			*s;
	int			pprecision;
	int			pwidth;
	unsigned long long	pointer;

	pointer = (unsigned long long)va_arg(args, void *);
	n = 2;
//	hexlen = hex_len(pointer) + 1;
	s = ft_base_itoa(pointer, 16);
	s = ft_lower_str(s);
	hexlen = ft_strlen(s);
	pprecision = list->precision - hexlen;
	pwidth = list->width - hexlen - n;
	if (list->dot && list->precision == 0)
		hexlen = 0;
	if (list->minus)
		left_palign(list, pwidth, pprecision, hexlen, s);
	else
		right_palign(list, pwidth, pprecision, hexlen, s);
	free(s);
}
