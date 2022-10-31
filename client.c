#include "minitalk.h"

// #include <signal.h>
// #include <unistd.h>
// #include <stdlib.h>

// void	ft_putstr(char *str)
// {
// 	while (*str)
// 		write(1, str++, 1);
// }

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// void	ft_putnbr(int n)
// {
// 	if (n > 9)
// 		ft_putnbr(n / 10);
// 	write(1, &"0123456789"[n % 10], 1);
// }

// int	ft_atoi(const char *str)
// {
// 	int			res;
// 	int			sign;

// 	sign = 1;
// 	res = 0;
// 	while (*str >= 7 && *str <= 14)
// 		str++;
// 	if (*str == '-')
// 		sign = -1;
// 	if (*str == '-' || *str == '+')
// 		str++;
// 	while (*str >= '0' && *str <= '9')
// 	{
// 		res = res * 10 + (*str - 48);
// 		str++;
// 	}
// 	return (res * sign);
// }

// size_t	ft_strlen(const char *str)
// {
// 	int	i;

// 	if (!str)
// 		return (0);
// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

static void ft_client_handler(int signum, siginfo_t *siginfo, void *context)
{
	(void)siginfo;
	(void)context;
	if (signum == SIGUSR2) // SIGUSR2 is the sending signal 
	{
		return ;
	}
	ft_putstr("sending successful");
	exit(EXIT_FAILURE);	
}

static void ft_last_bit(int pid)
{
	int i;

	i = 8;
	while (i--)
	{
		if (kill(pid, SIGUSR2) == -1)
			ft_putstr("\n Error : Kill failed\n");
		usleep(10);
	}
}

static void ft_error(void)
{
	ft_putstr("\nError :Invalid PID\n");
	exit(EXIT_FAILURE);
}

static void send_to_server(int pid, char *str)
{
	int		i;
	char	c;

	while(*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{	
			if (c >> i & 1) // checks if bit is 1 else it's 0
			{
				if(kill(pid, SIGUSR1) == -1) // kill function sends bit 1
					ft_error();
			}
			else
				if (kill(pid, SIGUSR2) == -1) // kill function sends bit 0
					ft_error();
			usleep(50);
		}
	}
	ft_last_bit(pid);
}

int main(int argc, char **argv)
{
	struct sigaction sa;

	if(argc !=3 || !ft_strlen(argv[2]))
	{
		ft_putstr(" Enter arguments as: ./client [pid] [string]\n");
		exit(0);
	}
	sa.sa_sigaction = ft_client_handler;
	sa.sa_flags =SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, 0) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, 0) == -1)
		exit(EXIT_FAILURE);
	send_to_server(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
