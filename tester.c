#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
void display_pid()
{
    printf("PID : %d\n", getpid());
}

void signal_handler(int signum) 
{
  printf("Received SIGINT! %d\n", signum);
  exit(0);
}

int main() 
{
  // Set the signal handler for the SIGINT and SIGTERM signals
  // to the signal_handler function
  display_pid();
  signal(SIGINT, signal_handler);
  signal(SIGTERM, signal_handler);

  while (1) {
    // Do some work here...
  }

  return 0;
}
*/

int main(void)
{
    sigset_t signal_set;

    // Initialize an empty signal set
    sigemptyset(&signal_set);

    // Add SIGINT to the signal set
    sigaddset(&signal_set, SIGINT);
}