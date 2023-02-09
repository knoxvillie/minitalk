/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:52:59 by kfaustin          #+#    #+#             */
/*   Updated: 2022/12/05 15:32:06 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_printfd(long number);
int		ft_printfx(unsigned long number, char c);
int		ft_printfc(char c);
int		ft_printfs(char *str);
int		ft_printfu(unsigned int number);
int		ft_printfp(unsigned long number);
char	ft_checkspecifier(char xar);

#endif
