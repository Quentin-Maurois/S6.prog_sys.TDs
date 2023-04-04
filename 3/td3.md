### Exercice 1

On stocke la sortie de multiple_fork.exe dans un fichier texte pour pouvoir utiliser la commande wc -l. Il y a bien 100 lignes


### Exercice 2

Lors de l'exécution de multiple_fork.exe avec une seconde d'attente, on regarde les processus multiple_fork.exe en cours :
```
[quentin@LASTERIX ~]$ ps aux | grep multiple_fork.exe
quentin    10797  0.0  0.0   2352   896 pts/0    S+   10:05   0:00 ./multiple_fork.exe
quentin    10798  0.0  0.0   2484   896 pts/0    S+   10:05   0:00 ./multiple_fork.exe
quentin    10799  0.0  0.0   2484   896 pts/0    S+   10:05   0:00 ./multiple_fork.exe
quentin    10800  0.0  0.0   2484   896 pts/0    S+   10:05   0:00 ./multiple_fork.exe
quentin    10801  0.0  0.0   2484   896 pts/0    S+   10:05   0:00 ./multiple_fork.exe
quentin    10802  0.0  0.0   2484   896 pts/0    S+   10:05   0:00 ./multiple_fork.exe
quentin    10803  0.0  0.0   2484   896 pts/0    S+   10:05   0:00 ./multiple_fork.exe
quentin    10804  0.0  0.0   2484   896 pts/0    S+   10:05   0:00 ./multiple_fork.exe
quentin    10805  0.0  0.0   2484   896 pts/0    S+   10:05   0:00 ./multiple_fork.exe
quentin    10806  0.0  0.0   2484   896 pts/0    S+   10:05   0:00 ./multiple_fork.exe
quentin    10807  0.0  0.0   2484   896 pts/0    S+   10:05   0:00 ./multiple_fork.exe
quentin    10809  0.0  0.0   6568  2432 pts/1    S+   10:05   0:00 grep multiple_fork.exe
```

On remarque que les pid (dans la seconde colonne) se suivent


### Exercice 3 :

Lors de l'exécution de zombie.exe, on regarde les processus lorsque le père et le fils "vivent", lorsque le fils "meurt" alors que le père "vit" toujours et lorsque le père "meurt" :
```
[quentin@LASTERIX ~]$ ps aux | grep zombie.exe
quentin    13452  0.0  0.0   2484  1152 pts/0    S+   10:45   0:00 ./zombie.exe
quentin    13453  0.0  0.0   2484   768 pts/0    S+   10:45   0:00 ./zombie.exe
quentin    13455  0.0  0.0   6568  2560 pts/1    S+   10:45   0:00 grep zombie.exe
[quentin@LASTERIX ~]$ ps aux | grep zombie.exe
quentin    13452  0.0  0.0   2484  1152 pts/0    S+   10:45   0:00 ./zombie.exe
quentin    13453  0.0  0.0      0     0 pts/0    Z+   10:45   0:00 [zombie.exe] <defunct>
quentin    13458  0.0  0.0   6568  2304 pts/1    S+   10:45   0:00 grep zombie.exe
[quentin@LASTERIX ~]$ ps aux | grep zombie.exe
quentin    13472  0.0  0.0   6568  2304 pts/1    S+   10:45   0:00 grep zombie.exe
```
Lorsque le fils se termine, son état passe à "z+" qui signifie zombie et sa taille résidente est donc de zéro car il est terminé.


### Exercice 4 :
```
[quentin@LASTERIX td03]$ ./orphelin.exe 
Processus père
pid : 15280
	Processus fils
	Parent : 15280
Fin du processus père
	Nouveau parent : -2051981120
	Fin du processus fils
```
Ici le nouveau parent a un pid négatif ce qui parrait étrange. Je ne suis pas sûr de comprendre pourquoi.


