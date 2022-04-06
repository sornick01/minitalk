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
			usleep(500);
		}
		++message;
	}
	
}

void	get_signal_handler(int signum)
{
	ft_putendl_fd("bit received by server", 1);
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	// struct sigaction	get_signal;

	if (argc != 3)
	{
		ft_putendl_fd("wrong number of parameters", 2);
		exit(EXIT_FAILURE);
	}
	// get_signal.sa_handler = get_signal_handler;
	signal(SIGUSR1, get_signal_handler);
	// sigaction(SIGUSR1, &get_signal, NULL);
	server_pid = ft_atoi(argv[1]);
	send_message(server_pid, argv[2]);
}
// i--
// 'a' = 78;
// 10010011

// num = 0
// for (int i = 0; i < 8; ++i)
// {
// 	sig_result = ... // (0, 1)

// 	num |= sig_result << i;
// }

// char sym;
// for (int i = 0; i < 8; ++i)
// {
// 	send((sym >> i) & 1);

// }

//hellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohello