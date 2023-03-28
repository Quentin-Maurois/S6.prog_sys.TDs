#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

void ls_rec(char* path);

int main (int argc, char** argv)
{
    while (--argc)
        ls_rec(*++argv);

    return (0);
}

void ls_rec(char* path)
{
    struct dirent *dentry;
    //ouverture du fichier et gestion des erreurs
    DIR *this_dir = opendir(path);
    if (this_dir == NULL)
    {
    perror("répertoire inaccessible\n");
    exit(EXIT_FAILURE);
    }


    //affichage du chemin du répertoire courant
    printf("%s :\n", path);


    //affichage du contenu du répertoire courant
    while ((dentry = readdir(this_dir)) != NULL)
    {
        printf("%s\t", dentry->d_name);
    }
    printf("\n\n");



    //retour au début du répertoire
    rewinddir(this_dir);


    //appels récursifs pour tous les dossiers contenus dans ce répertoire
    while ((dentry = readdir(this_dir)) != NULL)
    {
        struct stat sbuf;
        int m;

        //allocation de sub_path selon la taille de path, dentry->d_name et 2 octets de plus pour "/" et "\0"
        char* sub_path = malloc(sizeof(char)*(2 + strlen(path) + strlen(dentry->d_name)));
        sprintf(sub_path, "%s/%s", path, dentry->d_name);


        if (stat(sub_path, &sbuf) >= 0)
        {
            m = sbuf.st_mode;
        }

        if (S_ISDIR(m))
        {
            //pas d'appel récursif sur le parent ni sur lui même
            if (strcmp(dentry->d_name, "..") && strcmp(dentry->d_name, "."))   //strcmp return 0 si les deux chaines sont égales 
            {
                ls_rec(sub_path);    
            }
        }
        free(sub_path);
    }

    closedir(this_dir);
}