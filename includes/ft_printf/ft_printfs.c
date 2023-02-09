/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:51:55 by kfaustin          #+#    #+#             */
/*   Updated: 2022/12/05 15:30:51 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printfs(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!str)
		return (ft_printfs("(null)"));
	while (*(str + i))
	{
		ft_printfc(*(str + i++));
		count++;
	}
	return (count);
}
