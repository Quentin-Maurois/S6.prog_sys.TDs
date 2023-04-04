#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <libgen.h>

int main (void)
{
    //redirection
    int fd = open("foo",O_WRONLY|O_CREAT|O_TRUNC , S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    dup2(fd, 1);
    close(fd);

    system("ls -l");
    // execlp("ls", "ls", "-l", 0); //crée un warning

    close(1);
    return(0);
}