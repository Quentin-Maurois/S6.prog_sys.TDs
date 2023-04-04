#include <unistd.h>

void lecture(int fd);

int main (void)
{
    int fds[2];
    pipe(fds);

    write(fds[1], "0123456789", sizeof("0123456789"));
    close(fds[1]);

    lecture (fds[0]);

    return (0);
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