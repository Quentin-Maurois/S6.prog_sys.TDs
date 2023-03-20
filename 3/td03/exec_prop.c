#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {

    printf("pid pere : %d", getpid());      //ne s'affichera que lors du prochain \n
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork");
        abort();
    }
    else if (pid == 0)
    {
        printf("\tpid fils : %d\n", getpid());  //affichera le pid du père en buffer dont il a hérité puis celuis du fils
        printf("\tfin du fils\n");
        exit(0);
    }
    else
    {
        printf("pere reprends\n");
    }

    printf("pid du pere : %d", getpid());

    execl("./exec_prop_aux.exe", "exec_prop_aux", NULL);
    perror("exec"); //sauf erreur dans exec_prop-aux, le programme n'arrivera jamais ici
    exit(-1);
}