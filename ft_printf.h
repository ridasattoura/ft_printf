/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:56:49 by risattou          #+#    #+#             */
/*   Updated: 2024/11/23 19:37:49 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
#define   FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct s_flags{
    int hash;
    int plus;
    int space;
    int zero;
    int dash;
    int firstnbr;
    int secondnbr;
    int full_stop;
    
} t_flag;

int ft_countnbr(long nbr);

int ft_countnbr_base(unsigned int nbr);

int	ft_atoi(const char **str);

int 	ft_putchar(char c,t_flag *flag);

int	ft_puthex(size_t nbr, char *base,t_flag *flag);

int	ft_putnbr_base(unsigned int nbr, char *base,t_flag *flag);

int	ft_putnbr(int nb,t_flag *flag,int sign);

int	    ft_putstr(char *str,t_flag *flag);

int	ft_putunbr(unsigned int nb,t_flag *flag);

int ft_printf(const char *str, ...);

#endif
