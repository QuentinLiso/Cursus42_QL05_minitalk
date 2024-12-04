#include "minitalk.h"

void	set_sigaction(struct sigaction *sa, void (*action)(int, siginfo_t *, void *))
{
	ft_bzero(sa, sizeof(*sa));
	sa->sa_sigaction = action;
	sigemptyset (&(sa->sa_mask));
	sa->sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction (SIGUSR1, sa, NULL);
	sigaction (SIGUSR2, sa, NULL);
}