#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>
#include <string.h>

#define BUFFER_SIZE 128

int my_popen(char* cmd);

int main (int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("trop peu de paramètres\n");
        exit(-1);
    }

    int fd = my_popen(argv[1]);
    char buffer[BUFFER_SIZE];
    ssize_t n;
    ssize_t total;

    while((n = read(fd, buffer, sizeof(buffer))) > 0)
    {
        write(STDOUT_FILENO, buffer, n);
        total += n;
    }
    close(fd);
    printf("\n===== Nombre de caractères : %zd =====\n", total);

    return(0);
}

int my_popen(char* cmd) {
    int fds[2];
    pipe(fds);
    int pid;

    switch(pid = fork())
    {
        case -1 :
            perror("fork");
            exit(-1);
        case 0 :
            dup2(fds[1],STDOUT_FILENO);
            execl("/bin/sh", "sh", "-c", cmd, NULL);
            break;
        default :
            waitpid(pid,NULL,0);
            close(fds[1]);
    }
    return (fds[0]);
}