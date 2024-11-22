#include "ft_printf.h"
#include <limits.h> // Include the <limits.h> header file
#include <stdio.h>
int main()
{
ft_printf("||%-11p||%-12p|", INT_MIN, INT_MAX);
ft_printf("|%-13p||%-14p||", ULONG_MAX, -ULONG_MAX);
}
