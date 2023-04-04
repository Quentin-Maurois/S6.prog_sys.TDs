#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

void lecture (int fd);

int main (void)
{
    int fds[2];
    pipe(fds);

    switch(fork())
    {
        case 0 :    //processus fils : lecteur
            close(fds[1]);
            lecture(fds[0]);
            close(fds[0]);
            break;
        default :    //processus père : écrivain
            close(fds[0]);
            write(fds[1], "0123456789", sizeof("0123456789"));
            sleep(2);
            close(fds[1]);
            break;
    }
}

void lecture (int fd)
{
    char val;
    while (read(fd, &val, 1))
    {
        write(1, &val, 1);
        write(1, " ", 1);
    }
    write(1, "\n", 1);
}