
#include "ft_printf.h"

int	ft_putunbr(unsigned int nb)
{
	int count = 0;
    if (nb > 9)
	{
		count += ft_putunbr(nb / 10);
		count += ft_putunbr(nb % 10);
	}
    else
        count +=ft_putchar((nb + 48));

	return count;
}