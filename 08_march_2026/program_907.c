#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char * argv[], char * envp[])
{
    printf("List of environment veriables are : \n");

    int iCounter = 0;

    for (iCounter = 0; envp[iCounter] != NULL; iCounter++)
    {
        printf("%s\n", envp[iCounter]);
    }

    return 0;
}

