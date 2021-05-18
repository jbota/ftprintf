#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char *s = "1234";
	int r = ft_printf("ta feito %.*s %s !!!", 2, s, s);
	int h = printf("ta feito %.*s %s !!!", 2, s, s);
	ft_printf("\n%d   %d\n", r, h);
}
