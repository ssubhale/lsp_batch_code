#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>


int main(void)
{
    void * handle = NULL;

    int (*fp)(int, int);

    int iResult = 0;

    handle = dlopen("./libserver_01.so", RTLD_LAZY);

    if (handle == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    printf("Library gets loaded successfully\n");

    fp = (int (*)(int, int))dlsym(handle, "Addition");

    if (fp == NULL)
    {
        printf("Unable to get address of function\n");
        dlclose(handle);
        return -1;
    }

    iResult = fp(10, 12);

    printf("Addition is : %d\n", iResult);


    fp = (int (*)(int, int))dlsym(handle, "Subtraction");

    if (fp == NULL)
    {
        printf("Unable to get address of function\n");
        dlclose(handle);
        return -1;
    }

    iResult = fp(12, 10);

    printf("Subtraction is : %d\n", iResult);


    dlclose(handle);

    printf("Library gets unloaded successfully\n");

    return 0;
}

