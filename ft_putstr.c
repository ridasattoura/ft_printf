#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		return ft_putstr("(null)");
	}
	while (*str != '\0')
	{
		count +=ft_putchar(*str);
		str++;
	}
	return count;
}