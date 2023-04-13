### Exercice 1 :
1. L'éxecution de la commande xeyes prends la main sur le terminal.
2. En effectuant un Ctrl-z, l'éxecution de xeyes est suspendue et le terminal récupère la main.
3. xeyes reprends vie ! la fenêtre s'éxecute en arrière plan.
4. 
```shell
[quentin@LASTERIX td07]$ ps
    PID TTY          TIME CMD
   4628 pts/0    00:00:00 bash
  14798 pts/0    00:00:00 xeyes
  14854 pts/0    00:00:00 ps
```
5. [quentin@LASTERIX ~]$ kill -SIGSTOP 14798
   Cette commande agis comme l'as fait ctrl-z précédement.
6. Le signal n°18 permet de continuer un processus
   ```shell
[quentin@LASTERIX ~]$ kill -18 14798
```
7. La commande killall permet d'entrer un nom de processus a terminer. Cela a pour inconvénient cependant de fermer tous les processus portant ce nom.
   ```shell
[quentin@LASTERIX td07]$ killall xeyes
[1]+  Terminated              xeyes
```


### Exercice 2 :
```shell
[quentin@LASTERIX td07]$ ./tst_signal.exe 
^C*** signal 2
^C*** signal 2
*** signal 11
^C*** signal 2
^C*** signal 2
^C*** signal 2
^C*** signal 2
*** signal 11
^C*** signal 2
^C*** signal 2
^C*** signal 2
^C*** signal 2
^C*** signal 2
```
J'utilise un second terminal pour envoyer les signaux SIGSEGV.
```shell
[quentin@LASTERIX ~]$ ps aux | grep tst_
quentin    16406 99.2  0.0   2484  1024 pts/0    R+   09:53   0:30 ./tst_signal.exe
quentin    16466  0.0  0.0   6568  2284 pts/2    S+   09:53   0:00 grep tst_
[quentin@LASTERIX ~]$ kill -SEGV 16406
[quentin@LASTERIX ~]$ kill -SEGV 16406
```
Logiquement le signal SIGSEGV serait reçu lors d'une violation mémoire et serait donc une erreur d'éxecution et pas un signal envoyée par l'utilisateur.


### Exercice 3 :
```shell
[quentin@LASTERIX td07]$ ./tst_sigaction.exe 
^C*** signal 2
^C*** signal 2
*** signal 11
^C*** signal 2
^C*** signal 2
^C*** signal 2
^C*** signal 2
^C*** signal 2
```
Comme pour le programme précédent, j'utilise un second terminal pour envoyer le signal SIGSEGV. 


### Exercice 4 :
DESCRIPTION
       sleep() causes the calling thread to sleep either until the number
       of real-time seconds specified in seconds have elapsed or until  a
       signal arrives which is not ignored.

Dans la description de sleep, sleep permet d'attendre un nombre de secondes défini ou un signal non ignoré.

Ainsi, à la réception d'un signal le programme s'arrête.


### Exercice 5 :
J'ajoute -ansi dans les flags du Makefile. Lors d'un make, tst_sigaction ne compile pas car sigaction n'est pas connu lors de la compilation. 

```shell
[quentin@LASTERIX td07]$ ./tst_signal.exe 
^C*** signal 2
^C
```
Comme mon programme n'intègre pas de réarmement pour rediriger les signaux après une réception de ceux-ci (nécessaire en ansi c) lors de la seconde réception d'un même signal, celui-ci aura son comportement habituel et donc pour un ctrl-c, arrêtera le programme.


### Exercice 6 :
Lorsque le signal est ignoré, il n'y aura jamais de réponse de la part du programme (partie 1)
Lorsque le signal est trappé, il y aura une réponse de la part du programme lorsque celui-ci reprendra son cours, cependant il ne saura pas combien d'appels il y a eu à ce signal (partie 2)
Avec un handler vide, le comportement n'est pas celui par défaut, il ne fait simpement rien (partie 3)
Sans handler, le comportement des signaux est celui par défaut. (partie 4)


### Exercice 7 :
```
[quentin@LASTERIX td07]$ ./tst_children.exe 
handling SIGUSR1 : 10
handling SIGUSR2 : 12
```
Question 1 : Je pense que la question a un rapport avec le fait que les enfants sont créés dans un ordre spécifique et qu'il y aurait un envoie de signal avant que l'enfant ne soit créé.