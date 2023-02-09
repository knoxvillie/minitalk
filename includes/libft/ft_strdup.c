/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:43:38 by kfaustin          #+#    #+#             */
/*   Updated: 2023/01/10 16:35:54 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	size_t	sizestr;
	char	*str_cpy;

	sizestr = ft_strlen(str) + 1;
	str_cpy = (char *)malloc(sizestr);
	if (!str_cpy)
		return (NULL);
	i = 0;
	while (i < sizestr)
	{
		*(str_cpy + i) = *(str + i);
		i++;
	}
	return (str_cpy);
}
