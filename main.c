#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char *s = "1234";
//	int r = ft_printf("ta feito %03i !!!", 0);
//	int h = printf("ta feito %03i !!!", 0);
	int r = ft_printf(" %10p %-10p ", 0, 0);
	int h = printf(" %10p %-10p ", 0, 0);
	ft_printf("\n%d   %d\n", r, h);
}
