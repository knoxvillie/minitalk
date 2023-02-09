/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:04:24 by kfaustin          #+#    #+#             */
/*   Updated: 2022/12/05 15:22:20 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printfx(unsigned long number, char c)
{
	char	*basehex;
	int		count;

	count = 0;
	if (c == 'x')
		basehex = "0123456789abcdef";
	else
		basehex = "0123456789ABCDEF";
	if (number < 16)
		count += ft_printfc(*(basehex + number));
	else
	{
		count += ft_printfx((number / 16), c);
		count += ft_printfx((number % 16), c);
	}
	return (count);
}

/* static int	ft_get_num_len(long long num, int base)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num /= base;
	}
	return (len);
}

int	ft_printfx(unsigned int num, char c)
{
	int		len;
	char	*str;
	char	*basehex;

	if (c == 'x')
		basehex = "0123456789abcdef";
	else
		basehex = "0123456789ABCDEF";
	len = ft_get_num_len(num, 16);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	*(str + len--) = '\0';
	while (len >= 0)
	{
		*(str + len) = *(basehex + (num % 16));
		num /= 16;
		len--;
	}
	return (ft_printfs(str));
}
 */
