#include "ft_printf.h"
static int	manelu(long n)
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

char	*ft_u_itoa(unsigned int n)
{
	char	*dest;
	int	i;
	long	j;


	j = n;
	i = manelu(j);
	if (j == 0)
		return (ft_strdup("0"));
	if (!(dest = malloc(sizeof(char) * i + 1)))
		return (NULL);
	dest[i--] = '\0';
	if (j < 0)
	{
//		dest[0] = '-';
		j = j * -1;
	}
	while (j > 0)
	{
		dest[i] = j % 10 + '0';
		j = j / 10;
		i--;
	}
	return (dest);
}
