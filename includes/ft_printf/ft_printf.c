/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:48:09 by kfaustin          #+#    #+#             */
/*   Updated: 2022/12/06 10:57:38 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_mainprintf(char specifier, va_list var)
{
	int	printed_bytes;

	printed_bytes = 0;
	if (specifier == '%')
		printed_bytes = ft_printfc('%');
	else if (specifier == 'c')
		printed_bytes = ft_printfc(va_arg(var, int));
	else if (specifier == 's')
		printed_bytes = ft_printfs(va_arg(var, char *));
	else if (specifier == 'i' || specifier == 'd')
		printed_bytes = ft_printfd(va_arg(var, int));
	else if (specifier == 'u')
		printed_bytes = ft_printfu(va_arg(var, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		printed_bytes = ft_printfx(va_arg(var, unsigned int), specifier);
	else if (specifier == 'p')
		printed_bytes = ft_printfp(va_arg(var, unsigned long));
	return (printed_bytes);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	var;

	va_start(var, str);
	i = 0;
	count = 0;
	while (*(str + i))
	{
		if (*(str + i) == '%' && ft_checkspecifier(*(str + i + 1)))
			count += ft_mainprintf(*(str + i++ + 1), var);
		else if (*(str + i) == '%' && !ft_checkspecifier(*(str + i + 1)))
		{
			write (1, "Especifier ERROR!", 18);
			return (count);
		}
		else
		{
			write (1, (str + i), 1);
			count++;
		}
		i++;
	}
	va_end(var);
	return (count);
}
