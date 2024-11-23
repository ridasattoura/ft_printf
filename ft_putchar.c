/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ader <ader@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:43:08 by risattou          #+#    #+#             */
/*   Updated: 2024/11/23 00:49:12 by ader             ###   ########.fr       */
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
	while(flag && flag->dash == 1 && count < flag->firstnbr)
		count+= write(1," ",1);
	return count;
}
