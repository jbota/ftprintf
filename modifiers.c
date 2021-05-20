
#include "ft_printf.h"

void	asterix(const char *bota, t_struct *list, va_list args)
{
	if (bota[list->i] == '*')
	{
		list->width = va_arg(args, int);
		if (list->width < 0)
		{
			list->minus = 1;
			list->width = -(list->width);
		}
	//	while (bota[list->i] == '*')
			list->i++;
	}
}

static void	flags(const char *bota, t_struct *list)
{
	while (ft_strchr("-0", bota[list->i]))
	{
		if (bota[list->i] == '-')
			list->minus = 1;
		if (bota[list->i] == '0')
			list->zero = 1;
		list->i++;
	}
}

static void	width(const char *bota, t_struct *list, va_list args)
{
	asterix(bota, list, args);
	if (bota[list->i] >= '0' && bota[list->i] <= '9')
	{
		list->width = ft_atoi(&bota[list->i]);
		while (bota[list->i] >= '0' && bota[list->i] <= '9')
		{
			list->i++;
			if (bota[list->i] == '*')
			{
				if (list->width < 0)
				{
					list->minus = 1;
					list->width = -(list->width);
				}
				while (bota[list->i] == '*')
					list->i++;
			}
		}
	}
}

static void	precision(const char *bota, t_struct *list, va_list args, int h)
{
	//int	i;

	//i = list->i;
	if (bota[list->i] == '.')
	{
		list->i++;
		list->dot = 1;
		if (bota[list->i] >= '0' && bota[list->i] <= '9')
		{
			list->precision = ft_atoi(&bota[list->i]);
			while (bota[list->i] >= '0' && bota[list->i] <= '9')
				list->i++;
		}
		else if (bota[list->i] == '*')
		{
			h = va_arg(args, int);
			if (h >= 0)
				list->precision = h;
			else if (h < 0)
				list->dot = 0;
			//while (bota[list->i] == '*')
			list->i++;
		}
	}
	//list->i = i;
}

void	modifiers(const char *bota, t_struct *list, va_list args)
{
	flags(bota, list);
	width(bota, list, args);
	precision(bota, list, args, 0);
}
