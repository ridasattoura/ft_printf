#include "ft_printf.h"


static int	ft_printr(unsigned int num, char *base)
{
	int count = 0;
	if (num < 0)
	{
		count +=ft_putchar('-',0,0);
		num *= (-1);
		count +=ft_printr(num, base);
	}
	else if (num >= 16)
	{
		count +=ft_printr(num / 16, base);
		count +=ft_printr(num % 16, base);
	}
	else
		count +=ft_putchar(base[num],0,0);
	return count ;
}

int	ft_putnbr_base(unsigned int nbr, char *base,t_flag *flag, int nb)
{
	int count ;

	count = 0;
	if(flag && flag->hash == 1 && nbr > 0)
	{
		if(base[10] == 'a' )
			count +=ft_putstr("0x",0,0);
		else
			count +=ft_putstr("0X",0,0);
	}
	while(flag &&(flag->zero == 1 || flag->full_stop == 1) && nb > (count+ft_countnbr_base(nbr)))
		count += ft_putchar('0',0,0);
	return (count + ft_printr(nbr, base));

}