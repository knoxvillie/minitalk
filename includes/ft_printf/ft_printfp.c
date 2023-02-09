/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:56:38 by kfaustin          #+#    #+#             */
/*   Updated: 2022/12/05 16:48:26 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printfp(unsigned long number)
{
	int	count;

	count = 0;
	if (!number)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	count += ft_printfs("0x");
	count += ft_printfx(number, 'x');
	return (count);
}
/*
void	ft_buffer(char **str, int len, unsigned long num)
{
	**(str + len) = '\0';
	while (len-- >= 0)
	{
		**(str + len) = "0123456789abcdef"[num % 16];
		num /= 16;
	}
}

int	ft_magic(unsigned long number)
{
	int	i;

	i = 0;
	while (number > 0)
	{
		number /= 16;
		i++;
	}
	return (i);
}

int	ft_printfp(unsigned long number)
{
	int				count;
	int				len;
	unsigned long	num;
	char			*str;

	count = 0;
	if (!number)
		return (write (1, "(nil)", 5));
	num = number;
	len = ft_magic(num);
	if (len == 0)
		len = 1;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_buffer(&str, len, num);
	count += ft_printfs("0x");
	count += ft_printfs(str);
	free (str);
	return (count);
}

int	ft_printfp(unsigned long number)
{
	int				len;
	int				count;
	char			*str;
	unsigned long	num;

	count = 0;
	num = number;
	len = 0;
	if (number == 0)
		len = 1;
	while (num != 0 && len++ >= 0)
		num /= 16;
	len += 2;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	*(str + len) = '\0';
	*(str + 0) = '0';
	*(str + 1) = 'x';
	while (len > 1)
	{
		*(str + len) = "0123456789abcdef"[number % 16];
		number /= 16;
		len--;
	}
	count += ft_printfs(str);
	free (str);
	return (count);
}*/
