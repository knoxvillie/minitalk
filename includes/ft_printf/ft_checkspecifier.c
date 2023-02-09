/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkspecifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:19:56 by kfaustin          #+#    #+#             */
/*   Updated: 2022/12/05 14:22:13 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_checkspecifier(char xar)
{
	char	*specifier;
	int		i;

	i = 0;
	specifier = "cspdiuxX%";
	while (*(specifier + i))
	{
		if (xar == *(specifier + i))
			return (*(specifier + i));
		i++;
	}
	return (0);
}
