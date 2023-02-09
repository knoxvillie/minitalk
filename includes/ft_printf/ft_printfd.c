/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:57:08 by kfaustin          #+#    #+#             */
/*   Updated: 2022/12/05 15:33:10 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printfd(long number)
{
	int		count;

	count = 0;
	if (number < 0)
	{
		number *= -1;
		count += ft_printfc('-');
	}
	if (number < 10)
		count += ft_printfc(number + '0');
	else
	{
		count += ft_printfd(number / 10);
		count += ft_printfd(number % 10);
	}
	return (count);
}
