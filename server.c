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

static void handler(int sig, siginfo_t *siginfo, void *optional)
{
	static unsigned char
}



int main(void)
{
	struct sigaction	sa;

	ft_putstr("Server running\n");
	ft_putstr("PID : \n");
	ft_putnbr(getpid());
	ft_putstr("\n");
	
	sa.sa_sigaction = handler_s;

	
}

