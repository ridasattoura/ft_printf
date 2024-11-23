/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:43:08 by risattou          #+#    #+#             */
/*   Updated: 2024/11/23 15:37:19 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c,t_flag *flag)
{
	int count ;
	int sign;
	
	count  = 0;
	sign = 0;
	if(flag && flag->dash == 1)
		sign = 1;
	while( sign == 0 && flag && count+1 < flag->firstnbr)
		count+= write(1," ",1);
	count += write(1, &c, 1);
	while(flag && flag->dash == 1 && count < flag->secondnbr)
		count+= write(1," ",1);
	return count;
}
