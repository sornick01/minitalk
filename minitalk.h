#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef	struct s_message
{
	char	char_code;
	int		counter;
}	t_message;

t_message	g_msg;

#endif