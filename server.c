#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

static void response(unsigned int *c_pid)
{
	kill(*c_pid, SIGUSR1);
	*c_pid = 0;
}

static void handler(int sig, siginfo_t *siginfo, void *optional)
{
	static unsigned char	c = 0;
	static int 				i = 0;
	static unsigned int		c_pid = 0;

	(void)optional;
	if (!c_pid)
		c_pid = siginfo->si_pid;
	c |= (sig == SIGUSR1);
	if (i++ == 8)
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
	/// delete
	int a;
	struct sigaction	sa;

	ft_putstr("Server running\n");
	ft_putstr("PID : \n");
	ft_putnbr(getpid());
	ft_putstr("\n");

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, 0) == -1)
		return(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, 0) == -1)
		return(EXIT_FAILURE);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}

