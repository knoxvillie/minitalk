/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:00:27 by kfaustin          #+#    #+#             */
/*   Updated: 2022/12/05 14:18:39 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printfu(unsigned int number)
{
	int	count;

	count = 0;
	if (number < 10)
		count += ft_printfc(number + '0');
	else
	{
		count += ft_printfd(number / 10);
		count += ft_printfd(number % 10);
	}
	return (count);
}
