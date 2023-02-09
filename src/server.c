/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:48:22 by kfaustin          #+#    #+#             */
/*   Updated: 2023/01/09 15:55:01 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handler(int signalnum)
{
	static int	pos;
	static char	xar;

	if (signalnum == SIGUSR1)
		xar |= (0b1 << pos);
	pos++;
	if (pos == 8)
	{
		ft_printf("%c", xar);
		pos = 0;
		xar = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc > 1)
	{
		ft_printf("Server can not handle argvs");
		return (0);
	}
	pid = getpid();
	ft_printf("Mandatory Server is running - PID: %d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
		pause();
	}
	return (0);
}
