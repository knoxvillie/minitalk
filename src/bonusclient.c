/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonusclient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:10:31 by kfaustin          #+#    #+#             */
/*   Updated: 2023/01/09 16:07:55 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

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

static void	handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("%s", "Message recived!\n");
		exit(0);
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
	signal(SIGUSR1, handler);
	pid = ft_atoi(*(argv + 1));
	str = *(argv + 2);
	ft_printf("Bonus Client:  PID: %d, MSG: %s\n", pid, str);
	i = 0;
	while (*(str + i))
	{
		xartosignal(*(str + i), pid);
		i++;
	}
	xartosignal('\0', pid);
	return (0);
}
