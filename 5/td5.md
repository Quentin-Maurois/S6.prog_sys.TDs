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
