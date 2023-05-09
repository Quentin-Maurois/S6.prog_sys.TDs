### Notes :
J'ai modifié les Makefiles pour avoir les bons chemins vers jni sur mon système.

JAVA_H=/usr/lib/jvm/java-17-openjdk-amd64/
deviens
JAVA_H=/usr/lib/jvm/java-17-openjdk/



### Exercice 1 :
```shell
[quentin@LASTERIX td09]$ echo $LD_LIBRARY_PATH
.
[quentin@LASTERIX td09]$ java HelloWorld.java 
Loading Hello World native library...Exception in thread "main" java.lang.UnsatisfiedLinkError: no HelloWorld in java.library.path: .:/usr/java/packages/lib:/usr/lib64:/lib64:/lib:/usr/lib
	at java.base/java.lang.ClassLoader.loadLibrary(ClassLoader.java:2429)
	at java.base/java.lang.Runtime.loadLibrary0(Runtime.java:818)
	at java.base/java.lang.System.loadLibrary(System.java:1989)
	at HelloWorld.<clinit>(HelloWorld.java:12)
	at java.base/java.lang.Class.forName0(Native Method)
	at java.base/java.lang.Class.forName(Class.java:467)
	at jdk.compiler/com.sun.tools.javac.launcher.Main.execute(Main.java:409)
	at jdk.compiler/com.sun.tools.javac.launcher.Main.run(Main.java:192)
	at jdk.compiler/com.sun.tools.javac.launcher.Main.main(Main.java:132)
[quentin@LASTERIX td09]$ cd lib
[quentin@LASTERIX lib]$ java ../HelloWorld.java 
Loading Hello World native library...done.
Hello World !
Veuillez appuyer sur Entrée pour terminer le programme...

```
On remarque que le système ne trouve tout simplement pas la bibliothèque à charger. 

### Exercice 2 :
```shell
[quentin@LASTERIX td09]$ echo $LD_LIBRARY_PATH
.:./lib
[quentin@LASTERIX td09]$ java HelloWorld.java 
Loading Hello World native library...done.
Hello World !
Veuillez appuyer sur Entrée pour terminer le programme...

```
En ajoutant le répertoire ./lib on voit que le système charge bien la bibliothèque


### Exercice 3 :
```shell
quentin@LASTERIX td09]$ java HelloWorld.java 
Loading Hello World native library... done.
Hello World !
Je suis une chaine de caractères qui a été transférée depuis java vers c

Chaîne en C
Veuillez appuyer sur Entrée pour terminer le programme...

```


### Exercice 4 :
```shell
[quentin@LASTERIX td09]$ java HelloWorld.java 
Loading Hello World native library... done.
Je suis une chaine de caractères qui a été transférée depuis java vers c

Chaîne en C
Hello World !
Veuillez appuyer sur Entrée pour terminer le programme...

```
J'ai créé une méthode test dans mon programme java et modifié le code c++ pour ma fonction test qui prends void en entrée et renvoie void
```c
jmethodID mid = env->GetStaticMethodID(cls,"test","()V");
```
L'appel à callJavaMethod se passe correctement et la fonction test est donc exécutée (test contients le code initial de HelloWorld et renvoie donc Hello World ! sur la console).


### Exercice 5 :
```shell
[quentin@LASTERIX td09]$ java HelloWorld.java 
Loading Hello World native library... done.
Je suis une chaine de caractères qui a été transférée depuis java vers c

Chaîne en C
Hello World !
Hello [a = 1]
Veuillez appuyer sur Entrée pour terminer le programme...

```
Après avoir créé un int "entier" dans la classe java (initialisé à 0), on voit que le programme fonctionne comme attendu.


### Exercice 6 :
```shell
[quentin@LASTERIX td09]$ java HelloWorld.java 
Loading Hello World native library... done.
Je suis une chaine de caractères qui a été transférée depuis java vers c

Chaîne en C
Hello World !
Hello [a = 1]
fibonacci de 6 = 8
Veuillez appuyer sur Entrée pour terminer le programme...

```
J'ai implémenté la fonction fib en c++ et j'ai créé la fonction Java_HelloWorld_fib qui prends un int en paramètres et renvoie le résultat de fib.


### Exercice 7 :
```shell
[quentin@LASTERIX td09]$ java Exo1.java 
ID with old API: 8876
ID with new API: 8876
```
