/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:43:08 by risattou          #+#    #+#             */
/*   Updated: 2024/11/22 21:33:41 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c,t_flag *flag,int number)
{
	int count ;
	
	count  = 0;
	while(flag && flag->dash == 0 && count+1 < number)
		count+= write(1," ",1);
	count += write(1, &c, 1);
	while(flag && flag->dash == 1 && count < number)
		count+= write(1," ",1);
	return count;
}
