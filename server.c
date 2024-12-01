#include "minitalk.h"

/*
Prog execution : ./server
*/
ft_signal(int sign, void *handler, int use_signinfo)
{

}

void    ft_sighandler(int signo, siginfo_t *info, void *more_info)
{
    (void)more_info;


}


int main(void)
{
    printf("Server PID : %d\n", getpid());
    ft_signal(SIGUSR1, ft_sighandler, 1);
    while (1)
    {
        pause();
    }

    return (EXIT_SUCCESS);
}