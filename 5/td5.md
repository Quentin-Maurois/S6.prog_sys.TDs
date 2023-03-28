# Quentin Maurois - compte rendu

### Exercice 1 :
```shell
[quentin@LASTERIX td05]$ ./fd_simple.exe tst_lsrec.sh 
File descripteurs:
tst_lsrec.sh = 3
```
Le programme ouvre les fichiers donnés en paramètres et affiche leurs file descriptor. De base, le fichier n'est pas refermé.

En ne fermant pas le fichier :
```shell
[quentin@LASTERIX td05]$ ./fd_simple.exe tst_lsrec.sh tst_perf.sh 
File descripteurs:
stdin = 0
stdout = 1
stderr =  2
tst_lsrec.sh = 3
tst_perf.sh = 4
```

En fermant le fichier :
```shell
[quentin@LASTERIX td05]$ ./fd_simple.exe tst_lsrec.sh tst_perf.sh 
File descripteurs:
stdin = 0
stdout = 1
stderr =  2
tst_lsrec.sh = 3
tst_perf.sh = 3
```
Quand on ne referme pas le fichier, il reste ouvert et son numéro de file descriptor ne sera pas libéré pour le prochain fichier


### Exercice 2 :
```shell
[quentin@LASTERIX td05]$ ./lsrec.exe ..
.. :
TD5.pdf	..	td05_distrib.zip	.	cours5_gestion_entrees_sorties.pdf	td05	td5.md	.vscode	

../td05 :
lsrec.exe	lsrec.c	fd_simple.exe	util.o	..	util.h	util.c	tst_lsrec.sh	tst_perf.sh	.	lsrec_gpt.exe	lsrec_gpt.c	tst_mycp2.sh	Makefile	fd_simple.c	tst_mycp1.sh	set_tst_dir.sh	.vscode	

../td05/.vscode :
..	tasks.json	.	launch.json	

../.vscode :
..	.	c_cpp_properties.json	

```
En appelant de manière récursive, il faut penser à ne pas inclure le dossier actuel ni le dossier parent.


### Exercice 3 :
```shell
[quentin@LASTERIX td05]$ ls
cpy_test       lsrec.exe  set_tst_dir.sh  tst_perf.sh
fd_simple.c    Makefile   tst_lsrec.sh    util.c
fd_simple.exe  mycp1.c    tst_mycp1.sh    util.h
lsrec.c        mycp1.exe  tst_mycp2.sh    util.o
[quentin@LASTERIX td05]$ ls cpy_test/
[quentin@LASTERIX td05]$ ./mycp1.exe util.c mycp1.c fd_simple.c lsrec.c cpy_test/
[quentin@LASTERIX td05]$ ls cpy_test/
fd_simple.c  lsrec.c  mycp1.c  util.c
[quentin@LASTERIX td05]$ ./mycp1.exe cpy_test/util.c cpy_test/un_peu_moins_util.c
[quentin@LASTERIX td05]$ ls cpy_test/
fd_simple.c  lsrec.c  mycp1.c  un_peu_moins_util.c  util.c
```



### Exercice 4 :
Un peu comme pour l'exercice 1 mais je n'ai pas réussi à le faire marcher.