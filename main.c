#include "ft_printf.h"

int main()
{
	char *s = "1234";
	int r = ft_printf("ta feito %s!!!", s);
	ft_printf("\n%d", r);
}
