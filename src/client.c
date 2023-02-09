/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:48:25 by kfaustin          #+#    #+#             */
/*   Updated: 2023/01/09 16:07:45 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	xartosignal(char xar, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((xar & (0b1 << bit)) == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit++;
		usleep(150);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		pid;
	char	*str;

	if (argc != 3)
	{
		ft_printf("Client must have a PID and a msg!\n");
		return (0);
	}
	pid = ft_atoi(*(argv + 1));
	str = *(argv + 2);
	ft_printf("Mandatory Client:  PID: %d, MSG: %s\n", pid, str);
	i = 0;
	while (*(str + i))
	{
		xartosignal(*(str + i), pid);
		i++;
	}
	return (0);
}
