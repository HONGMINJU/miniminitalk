/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong  <mhong@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:59:07 by mhong             #+#    #+#             */
/*   Updated: 2022/02/18 18:59:07 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

struct sigaction	signalAction;

void	handleSignal(int signo, siginfo_t *siginfo, void *unused)
{
	static unsigned char	msg = 0;
	static int				digit = 0;

	(void)unused;
	(void)siginfo;
	if (signo == SIGUSR1)
		msg |= (1 << digit);
	digit++;
	if (digit == 8)
	{
		ft_printf("server receive msg : %c\n", msg);
		//ft_printf("%c", msg);
		digit = 0;
		msg = 0;
	}
}

void setSigaction(void)
{
    signalAction.sa_flags = SA_SIGINFO;
	signalAction.sa_sigaction = &handleSignal;
	sigemptyset(&signalAction.sa_mask);
	sigaddset(&signalAction.sa_mask, SIGUSR1);
	sigaddset(&signalAction.sa_mask, SIGUSR2);
}

void printPid(void)
{
	ft_printf("============== PID(server) : %d ==============\n", getpid());
}

int	main(void)
{
    printPid();
    setSigaction();
	if (sigaction(SIGUSR1, &signalAction, NULL) == -1)
	{
		ft_putstr_fd("Sigaction Error\n", 2);
		exit(1);
	}
	if (sigaction(SIGUSR2, &signalAction, NULL) == -1)
	{
		ft_putstr_fd("Sigaction Error\n", 2);
		exit(1);
	}
	while (1)
		pause();
	return (0);
}
