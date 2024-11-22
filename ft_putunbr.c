
#include "ft_printf.h"


int	ft_putunbr(unsigned int nb,t_flag *flag,int nbr)
{
	int count = 0;
	if(flag && flag->plus == 1 && nb >= 0)
		count +=ft_putchar('+');
	else if(flag && flag->space == 1 && nb >= 0)
		count +=ft_putchar(' ');
	while(flag && flag->zero == 1 && nbr > count+ft_countnbr(nb))
		count+= ft_putchar('0');
    if (nb > 9)
	{
		count += ft_putunbr(nb / 10,0,0);
		count += ft_putunbr(nb % 10,0,0);
	}
    else
        count +=ft_putchar((nb + 48));

	return count;
}
