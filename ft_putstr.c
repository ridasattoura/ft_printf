#include "ft_printf.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}
int	ft_putstr(char *str,t_flag *flag)
{
	int	count;
	int sign;

	count = 0;
	sign = -1;
	if (!str)
	{
		return ft_putstr("(null)",flag);
	}
	else if(flag && flag->full_stop == 1)
	{
		while(*str != '\0' && count < flag->secondnbr)
		{
			count +=ft_putchar(*str,0);
			str++;
		}
	}
	else 
	{
		if(!(flag && flag->dash == 1))
			sign = ft_strlen(str) ;
		while( flag && sign > -1 && count+sign < flag->firstnbr)
			count+= write(1," ",1);
		while (*str != '\0' )
		{
			count +=ft_putchar(*str,0);
				str++;
		}
		while(flag && flag->dash == 1 && count < flag->secondnbr )
			count +=ft_putchar(' ',0);
	}
	return count;
}