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
    signal(SIGSEGV, on_signal);
    signal(SIGINT, on_signal);

    while (1)
    {
        /*code*/
        sleep(1);   /*pour économiser un peu de cpu*/
    }
    return(0);
}