
#include "ft_printf.h"

int	ft_putnbr(int nb,t_flag *flag)
{
	int count = 0;
	if(flag->plus == 2 && nb >= 0)
		count +=ft_putchar('+');
	else if(flag->space == 1 && nb >= 0)
		count +=ft_putchar(' ');
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		count = 11;
	}
	else if (nb < 0)
	{
		count +=ft_putchar('-');
		nb *= (-1);
		count +=ft_putnbr(nb,0);
	}
	else if (nb > 9)
	{
		count +=ft_putnbr((nb / 10),0);
		count +=ft_putnbr((nb % 10),0);
	}
	else
		count +=ft_putchar((nb + 48));
	return count ;
}