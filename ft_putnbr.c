#include <stdio.h>
#include "ft_printf.h"
int	ft_putnbr(int nb,t_flag *flag,int sign)
{
	int x = 0;
	int count = 0;
	if(flag &&flag->plus == 1 && nb > -1 && sign == 1)
		count +=ft_putchar('+',0);
	else if(flag && ((flag->space == 1  && nb > -1&&sign == 1)||(flag->firstnbr > count+ft_countnbr(nb))))
	{
		x = ft_countnbr(nb);
		if(flag->secondnbr > x)
			x = flag->secondnbr;
		// if(nb < 0 &&  flag->secondnbr > x)
		// 	x++;
		while(flag && flag->firstnbr-1 > count+x)
			count +=ft_putchar(' ',0);
		count +=ft_putchar(' ',0);
		flag->firstnbr = 0;
	}
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648",0);
		count = 11;
	}
	else if (nb < 0)
	{
		count +=ft_putchar('-',0);
		flag->secondnbr--;
		count +=ft_putnbr(-nb,flag,2);
		flag->secondnbr++;
	}
	else if(flag && flag->secondnbr > 0)
	{
		while(flag && (flag->zero == 1 || flag->full_stop == 1)&& (flag->secondnbr > count+ft_countnbr(nb)))
			count+= ft_putchar('0',0);
		if(sign == 2 && flag->full_stop == 1&& flag->secondnbr+1 > count+ft_countnbr(nb))
			count+= ft_putchar('0',0);
		count +=ft_putnbr(nb, 0, 0);
	}
	else if (nb > 9)
	{
		count +=ft_putnbr((nb / 10),0,0);
		count +=ft_putnbr((nb % 10),0,0);
	}
	else
		count +=ft_putchar((nb +48),0);
	return count ;
}