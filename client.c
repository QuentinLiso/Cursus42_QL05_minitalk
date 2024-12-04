#include "minitalk.h"

static int	g_srv_received_bit;

int		main(int ac, char **av)
{
	struct sigaction	sa;
	pid_t	s_pid;

	if (ac != 3)
	{
		ft_printf ("Wrong number of args !\n");
		ft_printf ("Prototype is : ./client <server_id> <string>\n");
		return (1);
	}
	s_pid = ft_atoi(av[1]);
	if (!s_pid || (kill (s_pid, 0) == -1))
	{
		ft_printf("PID %d is unavailable !\n", s_pid);
		return (1);
	}
	set_sigaction(&sa, &handle_sigfrom_srv);
	send_str_to_srv(s_pid, av[2]);
	while (1)
		sleep(1);
}

void	handle_sigfrom_srv(int signum, siginfo_t *info, void *other)
{
	(void) info;
	(void) other;
	if (signum == SIGUSR1)
		g_srv_received_bit = 1;
	else if (signum == SIGUSR2)
	{
		write (1, "Server got your message!\n", 25);
		exit (0);
	}
}

void	send_char_to_srv(int pid, char c)
{
	int	count;

	count = 7;
	while (count >= 0)
	{
		if (kill(pid, 0) < 0)
		{
			ft_printf("PID %d unreachable !\n", pid);
			exit (1);
		}
		g_srv_received_bit = 0;
		if ((c & (1 << count)))
			kill (pid, SIGUSR1);
		else if ((c & (1 << count)) == 0)
			kill (pid, SIGUSR2);
		count--;
		while (g_srv_received_bit == 0)
			usleep (30);
	}
}

void	send_str_to_srv(int pid, char *str)
{
	unsigned int	len;

	len = 0;
	if (!str)
		return ;
	while (str[len])
		send_char_to_srv(pid, str[len++]);
	send_char_to_srv(pid, (char)0);
}
