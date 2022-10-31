#include "minitalk.h"

static void response(unsigned int *c_pid)
{
	kill(*c_pid, SIGUSR1);
	*c_pid = 0;
}

static void server_handler(int signum, siginfo_t *siginfo, void *context)
{
	static unsigned char	c = 0;
	static int 				i = 0;
	static unsigned int		c_pid = 0;

	(void)context;
	if (!c_pid)
		c_pid = siginfo->si_pid;
	c |= (signum == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		if (!c)
			return (response(&c_pid));
		ft_putchar(c);
		c = 0;
		kill(c_pid, SIGUSR2);
	}
	else
		c = c << 1;
}

int main(void)
{
	struct sigaction	sa;

	ft_putstr("Server running\n");
	ft_putstr("PID : \n");
	ft_putnbr(getpid());
	ft_putstr("\n");
	sa.sa_sigaction = server_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, 0) == -1)
		return(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, 0) == -1)
		return(EXIT_FAILURE);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}

