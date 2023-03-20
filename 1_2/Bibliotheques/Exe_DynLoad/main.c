#include <stdio.h>
#include <Windows.h>

typedef void(*function)(char*);

static function func;

int main(void) {
	void* ref = LoadLibrary(TEXT("C:/Users/Michel K/source/repos/Bibliotheques/Debug/Bibliotheques.dll")); // Conversion nécessaire
	if (!ref) // Erreur lors du chargement de la bibliothèque ?
	{
		printf("Impossible de charger la bibliothèque.");
	}
	else { // On récupère l'adresse de la fonction 
		func = (function) GetProcAddress(ref, "PrintStop");
		func("Test dynamic load");
	}
	return 0;
}