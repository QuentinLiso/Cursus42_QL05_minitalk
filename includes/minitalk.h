/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qzoli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:29:15 by qzoli             #+#    #+#             */
/*   Updated: 2024/12/17 09:29:16 by qzoli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct sigaction	t_sa;

// Server functions
void	handle_sigfrom_client(int signum, siginfo_t *info, void *other);

// Client functions
void	handle_sigfrom_srv(int signum, siginfo_t *info, void *other);
void	send_char_to_srv(int pid, char c);
void	send_str_to_srv(int pid, char *str);

// Helper functions
void	set_sigaction(t_sa *sa, void (*action)(int, siginfo_t *, void *));

#endif
