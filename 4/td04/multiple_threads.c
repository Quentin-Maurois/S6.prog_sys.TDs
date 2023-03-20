#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

#include "timer.h"

#define NPROCESS 100

void *thread(void *arg)
{
    // sleep(30);
    pthread_exit(0);
}

long create_thread(int n)
{
    struct timespec vartime = timer_start();
    pthread_t *th = (pthread_t *) malloc(n * sizeof(pthread_t));
    for (int i = 0; i < n; i++)
    {
        pthread_create((th+n), NULL, thread, NULL);
    }
    for (int i = 0; i < n; i++)
    {
        pthread_join(*(th+n), NULL);
    }
    long time = timer_end(vartime);

    return time;
}


int main(int argc, char *argv[]) {
    int n = NPROCESS;

    for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-') {
        n = atoi(argv[i]);
        }
    }
    
    long time_thread = create_thread(n);
    
    printf("Time taken for creating %d threads (nanoseconds): %ld\n", n, time_thread);
    printf("Time taken for creating %d threads (milliseconds): %ld\n", n, time_thread / NANO_TO_MILLI);

    /* On flushe la sortie standard */
    fflush(stdout);

    /* Fin du père */
    exit(0);
}



