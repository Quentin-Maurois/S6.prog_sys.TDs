#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 128

int main (int argc, char* argv[])
{
    if (argc < 1) exit(1);
	char buffer[BUFFER_SIZE];
	ssize_t n;
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1) exit(1);

    //lecture depuis fd
	while((n = read(fd, buffer, sizeof(buffer))) > 0)
	{
        //ecriture sur la sortie standard
		write(STDOUT_FILENO, buffer, n);
	}
	close(fd);
}