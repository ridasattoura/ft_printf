
#include "ft_printf.h"

int	ft_putnbr(int nb,t_flag *flag,int number,int sign)
{
	int count = 0;
	if(flag &&flag->plus == 1 && nb > -1 && sign == 1)
		count +=ft_putchar('+',0,0);
	else if(flag && flag->space == 1 && nb > -1 && sign == 1)
		count +=ft_putchar(' ',0,0);
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648",0,0);
		count = 11;
	}
	else if (nb < 0)
	{
		count +=ft_putchar('-',0,0);
		nb *= (-1);
		count +=ft_putnbr(nb,flag,number-1,2);
		number = 0;
	}
	else if(number > 0)
	{
		while(flag && (flag->zero == 1 || flag->full_stop == 1)&& number > count+ft_countnbr(nb))
			count+= ft_putchar('0',0,0);
		if(sign == 2 && flag->full_stop == 1&& number+1 > count+ft_countnbr(nb))
			count+= ft_putchar('0',0,0);
		count +=ft_putnbr(nb, 0, 0,0);
	}
	else if (nb > 9)
	{
		count +=ft_putnbr((nb / 10),0,0,0);
		count +=ft_putnbr((nb % 10),0,0,0);
	}
	else
		count +=ft_putchar((nb + 48),0,0);
	return count ;
}