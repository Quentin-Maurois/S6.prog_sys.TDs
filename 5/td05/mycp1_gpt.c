#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void copy_file(char* src_path, char* dst_path) {
    int src_fd, dst_fd, n;
    char buf[4096];
    struct stat src_stat;
    
    // Ouvre le fichier source en lecture
    src_fd = open(src_path, O_RDONLY);
    if (src_fd == -1) {
        perror("Erreur ouverture fichier source");
        exit(EXIT_FAILURE);
    }
    
    // Récupère les attributs du fichier source
    if (stat(src_path, &src_stat) == -1) {
        perror("Erreur stat fichier source");
        exit(EXIT_FAILURE);
    }
    
    // Ouvre le fichier destination en écriture (crée le fichier s'il n'existe pas)
    dst_fd = open(dst_path, O_WRONLY | O_CREAT | O_TRUNC, src_stat.st_mode);
    if (dst_fd == -1) {
        perror("Erreur ouverture fichier destination");
        exit(EXIT_FAILURE);
    }
    
    // Copie le contenu du fichier source dans le fichier destination
    while ((n = read(src_fd, buf, sizeof(buf))) > 0) {
        if (write(dst_fd, buf, n) != n) {
            perror("Erreur écriture fichier destination");
            exit(EXIT_FAILURE);
        }
    }
    if (n == -1) {
        perror("Erreur lecture fichier source");
        exit(EXIT_FAILURE);
    }
    
    // Ferme les fichiers
    if (close(src_fd) == -1) {
        perror("Erreur fermeture fichier source");
        exit(EXIT_FAILURE);
    }
    if (close(dst_fd) == -1) {
        perror("Erreur fermeture fichier destination");
        exit(EXIT_FAILURE);
    }
}

void copy_files_to_dir(int argc, char* argv[], char* dir_path) {
    int i;
    char dst_path[4096];
    struct stat dir_stat;
    
    // Vérifie que le répertoire destination existe
    if (stat(dir_path, &dir_stat) == -1) {
        perror("Erreur stat répertoire destination");
        exit(EXIT_FAILURE);
    }
    if (!S_ISDIR(dir_stat.st_mode)) {
        fprintf(stderr, "Erreur: %s n'est pas un répertoire\n", dir_path);
        exit(EXIT_FAILURE);
    }
    
    // Parcourt les fichiers sources et les copie dans le répertoire destination
    for (i = 1; i < argc - 1; i++) {
        sprintf(dst_path, "%s/%s", dir_path, basename(argv[i]));
        copy_file(argv[i], dst_path);
    }
}

int main(int argc, char* argv[]) {
    struct stat src_stat, dst_stat;
    
    // Vérifie le nombre d'arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s fic1 fic2\n", argv[0]);
        fprintf(stderr, "       %s fic1 fic2 ... dir\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    // Vérifie si la dernière argument est un fichier ou un répertoire
    if (stat(argv[argc-1], &dst_stat) == -1) {
        // Si la stat échoue, on considère que le dernier argument est un nom de fichier
        if (argc != 3) {
            fprintf(stderr, "Erreur: le dernier argument doit être un répertoire");
        }
    }
}
