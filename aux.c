int	manel(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa_base(uintmax_t n, uintmax_t base)
{
	char	*dest;
	int	i;
	long	j;


	j = n;
	i = 1;
	while ((j /= base) >= 1)
		i++;
	dest = malloc(sizeof(char) * i + 1)
	dest[i] = '\0';
	j = n;
	while (j > 0)
	{
		dest[i] = j % base + '0';
		j = j / base;
		i--;
	}
	return (dest);
}
