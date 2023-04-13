#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SIGINT 5


int current_sigint = 0;

void on_signal(int sig) {
    printf("*** signal %d\n", sig);
    if (sig == SIGINT)  current_sigint ++;
    else    current_sigint = 0;
    if (current_sigint >= MAX_SIGINT)   exit(0);
}


int main (void)
{
    struct sigaction sigact;

    sigact.sa_handler = on_signal;
    sigemptyset(&sigact.sa_mask);
    sigact.sa_flags = 0;

    sigaction(SIGSEGV, &sigact, NULL);
    sigaction(SIGINT, &sigact, NULL);

    // sleep(5);
    while (1)
    {
        /*code*/
        sleep(1);   /*pour économiser un peu de cpu*/
    }
    return(0);
}