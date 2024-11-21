/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:46:22 by risattou          #+#    #+#             */
/*   Updated: 2024/11/21 16:44:57 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



void ft_flage(char *str,t_flag *flag)
{
   
    while(*str == ' ' ||*str == '+' ||*str == '#' )
    {
        if(*str == ' ')
            flag->space = 1;
        else if(*str == '+')
            flag->plus = 1;
        else if(*str == '#')
            flag->hash = 1;
        str++;
    }
    
}


int ft_printf(const char *str, ...)
{
    va_list args;
    t_flag *flag = NULL;
    int count = 0;

    va_start(args, str);
    int i = 0;
    if(write(1,0,0) < 0)
        return (-1);
    while(*str)
    {
        if (*str == '%' )
        {
            i++;
            if(*str == ' ' ||*str == '+' ||*str == '#')
                ft_flage((char *)str,flag);
            if(*str == 'd' || *str == 'i')
                count +=ft_putnbr(va_arg(args,int),flag);
            else if(*str == 'c')
                count +=ft_putchar(va_arg(args,int));
            else if(*str == 's')
                count +=ft_putstr(va_arg(args,char *));
            else if(*str == 'u')
                count +=ft_putunbr(va_arg(args,unsigned int),flag);
            else if(*str == 'x')
                count +=ft_putnbr_base(va_arg(args,int),"0123456789abcdef",flag);
            else if(*str == 'X')
                count +=ft_putnbr_base(va_arg(args, int),"0123456789ABCDEF",flag);
            else if(*str == 'p')
            {
                count +=ft_putstr("0x");
                count +=ft_puthex(va_arg(args, size_t),"0123456789abcdef");
            }
            else if(*str == '%')
            {
                write(1,&*str,1);
                count++;
            }
        }
        else
        {
            write(1,&*str,1);
            count++;
        }
        str++;
    }
    va_end(args);
    return count;
}
