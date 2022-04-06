#include "minitalk.h"

void	handler(int signum, siginfo_t *info, void *context)
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
		// printf("%c\t%d\t%d\n", g_msg.char_code, g_msg.char_code, g_msg.counter);
		g_msg.char_code = 0;
		g_msg.counter = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	sigset_t			set;
	struct sigaction	act1;

	sigemptyset(&set);
	g_msg.char_code = 0;
	g_msg.counter = 0;
	act1.sa_flags = SA_SIGINFO;
	act1.sa_mask = set;
	act1.__sigaction_u.__sa_sigaction = handler;
	ft_putnbr_fd(getpid(), 1);
	sigaction(SIGUSR1, &act1, NULL);
	sigaction(SIGUSR2, &act1, NULL);
	while (1)
		pause();
}
