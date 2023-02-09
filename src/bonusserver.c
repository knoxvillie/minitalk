/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonusserver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:48:22 by kfaustin          #+#    #+#             */
/*   Updated: 2023/01/10 16:39:35 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void	handler(int signalnum, siginfo_t *info, void *ucontext)
{
	static int	pos;
	static char	xar;

	(void)ucontext;
	if (signalnum == SIGUSR1)
		xar |= (0b1 << pos);
	pos++;
	if (pos == 8)
	{
		ft_printf("%c", xar);
		if (xar == '\0')
			kill(info->si_pid, SIGUSR1);
		pos = 0;
		xar = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	cmd;

	(void)argv;
	if (argc > 1)
	{
		ft_printf("Server can not handle argvs");
		return (0);
	}
	cmd.sa_flags = SA_SIGINFO;
	cmd.sa_sigaction = &handler;
	sigemptyset(&cmd.sa_mask);
	sigaction(SIGUSR1, &cmd, NULL);
	sigaction(SIGUSR2, &cmd, NULL);
	pid = getpid();
	ft_printf("Bonus Server is running - PID: %d\n", pid);
	while (1)
	{
		pause();
	}
	return (0);
}
