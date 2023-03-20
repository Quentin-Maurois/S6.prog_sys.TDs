#include <stdio.h>

_declspec(dllexport) void PrintStop(char*);

void PrintStop(char* msg) {
    printf("%s", msg);
    char a = getchar();
}
