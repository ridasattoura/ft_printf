/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ader <ader@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:46:22 by risattou          #+#    #+#             */
/*   Updated: 2024/11/22 07:10:30 by ader             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



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
static void ft_reset(t_flag *flag)
{
    flag->dash = 0;
    flag->space = 0;
    flag->full_stop = 0;
    flag->zero = 0;
    flag->plus = 0;
    flag->hash = 0;
}

int ft_printf(const char *str, ...)
{
    if(write(1,0,0) < 0)
        return (-1);
    va_list args;
    t_flag *flag ;
    flag = malloc(sizeof(t_flag));
    if(!flag)
        return -1;
    int count = 0;
    int number = 0;

    va_start(args, str);
    while(*str)
    {
        if (*str == '%' )
        {
            str++;
            if(*str == ' ' ||*str == '+' ||*str == '#'||*str == '0' || *str == '-' || *str == '.')
                ft_flage(&str,flag);
            if(*str >= '0' && *str <= '9')
                number = ft_atoi(&str);
            if(*str == 'd' || *str == 'i')
                count +=ft_putnbr(va_arg(args,int),flag,number,1);
            else if(*str == 'c')
                count +=ft_putchar(va_arg(args,int),flag,number);
            else if(*str == 's')
                count +=ft_putstr(va_arg(args,char *),flag,number);
            else if(*str == 'u')
                count +=ft_putunbr(va_arg(args,unsigned int),flag,number);
            else if(*str == 'x')
                count +=ft_putnbr_base(va_arg(args,int),"0123456789abcdef",flag,number);
            else if(*str == 'X')
                count +=ft_putnbr_base(va_arg(args, int),"0123456789ABCDEF",flag,number);
            else if(*str == 'p')
            {
                count +=ft_putstr("0x",0,0);
                count +=ft_puthex(va_arg(args, size_t),"0123456789abcdef");
            }
            else if(*str == '%')
                count +=ft_putchar(*str,0,0);
        }
        else
            count +=ft_putchar(*str,0,0);
        ft_reset(flag);
        str++;
    }
    va_end(args);
    free(flag);
    return count;
}
