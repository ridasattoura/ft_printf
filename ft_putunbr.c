
#include "ft_printf.h"

int	ft_putunbr(unsigned int nb,t_flag *flag)
{
	int count = 0;
	if(flag->plus == 2 && nb >= 0)
		count +=ft_putchar('+');
	else if(flag->space == 1 && nb >= 0)
		count +=ft_putchar(' ');
    if (nb > 9)
	{
		count += ft_putunbr(nb / 10,0);
		count += ft_putunbr(nb % 10,0);
	}
    else
        count +=ft_putchar((nb + 48));

	return count;
}