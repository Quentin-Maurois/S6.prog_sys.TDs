#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (void)
{
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        printf("\tProcessus fils\n");
        sleep(5);
        printf("\tFin du processus fils\n");
    }
    else
    {
        printf("Processus père\n");
        sleep(10);
        printf("Fin du processus père\n");
    }

    

    return 0;
}