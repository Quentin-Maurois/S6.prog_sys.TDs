### Exercice 1 :
```shell
[quentin@LASTERIX td04]$ ./tres_simple.exe 
Hello from the thread
Bye bye from the thread
Valeur renvoyée: 1
The end
```
Après avoir enlevé pthread_join() :
```shell
[quentin@LASTERIX td04]$ ./tres_simple.exe 
Valeur renvoyée: 0
The end
```
On empèche le programme d'accéder au thread et donc le programme passse directement à la suite.

Avec le exit(0) dans le thread :
```shell
[quentin@LASTERIX td04]$ ./tres_simple.exe 
Hello from the thread
```
Le processus entier est arrêté, pas juste le thread qui a effectué le exit(0)

Avec le exit avant de rejoindre le thread :
```shell
[quentin@LASTERIX td04]$ ./tres_simple.exe
```
On ne rentre même plus dans le thread car le processus est arrêté avant

Conclusion : exit() permet de sortir entièrement du processus alors que pthread_exit() permet d'arrêter le thread qui l'appelle.


### Exercice 2 :
```shell
[quentin@LASTERIX td04]$ ./threads.exe 1 2
PID du processus : 19293
	PID : 19293,	TID : 140513880524480
	PID : 19293,	TID : 140513872131776
	PID : 19293,	TID : 140513880524480
	PID : 19293,	TID : 140513872131776
	PID : 19293,	TID : 140513880524480
	PID : 19293,	TID : 140513880524480
	PID : 19293,	TID : 140513872131776
	PID : 19293,	TID : 140513880524480
	PID : 19293,	TID : 140513872131776
	PID : 19293,	TID : 140513872131776
Valeurs de retour : retour1 = 0, retour2 = 0
quentin@LASTERIX td04]$ ./threads.exe -1 0
PID du processus : 19232
	PID : 19232,	TID : 140196074632896
	PID : 19232,	TID : 140196074632896
	PID : 19232,	TID : 140196074632896
	PID : 19232,	TID : 140196074632896
	PID : 19232,	TID : 140196074632896
Valeurs de retour : retour1 = 1, retour2 = 0
[quentin@LASTERIX td04]$ ./threads.exe 3 2
PID du processus : 19534
	PID : 19534,	TID : 139912650139328
	PID : 19534,	TID : 139912641746624
	PID : 19534,	TID : 139912641746624
	PID : 19534,	TID : 139912650139328
	PID : 19534,	TID : 139912641746624
	PID : 19534,	TID : 139912650139328
	PID : 19534,	TID : 139912641746624
	PID : 19534,	TID : 139912641746624
	PID : 19534,	TID : 139912650139328
	PID : 19534,	TID : 139912650139328
Valeurs de retour : retour1 = 0, retour2 = 0
```
Lors de l'éxecution des différents threads, on voit bien les différents timings de sleep


### Exercice 3 :
```shell
[quentin@LASTERIX td04]$ ./threads.exe 1 2
PID du processus : 20063
	PID : 20063,	TID : 140049860560576
		Linux Thread ID: 20064
	PID : 20063,	TID : 140049852167872
		Linux Thread ID: 20065
	PID : 20063,	TID : 140049860560576
		Linux Thread ID: 20064
	PID : 20063,	TID : 140049860560576
		Linux Thread ID: 20064
	PID : 20063,	TID : 140049852167872
		Linux Thread ID: 20065
	PID : 20063,	TID : 140049860560576
		Linux Thread ID: 20064
	PID : 20063,	TID : 140049852167872
		Linux Thread ID: 20065
	PID : 20063,	TID : 140049860560576
		Linux Thread ID: 20064
	PID : 20063,	TID : 140049852167872
		Linux Thread ID: 20065
	PID : 20063,	TID : 140049852167872
		Linux Thread ID: 20065
Valeurs de retour : retour1 = 0, retour2 = 0
```


### Exercice 4 : 
```shell
[quentin@LASTERIX td04]$ ./multiple_fork.exe 100
Time taken for creating 100 processus (nanoseconds): 7250504
Time taken for creating 100 processus (milliseconds): 7
[quentin@LASTERIX td04]$ ./multiple_fork.exe 1000000
fork: Resource temporarily unavailable
Aborted (core dumped)
[quentin@LASTERIX td04]$ 
```
On ne peut pas faire autant de processus que l'on veut. Même si le système ne limitait pas, il y a une limite à la quantité de RAM de la machine.


### Exercice 5 :
```shell
[quentin@LASTERIX td04]$ ./multiple_threads.exe 1000
Time taken for creating 1000 processus (nanoseconds): 69336970
Time taken for creating 1000 processus (milliseconds): 69
[quentin@LASTERIX td04]$ ./multiple_threads.exe 10000
Time taken for creating 10000 processus (nanoseconds): 731989083
Time taken for creating 10000 processus (milliseconds): 731
```
La création de threads est bien plus rapide que pour les processus


### Exercice 6 :
Avec htop, on peut afficher le nombre de threads associés à chaque processus (le NLWP). On remarque que pour chaque processus, au moins un thread est associé. Cela doit être dû à la façon dont les threads sont implémentés dans linux, ce qui fait de ce thread le thread principal du processus


### Exercice 7 :
Le but d'un programme est d'être prévisible, le fait qu'il dépende du temps le rend moins prévisible car l'OS est le chef d'orchestre et réagira différement sur différentes machines et même selon les charges sur une même machine.

Affichage du programme quand on laisse le sleep(1) :
```shell
[quentin@LASTERIX td04]$ ./juste_presque.exe 
Dans la thread #2
Dans la thread #3
Dans la thread #4
Dans la thread #4
Dans la thread #4
```
Même quand on laisse le sleep(1) du main, les threads ne sont pas affichés dans l'ordre : pas de thread 0 ou 1 et beaucoup de threads 4. Cela semble être dû au fait que l'on crée les threads avec un pointeur verts i qui est la variable de la boucle. i incrémente à chaque boucle et en attendant une seconde et un nombre aléatoire dans le premier thread il est impossible d'afficher thread 0 (0 étant la valeur de i avec laquelle le thread a été créé)

```shell
[quentin@LASTERIX td04]$ ./juste.exe 
Dans la thread #2
Dans la thread #1
Dans la thread #3
Dans la thread #4
Dans la thread #0
```
Le programme corrigé permet à chaque thread d'afficher un numéro spécifique car la zone mémoire qui lui est attribuée est un tableau créé dans le processus principal. Chaque thread a maintenant un emplacement spécifique pour ses paramètres d'entrée et ne sont plus dépendants du temps.


### Exercice 8 :
En enlevant le sleep dans les joueurs, ils jouent très longtemps. c'est sûrement dû à la gestion des threads par l'OS (donne du temps à l'execution de chaque thread et ici, ce temps doit être bien supérieur au temps d'éxecution d'un action du joueur. Il reste dans le thread et continue de jouer). Ce qui est sûr c'est que la synchronisation entre les threads par le temps n'est pas la bonne méthode.
Autre chose : l'utilisation de mon cpu a augmenté de 30% au maximum (passant de 5% idle à 35% lors de l'éxecution du programme au lieu des 100% prévus, j'utilise linux 6.2.6 et bash 5.1.160). C'est sûrement lié à une amélioration sur les dernières mises à jour comme la VM fournie


### Exercice 9 :
