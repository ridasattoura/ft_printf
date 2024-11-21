/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:46:22 by risattou          #+#    #+#             */
/*   Updated: 2024/11/21 23:51:43 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>



void ft_flage(const char **str,t_flag *flag)
{
   
    while(**str == ' ' ||**str == '+' ||**str == '#'  ||**str == '0' || **str == '-' || **str == '.')
    {
        if(**str == ' ')
            flag->space = 1;
        else if(**str == '+')
            flag->plus = 1;
        else if(**str == '#')
            flag->hash = 1;
        else if(**str == '0')
            flag->zero = 1;
        else if(**str == '.')
            flag->full_stop = 1;
        else if(**str == '-')
            flag->dash = 1;
        (*str)++;
    }
    
}


int ft_printf(const char *str, ...)
{
    va_list args;
    t_flag *flag = NULL;
    flag = malloc(sizeof(t_flag));
    if(!flag)
        return -1;
    int count = 0;
    int nbr = 0;

    va_start(args, str);
    if(write(1,0,0) < 0)
        return (-1);
    while(*str)
    {
        if (*str == '%' )
        {
            str++;
            if(*str == ' ' ||*str == '+' ||*str == '#'||*str == '0' || *str == '-' || *str == '.')
                ft_flage(&str,flag);
            if(*str >= '0' && *str <= '9')
                nbr = ft_atoi(&str);
            if(*str == 'd' || *str == 'i')
                count +=ft_putnbr(va_arg(args,int),flag,nbr);
            else if(*str == 'c')
                count +=ft_putchar(va_arg(args,int));
            else if(*str == 's')
                count +=ft_putstr(va_arg(args,char *));
            else if(*str == 'u')
                count +=ft_putunbr(va_arg(args,unsigned int),flag,nbr);
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
                write(1,str,1);
                count++;
            }
        }
        else
        {
            write(1,str,1);
            count++;
        }
        str++;
    }
    va_end(args);
    free(flag);
    return count;
}
