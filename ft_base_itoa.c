#include "ft_printf.h"

static char	*base_treat(unsigned long j, int base, char *dest, int i)
{
	while (j != 0)
	{
		if((j % base < 10))
			dest[i - 1] = (j % base) + 48;
		else
			dest[i - 1] = (j % base) + 55;
		j /= base;
		i--;
	}
	return (dest);
}

char	*ft_base_itoa(unsigned long n, int base)
{
	char	*dest;
	int	i;
	long	j;

	i = 0;
	j = n;
	if (j == 0)
		return (ft_strdup("0"));
	while (n != 0)
	{
		n /= base;
		i++;
	}
	if (!(dest = malloc(sizeof(char) * (i + 1))))
		return (0);
	dest[i] = '\0';
	dest = base_treat(j, base, dest, i);
	return (dest);
}
