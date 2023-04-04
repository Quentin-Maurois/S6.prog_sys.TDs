#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 128

int main (int argc, char* argv[])
{
	if (argc < 1) exit(1);
	char buffer[BUFFER_SIZE];
	ssize_t n;
	int fd = open(argv[1], O_WRONLY | O_APPEND);
	if (fd == -1) exit(1);

	//lecture depuis l'entrée standard
	while((n = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
	{
		//écriture sur fd
		write(fd, buffer, n);
	}
	close(fd);
}