### Exercice 5 :
```
[quentin@LASTERIX td03]$ ./exec_prop.exe 
pid pere : 50510pere reprends
pid pere : 50510	pid fils : 50511
	fin du fils
pid apres exec : 50510
```
Le père stocke le message "pid pere : 50510" dans son buffer puis fork sur son fils qui ajoute "\tpid fils : 50511\n" dans son buffer puis l'affiche grâce au \n. Le fils se termine et le père ajoute ensuite "pere reprends\n" dans son buffer et l'affiche grâce à \n. Je ne comprends cependant pas pourquoi le message du pere s'affiche avant celui du fils. Le pid après l'exec a bien été conservé.


### Exercice 6 :
```
[quentin@LASTERIX td03]$ ./shell_exec.exe 
quentin  tty2         2023-03-10 15:05 (tty2)
total 180
 4 -rw-r--r-- 1 quentin quentin   157 Mar 10 14:48 exec_prop_aux.c
20 -rwxr-xr-x 1 quentin quentin 16848 Mar 10 15:48 exec_prop_aux.exe
 4 -rw-r--r-- 1 quentin quentin   752 Mar 10 14:51 exec_prop.c
20 -rwxr-xr-x 1 quentin quentin 17320 Mar 10 15:48 exec_prop.exe
 4 -rw-rw-r-- 1 quentin quentin  3547 Mar  4  2017 fcat.c
20 -rwsr-xr-x 1 quentin quentin 19024 Mar 10 15:48 fcat.exe
 4 -rw-rw-r-- 1 quentin quentin  1725 Feb 22  2018 Makefile
 4 -rw-r--r-- 1 quentin quentin   526 Mar  7 10:29 multiple_fork.c
20 -rwxr-xr-x 1 quentin quentin 17240 Mar 10 15:48 multiple_fork.exe
 4 -rw-r--r-- 1 quentin quentin   806 Mar 10 14:37 orphelin.c
20 -rwxr-xr-x 1 quentin quentin 17392 Mar 10 15:48 orphelin.exe
 4 -rw-r--r-- 1 quentin quentin   200 Mar  7 09:49 output.txt
 4 -rw------- 1 quentin quentin    41 Mar 10 15:52 secret_file.txt
 4 -rw-r--r-- 1 quentin quentin  1181 Mar 10 15:52 shell_exec.c
20 -rwxr-xr-x 1 quentin quentin 17176 Mar 10 15:52 shell_exec.exe
 4 -rw-r--r-- 1 quentin quentin   510 Mar  7 10:44 zombie.c
20 -rwxr-xr-x 1 quentin quentin 17064 Mar 10 15:48 zombie.exe
```


### Exercice 7 :
```
[quentin@LASTERIX td03]$ ./shell_exec.exe 
quentin  tty2         2023-03-10 15:05 (tty2)
total 60
 4 drwxr-xr-x  2 quentin quentin 4096 Jan 23 22:33  Desktop
 4 drwxr-xr-x  6 quentin quentin 4096 Mar  1 10:52  Documents
 4 drwxr-xr-x  3 quentin quentin 4096 Mar 10 14:19  Downloads
 4 drwxr-xr-x  2 quentin quentin 4096 Jan 20 19:24  Public
 0 lrwxrwxrwx  1 quentin quentin   35 Mar 10 15:10  S6 -> /home/quentin/Documents/polytech/S6
 4 drwxr-xr-x  2 quentin quentin 4096 Feb 13 19:37  Templates
```
Info : j'ai enlevé quelques répertoires de l'affichage À la fin de l'éxecution, on finit dans le répertoire dans lequel on a lancé la commande, contrairement à lorsqu'on les fait manuellement.


### Exercice 8 :
```
[quentin@LASTERIX td03]$ ./shell-system.exe 
$ ls
exec_prop-aux.c    exec_prop.exe    multiple_fork.exe  shell-exec.c    shell-system.exe
exec_prop-aux.exe  Makefile	    orphelin.c	       shell-exec.exe  zombie.c
exec_prop.c	   multiple_fork.c  orphelin.exe       shell-system.c  zombie.exe
$ cd ..
$ ls
td03  td03.zip
$ 
```


### Exercice 9 :
```
[quentin@LASTERIX td03]$ ./shell-system.exe 
$ cat
^C
[quentin@LASTERIX td03]$ 
```
Avec my_system, un ^C arrête également l'éxecution shell-system.exe alors qu'avec system, seule la commande définie était arrêtée
