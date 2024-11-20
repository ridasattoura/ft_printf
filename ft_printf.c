/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:46:22 by risattou          #+#    #+#             */
/*   Updated: 2024/11/20 17:28:49 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    va_list args;
    int count = 0;
    va_start(args, str);
    int i = 0;
    if(write(1,0,0) < 0)
        return (-1);
    while(str[i])
    {
        if (str[i] == '%' )
        {
            i++;
            if(str[i] == 'd' || str[i] == 'i')
                count +=ft_putnbr(va_arg(args,int));
            else if(str[i] == 'c')
                count +=ft_putchar(va_arg(args,int));
            else if(str[i] == 's')
                count +=ft_putstr(va_arg(args,char *));
            else if(str[i] == 'u')
                count +=ft_putunbr(va_arg(args,unsigned int));
            else if(str[i] == 'x')
                count +=ft_putnbr_base(va_arg(args,int),"0123456789abcdef");
            else if(str[i] == 'X')
                count +=ft_putnbr_base(va_arg(args, int),"0123456789ABCDEF");
            else if(str[i] == 'p')
            {
                count +=ft_putstr("0x");
                count +=ft_puthex(va_arg(args, size_t),"0123456789abcdef");
            }
            else if(str[i] == '%')
            {
                write(1,&str[i],1);
                count++;
            }
        }
        else
        {
            write(1,&str[i],1);
            count++;
        }
        i++;
    }
    va_end(args);
    return count;
}
#include <stdio.h>
int main()
{

	close(1);
	int i =printf("1234") + 48;
    
	write(2,&i,1);
	
}
