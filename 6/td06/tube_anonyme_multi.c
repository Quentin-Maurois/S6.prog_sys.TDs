#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void lecture (int fd);

int main (void)
{
    int fds[2];
    pipe(fds);

    switch(fork())
    {
        case -1 :
            perror("fork");
            exit(-1);
            break;
        case 0 :
            close(fds[0]);
            for(int i = 0; i < 26; i+=2)
            {
                char vals[2];
                vals[0] = i + 'a';
                vals[1] = i+1 + 'a';
                write(fds[1], vals, sizeof(vals));
                sleep(1);
            }
            close(fds[1]);
            break;
        default :   
            switch(fork())
            {
                case -1 :
                    perror("fork");
                    exit(-1);
                    break;
                case 0 :
                    close(fds[0]);
                    for(int i = 0; i < 26; i+=2)
                    {
                        char vals[2];
                        vals[0] = i + 'A';
                        vals[1] = i+1 + 'A';
                        write(fds[1], vals, sizeof(vals));
                        sleep(2);
                    }
                    close(fds[1]);
                    break;
                default :
                    close(fds[1]);
                    lecture(fds[0]);
                    close(fds[0]);
            }
            
    }
}

void lecture (int fd)
{
    char val[3];
    while (read(fd, val, 3))
    {
        write(1, val, 3);
        write(1, "\n", 1);

    }
}