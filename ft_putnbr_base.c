#include "ft_printf.h"


static int	ft_printr(unsigned int num, char *base, unsigned int len)
{
	int count = 0;
	if (num < 0)
	{
		count +=ft_putchar('-');
		num *= (-1);
		count +=ft_printr(num, base, len);
	}
	else if (num >= len)
	{
		count +=ft_printr(num / len, base, len);
		count +=ft_printr(num % len, base, len);
	}
	else
		count +=ft_putchar(base[num]);
	return count ;
}

int	ft_putnbr_base(unsigned int nbr, char *base,t_flag *flag)
{
	unsigned int	i;
	int count ;

	i = 16;
	count = 0;
	if(flag->hash == 1 && nbr > 0)
	{
		if(base[10] == 'a' )
			count +=ft_putstr("0x");
		else
			count +=ft_putstr("0X");
	}
	return (count + ft_printr(nbr, base, i));

}