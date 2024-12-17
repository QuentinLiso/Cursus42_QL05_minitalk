/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qzoli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:13:18 by qzoli             #+#    #+#             */
/*   Updated: 2024/12/17 09:13:19 by qzoli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	t_sa	sa;

	ft_printf("(#~>~#~>:. Welcome to server %d .:<~#~<~#)\n", getpid());
	set_sigaction(&sa, &handle_sigfrom_client);
	while (1)
		sleep(1);
	return (0);
}

void	handle_sigfrom_client(int signum, siginfo_t *info, void *other)
{
	static char	letter = '\0';
	static int	count = -1;

	(void) other;
	if (kill(info->si_pid, 0) < 0)
	{
		printf ("Cannot send back signal to PID : %d\n", info->si_pid);
		exit (1);
	}
	if (count < 0 && letter == '\0')
		ft_printf("\nMessage from %d : ", info->si_pid);
	if (count < 0)
		count = 7;
	if (signum == SIGUSR1)
		letter |= 1 << count;
	else if (signum == SIGUSR2)
		letter &= ~(1 << count);
	if (count == 0 && letter != '\0')
		ft_putchar_fd(letter, 1);
	else if (count == 0 && letter == '\0')
		kill (info->si_pid, SIGUSR2);
	count--;
	kill (info->si_pid, SIGUSR1);
}
