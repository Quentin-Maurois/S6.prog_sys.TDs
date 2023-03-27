#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#define MAX 100

int main (int argc, char** argv)
{
    if (argc < 2) return(1);

    char* output_dir_path = *(argv - argc - 1);
    int input_fd, output_fd;


    printf("chemin : %s\n", output_dir_path);
    //on regarde si le dernier argument est répertoire
    // struct stat sbuf;
    // int m;
    // if (stat(*(argv + argc - 1), &sbuf) >= 0)
    // {
    //     m = sbuf.st_mode;
    // }
    // if (S_ISDIR(m))
    // {
    //     printf("c'est vers un dossier que vous voulez copier\n");
    //     dir_path = *(argv + argc - 1);  //new path
    // }


    char buffer[MAX];

    



    for (int i = 0; i < (argc - 1); i++)
    {
        //for each file
        ssize_t bytes_read, bytes_written;

        // ouverture des fichiers en lecture
        char* path = 
        input_fd = open(*(argv+i), O_RDONLY);
        if (input_fd == -1) {
            perror("open");
            return 1;
        }


        while ((bytes_read = read(input_fd, buffer, BUFSIZ)) > 0)
        {
            bytes_written = write(output_fd, buffer, bytes_read);
            if (bytes_written != bytes_read) {
                perror("write");
                return 1;
            }
        }
    }





    return (0);
}
