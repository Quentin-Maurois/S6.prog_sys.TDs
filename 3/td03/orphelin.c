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
        int ppid = getppid();   //pid du père qui l'a fork
        printf("\tParent : %d\n", ppid);
        while (getppid() == ppid) sleep(1); //attends le changement de pid du parent qui signifie que le parent est terminé avant le fils 
        printf("\tNouveau parent : %d\n", getppid());
        printf("\tFin du processus fils\n");
    }
    else
    {
        printf("Processus père\npid : %d\n", getpid());
        sleep(2);
        printf("Fin du processus père\n");
    }

    

    return 0;
}