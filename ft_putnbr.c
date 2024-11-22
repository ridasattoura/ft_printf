
#include "ft_printf.h"

int	ft_putnbr(int nb,t_flag *flag,int nbr,int sign)
{
	int count = 0;
	if(flag &&flag->plus == 1 && nb > -1 && sign == 1)
		count +=ft_putchar('+');
	else if(flag && flag->space == 1 && nb > -1 && sign == 1)
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
		count +=ft_putnbr(nb,flag,nbr-1,0);
		nbr = 0;
	}
	else if(nbr > 0)
	{
		while(flag && flag->zero == 1 && nbr > count+ft_countnbr(nb))
			count+= ft_putchar('0');
		count +=ft_putnbr(nb, 0, 0,0);
	}
	else if (nb > 9)
	{
		count +=ft_putnbr((nb / 10),0,0,0);
		count +=ft_putnbr((nb % 10),0,0,0);
	}
	else
		count +=ft_putchar((nb + 48));
	return count ;
}