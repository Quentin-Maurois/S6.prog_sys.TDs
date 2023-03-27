#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Fonction exécutée par les threads
DWORD WINAPI threadFunction(LPVOID lpParam) {
    DWORD tid = GetCurrentThreadId();
    DWORD pid = GetCurrentProcessId();
    printf("Thread TID=%d, PID=%d en cours d'exécution...\n", tid, pid);
    Sleep(1000); // Attendre 1 seconde
    printf("Thread TID=%d, PID=%d terminé.\n", tid, pid);
    return 0;
}

int main(int argc, char* argv[]) {
    // Nombre de threads par défaut
    int numThreads = 5;

    // Si un argument de ligne de commande est fourni, l'utiliser comme nombre de threads
    if (argc > 1) {
        numThreads = atoi(argv[1]);
    }

    DWORD tid = GetCurrentThreadId();
    DWORD pid = GetCurrentProcessId();
    printf("Processus TID=%d, PID=%d\n", tid, pid);

    HANDLE* threadHandles = malloc(sizeof(HANDLE) * numThreads);
    if (threadHandles == NULL) {
        printf("Erreur lors de l'allocation de la mémoire.\n");
        return 1;
    }

    // Créer les threads
    for (int i = 0; i < numThreads; i++) {
        threadHandles[i] = CreateThread(NULL, 0, threadFunction, NULL, 0, NULL);
        if (threadHandles[i] == NULL) {
            printf("Erreur lors de la création du thread %d.\n", i);
            return 1;
        }
    }

    // Attendre que tous les threads soient terminés
    WaitForMultipleObjects(numThreads, threadHandles, TRUE, INFINITE);

    printf("Tous les threads sont terminés.\n");

    free(threadHandles);

    return 0;
}
