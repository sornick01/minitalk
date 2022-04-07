/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeanuts <mpeanuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:57:13 by mpeanuts          #+#    #+#             */
/*   Updated: 2022/04/07 15:57:14 by mpeanuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum)
{
	if (signum == SIGUSR1)
	{
		g_msg.char_code |= 1 << g_msg.counter;
		++g_msg.counter;
	}
	if (signum == SIGUSR2)
	{
		g_msg.char_code |= 0 << g_msg.counter;
		++g_msg.counter;
	}
	if (g_msg.counter == 8)
	{
		write(1, &g_msg.char_code, 1);
		g_msg.char_code = 0;
		g_msg.counter = 0;
	}
}

int	main(void)
{
	sigset_t			set;
	struct sigaction	act;

	sigemptyset(&set);
	g_msg.char_code = 0;
	g_msg.counter = 0;
	act.sa_flags = SA_SIGINFO;
	act.sa_mask = set;
	act.sa_handler = handler;
	ft_putstr_fd("My PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
}
