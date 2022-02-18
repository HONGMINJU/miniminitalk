/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhong  <mhong@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 00:13:20 by mhong             #+#    #+#             */
/*   Updated: 2022/02/19 00:13:20 by mhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
	ft_printf("Server received message\n");
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

int	main(int argc, char *argv[])
{
	int	serverPID;

	serverPID = get_server_pid(argc, argv);
	send(serverPID, argv[2]);
	return (0);
}
