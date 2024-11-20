/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:56:49 by risattou          #+#    #+#             */
/*   Updated: 2024/11/20 16:49:39 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
#define   FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int 	ft_putchar(char c);
int	ft_puthex(size_t nbr, char *base);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_putnbr(int nb);
int	    ft_putstr(char *str);
int	ft_putunbr(unsigned int nb);
int ft_printf(const char *str, ...);

#endif
