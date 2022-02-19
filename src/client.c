/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong  <mhong@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:16:31 by mhong             #+#    #+#             */
/*   Updated: 2022/02/18 19:16:31 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	send_signal(int	s_pid, int byte)
{
	int	digit;

	digit = 0;
	while (digit <= 7)
	{
		if ((byte >> digit) & 1)
		{
			if (kill(s_pid, SIGUSR1) == -1)
			{
				ft_putstr_fd("Signal Error : from Client\n", 2);
				exit(1);
			}
		}
		else
		{
			if (kill(s_pid, SIGUSR2) == -1)
			{
				ft_putstr_fd("Signal Error : from Client\n", 2);
				exit(1);
			}
		}
		digit++;
		usleep(100);
	}
}

void	send(int s_pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i] != '\0')
	{
		send_signal(s_pid, msg[i++]);
	}
}

int	get_server_pid(int argc, char *argv[])
{
	int	s_pid;

	if (argc != 3)
	{
		ft_putstr_fd("please enter all arguments\n", 2);
		exit(1);
	}
	s_pid = ft_atoi(argv[1]);
	if (s_pid < 100 || s_pid > 99998)
	{
		ft_putstr_fd("Wrong pid\n", 2);
		exit(1);
	}
	return (s_pid);
}

void	handleSignal(int signo, siginfo_t *siginfo, void *unused)
{
	static unsigned char	msg = 0;
	static int				digit = 0;

	(void)unused;
	(void)siginfo;
	if (signo == SIGUSR2)
		ft_printf("\n=======Server received message=======\n");
}

int	main(int argc, char *argv[])
{
	struct sigaction	signalAction;
	int	serverPID;

	signalAction.sa_flags = SA_SIGINFO;
	signalAction.sa_sigaction = &handleSignal;
	sigemptyset(&signalAction.sa_mask);
	sigaddset(&signalAction.sa_mask, SIGUSR2);
	serverPID = get_server_pid(argc, argv);
	send(serverPID, argv[2]);
	return (0);
}
