#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void(*pointeur_fonction_sort)(int[], int);

void load_library(char* library_name)
{
    void* handle = dlopen(library_name, RTLD_LAZY);
    if(!handle)
    {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    dlerror();

    *(void **) (&pointeur_fonction_sort) = dlsym(handle, "sort");
}

void sort(int list[], int size)
{
    pointeur_fonction_sort(list, size);
}