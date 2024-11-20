
#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int count = 0;
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		count = 11;
	}
	else if (nb < 0)
	{
		count +=ft_putchar('-');
		nb *= (-1);
		count +=ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		count +=ft_putnbr(nb / 10);
		count +=ft_putnbr(nb % 10);
	}
	else
		count +=ft_putchar((nb + 48));
	return count ;
}