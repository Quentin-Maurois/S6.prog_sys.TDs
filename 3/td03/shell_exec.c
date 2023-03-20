#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
    //execution des commandes "who" suivie de "ls -ls"
    //avec fork et execxx

    /*  Exercice 6
        who
    */
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        execlp("who", "who", 0);
        perror("execXX(who)");  //juste au cas où
    }
    else
    {
        wait(0);
    }

    /*  Exercice 7
        cd
    */
    char* home_dir = getenv("HOME");
    if (strcmp(home_dir, "") == 0)   //cannot access home directory
    {
        perror("cannot access home directory");
        exit(1);
    }
    if (chdir(home_dir) < 0)
    {
        perror("unable to move to home directory");
        exit(1);
    }


    /*  Exercice 6
        who
    */
    pid = fork(); 
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        execlp("ls", "ls", "-ls", 0);
        perror("execXX(ls -ls)");  //juste au cas où
    }
    else
    {
        wait(0);
    }

    return(0);
}