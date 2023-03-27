#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char* argv[]) {
    // Nombre de processus par défaut
    int numProcesses = 5;

    // Si un argument de ligne de commande est fourni, l'utiliser comme nombre de processus
    if (argc > 1) {
        numProcesses = atoi(argv[1]);
    }

    DWORD pid = GetCurrentProcessId();
    printf("Processus parent PID=%d\n", pid);

    // Créer les processus
    for (int i = 0; i < numProcesses; i++) {
        PROCESS_INFORMATION pi;
        STARTUPINFO si;

        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);
        ZeroMemory(&pi, sizeof(pi));

        if (!CreateProcess(NULL, "child.exe", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
            printf("Erreur lors de la création du processus %d.\n", i);
            return 1;
        }
        printf("Processus enfant PID=%d en cours d'exécution...\n", pi.dwProcessId);

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }

    printf("Tous les processus sont créés.\n");

    return 0;
}
