#include "ft_printf.h"
#include <limits.h> // Include the <limits.h> header file
#include <stdio.h>
int main()
{
	ft_printf(" % 1s", "");
ft_printf("% 1s ", "");
ft_printf(" % d ", -1);
ft_printf(" % d ", -9);
ft_printf(" % d ", -10);
ft_printf(" % d ", -11);
ft_printf(" % d ", -14);
ft_printf(" % d ", -15);
ft_printf(" % d ", -16);
ft_printf(" % d ", -99);
ft_printf(" % d ", -100);
ft_printf(" % d ", -101);
ft_printf(" % d ", LONG_MAX);
ft_printf(" % d ", UINT_MAX);
ft_printf(" % d ", ULONG_MAX);
ft_printf(" % d ", 9223372036854775807LL);
ft_printf(" % d % d % d % d % d % d % d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

}
