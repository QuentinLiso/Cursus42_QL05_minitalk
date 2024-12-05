#ifndef MINITALK_H
# define MINITALK_H

#include "libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

// Server functions
void	handle_sigfrom_client(int signum, siginfo_t *info, void *other);

// Client functions
void	handle_sigfrom_srv(int signum, siginfo_t *info, void *other);
void	send_char_to_srv(int pid, char c);
void	send_str_to_srv(int pid, char *str);

// Helper functions
void	set_sigaction(struct sigaction *sa, void (*action)(int, siginfo_t *, void *));

#endif