

### Question 1 :
La taille demandée sera de la taille de la structure Data, soit 100 octets pour la chaine de caractères et 2 (système 32bits) ou 4 (système 64 bits) pour l'âge en fonction du système. Pour un système 64 bits, l'appel à malloc dans ce programme demandera donc 104 octets et pour un système 32 bits, seulement 102 octets.


### Question 2 :
L'allocation suit au malloc sera à la fin du tas car les zones précédentes sont trop petites pour 80 Octets. En ajoutant 80 Octets, on ne dépasse pas de la zone allouée par sbrk donc il n'y aura pas de nouvel appel à sbrk.


### Question 3 :
La taille du premier trou est de 48 Octets donc en prenant en compte le header de la zone qu'il faut allouer, il faut faire un malloc pour 32 Octets.


### Question personnelle et remarques : 
Dans le code de allocate_core, je ne comprends pas pourquoi en mettant myfree, le programme entier ne fonctionne plus alors qu'en utilisant internal_free ça marche, d'autant que myfree fait simplement appel à internal_free.  
```c
static void *allocate_core(size_t size) {
Header *new_zone;
if((size < MIN_ALLOCATION) & !!(size < MIN_ALLOCATION))
	size = MIN_ALLOCATION;

new_zone = mysbrk(size * sizeof(Header));
if(new_zone == ((void *) - 1))
	return NULL;

SIZE(new_zone) = size;
// J'aurais mis myfree mais il ne marche pas, c'est un mystère entier pour moi o.O'
internal_free(new_zone + 1);
return freep;
}
```