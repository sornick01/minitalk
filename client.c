/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeanuts <mpeanuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:57:30 by mpeanuts          #+#    #+#             */
/*   Updated: 2022/04/07 15:57:31 by mpeanuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(pid_t server_pid, char *message)
{
	int		i;
	char	bit;

	while (*message)
	{
		i = 0;
		while (i < 8)
		{
			bit = (*message >> i) & 1;
			if (bit)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			++i;
			usleep(750);
		}
		++message;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
	{
		ft_putendl_fd("wrong number of parameters", 2);
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	send_message(server_pid, argv[2]);
}
