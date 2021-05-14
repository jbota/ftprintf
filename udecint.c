
void	formatvalue(uintmax_t n, t_struct *list, int sinal)
{
	char	*s;
	int	len;

	if (list->space && sinal != 0)
		list->space = 0;
	s = ft_itoa(n);
	len = manel(n);
	if (n == 0)
		len = 1;
	if (list->dot && list->precsion == 0)
		len = 0;
	if (list->dot && list->precision > len)
		list->precision = list->precision - len;
	else
		list->precision = 0;
	if (sinal != 0)
		list->width = list->width - (list->precision + len + 1 + list->space);
	else
		list->width = list->width - (list->precision + len + list->space);
	if (list->minus == 0)
		right_u(list, len, s, sinal);
	if (ist->minus == 1)
		left_u(list, len, s, sinal);
	free(s);
}

void	isudecint(t_struct *list, va_list args)
{
	uintmax_t	n;
	int		sinal;

	sinal = 0;
	n = 0;
	if (list->space)
		list->space = 0;
	if (list->length == 0)
		n = (unsigned int)va_arg(args, unsigned int);
	if (list->plus)
		sinal = POSITIVE;
	formatvalue(n, list, sinal);
}
