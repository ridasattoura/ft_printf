/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:28:14 by risattou          #+#    #+#             */
/*   Updated: 2024/11/21 23:14:12 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char **str)
{
	long	result;



	result = 0;
	while (**str >= 48 && **str <= 57)
	{
		result = result * 10 + **str - 48;
		(*str)++;
	}
	return (result);
}
