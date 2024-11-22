#include "ft_printf.h"

int	ft_putstr(char *str,t_flag *flag,int number)
{
	int	count;

	count = 0;
	if (!str)
	{
		return ft_putstr("(null)",0,0);
	}
	else if(flag && flag->full_stop == 1)
	{
		while(*str != '\0' && count < number)
		{
			count +=ft_putchar(*str,0,0);
			str++;
		}
	}
	else 
	{
		while (*str != '\0' )
		{
			count +=ft_putchar(*str,0,0);
				str++;
		}
		while(flag && flag->dash == 1 && count < number )
			count +=ft_putchar(' ',0,0);
	}
	return count;
}