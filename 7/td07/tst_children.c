#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

pid_t aine;

void sigusr1_handler(int sig)
{
    printf("handling SIGUSR1 : %d\n", sig);
    kill(aine, SIGUSR2);
    exit(0);
}

void sigusr2_handler(int sig)
{
    printf("handling SIGUSR2 : %d\n", sig);
    exit(0);
}

int main (void)
{
    pid_t cadet;

    switch (aine = fork())
    {
        case -1 :
            perror("fork");
            exit(-1);
        case 0 :
            signal(SIGUSR2, sigusr2_handler);
            while(1)    sleep(1);
            break;
        default :
            switch (cadet = fork())
            {
                case -1 :
                    perror("fork");
                    exit(-1);
                case 0 :
                    signal(SIGUSR1, sigusr1_handler);
                    while(1)    sleep(1);
                    break;
                default :
                    sleep(1);   //attends que le cadet soit entièrement créé et ait setup la réception de signal correctement
                    kill(cadet, SIGUSR1);

                    for (int i = 0; i < 2; i++)
                    {
                        wait(NULL);
                    }
            }
    }






}