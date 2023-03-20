#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    printf("pid apres exec : %d\n", getpid());
    exit(0);
}