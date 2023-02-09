/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:27:49 by kfaustin          #+#    #+#             */
/*   Updated: 2023/01/10 16:37:41 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if ((dest == NULL) && (src == NULL))
		return (NULL);
	i = 0;
	if (dest > src)
	{
		while (n--)
		{
			*((unsigned char *)dest + n) = *((unsigned char *)src + n);
		}
	}
	else
	{
		while (n--)
		{
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
			i++;
		}
	}
	return (dest);
}
