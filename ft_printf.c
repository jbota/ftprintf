int	ft_printf(const char *bota, ...)
{
	const char	joao;
	va_list		args;
	int		print;

	joao = ft_strdup(bota);
	if (!joao)
		return (0);
	va_start(args, bota);


	va_end(args);
	free (joao);
	return(print);
}
