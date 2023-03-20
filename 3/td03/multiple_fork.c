#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define P 10
#define N 10

int main (void)
{
    pid_t pid[P];
    for (int i = 0; i < P; i ++)
    {
        pid[i] = fork();
        if (pid[i] == 0)
        {
            for (int j = 0; j < N; j ++)
            {
                printf("%d\n", i);
                //sleep(1); //exercice 2
            }
            return 0;
        }
    }

    for (int i = 0; i < P; i ++)
    {
        waitpid(pid[i], NULL, 0);
    }

    return 0;
}