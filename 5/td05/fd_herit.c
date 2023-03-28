#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int fd, ret;
    pid_t pid;
    char buf[50];

    // Ouvre les fichiers passés en argument pour lecture
    for (int i = 1; i < argc; i++) {
        fd = open(argv[i], O_RDONLY);
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        printf("%s = %d\n", argv[i], fd);
        close(fd);
    }

    // Ouvre un fichier pour écriture
    fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Écrit une chaîne dans le fichier
    ret = write(fd, "Hello world!\n", 13);
    if (ret == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Crée un processus fils
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Processus fils
        // Lit le contenu du fichier
        lseek(fd, 0, SEEK_SET);
        ret = read(fd, buf, 50);
        if (ret == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Affiche le contenu lu
        printf("Contenu du fichier dans le processus fils :\n%s\n", buf);

        // Ferme le descripteur de fichier ouvert dans le processus fils
        close(fd);

        exit(EXIT_SUCCESS);
    } else { // Processus père
        // Attend que le processus fils se termine
        wait(NULL);

        // Ferme le descripteur de fichier ouvert dans le processus père
        close(fd);

        // Affiche un message de confirmation
        printf("Le descripteur de fichier a été fermé dans le processus père.\n");
    }

    return 0;
}
