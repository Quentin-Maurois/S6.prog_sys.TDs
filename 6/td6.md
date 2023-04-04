### Exercice 1
```shell
[quentin@LASTERIX td06]$ rm foo 
[quentin@LASTERIX td06]$ ./redir_simple.exe 
[quentin@LASTERIX td06]$ cat foo 
total 204
-rw-r--r-- 1 quentin quentin   417 Apr  2 23:50 ecrivain.c
-rwxr-xr-x 1 quentin quentin 17440 Apr  3 18:51 ecrivain.exe
-rw-r--r-- 1 quentin quentin     0 Apr  4 12:14 foo
-rw-r--r-- 1 quentin quentin   418 Apr  2 23:50 lecteur.c
-rwxr-xr-x 1 quentin quentin 17432 Apr  3 18:51 lecteur.exe
-rw-rw-r-- 1 quentin quentin  2107 Mar 24  2018 Makefile
-rw-r--r-- 1 quentin quentin  1027 Apr  3 21:10 mypopen.c
-rwxr-xr-x 1 quentin quentin 18280 Apr  3 21:10 mypopen.exe
-rw-rw-r-- 1 quentin quentin  1145 Mar 28 10:26 redir.c
-rwxr-xr-x 1 quentin quentin 18664 Mar 28 10:34 redir.exe
-rw-r--r-- 1 quentin quentin   408 Mar 28 09:45 redir_simple.c
-rwxr-xr-x 1 quentin quentin 16912 Mar 28 10:05 redir_simple.exe
-rwxrwxr-x 1 quentin quentin   531 Mar 23  2017 tst_redir.sh
-rw-r--r-- 1 quentin quentin   368 Mar 28 11:02 tube_anonyme1.c
-rwxr-xr-x 1 quentin quentin 17264 Mar 28 11:02 tube_anonyme1.exe
-rw-r--r-- 1 quentin quentin   685 Mar 28 11:43 tube_anonyme2.c
-rwxr-xr-x 1 quentin quentin 17488 Mar 28 11:43 tube_anonyme2.exe
-rw-r--r-- 1 quentin quentin  1484 Apr  1 16:37 tube_anonyme_multi.c
-rwxr-xr-x 1 quentin quentin 18088 Apr  1 16:37 tube_anonyme_multi.exe
drwxrwxr-x 6 quentin quentin  4096 Mar 27  2017 Win32NamedPipe
```


### Exercice 2 :
```shell
[quentin@LASTERIX td06]$ ./redir.exe W date.txt date
[quentin@LASTERIX td06]$ cat date.txt 
Tue Apr  4 12:16:53 PM CEST 2023
```



### Exercice 3 :
```shell
[quentin@LASTERIX td06]$ ./tube_anonyme1.exe 
0 1 2 3 4 5 6 7 8 9 
```



### Exercice 4 :
```shell
[quentin@LASTERIX td06]$ ./tube_anonyme2.exe 
0 1 2 3 4 5 6 7 8 9  
```
On remarque bien la pause de 2 secondes lors de l'éxecution du programme qui empêche le lecteur de se fermer et donc ne nous rends pas la main.


### Exercice 5 :
```shell
[quentin@LASTERIX td06]$ ./tube_anonyme_multi.exe 
ab
AB
CDc
dDc
efE
FfE
GHg
hHg
IJi
jJi
KLk
lLk
MNm
nNm
OPo
pPo
QRq
rRq
STs
tTs
uvU
VvU
WXw
xXw
yzY
ZzY
```
L'éxecution ne se passe pas comme prévue, on remarque que certaines lettres sont lues en double par le lecteur. Pour corriger cela, on pourait utiliser des variables sémaphores pour bloquer le tube en lecture et en écriture pour les autres lors d'une écriture, de même en lecture.


### Exercice 6 :
#### Question 1 :
```shell
[quentin@LASTERIX td06]$ ls -l /tmp
prw-r--r-- 1 quentin quentin  0 Apr  4 12:25 my_named_pipe
```
Le fichier n'est accessible qu'en lecture pour le groupe et pour les invités. Cela est normal en sachant que le tube nomé permet simplement de créer un file descriptor (un pour l'entrée et un pour la sortie) qui permet d'accéder à une zone mémoire où les informations sont stockées avant d'être lues.

#### Question 2 :
Il faudrait pour chacun des processus un tube d'entrée et un tube de sortie.

#### Question 3 :
Si il y a plusieurs lecteurs sur le tube, chacun des lecteurs va lire à tour de rôle le nombre de caractères entrée dans la fonction read qu'ils appellent. Si la fonction demande à lire trop de paramètres d'un coup alors elle laisse la main à l'autre lecteur comme si elle avait finit de lire sur ce tour.


### Exercice 7 :
```shell
[quentin@LASTERIX td06]$ ./mypopen.exe ls -l
ecrivain.c
ecrivain.exe
foo
lecteur.c
lecteur.exe
Makefile
mypopen.c
mypopen.exe
redir.c
redir.exe
redir_simple.c
redir_simple.exe
tst_redir.sh
tube_anonyme1.c
tube_anonyme1.exe
tube_anonyme2.c
tube_anonyme2.exe
tube_anonyme_multi.c
tube_anonyme_multi.exe
Win32NamedPipe

===== Nombre de caractères : 275 =====
[quentin@LASTERIX td06]$ ./mypopen.exe cat foo
^C
```
Voici un exemple de sortie avec my_popen. Je ne comprends cependant pas pourquoi lorsque j'essaye d'afficher le contenu de foo mon programme n'arrive ni à l'afficher, ni à s'arrêter. Le processus père attends le processus enfant mais celui-ci est bloqué ce qui empêche de sortir de la fonction.
